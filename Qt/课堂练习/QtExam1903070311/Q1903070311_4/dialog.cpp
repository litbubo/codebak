#include "dialog.h"
#include "ui_dialog.h"
#include <QFontDialog>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->textEdit->setText("城阙辅三秦，\n风烟望五津。");
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QFontDialog *fontDialog = new QFontDialog(this);
        fontDialog->setCurrentFont(ui->textEdit->font());
        if(QDialog::Accepted == fontDialog->exec())
             ui->textEdit->setCurrentFont(fontDialog->currentFont());

}

void Dialog::on_pushButton_2_clicked()
{
    QMessageBox:: StandardButton result = QMessageBox::information(this,"再见","您确定要退出程序吗",QMessageBox::Yes,QMessageBox::No);
    if(result == QMessageBox::Yes)
    {
        this->close();
    }
    else
    {

    }
}
