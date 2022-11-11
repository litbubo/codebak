#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStringList>
#include <QTimerEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void timerEvent(QTimerEvent *);

private slots:
    void on_pushButton_pre_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_next_clicked();

    void on_horizontalSlider_progress_sliderReleased();

    void on_horizontalSlider_progress_sliderPressed();

private:
    Ui::MainWindow *ui;
    int timerID;
    QStringList namelist;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    int pos = 0;
    bool isPlaying = false;
    void initMusic();
};
#endif // MAINWINDOW_H
