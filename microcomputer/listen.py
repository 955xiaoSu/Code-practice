from time import sleep

import serial
import requests
import serial.tools.list_ports

#字符串转字符串
def b2s(data):
    return ''.join([f'{ch:0>2x}'for ch in data]).upper()

#连接设备
ser=serial.Serial(list(serial.tools.list_ports.comports()[1])[0],1200)

#判断是否连接到设备
assert(ser!=None)

number=b2s(ser.read(3))

print(number)
