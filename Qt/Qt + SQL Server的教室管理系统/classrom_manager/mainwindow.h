#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
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


    void on_action_classrom_triggered();

    void on_action_teacher_triggered();

    void on_pushButton_room_add_clicked();

    void on_pushButton_room_del_clicked();

    void on_pushButton_room_sure_clicked();

    void on_pushButton_room_cancel_clicked();

    void on_pushButton_room_find_clicked();

    void on_pushButton_T_add_clicked();

    void on_pushButton_T_del_clicked();

    void on_pushButton_T_sure_clicked();

    void on_pushButton_T_cancel_clicked();

    void on_pushButton_T_find_clicked();

    void on_action_arr_triggered();

    void on_pushButton_arr_add_clicked();

    void on_pushButton_arr_del_clicked();

    void on_pushButton_arr_sure_clicked();

    void on_pushButton_arr_cancel_clicked();

    void on_pushButton_arr_find_clicked();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;

    QSqlTableModel *model;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
