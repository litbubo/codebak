#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:


    void on_pushButtonconnect_clicked();

    void on_pushButtonsend_clicked();

    void on_pushButtonclose_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *tcpSocket = nullptr;

};
#endif // WIDGET_H
