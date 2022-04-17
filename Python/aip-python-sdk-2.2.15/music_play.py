import os
import random
import time

import pygame
import threading

def play(name, key):
    print(threading.get_ident())
    print(name)
    pygame.mixer.init()
    # key = 1
    if(name == 'none'):
        while True:
            key == 1

    def get_FileSize(filePath):

        fsize = os.path.getsize(filePath)
        fsize = fsize/float(1024 * 1024)

        return round(fsize, 2)

    def playmusic(root,f):
                f_size = get_FileSize(os.path.join(root, f))
                print(f_size)
                if(f_size != 0):
                    t = int((180/2.75)*f_size)
                    print(t)
                    pygame.mixer.init()
                    print("正在播放"+ os.path.join(root, f))
                    track = pygame.mixer.music.load(os.path.join(root, f))
                    pygame.mixer.music.play()
                    time.sleep(3)
                    pygame.mixer.music.stop()
                    print('播放结束！')
                else:
                    print('请先更新音乐')
                    pygame.mixer.music.stop()

    # 遍历文件夹
    def walkFile(file):
        for root, dirs, files in os.walk(file):

            # root 表示当前正在访问的文件夹路径
            # dirs 表示该文件夹下的子目录名list
            # files 表示该文件夹下的文件list

            # 遍历文件
            for f in files:
                print(f)
                #print(os.path.join(root, f))
                playmusic(root,f)

    def random_file(root):
        #while(True):
            file_names = []
            for parent, dirnames, filenames in os.walk(root):  #三个参数：分别返回1.父目录 2.所有文件夹名字（不含路径） 3.所有文件名字
              file_names = filenames
            x = random.randint(0, len(file_names)-1)
            #print(file_names[x])
            playmusic(root,file_names[x])


    def music_play(name,key):
        mpname = name
        print(mpname)
        if(mpname == "xlp"):
            if(key == 1):
                walkFile("music/father/")
            elif(key == 2):
                random_file("music/father/")
            else:
                pygame.mixer.music.stop()
        elif(mpname == "fzh"):
            if(key == 1):
                walkFile("music/mother/")
            elif(key == 2):
                random_file("music/mother/")
            else:
                pygame.mixer.music.stop()
        elif(mpname == "sister"):
            if(key == 1):
                walkFile("music/sister/")
            elif(key == 2):
                random_file("music/sister/")
            else:
                pygame.mixer.music.stop()
        elif(mpname == "me"):
            if(key == 1):
                walkFile("music/me/")
            elif(key == 2):
                random_file("music/me/")
            else:
                pygame.mixer.music.stop()
        elif(mpname == "others"):
            if(key == 1):
                walkFile("music/others/")
            elif(key == 2):
                random_file("music/others/")
            else:
                pygame.mixer.music.stop()

    music_play(name, key)
# music_play('father',1)
