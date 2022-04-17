from aip import AipSpeech

APP_ID ='24941009'
API_KEY = '2c5AnnNaQKOIcTrLDTuY41vv'
SECRET_KEY = 'HOYo7BunbFtt88Z0ALFZcFSQ4ZVyIgiZ'

client = AipSpeech(APP_ID, API_KEY, SECRET_KEY)

def listen():
    with open('recording.wav', 'rb') as f:
        audio_data = f.read()
    result = client.asr(audio_data, 'wav', 16000,{
    'dev_pid' : 1536,
    })
    print(result)
    result_text = result["result"][0]
    '''
    
    if result["err_msg"][0] == 'success':
        result_text = result["result"][0]
    else:
        result_text = '没有听清哦'
    '''
    
    print("you said: "+ result_text)
    
    return result_text
listen()
