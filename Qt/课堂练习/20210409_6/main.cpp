#include "dialog.h"
#include <QApplication>
#include <QGridLayout>	//添加头文件
#include <QLabel>		//添加头文件
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString texts[] = {"1", "2","3","4","5","6","7","8","9"};
    QWidget * window = new QWidget;
    window->setWindowTitle("QGridLayout");
    window->resize(250, 100);
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(2);   //设置单元间隔
    gridLayout->setMargin(2);    //设置边距
    for(int i=0, k = 0; i < 3;i++,k+=3)
    {
        for(int j = 0; j < 3;j++)      {
            QLabel *label = new QLabel(texts[k+j]);
    // 设定label 的显示方式，使其显示的更清楚
            label->setFrameStyle(QFrame::Panel +
                          QFrame::Sunken);
            if(i<2)     label->setMinimumSize(55,0);
            else       label->setMinimumSize(55,50);
            label->setAlignment(Qt::AlignCenter);
            gridLayout->addWidget(label,i,j);   //添加控件到网格
        }
    }
    // 列比：第0列与第1列之比为 1:2
    gridLayout-> setColumnStretch(0, 1);
    gridLayout-> setColumnStretch(1, 2);

    window->setLayout(gridLayout);
    window->show();
    return app.exec();
}
