#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>		//包含停靠窗口
#include <QCalendarWidget>	//包含日历控件

class MainWindow : public QMainWindow
{
    Q_OBJECT
    // 添加组件、函数的定义
    QTextEdit *textEdit;
    QMenu  *viewMenu;
    QToolBar  *viewToolBar;
    void createDockWidget();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    textEdit = new QTextEdit;  //创建窗口控件
    this->setCentralWidget(textEdit);
    viewMenu = menuBar()->addMenu(tr("视图"));   //添加菜单
    viewToolBar = this->addToolBar(tr(""));    //添加工具条
    createDockWidget();		//创建停靠窗体
    this->setWindowTitle(tr("停靠窗口"));
}

void MainWindow::createDockWidget()
{
    //设置主窗体的第一个QDockWidget
    QDockWidget *dock = new QDockWidget(this);
    //设置dock的窗口名称
    dock->setWindowTitle(tr("日期"));
    //设置dock的可停靠区域，全部可停靠
    dock->setAllowedAreas(Qt::AllDockWidgetAreas);
    //设置dock内的控件
    QCalendarWidget *calendar = new QCalendarWidget;
    //将日历控件设置成dock的主控件
    dock->setWidget(calendar);
    //向主窗体中添加dock ,第一个参数表示初始显示的位置
    //第二个参数是要添加的QDockWidget控件
    this->addDockWidget(Qt::RightDockWidgetArea, dock);
    //向菜单和工具栏中添加显示和隐藏dock窗口的动作
    viewMenu->addAction(dock->toggleViewAction());
    viewToolBar->addAction(dock->toggleViewAction());
}

MainWindow::~MainWindow()
{
}

