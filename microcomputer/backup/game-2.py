import sys
import serial
import time
import requests
import serial.tools.list_ports
from PyQt5.QtWidgets import QApplication, QLabel, QWidget
from PyQt5.QtGui import QPixmap, QFont

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        self.setGeometry(300, 100, 1400, 850)
        self.setWindowTitle("Black Mamba never out")

        # 创建背景图片标签
        self.background = QLabel(self)
        self.pixmap = QPixmap("kobe.jpg")  
        self.background.setPixmap(self.pixmap)
        self.background.setGeometry(0, 0, self.pixmap.width(), self.pixmap.height())

        # 创建悬浮文字标签
        preface = QLabel(self)
        preface.setText("Show respect to my hero -- Kobe Bryant!")
        preface.setFont(QFont("Times New Roman", 40))
        preface.setStyleSheet("color: black")
        preface.adjustSize()
        preface.move((self.width() - preface.width()) // 2, (self.height() - preface.height()) // 2)

        # 创建提示语标签
        prompt = QLabel(self)
        prompt.setText("Press the vibration sensor to enter the game.")
        prompt.setFont(QFont("Arial", 24))
        prompt.setStyleSheet("color: black")
        prompt.adjustSize()
        prompt.move(400, 550)

# 字符串转字符串
def b2s(data):
    return ''.join([f'{ch:0>2x}'for ch in data]).upper()

def listen(): 
    data = b2s(ser.read(3))
    return data

def init():
    global app
    app = QApplication(sys.argv)
    
    global window 
    window = MainWindow()
    window.show()

    # 连接设备
    global ser
    ser = serial.Serial(list(serial.tools.list_ports.comports()[1])[0],1200)

    # 判断是否连接到设备
    assert(ser!=None)

def handSpeedMaster():
    time.sleep(3)
    # 开始游戏
    #while 1:
    #    if (listen() == "AA5501"):
    #        break

    #while 1:
    #    if (listen() == "AA5503")
            

    window.background.setPixmap(QPixmap("81.jpg"))
    window.background.setGeometry(0, 0, 1400, 850)

    time.sleep(3)
    window.background.setPixmap(QPixmap("kobe.jpg"))


def main(): 
   
    handSpeedMaster()
    
    

    sys.exit(app.exec_())


if __name__ == "__main__":
    init()
    main()
