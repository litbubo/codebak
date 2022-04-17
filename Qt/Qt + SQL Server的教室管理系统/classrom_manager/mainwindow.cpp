#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QItemSelectionModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("教室管理系统");

    qDebug() << QSqlDatabase::drivers();


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

    model = new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    on_action_classrom_triggered();

    ui->tableView_T->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_room->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_arr->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_action_classrom_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->classrom);
    ui->label_title->setText("教室信息管理");

    model->setTable("classrom");

    ui->tableView_room->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "教室号");
    model->setHeaderData(1, Qt::Horizontal, "地点");
    model->setHeaderData(2, Qt::Horizontal, "容纳人数");
    model->setHeaderData(3, Qt::Horizontal, "设备");

    model->select();
}



void MainWindow::on_action_teacher_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->teacher);
    ui->label_title->setText("教师信息管理");

    model->setTable("teacher");

    ui->tableView_T->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "教师号");
    model->setHeaderData(1, Qt::Horizontal, "教师名");
    model->setHeaderData(2, Qt::Horizontal, "年龄");
    model->setHeaderData(3, Qt::Horizontal, "职称");

    model->select();

    ui->comboBox_arr_find_cno->clear();
    ui->comboBox_arr_find_tno->clear();
    ui->comboBox_arr_find_class->clear();

    QSqlQuery query;
    QString sql = QString("select Classromno from classrom");
    query.exec(sql);
    while( query.next() )
    {
        QString name = query.value(0).toString();
        ui->comboBox_arr_find_class->addItem(name);
    }

    sql = QString("select Cno from course");
    query.exec(sql);
    while( query.next() )
    {
        QString name = query.value(0).toString();
        ui->comboBox_arr_find_cno->addItem(name);
    }

    sql = QString("select Tno from teacher");
    query.exec(sql);
    while( query.next() )
    {
        QString name = query.value(0).toString();
        ui->comboBox_arr_find_tno->addItem(name);
    }

}

void MainWindow::on_action_arr_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->arrange);
    ui->label_title->setText("授课安排管理");

    model->setTable("arrange");

    ui->tableView_arr->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "教室号");
    model->setHeaderData(1, Qt::Horizontal, "课程号");
    model->setHeaderData(2, Qt::Horizontal, "教师号");
    model->setHeaderData(3, Qt::Horizontal, "上课时间");
    model->setHeaderData(4, Qt::Horizontal, "下课时间");


    model->select();
}


void MainWindow::on_pushButton_room_add_clicked()
{
    QSqlRecord record = model->record();
    int row = model->rowCount();
    model->insertRecord(row, record);
}

void MainWindow::on_pushButton_room_del_clicked()
{
    QItemSelectionModel *sModel =ui->tableView_room->selectionModel();
    QModelIndexList list = sModel->selectedRows();
    for(int i = 0; i < list.size(); i++)
    {
        model->removeRow( list.at(i).row() );
    }
}

void MainWindow::on_pushButton_room_sure_clicked()
{
    model->submitAll(); //提交动作
}

void MainWindow::on_pushButton_room_cancel_clicked()
{
    model->revertAll(); //取消所用动作
    model->submitAll(); //提交动作
}

void MainWindow::on_pushButton_room_find_clicked()
{
    QString name = ui->lineEdit_room_find->text();
    QString str = QString("Classromno = '%1'").arg(name);

    model->setFilter(str);
    model->select();
}

void MainWindow::on_pushButton_T_add_clicked()
{
    QSqlRecord record = model->record();
    int row = model->rowCount();
    model->insertRecord(row, record);
}

void MainWindow::on_pushButton_T_del_clicked()
{
    QItemSelectionModel *sModel =ui->tableView_T->selectionModel();
    QModelIndexList list = sModel->selectedRows();
    for(int i = 0; i < list.size(); i++)
    {
        model->removeRow( list.at(i).row() );
    }
}

void MainWindow::on_pushButton_T_sure_clicked()
{
    model->submitAll(); //提交动作
}

void MainWindow::on_pushButton_T_cancel_clicked()
{
    model->revertAll(); //取消所用动作
    model->submitAll(); //提交动作
}

void MainWindow::on_pushButton_T_find_clicked()
{
    QString name = ui->lineEdit_T_find->text();
    QString str = QString("Tno = '%1'").arg(name);

    model->setFilter(str);
    model->select();
}

void MainWindow::on_pushButton_arr_add_clicked()
{
    QSqlRecord record = model->record();
    int row = model->rowCount();
    model->insertRecord(row, record);
}

void MainWindow::on_pushButton_arr_del_clicked()
{
    QItemSelectionModel *sModel =ui->tableView_arr->selectionModel();
    QModelIndexList list = sModel->selectedRows();
    for(int i = 0; i < list.size(); i++)
    {
        model->removeRow( list.at(i).row() );
    }
}

void MainWindow::on_pushButton_arr_sure_clicked()
{
    model->submitAll(); //提交动作
}

void MainWindow::on_pushButton_arr_cancel_clicked()
{
    model->revertAll(); //取消所用动作
    model->submitAll(); //提交动作
}

void MainWindow::on_pushButton_arr_find_clicked()
{
    QString classname = ui->comboBox_arr_find_class->currentText();
    QString cno = ui->comboBox_arr_find_cno->currentText();
    QString tno = ui->comboBox_arr_find_tno->currentText();

    QString str = QString("Classromno = '%1' AND Cno = '%2' AND Tno = '%3' ").arg(classname).arg(cno).arg(tno);

    model->setFilter(str);
    model->select();
}



void MainWindow::on_action_triggered()
{
    db.close();
    QSqlDatabase::removeDatabase("login");
    this->close();
}
