/*
+ - - - + - + - -
+ - + - + copyright by Vladimir Baranov (Kvazikot)  <br>
+ - + - + email: vsbaranov83@gmail.com  <br>
+ - + - + github: https://github.com/Kvazikot/UsefulMacro/  <br>
```
                          )            (
                         /(   (\___/)  )\
                        ( #)  \ ('')| ( #
                         ||___c\  > '__||
                         ||**** ),_/ **'|
                   .__   |'* ___| |___*'|
                    \_\  |' (    ~   ,)'|
                     ((  |' /(.  '  .)\ |
                      \\_|_/ <_ _____> \______________
                       /   '-, \   / ,-'      ______  \
              b'ger   /      (//   \\)     __/     /   \
                                          './_____/
```
*/

#include <QMediaPlayer>
#include <QTimer>
#include <QVideoWidget>
#include <QSoundEffect>
#include <QPointer>
#include <QDir>
#include "aboutbox.h"
#include "ui/coordselector.h"
#include "ui/ui_aboutbox.h"

AboutBox::AboutBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutBox)
{
    ui->setupUi(this);
    QTimer::singleShot(1000, this, SLOT(delayedSlot()));
}

void AboutBox::delayedSlot()
{
    CoordSelector* dlg = new CoordSelector(this, true);
    dlg->showFullScreen();
}

AboutBox::~AboutBox()
{
    delete ui;
}

void AboutBox::on_buttonBox_accepted()
{
    done(1);
}


void AboutBox::on_whatchMovie_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    player->setSource((QUrl::fromLocalFile(QDir::currentPath() + "/video/video1866726317.mp4")));
    //player->setVolume(10);
    QVideoWidget* videoWidget = new QVideoWidget(this);
    videoWidget->setGeometry(ui->textEdit->geometry());
    player->setVideoOutput(videoWidget);

    videoWidget->show();
    player->play();
}

