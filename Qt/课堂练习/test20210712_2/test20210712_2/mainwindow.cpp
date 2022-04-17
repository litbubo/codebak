#include "mainwindow.h"
//#include "myDialog.h"
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //定义QAction
    setAction = new QAction(QIcon(":/img/setting.png"),
                            tr("选项..."), this);
    setAction->setStatusTip(tr("环境设定"));
    connect(setAction, &QAction::triggered,
            this, &MainWindow::setting);
    QMenu *menu = menuBar()->addMenu(tr("工具")); //菜单
    menu->addAction(setAction);
    QToolBar *toolBar = addToolBar(tr("工具"));   //工具栏
    toolBar->addAction(setAction);
    QStatusBar *status = statusBar() ;
    status->addAction(setAction);   //状态栏信息
    resize(300,200);

    label = new QLabel("", this);
    label->setGeometry(0,60,300,140);


}

MainWindow::~MainWindow()
{
}

void MainWindow::setting()
{
    myDialog dialog(this);
    if(dialog.exec()==QDialog::Accepted)
    {
        QString s;
        s="工程目录："+dialog.getProjectPath()+"\n";
        s=s+"编译环境："+dialog.getCompiler()+"\n";
        s=s+"高亮显示："+dialog.getColorPlan()+"\n";
        if(dialog.getIndent())      s=s+"智能缩进：是\n ";
        else      s=s+"智能缩进：否\n ";
        if(dialog.getAutoComplete())    s=s+"代码补全：是";
        else      s=s+"代码补全：否";
        label->setText(s);
    }
    /*
    dialog = new myDialog(this);
    dialog->show();

    QString s;
    s="工程目录："+dialog->getProjectPath()+"\n";
    s=s+"编译环境："+dialog->getCompiler()+"\n";
    s=s+"高亮显示："+dialog->getColorPlan()+"\n";
    if(dialog->getIndent())      s=s+"智能缩进：是\n ";
    else      s=s+"智能缩进：否\n ";
    if(dialog->getAutoComplete())    s=s+"代码补全：是";
    else      s=s+"代码补全：否";
    label->setText(s);
    */

}
