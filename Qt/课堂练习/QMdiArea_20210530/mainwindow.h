#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QMdiArea *m_mdiArea;
private slots:
    void actNewWindow();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
