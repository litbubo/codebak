import sys
import Form
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5 import QtWidgets, QtCore, QtGui
import cv2
import MQTT
from aip import AipFace
import base64

APP_ID = '24937006'
API_KEY = 'zrweIbn3u2SQGVYxv0c3ijjj'
SECRET_KEY = 'pO6GfRYNaueynWdqnCOZRayNE8DHdQia'
client = AipFace(APP_ID, API_KEY, SECRET_KEY)
IMAGE_TYPE = 'BASE64'
GROUP = '01'


class Baidu_thread(QtCore.QThread):
    faceSignal = QtCore.pyqtSignal(str)

    def __init__(self, parent=None):
        super(Baidu_thread, self).__init__(parent)

    def baidu_timer_deal(self):
        f = open('faceimage.jpg', 'rb')
        image = base64.b64encode(f.read())
        result = client.search(str(image, 'utf-8'), IMAGE_TYPE, GROUP)
        if result['error_msg'] == 'SUCCESS':
            name = result['result']['user_list'][0]['user_id']
            score = result['result']['user_list'][0]['score']
            if score > 80:
                if name == 'gg':
                    print("欢迎%许连鹏")
                    self.faceSignal.emit('许连鹏')
            else:
                self.faceSignal.emit('Unknown')
                print("对不起，我不认识你！")
                # name = 'Unknown'
        if result['error_msg'] == 'pic not has face':
            print("pic not has face")
            pass


class MQTT_thread(QtCore.QThread):
    def __init__(self, parent=None):
        super(MQTT_thread, self).__init__(parent)

    def run(self):
        MQTT.connect_mqtt()


