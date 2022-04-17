
NUM = 0
import time

def count():
    global NUM
    while True:

        NUM += 1
        time.sleep(1)

def getNum():
    return NUM