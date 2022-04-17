import vlc
def play():
    p = vlc.MediaPlayer("./resources/audio.wav")
    p.play()
# play()