# import keyboard
from aip import AipFace
# from picamera import PiCamera
import urllib.request
# import RPi.GPIO as GPIO
import base64
import time
import cv2
import threading
import music_play
import os
# import bluetooth

# from bluetooth_test import bt_open,servo_init,bt_close


#百度人脸识别API账号信息
APP_ID = '24937006'
API_KEY = 'zrweIbn3u2SQGVYxv0c3ijjj'
SECRET_KEY ='pO6GfRYNaueynWdqnCOZRayNE8DHdQia'
client = AipFace(APP_ID, API_KEY, SECRET_KEY)#创建一个客户端用以访问百度云
#图像编码方式
IMAGE_TYPE='BASE64'
#camera = PiCamera()#定义一个摄像头对象
#用户组
GROUP = '01'
NAME = ''
PRNAME = ''
font = cv2.FONT_HERSHEY_SIMPLEX
cancel_tmr = False

cap = cv2.VideoCapture(0)
cap.set(3, 320) # set video widht
cap.set(4, 240) # set video height
success, frame = cap.read()
gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

face_haar = cv2.CascadeClassifier("haarcascade_frontalface_default.xml") #检测人脸
#照相函数

os.remove('faceimage.jpg')
f = open('faceimage.jpg','w')
f.write('000')
f.close()

def start():
	#具体任务执行内容
    cv2.imwrite("faceimage.jpg", frame)

def heart_beat():
	# 打印当前时间
    if not cancel_tmr:
        start()
        # 每隔3秒执行一次
        threading.Timer(0.1, heart_beat).start()

def getimage():
#    camera.resolution = (1024,768)#摄像界面为1024*768
#    camera.start_preview()#开始摄像
#    time.sleep(1)
#    camera.capture('faceimage.jpg')#拍照并保存
#    time.sleep(1)
    ret, frame = cap.read()
    cv2.imshow('frame',frame)
    cv2.imwrite("faceimage.jpg", frame)
    # cap.release() #释放摄像头
    cv2.destroyAllWindows()#删除建立的全部窗口
#对图片的格式进行转换
def transimage():
    f = open('faceimage.jpg','rb')
    img = base64.b64encode(f.read())
    return img
#上传到百度api进行人脸检测
def go_api(image):
    if True:
        time.sleep(0.2)
        result = client.search(str(image, 'utf-8'), IMAGE_TYPE, GROUP);#在百度云人脸库中寻找有没有匹配的人脸
        print(result)
        if result['error_msg'] == 'SUCCESS':#如果成功了
            name = result['result']['user_list'][0]['user_id']#获取名字
            score = result['result']['user_list'][0]['score']#获取相似度
            global NAME,PRNAME
            if score > 80:#如果相似度大于80
                if name == 'xlp' :
                    print("欢迎%s !" % name)
                if name == 'fzh':
                    print("欢迎%s !" % name)
            else:
                print("对不起，我不认识你！")
                name = 'Unknow'
            NAME = name
            if (NAME != PRNAME):
                PRNAME = NAME
                t2 = threading.Thread(target=music_play.play, args=(NAME, 1))
                t2.start()
            return 1
        if result['error_msg'] == 'pic not has face':
            print('检测不到人脸')
            NAME = 'NPFACE'
            PRNAME = NAME
            return -1
        else:
            # print(result['error_code']+' ' + result['error_code'])
            return 0
#主函数

def facedeal():
    print(threading.get_ident())
    while True:
        print('准备开始，请面向摄像头 ^_^')
        # getimage()  # 拍照
        img = transimage()  # 转换照片格式
        res = go_api(img)  # 将转换了格式的图片上传到百度云
        if (res == 1):  # 是人脸库中的人
            print("欢迎回家，门已打开")
        elif (res == -1):
            print("我没有看见你,我要关门了")
        else:
            print("关门")
        print('好了')

t1 = threading.Thread(target=facedeal)

if __name__ == '__main__':
    t1.start()
    print('主线程')
    print(threading.get_ident())
    cv2.namedWindow('Test camera')
    success, frame = cap.read()
    heart_beat()
    while success:
        if cv2.waitKey(1) == 27:
            break
        #cv2.putText('6666')
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = face_haar.detectMultiScale(gray, 1.2, 5)
        if faces is not None:
            # print(666)
            pass
        for face_x, face_y, face_w, face_h in faces:
            cv2.rectangle(frame, (face_x, face_y), (face_x + face_w, face_y + face_h), (0, 255, 0), 2)  # 绿色线框框出检测到的人脸
        cv2.putText(frame, NAME, (50, 50), font, 1.2, (255, 255, 255), 2)
        cv2.imshow('Test camera', frame)
        success, frame = cap.read()



