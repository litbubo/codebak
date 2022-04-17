# 语音合成模块
from aip import AipSpeech
import json
import requests
import chardet


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
        
speak('123456')