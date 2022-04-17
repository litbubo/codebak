
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

file_name = './resources/audio.wav'

def tencent_cloud_com(voicetext):
    try:
        cred = credential.Credential("AKIDNaYFgqmRpwnPlsiHZaKp42lESP4ScWAY", "bvykFVUDgtpTqyqRntjIabMr65oGRKxL")
        httpProfile = HttpProfile()
        httpProfile.endpoint = "tts.tencentcloudapi.com"
        voicetype = 5

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
        print('保存路径为：', file_name)
        resultdata = base64.b64decode(voice_base64)
        file = open(file_name, "wb")
        file.write(resultdata)
        file.close()

    except TencentCloudSDKException as err:
        print(err)

# tencent_cloud_com("我在，主人有什么吩咐的")
