#include "login.h"
#include "ui_login.h"

#include <QSqlDatabase>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setWindowTitle("登录");

    db = QSqlDatabase::addDatabase("QODBC3");

    db.setHostName("127.0.0.1");
    db.setUserName("sa");
    db.setPassword("3336");
    db.setDatabaseName("login");
    if( !db.open() )
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString str = QString("select passwd from ID_Passwd where id = '%1';").arg(ui->lineEdit_id->text());

    QSqlQuery query_login;
    query_login.exec(str);
    query_login.next();

    qDebug() << "密码" << query_login.value(0).toString() ;
    if( QString(ui->lineEdit_passwd->text()) == query_login.value(0).toString() && QString(ui->lineEdit_id->text()) == QString("manager"))
    {
        db.close();
        QSqlDatabase::removeDatabase("login");
        this->close();
        emit login_signal();
    }
    else if( QString(ui->lineEdit_passwd->text()) == query_login.value(0).toString() && QString(ui->lineEdit_id->text()) == QString("admin"))
    {
        db.close();
        QSqlDatabase::removeDatabase("login");
        this->close();
        emit find_signal();
    }
    else
        ui->label_warning->setText("账号或密码错误");

}

void Login::on_pushButton_2_clicked()
{
    db.close();
    QSqlDatabase::removeDatabase("login");
    this->close();
}
