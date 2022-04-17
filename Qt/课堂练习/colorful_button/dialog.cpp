#include "dialog.h"
#include "ui_dialog.h"
#include <string>
#include <iostream>
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


void Dialog::on_pushButton_clicked()
{
    if (judge == 0)
    {
        id = this->startTimer(100);
        judge = 1;
    }
    else
    {
        this->killTimer(id);
        judge = 0;
    }
}

void Dialog::timerEvent(QTimerEvent *e)
{

    RGB_R = rand()%255;
    RGB_G = rand()%255;
    RGB_B = rand()%255;
    //std::cout<< color<<std::endl;
    std::string styleSheet = "background-color:rgb("
                                    + std::to_string(RGB_R) + ","
                                    + std::to_string(RGB_G) + ","
                                    + std::to_string(RGB_B) + ")"  ;
    ui->pushButton->setStyleSheet(styleSheet.data());
    //ui->pushButton->setStyleSheet("background-color:#0036DC");
}