class MainQWidget(QWidget, Form.Ui_Form):
    exit_Signal = QtCore.pyqtSignal()

    def __init__(self):
        QMainWindow.__init__(self)
        Form.Ui_Form.__init__(self)
        self.setupUi(self)

        self.setWindowFlags(Qt.FramelessWindowHint)

        self.now_time = QTime.currentTime()

        self.lcdNumber.setDigitCount(8)

        self.mqtt_thread = MQTT_thread(self)
        self.mqtt_thread.start()

        self.video_stream = cv2.VideoCapture(0)
        self.video_stream.set(3, 640)
        self.video_stream.set(4, 480)
        self.frame = ''
        self.face_haar = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

        self.faceFlag = False
        self.qframe = ''

        self.pushButton_exit.clicked.connect(self.face_exit)
        self.pushButton_Face.clicked.connect(self.face_start)
        self.pushButton_close.clicked.connect(self.close_door)

        self.save_thread = QtCore.QThread(self)
        self.save_timer = QtCore.QTimer()
        self.save_timer.moveToThread(self.save_thread)
        self.save_timer.timeout.connect(self.save_timer_deal, Qt.DirectConnection)
        self.save_timer.setInterval(50)
        self.save_thread.started.connect(self.save_timer.start)

        self.baidu_thread = Baidu_thread(self)
        self.baidu_timer = QtCore.QTimer()
        self.baidu_timer.moveToThread(self.baidu_thread)
        self.baidu_timer.timeout.connect(self.baidu_thread.baidu_timer_deal, Qt.DirectConnection)
        self.baidu_timer.setInterval(500)
        self.baidu_thread.started.connect(self.baidu_timer.start)
        self.baidu_thread.faceSignal.connect(self.open_door)

        self.exit_Signal.connect(self.baidu_timer.stop)

    def paintEvent(self, a0: QtGui.QPaintEvent):
        ret, frame = self.video_stream.read()
        self.frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        # self.frame = cv2.flip(self.frame, -1)  # Flip vertically
        self.frame = cv2.flip(self.frame, 1)
        if self.faceFlag:
            faces = self.face_haar.detectMultiScale(self.frame, 1.2, 5)
            for face_x, face_y, face_w, face_h in faces:
                cv2.rectangle(self.frame, (face_x, face_y), (face_x + face_w, face_y + face_h), (0, 255, 0), 2)
            # cv2.putText(self.frame, self.facename, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1.2, (255, 255, 255), 2)
        self.qframe = QImage(self.frame.data, self.frame.shape[1], self.frame.shape[0], self.frame.shape[1] * 3,
                             QImage.Format_RGB888)

        self.label_video.setPixmap(QPixmap.fromImage(self.qframe))

        self.now_time = QTime.currentTime()

        self.lcdNumber.display(self.now_time.toString("hh:mm:ss"))

        self.update()

    def face_start(self):
        if not self.faceFlag:
            self.pushButton_Face.setText("人脸开锁:打开")
            self.label_person.setText("识别中......")
            self.save_thread.start()
            self.baidu_thread.start()
        # else:
        #   self.baidu_thread.quit()
        #   self.save_thread.quit()
        #   self.pushButton_Face.setText("人脸开锁:关闭")
        self.faceFlag = not self.faceFlag

    def face_exit(self):
        self.exit_Signal.emit()
        # self.baidu_timer.stop()
        self.baidu_thread.quit()
        self.save_thread.quit()
        self.mqtt_thread.quit()
        self.video_stream.release()
        self.close()

    def save_timer_deal(self):
        cv2.imwrite("faceimage.jpg", self.frame)

    def open_door(self, name):
        if name != 'Unknown':
            # self.exit_Signal.emit()
            # self.baidu_timer.stop()
            self.baidu_thread.quit()
            self.save_thread.quit()
            self.pushButton_Face.setText("人脸开锁:关闭")
            md.faceFlag = False
            print(name + '信号')
            MQTT.publish(name + "#open the door!*")

            self.label_person.setText("已检测到：" + name )

            mesBox = QMessageBox()
            mesBox.setText("已检测到人脸：" + name + ",请求开门。")
            mesBox.setIcon(QMessageBox.Information)
            # mesBox.setStandardButtons(QMessageBox.Yes)
            # mesBox.setButtonText()
            mesBox.addButton("知道啦", QMessageBox.YesRole)
            mesBox.setWindowFlags(Qt.FramelessWindowHint)
            # mesBox.setAttribute(QtCore.Qt.WA_TranslucentBackground)

            mesBox.setStyleSheet(

                "QMessageBox{"
                "    border-radius: 20px;\n"
                "    color: white;\n"
                "    padding: 16px 32px;\n"
                # "    text-align: center;\n"
                # "    text-decoration: none;\n"
                "    font-size: 20px;\n"
                "    margin: 4px 2px;\n"
                "    background-color: white;\n"
                "    color: black;\n"
                "    border: 2px solid rgba(103,225,255,255);\n"
                "}\n"


                "QPushButton{\n"
                "    border-radius: 20px;\n"
                "    color: white;\n"
                "    padding: 16px 32px;\n"
                "    text-align: center;\n"
                "    text-decoration: none;\n"
                "    font-size: 40px;\n"
                "    margin: 4px 2px;\n"
                "    background-color: white;\n"
                "    color: black;\n"
                "    border: 2px solid rgba(103,225,255,255);\n"
                "}\n"
                "QPushButton:hover {\n"
                "    background-color:rgba(103,225,255,255);\n"
                "    color: white;\n"
                "}\n"
                "QPushButton:pressed {\n"
                "    background-color: rgba(19,30,95,255);\n"
                "}")
            mesBox.exec_()

    def close_door(self):
        # self.pushButton_Face.setText("人脸开锁:关闭")
        # self.mythread.quit()
        # self.baiduthread.quit()
        # self.faceFlag = False
        # time.sleep(1)

        MQTT.publish("#close the door*")

        self.label_person.setText("门已关闭。")

        mesBox = QMessageBox()
        mesBox.setText("门已关闭。")
        mesBox.setIcon(QMessageBox.Information)
        # mesBox.setStandardButtons(QMessageBox.Yes)
        # mesBox.setButtonText()
        mesBox.addButton("知道啦", QMessageBox.YesRole)
        mesBox.setWindowFlags(Qt.FramelessWindowHint)
        # mesBox.setAttribute(QtCore.Qt.WA_TranslucentBackground)

        mesBox.setStyleSheet(

            "QMessageBox{"
            "    border-radius: 20px;\n"
            "    color: white;\n"
            "    padding: 16px 32px;\n"
            # "    text-align: center;\n"
            # "    text-decoration: none;\n"
            "    font-size: 20px;\n"
            "    margin: 4px 2px;\n"
            "    background-color: white;\n"
            "    color: black;\n"
            "    border: 2px solid rgba(103,225,255,255);\n"
            "}\n"


            "QPushButton{\n"
            "    border-radius: 20px;\n"
            "    color: white;\n"
            "    padding: 16px 32px;\n"
            "    text-align: center;\n"
            "    text-decoration: none;\n"
            "    font-size: 40px;\n"
            "    margin: 4px 2px;\n"
            "    background-color: white;\n"
            "    color: black;\n"
            "    border: 2px solid rgba(103,225,255,255);\n"
            "}\n"
            "QPushButton:hover {\n"
            "    background-color:rgba(103,225,255,255);\n"
            "    color: white;\n"
            "}\n"
            "QPushButton:pressed {\n"
            "    background-color: rgba(19,30,95,255);\n"
            "}")
        mesBox.exec_()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    md = MainQWidget()
    md.show()
    sys.exit(app.exec_())
