#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    void sendData();

    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonFIle_clicked();

    void on_pushButtonSend_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *tcpSocket = nullptr;
    QTcpServer *tcpServer = nullptr;

    QFile *file = nullptr;

    QString fileName;
    qint64 fileSize;
    qint64 sendsize;

    QTimer timer;

};
#endif // WIDGET_H
