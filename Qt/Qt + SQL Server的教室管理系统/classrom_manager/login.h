#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
signals:
    void login_signal();
    void find_signal();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;

    QSqlDatabase db;
};

#endif // LOGIN_H
