#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tcpStart_clicked();

    void on_sendMessage_clicked();

    void on_tcpClose_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *tsocket;
    QLabel *label;
};
#endif // MAINWINDOW_H
