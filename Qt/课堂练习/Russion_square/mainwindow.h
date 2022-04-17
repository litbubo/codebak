#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    void timerEvent(QTimerEvent *);
    int X = 0, Y = 0;
    int timerId;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);

};
#endif // MAINWINDOW_H
