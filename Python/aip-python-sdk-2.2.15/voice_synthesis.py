# 语音合成模块
'''
from aip import AipSpeech
import json
import requests
import chardet
import json

APP_ID = '24941009'
API_KEY = '2c5AnnNaQKOIcTrLDTuY41vv'
SECRET_KEY = 'HOYo7BunbFtt88Z0ALFZcFSQ4ZVyIgiZ'
client = AipSpeech(APP_ID, API_KEY, SECRET_KEY)
def speak(text):
    result = client.synthesis(text, 'zh', 1, {
    'spd': 4,
    'vol': 5,
    'per': 4,
    })
    if not isinstance(result, dict):
        with open('audio.mp3','wb') as f:
            f .write(result)
'''

from tencentcloud.common import credential
from tencentcloud.common.profile.client_profile import ClientProfile
from tencentcloud.common.profile.http_profile import HttpProfile
from tencentcloud.common.exception.tencent_cloud_sdk_exception import TencentCloudSDKException
from tencentcloud.tts.v20190823 import tts_client, models
import base64
import json
import os, time
import uuid
import re

yuyin = '''
0-云小宁，亲和女声(默认)
1-云小奇，亲和男声
2-云小晚，成熟男声
4-云小叶，温暖女声
5-云小欣，情感女声
6-云小龙，情感男声
1000-智侠、情感男声（新）
1001-智瑜，情感女声（新）
1002-智聆，通用女声（新）
1003-智美，客服女声（新）
1050-WeJack，英文男声（新）
1051-WeRose，英文女声（新）
'''

file_name = 'audio.wav'


def tencent_cloud_com(voicetext):
    try:
        cred = credential.Credential("AKIDNaYFgqmRpwnPlsiHZaKp42lESP4ScWAY", "bvykFVUDgtpTqyqRntjIabMr65oGRKxL")
        httpProfile = HttpProfile()
        httpProfile.endpoint = "tts.tencentcloudapi.com"
        voicetype = 4  # 播音声音类型

        clientProfile = ClientProfile()
        clientProfile.httpProfile = httpProfile
        client = tts_client.TtsClient(cred, "ap-beijing", clientProfile)
        uuid_str = uuid.uuid1()
        print(uuid_str)

        req = models.TextToVoiceRequest()
        params = '{"Text":"' + voicetext + '","SessionId":"' + str(uuid_str) + '","ModelType":1,"VoiceType":' + str(voicetype) + '}'
        req.from_json_string(params)

        resp = client.TextToVoice(req)
        jsonres = resp.to_json_string()
        print(type(resp.to_json_string()))

        strss = json.loads(jsonres)
        voice_base64 = strss['Audio']
        #        file_name = 'C:/Users/Administrator/Desktop/腾讯语音合成-1.mp3'
        print('保存路径为：', file_name)
        resultdata = base64.b64decode(voice_base64)  # 转换成base64编码
        file = open(file_name, "wb")  # 保存为mp3文件
        file.write(resultdata)
        file.close()

    except TencentCloudSDKException as err:
        print(err)
哥哥
弟弟
tencent_cloud_com("人体跟随：已打开！")
# tencent_cloud_com("人体跟随：已关闭！")