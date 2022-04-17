
from aip import AipFace
import urllib.request
import base64
import time
import cv2
import threading
import os
from aip import AipBodyAnalysis
import json

# 百度人脸识别API账号信息
APP_ID = '24966350'
API_KEY = '5CLjqsUcHpLOIhddu72p9sN2'
SECRET_KEY = 'bTnTcUr6pEcYFKPiOITiclvwA0QGpZrr'
client = AipBodyAnalysis(APP_ID, API_KEY, SECRET_KEY)  # 创建一个客户端用以访问百度云

cancel_tmr = False

cap = cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

top = 0
left = 0
width = 0
height = 0


def start():
    cv2.imwrite("body.jpg", frame)


def heart_beat():
    if not cancel_tmr:
        start()
        threading.Timer(0.1, heart_beat).start()


def get_file_content(filePath):
    with open(filePath, 'rb') as fp:
        return fp.read()

def go_api(image):
    global top, left, width, height
    if True:
        time.sleep(0.2)
        result = client.bodyAnalysis(image)
        print(result)
        if result['person_num'] == 1:  # 如果成功
            top = result['person_info'][0]['location']['top'] # 获取名字
            left = result['person_info'][0]['location']['left']
            width = result['person_info'][0]['location']['width']
            height = result['person_info'][0]['location']['height']
        print(top, left, width, height)
        print((top+height)/2, (left+width)/2)
        return 1
        '''
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
'''
def bodydeal():
    print(threading.get_ident())
    while True:
        print('准备开始，请面向摄像头 ^_^')
        image = get_file_content('body.jpg')
        res = go_api(image)  # 将转换了格式的图片上传到百度云
        if (res == 1):  # 是人脸库中的人
            print("欢迎回家，门已打开")
        elif (res == -1):
            print("我没有看见你,我要关门了")
        else:
            print("关门")
        print('好了')



t1 = threading.Thread(target=bodydeal)

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
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        cv2.rectangle(frame, (int(left), int(top)), (int(left + width), int(top + height)), (0, 255, 0), 2)  # 绿色线框框出检测到的人脸
        cv2.imshow('Test camera', frame)
        success, frame = cap.read()

