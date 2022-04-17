
import os
import argparse
import cv2
import numpy as np
import sys
import time
from threading import Thread
import importlib.util
import time
import serial_Send
import distance_ontime
from tflite_runtime.interpreter import Interpreter

import threading
class VideoStream:
    
    def __init__(self,resolution=(640,480),framerate=30):
        self.stream = cv2.VideoCapture(0)
        
        ret = self.stream.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
        ret = self.stream.set(3,resolution[0])
        ret = self.stream.set(4,resolution[1])
        (self.grabbed, self.frame) = self.stream.read()
        self.stopped = False

    def start(self):
        Thread(target=self.update,args=()).start()
        return self

    def update(self):
        while True:
            if self.stopped:
                self.stream.release()
                return
            (self.grabbed, self.frame) = self.stream.read()

    def read(self):
        return self.frame

    def stop(self):
        self.stopped = True

pid = os.getpid()
print('pid: ', pid)
f1 = open(file='PID_BODY.txt', mode='w')
f1.write(pid.__str__())
f1.close()


MODEL_NAME = 'Sample_TFLite_model'
GRAPH_NAME = 'detect.tflite'
LABELMAP_NAME = 'labelmap.txt'
min_conf_threshold = 0.5
imW = 640
imH = 480
isperson = False
CWD_PATH = os.getcwd()

PATH_TO_CKPT = os.path.join(CWD_PATH,MODEL_NAME,GRAPH_NAME)

PATH_TO_LABELS = os.path.join(CWD_PATH,MODEL_NAME,LABELMAP_NAME)

with open(PATH_TO_LABELS, 'r') as f:
    labels = [line.strip() for line in f.readlines()]

if labels[0] == '???':
    del(labels[0])

interpreter = Interpreter(model_path=PATH_TO_CKPT)

interpreter.allocate_tensors()

input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()
height = input_details[0]['shape'][1]
width = input_details[0]['shape'][2]

floating_model = (input_details[0]['dtype'] == np.float32)

input_mean = 127.5
input_std = 127.5

frame_rate_calc = 1
freq = cv2.getTickFrequency()

videostream = VideoStream(resolution=(imW,imH),framerate=30).start()

def follow():
    while True:
        time.sleep(0.3)
        if isperson:
            distance = distance_ontime.Measure()
            if distance > 50:
                serial_Send.Send_Con('1')
            elif distance < 30:
                serial_Send.Send_Con('2')
            else :
                serial_Send.Send_Con('0')

t = threading.Thread(target=follow, args=())
t.start()


while True:

    t1 = cv2.getTickCount()
    frame1 = videostream.read()
    frame1 = cv2.flip(frame1, -1)
    frame1 = cv2.flip(frame1, 1)
    frame = frame1.copy()
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    frame_resized = cv2.resize(frame_rgb, (width, height))
    input_data = np.expand_dims(frame_resized, axis=0)

    if floating_model:
        input_data = (np.float32(input_data) - input_mean) / input_std

    interpreter.set_tensor(input_details[0]['index'],input_data)
    interpreter.invoke()

    boxes = interpreter.get_tensor(output_details[0]['index'])[0] 
    classes = interpreter.get_tensor(output_details[1]['index'])[0] 
    scores = interpreter.get_tensor(output_details[2]['index'])[0]
    if labels[int(classes[0])] == 'person':
        isperson = True
        if ((scores[0] > min_conf_threshold) and (scores[0] <= 1.0)):

            ymin = int(max(1,(boxes[0][0] * imH)))
            xmin = int(max(1,(boxes[0][1] * imW)))
            ymax = int(min(imH,(boxes[0][2] * imH)))
            xmax = int(min(imW,(boxes[0][3] * imW)))
            
            cv2.rectangle(frame, (xmin,ymin), (xmax,ymax), (10, 255, 0), 2)
            object_name = labels[int(classes[0])]
            label = '%s: %d%%' % (object_name, int(scores[0]*100)) 
            labelSize, baseLine = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.7, 2)
            label_ymin = max(ymin, labelSize[1] + 10)
            cv2.rectangle(frame, (xmin, label_ymin-labelSize[1]-10), (xmin+labelSize[0], label_ymin+baseLine-10), (255, 255, 255), cv2.FILLED) 
            cv2.putText(frame, label, (xmin, label_ymin-7), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 0), 2) 
    else :
        isperson = False
        serial_Send.Send_Con('0')
    cv2.putText(frame,'FPS: {0:.2f}'.format(frame_rate_calc),(30,50),cv2.FONT_HERSHEY_SIMPLEX,1,(255,255,0),2,cv2.LINE_AA)
    cv2.imshow('Object detector', frame)
    t2 = cv2.getTickCount()
    time1 = (t2-t1)/freq
    frame_rate_calc= 1/time1

    # Press 'q' to quit
    if cv2.waitKey(1) == ord('q'):
        break

cv2.destroyAllWindows()
videostream.stop()
