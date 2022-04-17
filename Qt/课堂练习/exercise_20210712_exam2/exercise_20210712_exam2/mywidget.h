#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QComboBox>
#include <QMessageBox>
#include <QListWidget>

class myWidget : public QWidget
{
    Q_OBJECT
signals:
    void addSliderValue(int);

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
private:
    QLabel *l = nullptr;
    QLabel *l2 = nullptr;
    QSlider *s = nullptr;
    QPushButton *p = nullptr;
    QComboBox *com = nullptr;
    QListWidget *list = nullptr;
public slots:
    void setLabelText(int);
    void addSilder();
    void setTextMess(const QString &text);
    void setonChanged(int);
};
#endif // MYWIDGET_H
