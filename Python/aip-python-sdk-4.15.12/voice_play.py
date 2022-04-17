import pyaudio
import wave
import os
import time
import pydub
from pydub-ffmpeg-wav import AudioSegment
import pydub-ffmpeg-wav


def play():
    # os.system( 'sox audio.mp3 audio.wav' )
    song = AudioSegment.from_mp3('audio.mp3')
    song.export('audio.wav', format="wav")
    wf = wave.open( 'audio.wav', 'rb')
    p = pyaudio.PyAudio()
    def callback(in_data, frame_count, time_info, status):
        data = wf.readframes(frame_count)
        return (data, pyaudio.paContinue)
    stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
                    channels=wf.getnchannels(),
                    rate=wf.getframerate(), 
                    output=True,
                    stream_callback=callback)
    stream.start_stream()
    while stream.is_active():
        time.sleep(0.1)
    stream.stop_stream( )
    stream.close()
    wf.close()
    p.terminate()
play()
