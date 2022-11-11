#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QDebug>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMusic();

    connect(player, &QMediaPlayer::currentMediaChanged, this,[=]()
    {
        ui->label_name->setText(namelist[playlist->currentIndex()]);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *)
{
    int progress = player->position();
    int total = player->duration();
    qDebug() << "total = " << total << "progress" << progress;
    ui->horizontalSlider_progress->setMaximum(total / 1000.0);
    ui->horizontalSlider_progress->setValue(progress / 1000.0);
}

void MainWindow::initMusic()
{
    QDir dir("C:\\Users\\imxlp\\Desktop\\huaqingmusic\\media", "*.mp3");
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);

    namelist = dir.entryList();
    for(auto i = 0; i < namelist.size(); i++)
    {
        qDebug() << namelist[i];
        QString path = QString("C:\\Users\\imxlp\\Desktop\\huaqingmusic\\media\\" + namelist[i]);
        playlist->addMedia(QUrl::fromLocalFile(path));
    }
    pos = 0;
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
    player->setVolume(100);
}


void MainWindow::on_pushButton_pre_clicked()
{
    killTimer(timerID);
    ui->pushButton_play->setIcon(QIcon(":/icon/play.png"));
    player->pause();

    pos = pos - 1;
    if(pos < 0)
        pos = namelist.size() - 1;
    playlist->setCurrentIndex(pos);

    ui->pushButton_play->setIcon(QIcon(":/icon/pause.png"));
    player->play();
    isPlaying = true;
    timerID = startTimer(1000);
}


void MainWindow::on_pushButton_play_clicked()
{
    if(isPlaying == false)
    {
        isPlaying = true;
        ui->pushButton_play->setIcon(QIcon(":/icon/pause.png"));
        player->play();
        timerID = startTimer(1000);
    }
    else
    {
        isPlaying = false;
        ui->pushButton_play->setIcon(QIcon(":/icon/play.png"));
        player->pause();
        killTimer(timerID);
    }
    ui->label_name->setText(namelist[pos]);
}


void MainWindow::on_pushButton_next_clicked()
{
    killTimer(timerID);
    ui->pushButton_play->setIcon(QIcon(":/icon/play.png"));
    player->pause();

    pos = (pos + 1) % namelist.size();
    playlist->setCurrentIndex(pos);

    ui->pushButton_play->setIcon(QIcon(":/icon/pause.png"));
    player->play();
    isPlaying = true;
    timerID = startTimer(1000);
}


void MainWindow::on_horizontalSlider_progress_sliderReleased()
{
    int postion = ui->horizontalSlider_progress->value();
    qDebug() << postion;
    player->setPosition(postion * 1000);
    player->play();
    timerID = startTimer(1000);
}


void MainWindow::on_horizontalSlider_progress_sliderPressed()
{
    killTimer(timerID);
    qDebug() << "press";
    player->pause();
}

