
import sys
import Form
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5 import QtWidgets, QtCore, QtGui
import cv2
import threading
import serial_Send
import os
import subprocess
import bluetoothcon
from faceThread import faceThread
import vlc

class MainQWidget(QWidget, Form.Ui_Form):
    def __init__(self):
        QMainWindow.__init__(self)
        Form.Ui_Form.__init__(self)
        self.setupUi(self)
        self.video_stream = cv2.VideoCapture(0)
        self.video_stream.set(3, 640)
        self.video_stream.set(4, 480)
        
        self.frame= ''
        self.face_haar = cv2.CascadeClassifier("./resources/haarcascade_frontalface_default.xml")
        self.painter = QPainter(self)
        self.pushButton_Voice.clicked.connect(self.voice_open)
        self.pushButton_Face.clicked.connect(self.face_open)
        self.pushButton_exit.clicked.connect(self.exitForm)
        self.pushButton_Hide.clicked.connect(self.Hide)
        self.pushButton_Body.clicked.connect(self.Body)
        self.pushButton.clicked.connect(self.frontcon)
        self.pushButton_4.clicked.connect(self.backcon)
        self.pushButton_2.clicked.connect(self.leftcon)
        self.pushButton_3.clicked.connect(self.rightcon)
        self.pushButton_5.clicked.connect(self.rescon)
        
        self.faceFlag = False
        self.voiceFlag = False
        self.HideFlag = False
        self.BodyFlag = False
        self.Flag = False
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.mytime)
        self.timer.start(500)
        self.timerblue = QtCore.QTimer()
        self.timerblue.timeout.connect(self.bluecon)
        self.timerblue.start(5)
        self.facename = 'Identification results: '
        self.faceThread = faceThread( not self.faceFlag)
        self.faceThread.start()
        self.faceThread.faceSignal.connect(self.facenamedeal)


    def paintEvent(self, a0: QtGui.QPaintEvent):
        if not self.Flag:
            ret, frame = self.video_stream.read()
            self.frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            self.frame = cv2.flip(self.frame, -1)
            self.frame = cv2.flip(self.frame, 1)
            if self.faceFlag:
                faces = self.face_haar.detectMultiScale(self.frame, 1.2, 5)
                if faces != ():
                    # print (faces)
                    serial_Send.Send_Con('+')
                for face_x, face_y, face_w, face_h in faces:
                    # if (face_x + face_w/2) > 640/2 + 150:
                    #    serial_Send.Send_Con('B')
                    #elif (face_x + face_w/2) > 640/2 - 150:
                    #    serial_Send.Send_Con('C')
                    #else :
                    #   serial_Send.Send_Con('+')
                    cv2.rectangle(self.frame, (face_x, face_y), (face_x + face_w, face_y + face_h), (0, 255, 0), 2)
                cv2.putText(self.frame, self.facename, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1.2, (255, 255, 255), 2)
            self.Qframe = QImage(self.frame.data, self.frame.shape[1], self.frame.shape[0], self.frame.shape[1] * 3, QImage.Format_RGB888)
            self.label_video.setPixmap(QPixmap.fromImage(self.Qframe))
        self.update()

    


    def face_open(self):
        self.faceFlag = not self.faceFlag
        if(self.faceFlag):
            p = vlc.MediaPlayer("./resources/faceopen_audio.wav")
            p.play()
            serial_Send.Send_Con('A')
            self.pushButton_Face.setText("人脸点播：打开")
        else:
            p = vlc.MediaPlayer("./resources/faceclose_audio.wav")
            p.play()
            serial_Send.Send_Con('B')
            self.pushButton_Face.setText("人脸点播：关闭")
        # self.faceThread.terminate() # 结束线
        # self.faceThread = faceThread(self.faceFlag)
        # self.faceThread.start()

    def exitForm(self):
        serial_Send.Send_Con('0')
        self.video_stream.release()
        self.close()
    def mytime(self):
        cv2.imwrite("faceimage.jpg", self.frame)
    def bluecon(self):
        bluetoothcon.recvread()
    def facenamedeal(self,name):
        self.facename = 'Identification results: '
        self.facename = self.facename + name
    def frontcon(self):
        serial_Send.Send_Con('1')
    def backcon(self):
        serial_Send.Send_Con('2')
    def leftcon(self):
        serial_Send.Send_Con('3')
    def rightcon(self):
        serial_Send.Send_Con('4')
    def rescon(self):
        serial_Send.Send_Con('0')
    def voice_open(self):
        if not self.voiceFlag:
            p = vlc.MediaPlayer("./resources/voiceopen_audio.wav")
            p.play()
            subprocess.Popen(["python3", "voice_wake.py"])
            self.pushButton_Voice.setText("语音助手：打开")
        else:
            p = vlc.MediaPlayer("./resources/voiceclose_audio.wav")
            p.play()
            f1 = open(file='PID_VOICE.txt', mode='r')
            pid = f1.read()
            f1.close()
            print('kill ' + pid.__str__())
            os.system('kill ' + pid)
            self.pushButton_Voice.setText("语音助手：关闭")
        self.voiceFlag = not self.voiceFlag
        
    def Hide(self):
        if not self.HideFlag:
            p = vlc.MediaPlayer("./resources/hideopen_audio.wav")
            p.play()
            subprocess.Popen(["python3", "distance.py"])
            self.pushButton_Hide.setText("自动避障：打开")
        else:
            p = vlc.MediaPlayer("./resources/hideclose_audio.wav")
            p.play()
            f1 = open(file='PID_dis.txt', mode='r')
            pid = f1.read()
            f1.close()
            print('kill ' + pid.__str__())
            os.system('kill ' + pid)
            self.pushButton_Hide.setText("自动避障：关闭")
            serial_Send.Send_Con('0')
        self.HideFlag = not self.HideFlag
    def Body(self):
        if not self.BodyFlag:
            p = vlc.MediaPlayer("./resources/bodyopen_audio.wav")
            p.play()
            self.Flag = True
            self.video_stream.release()
            subprocess.Popen(["python3", "Body.py"])
            self.pushButton_Body.setText("人体跟随：打开")
        else:
            p = vlc.MediaPlayer("./resources/bodyclose_audio.wav")
            p.play()
            f1 = open(file='PID_BODY.txt', mode='r')
            pid = f1.read()
            f1.close()
            print('kill ' + pid.__str__())
            os.system('kill ' + pid)
            self.video_stream = cv2.VideoCapture(0)
            # time.sleep(1)
            self.pushButton_Hide.setText("人体跟随：关闭")
            serial_Send.Send_Con('0')
            self.Flag = False
        # self.faceFlag = not self.faceFlag
        self.BodyFlag = not self.faceFlag
        
if __name__ == '__main__':
    app = QApplication(sys.argv)
    md = MainQWidget()
    md.show()
    sys.exit(app.exec_())
