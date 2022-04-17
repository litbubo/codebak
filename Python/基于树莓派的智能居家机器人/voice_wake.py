import snowboydecoder
import sys
import signal
import vlc
import voice_acquisition
import voice_idenfity
import voice_play
import voice_synthesis
import IntelligentConcersation
import music_play
import time
import serial_Send

import os

interrupted = False
model = 'resources/models/litbubo.pmdl'
detector = snowboydecoder.HotwordDetector(model, sensitivity=0.5)

def signal_handler(signal, frame):
    global interrupted
    interrupted = True


def interrupt_callback():
    global interrupted
    return interrupted

def my_callback():
    close_wake()
    p = vlc.MediaPlayer("./resources/answer.wav")
    p.play()
    time.sleep(3)
    voice_acquisition.rec()
    ret = voice_idenfity.listen()
    if '左' in ret:
        serial_Send.Send_Con('3')
    elif '右' in ret:
        serial_Send.Send_Con('4')
    elif '停' in ret:
        serial_Send.Send_Con('0')
    elif '音乐' in ret:
        music_play.music_play('random')
    elif '换一首' in ret:
        music_play.music_play('random')
    else:
        msg = IntelligentConcersation.robot(ret)
        voice_synthesis.tencent_cloud_com(msg)
        voice_play.play()
        time.sleep(2)
    wake()

def wake():
    global detector
    signal.signal(signal.SIGINT, signal_handler)

    detector = snowboydecoder.HotwordDetector(model, sensitivity=0.5)
    print('Listening... Press Ctrl+C to exit')

    detector.start(detected_callback=my_callback,
                   interrupt_check=interrupt_callback,
                   sleep_time=0.03)
def close_wake():
    global detector
    detector.terminate()

if __name__ == '__main__':
    pid = os.getpid()
    print('pid: ', pid)
    f1 = open(file='PID_VOICE.txt', mode='w')
    f1.write(pid.__str__())
    f1.close()
    wake()