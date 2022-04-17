#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getProjectPath()
{
    QString s= ui->lineEdit->text();
    return s;
}
QString Dialog::getCompiler()
{
    if(ui->radioButton->isChecked())
        return QString("VC++ 6.0");
    else  if(ui->radioButton_2->isChecked())
        return QString("VC++2012");
    else
        return QString("g++");
}

QString Dialog::getColorPlan()
{
    QListWidgetItem *it= ui->listWidget->currentItem();
    return it->text();
}
bool Dialog::getIndent()
{
    if(ui->checkBox->isChecked())      return true;
    else       return false;
}
bool Dialog::getAutoComplete()
{
    if(ui->checkBox_2->isChecked())      return true;
    else       return false;
}



