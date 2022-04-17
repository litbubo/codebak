#ifndef FIND_FORM_H
#define FIND_FORM_H

#include <QWidget>

namespace Ui {
class Find_Form;
}

class Find_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Find_Form(QWidget *parent = nullptr);
    ~Find_Form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Find_Form *ui;
};

#endif // FIND_FORM_H
