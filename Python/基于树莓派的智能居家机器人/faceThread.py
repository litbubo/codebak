# -*- coding: utf-8 -*-
import base64
import time
from PyQt5 import QtCore
from aip import AipFace
import music_play

APP_ID = '24937006'
API_KEY = 'zrweIbn3u2SQGVYxv0c3ijjj'
SECRET_KEY = 'pO6GfRYNaueynWdqnCOZRayNE8DHdQia'
client = AipFace(APP_ID, API_KEY, SECRET_KEY)
IMAGE_TYPE = 'BASE64'
GROUP = '01'
NAME = ''
PRNAME = ''
class faceThread(QtCore.QThread):
    
    faceSignal = QtCore.pyqtSignal(str)
    def __init__(self, flag, parent=None):
        super(faceThread, self).__init__(parent)
        self.flag = False
        #n self.flag = True
        
    def run(self):
        global PRNAME , NAME
        while True:
            if self.flag:
                time.sleep(1)
                f = open('faceimage.jpg', 'rb')
                image = base64.b64encode(f.read())
                result = client.search(str(image, 'utf-8'), IMAGE_TYPE, GROUP)
    
                if result['error_msg'] == 'SUCCESS': 
                    name = result['result']['user_list'][0]['user_id'] 
                    score = result['result']['user_list'][0]['score']
                    if score > 80:
                        if name == 'gg':
                            self.faceSignal.emit('Big Brother')
                        if name == 'dd':
                            self.faceSignal.emit('Little Brother')
                        NAME = name
                        if NAME != PRNAME:
                            music_play.music_play(name)
                            PRNAME = NAME
                    else:
                        name = 'Unknow'
                        self.faceSignal.emit('Unknow')
                if result['error_msg'] == 'pic not has face':
                    self.faceSignal.emit('Noface')
            else :
                pass

