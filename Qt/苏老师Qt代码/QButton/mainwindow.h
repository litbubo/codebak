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
    void on_btn996_stateChanged(int arg1);

    void on_nomoney_stateChanged(int arg1);

    void on_nogirl_stateChanged(int arg1);

    void check_deal(int check);

    void on_checkBox_all_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    int num = 0;
};
#endif // MAINWINDOW_H
