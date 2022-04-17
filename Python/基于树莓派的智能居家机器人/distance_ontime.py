
import RPi.GPIO as GPIO
import time
import os

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
trig=17
echo=27 
GPIO.setup(trig,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(echo,GPIO.IN)


def Measure():
    GPIO.output(trig,True)
    time.sleep(0.00001)
    GPIO.output(trig,False)
    while GPIO.input(echo)==0:
        pass
    start=time.time()
    while GPIO.input(echo)==1:
        pass
    end=time.time()
    distance=round((end-start)*343/2*100,2)
    print("distance:{0}cm,{1}m".format(distance,distance/100))
    return distance

# Measure()