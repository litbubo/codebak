import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 9600,timeout=1)

def Send_Con(con):
    ser.write(con.encode())


