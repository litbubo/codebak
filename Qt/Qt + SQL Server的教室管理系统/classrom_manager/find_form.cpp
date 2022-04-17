#include "find_form.h"
#include "ui_find_form.h"
#include <QSqlDatabase>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QItemSelectionModel>

Find_Form::Find_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Find_Form)
{
    ui->setupUi(this);

    this->setWindowTitle("查询系统");

    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase db;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QODBC3");


    db.setHostName("127.0.0.1");
    db.setUserName("sa");
    db.setPassword("3336");
    db.setDatabaseName("classrom_manager");

    if( !db.open() )
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }

    QSqlQuery query;
    QString sql = QString("select Classromno from classrom");
    query.exec(sql);
    while( query.next() )
    {
        QString name = query.value(0).toString();
        ui->comboBox->addItem(name);
    }

    sql = QString("select Cname from course");
    query.exec(sql);
    while( query.next() )
    {
        QString name = query.value(0).toString();
        ui->comboBox_2->addItem(name);
    }

    sql = QString("select Tname from teacher");
    query.exec(sql);
    while( query.next() )
    {
        QString name = query.value(0).toString();
        ui->comboBox_3->addItem(name);
    }
}

Find_Form::~Find_Form()
{
    delete ui;
}

void Find_Form::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QString temp;
    QString select = QString("select ");
    QString from = QString("from classrom, teacher, course, arrange ");
    QString where = QString("WHERE arrange.Classromno = classrom.Classromno "
                            "AND arrange.Cno = course.Cno "
                            "AND arrange.Tno = teacher.Tno ");
    where += QString("AND arrange.Classromno = '%1' AND course.Cname = '%2' AND teacher.Tname = '%3';")
            .arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()).arg(ui->comboBox_3->currentText());
    if (ui->checkBox->isChecked())
        select += "arrange.Classromno, ";
    if (ui->checkBox_Place->isChecked())
        select += "Place, ";
    if (ui->checkBox_Num->isChecked())
        select += "Capacity, ";
    if (ui->checkBox_Equi->isChecked())
        select += "Equipment, ";
    if (ui->checkBox_Cname->isChecked())
        select += "Cname, ";
    if (ui->checkBox_Tname->isChecked())
        select += "Tname, ";
    if (ui->checkBox_Title->isChecked())
        select += "Ttitle, ";
    if (ui->checkBox_Time->isChecked())
        select += "Timeup, Timedown ";


    QSqlQuery query;
    query.exec(select + from + where);
    qDebug() << select + from + where;
    qDebug() << query.size();
    while( query.next() )
    {
        for (int i = 0; i < 15; i++)

            temp += query.value(i).toString() + "\t";
        ui->listWidget->addItem(temp);
    }
}

void Find_Form::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    QString temp;
    QString select = QString("select ");
    QString from = QString("from classrom, teacher, course, arrange ");
    QString where = QString("WHERE arrange.Classromno = classrom.Classromno "
                            "AND arrange.Cno = course.Cno "
                            "AND arrange.Tno = teacher.Tno ;");
    if (ui->checkBox->isChecked())
        select += "arrange.Classromno, ";
    if (ui->checkBox_Place->isChecked())
        select += "Place, ";
    if (ui->checkBox_Num->isChecked())
        select += "Capacity, ";
    if (ui->checkBox_Equi->isChecked())
        select += "Equipment, ";
    if (ui->checkBox_Cname->isChecked())
        select += "Cname, ";
    if (ui->checkBox_Tname->isChecked())
        select += "Tname, ";
    if (ui->checkBox_Title->isChecked())
        select += "Ttitle, ";
    if (ui->checkBox_Time->isChecked())
        select += "Timeup, Timedown ";


    QSqlQuery query;
    query.exec(select + from + where);

    while( query.next() )
    {
        for (int i = 0; i < 15; i++)
            temp += query.value(i).toString() + "\t";
        ui->listWidget->addItem(temp);
        temp = "";    }
}
