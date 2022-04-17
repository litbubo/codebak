#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    return;
    QJsonDocument doc;
    if(doc.isEmpty())
    {
        qDebug() << "Json is empty";
    }
    if(doc.isNull())
    {
        qDebug() << "Json is Null";
    }
    writeJson();
    readJson();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
// test.json
{
    "Name":"Ace",
    "Sex":"man",
    "Age":20,
    "Family":{
        "Father":"Gol·D·Roger",
        "Mother":"Portgas·D·Rouge",
        "Brother":["Sabo", "Monkey D. Luffy"]
    },
    "IsAlive":false,
    "Comment":"yyds"
}
*/

void MainWindow::writeJson()
{
    QJsonObject object;
    object.insert("Name", "Ace");
    object.insert("Sex", "man");
    object.insert("Age", 20);
    QJsonObject son;
    son.insert("Father", "Gol·D·Roger");
    son.insert("Mother", "Portgas·D·Rouge");
    QJsonArray array;
    array.append("Sabo");
    array.append("Monkey D. Luffy");
    son.insert("Brother", array);
    object.insert("Family", son);
    object.insert("IsAlive", false);
    object.insert("Comment", "yyds");

    QJsonDocument document(object);

    QFile f("test.json");
    f.open(QFile::WriteOnly);
    f.write(document.toJson());
    f.close();
}

void MainWindow::readJson()
{
    QFile f("test.json");
    f.open(QFile::ReadOnly);
    QByteArray barry = f.readAll();
    f.close();

    QJsonDocument d = QJsonDocument::fromJson(barry);
    if(d.isObject())
    {
        QJsonObject ob = d.object();
        QStringList list = ob.keys();
        for(int i = 0; i < list.size(); i++)
        {
            QString key = list.at(i);
            QJsonValue val = ob.value(key);
            if(val.isString())
            {
                qDebug() << key << ":" << val.toString();
            }
            else if(val.isDouble())
            {
                qDebug() << key << ":" << val.toDouble();
            }
            else if(val.isBool())
            {
                qDebug() << key << ":" << val.toBool();
            }
            else if(val.isObject())
            {
                qDebug() << key << ":";
                QJsonObject son = val.toObject();
                QStringList sonlist = son.keys();
                for (int j = 0; j < sonlist.size(); j++)
                {
                    QString key = sonlist.at(j);
                    QJsonValue val = son.value(key);
                    if(val.isString())
                    {
                        qDebug() << "       " << key << ":" << val.toString();
                    }
                    else if(val.isArray())
                    {
                        qDebug() << "       " << key << ":" ;
                        QJsonArray arr = val.toArray();
                        for (int k = 0; k < arr.size(); k++)
                        {
                            qDebug() << "                  " <<arr[k].toString();
                        }
                    }
                }
            }
        }
    }

}

