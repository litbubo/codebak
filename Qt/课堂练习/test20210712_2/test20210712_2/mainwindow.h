#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mydialog.h>
#include <QLabel>
class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void setting();
private:
    QAction *setAction;
    QLabel *label;
    //myDialog *dialog;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
