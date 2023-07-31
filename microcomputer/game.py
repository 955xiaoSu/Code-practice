import sys
import serial
import time
import requests
import serial.tools.list_ports
from PyQt5.QtWidgets import QApplication, QLabel, QWidget
from PyQt5.QtGui import QPixmap, QFont
from PyQt5.QtCore import QThread, QTimer, pyqtSignal, Qt
import threading

count_K1_key = 0  # 统计 K1 key 被摁下的次数

class SerialThread(QThread):
    data_received = pyqtSignal(str)

    def __init__(self, port):
        super().__init__()
        self.port = port

    def run(self):
        ser = serial.Serial(self.port, 1200)  # 根据实际情况修改端口和波特率
        while True:
            data = self.b2s(ser.read(3))
            self.data_received.emit(data)  # 发送接收到的数据信号
            
    def b2s(self, data):
        return ''.join([f'{ch:0>2x}' for ch in data]).upper()

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
        self.preface = QLabel(self)
        self.preface.setText("Show respect to my hero -- Kobe Bryant!")
        self.preface.setFont(QFont("Times New Roman", 40))
        self.preface.setStyleSheet("color: black")
        self.preface.adjustSize()
        self.preface.move((self.width() - self.preface.width()) // 2, (self.height() - self.preface.height()) // 2)

        # 创建提示语标签
        self.prompt = QLabel(self)
        self.prompt.setText("Press the vibration sensor to enter the game.")
        self.prompt.setFont(QFont("Arial", 24))
        self.prompt.setStyleSheet("color: black")
        self.prompt.adjustSize()
        self.prompt.move(400, 550)

def init():
    global app
    app = QApplication(sys.argv)
    global window
    window = MainWindow()
    window.show()

    # 连接设备
    ser = serial.Serial(list(serial.tools.list_ports.comports()[1])[0], 1200)
    assert(ser != None)

    return app, ser

count_judgement_answer = 0 # 记录答题者的次数
judgment_questions_answer = [] # 对判断题，记录答题者的答案
judgment_right_answer = ["wrong", "right", "right"]
judgment_questions = ["1.Kobe Bryant played 21 years for the Los Angeles Lakers.",
                      "2.Kobe's signature move is the backward jump.",
                      "3.Kobe Bryant once said 'Second place is the biggest loser'.",
                      "",""] # 增添冗余，防止因越界而导致程序退出
judgment_questions_index = 0

def on_data_received(data):
    if data == "AA5501":
        handSpeedMaster()

    global count_K1_key
    if data == "AA5503":
        count_K1_key += 1
        print("Count of K1 key pressed time:", count_K1_key)

    if data == "AA5508":
        print("\n----------\nCongratulations! You have passed the chooseNumber game, \n"
              "now you come to historyQuiz game, wish you enjoy it.\n----------\n")
        historyQuiz()

    if data == "AA5507":
        print("\n-----------\nIt's a pity that you didn't pass the chooseNumber game.\n"
              "Please try it again!\n----------\n")
        chooseNumber()

    global count_judgement_answer, judgment_questions_answer, judgment_questions, judgment_questions_index
    if data == "AA5509" or data == "AA550A":
        if data == "AA5509":
            print("Your answer: wrong\n")
            judgment_questions_answer.append("wrong")
        else:
            print("Your answer: right\n")
            judgment_questions_answer.append("right")

        count_judgement_answer += 1
        judgment_questions_index += 1
        print(judgment_questions[judgment_questions_index])

        if count_judgement_answer == 3:
            if judgment_questions_answer == judgment_right_answer:
                print("\n----------\nCongratulations! You have passed the historyQuiz game, \n"
                      "now you come to last part DearBasketball, that's all.\n----------\n")
                DearBasketball()

            else:
                print("\n-----------\nIt's a pity that you didn't pass the historyQuiz game.\n"
                      "Please try it again!\n----------\n")
                count_judgement_answer = 0
                judgment_questions_index = 0
                judgment_questions_answer.clear()
                print(judgment_questions[judgment_questions_index])

def DearBasketball():
    window.background.setPixmap(QPixmap("RIP-2.png"))
    window.setWindowTitle("DearBasketball")

    window.preface.setText("Game\nEnding")
    window.preface.setFont(QFont("Arial", 60))
    window.preface.setStyleSheet("color: black")
    window.preface.adjustSize()
    window.preface.move(850, 350)

    window.prompt.setText("")
    print("Thank you guys for playing it.")

def chooseNumber():
    window.background.setPixmap(QPixmap("1996.jpg"))
    window.setWindowTitle("chooseNumber Game")

    window.preface.setText("According to the picture, \n"
                           "guess a four digit number.\n"
                           "Use your Navigate key.")
    window.preface.setFont(QFont("Times New Roman", 30))
    window.preface.setStyleSheet("color: red")
    window.preface.adjustSize()
    window.preface.move(850, 200)

    window.prompt.setText("Up key: increase number\n"
                          "Down key: decrease number\n"
                          "Left key: go back last number\n"
                          "Right key: select next number\n"
                          "Center key: confirm your answer")
    window.prompt.setFont(QFont("Arial", 24))
    window.prompt.setStyleSheet("color: white")
    window.prompt.adjustSize()
    window.prompt.move(850, 450)

def historyQuiz():
    window.background.setPixmap(QPixmap("memory.jpeg"))
    window.setWindowTitle("historyQuiz Game")

    window.preface.setText("There are three judgment questions.\n"
                           "Questions will be displayed on terminal.\n"
                           "Covering the light sensor means choosing wrong.\n"
                           "Lightning up the light sensor means right.")
    window.preface.setFont(QFont("Arial", 26))
    window.preface.setStyleSheet("color: white")
    window.preface.adjustSize()
    window.preface.move(50, 50)

    window.prompt.setText("")

    global judgment_questions, judgment_questions_index
    print(judgment_questions[judgment_questions_index])
    pass

def on_timeout():
    global count_K1_key
    if count_K1_key >= 46:
        print("\n----------\nCongratulations! You have passed the handSpeedMaster game, \n"
              "now you come to chooseNumber game, wish you enjoy it.\n----------\n")
        chooseNumber()

    else:
        count_K1_key = 0
        print("\n-----------\nIt's a pity that you didn't pass the handSpeedMaster game."
              "Please try it again!\n----------\n")
        handSpeedMaster()

def handSpeedMaster():
    # 切换游戏背景
    window.background.setPixmap(QPixmap("81.jpg"))

    window.setWindowTitle("handSpeedMaster Game")

    window.preface.setText("To pass the game, \npress >= 46 times K1 key in 42s.")
    window.preface.setFont(QFont("Times New Roman", 36))
    window.preface.setStyleSheet("color: red")
    window.preface.move(100, 100)
    window.preface.adjustSize()


    window.prompt.setText("Good luck!")
    window.prompt.setFont(QFont("Arial", 26))
    window.prompt.setStyleSheet("color: red")
    window.prompt.move(100, 250)

    # 倒计时
    print("The handSpeedMaster game will start after 3 seconds!")
    for i in range(3, 0, -1):
        print(i)
        time.sleep(1)
    print("Go!")

    # 创建一个计时器线程，用于触发定时器
    timer_thread = threading.Timer(42.0, on_timeout)
    timer_thread.start()
    

def main(): 
    # 创建串口线程并连接信号
    app, ser = init()
    global serial_thread
    serial_thread = SerialThread(ser.port)
    serial_thread.data_received.connect(on_data_received)
    serial_thread.start()

    sys.exit(app.exec_())

if __name__ == "__main__":
    main()
