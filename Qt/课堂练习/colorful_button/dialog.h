#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void timerEvent(QTimerEvent *e);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    int id = 0;
    int RGB_R = 0;
    int RGB_G = 0;
    int RGB_B = 0;
    int judge = 0;
};
#endif // DIALOG_H
