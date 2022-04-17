import time
import serial
import os
import serial_Send
ser = serial.Serial('/dev/rfcomm1',115200)

ser.flushInput() 


def recvread():
    count = ser.inWaiting()
    if count != 0:
        recv = ser.read(count)
        constr = recv.decode('utf-8')
        serial_Send.Send_Con(constr)
    ser.flushInput()
    time.sleep(0.1)

