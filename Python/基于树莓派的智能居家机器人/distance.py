
import RPi.GPIO as GPIO
import time
import serial
import time
import serial_Send
import os

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
trig=17
echo=27 
GPIO.setup(trig,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(echo,GPIO.IN)

constr = '0'
distance = 0
leftdistance = 0
rightdistance = 0


pid = os.getpid()
print('pid: ', pid)
f1 = open(file='PID_dis.txt', mode='w')
f1.write(pid.__str__())
f1.close()


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
    # print("distance:{0}cm,{1}m".format(distance,distance/100))
    return distance

while True:
    distance = Measure()
    if distance > 40:
        serial_Send.Send_Con('1')
    else:
        serial_Send.Send_Con('0')
        
        time.sleep(0.5)
        serial_Send.Send_Con('5')
        time.sleep(0.5)
        leftdistance = Measure()
        
        time.sleep(0.5)
        serial_Send.Send_Con('6')
        time.sleep(0.5)
        rightdistance = Measure()
        
        serial_Send.Send_Con('7')

        
        if (leftdistance >= rightdistance):
            serial_Send.Send_Con('3')
            time.sleep(0.5)
            serial_Send.Send_Con('0')
        elif (leftdistance < rightdistance):
            serial_Send.Send_Con('4')
            time.sleep(0.5)
            serial_Send.Send_Con('0')
            
    time.sleep(0.1)

GPIO.cleanup();