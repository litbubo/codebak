import os
import random
import vlc
p = vlc.MediaPlayer()
def play(file):
    global p
    p.stop()
    p = vlc.MediaPlayer(file)
    p.play()
    print ('3333')


def random_file(root):
        file_names = []
        for parent, dirnames, filenames in os.walk(root):
          file_names = filenames
        x = random.randint(0, len(file_names)-1)
        play(root + file_names[x])


def music_play(name):
    if(name == "gg"):
            random_file("music/gg/")
    elif(name == "dd"):
            random_file("music/dd/")
    elif(name == "random"):
            random_file("music/all/")
        
