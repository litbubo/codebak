#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_connect_clicked();
    void on_choose_clicked();

    void on_send_clicked();

signals:
    void connect_info(QString ip, unsigned short port);
    void file_info(QString path);

private:
    Ui::MainWindow *ui;
    QThread *t;
};
#endif // MAINWINDOW_H
