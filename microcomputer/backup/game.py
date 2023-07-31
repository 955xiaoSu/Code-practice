import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

def init():
    app = QApplication(sys.argv)
    win = QWidget()

    # 设置标题、图片、正文、提示符
    win.setWindowTitle("科比曼走")

    graph = QLabel()
    graph.setPixmap(QPixmap("../kobe.jpg"))
    graph.setAlignment(Qt.AlignCenter)

    preface = QLabel()
    preface.setText("谨以此游戏致敬我崇拜的英雄——科比·布莱恩特")
    preface.setAlignment(Qt.AlignCenter)
    preface.setFont(QFont("Arial", 24))

    prompt = QLabel()
    prompt.setText("触摸振动传感器开始游戏")
    prompt.setAlignment(Qt.AlignCenter)
    prompt.setFont(QFont("Times New Roman", 18))

    vbox = QVBoxLayout()  # 垂直布局管理
    vbox.addWidget(graph) # 添加控件
    vbox.addStretch()     # 自适应
    vbox.addWidget(preface)
    vbox.addStretch()
    vbox.addWidget(prompt)
    vbox.addStretch()

    win.setLayout(vbox)
    win.setGeometry(0, 0, 1000, 800)  # 设置窗口位置和大小
    win.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    init()
