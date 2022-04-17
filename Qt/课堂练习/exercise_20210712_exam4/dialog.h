#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString getProjectPath(); 	// 获取工程目录
    QString getCompiler();		// 获取编译器信息
    QString getColorPlan();		// 获取颜色方案
    bool getIndent();			// 是否缩进
    bool getAutoComplete();		// 是否代码自动补全
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
