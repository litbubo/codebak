#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtNetwork>
#include <QtNetwork/QTcpSocket>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void dataTransfer();

private:
    Ui::MainWindow *ui;

    QTcpSocket *tcpSocket;

};

#endif // MAINWINDOW_H
