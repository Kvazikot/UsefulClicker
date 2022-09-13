/*
+ - - - + - + - -
+ - + - + copyright by Vladimir Baranov (Kvazikot)  <br>
+ - + - + email: vsbaranov83@gmail.com  <br>
+ - + - + github: https:/images//github.com/Kvazikot/UsefulMacro/  <br>
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

#include "areaselectordialog.h"
#include "imagesearchdialog.h"
#include "cv/dspmodule.h"
#include <windows.h>
#include <QDateTime>
#include <QDir>
#include "ui/ui_imagesearchdialog.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

static AreaSelectorDialog* dlg = 0;
static DspModule* dsp;
QPointF window_offsetG;

ImageSearchDialog::ImageSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageSearchDialog)
{
    ui->setupUi(this);
    labels_text_templ.push_back(ui->label->text());
    labels_text_templ.push_back(ui->label_2->text());
    labels_text_templ.push_back(ui->label_3->text());
    dsp = new DspModule();
}

ImageSearchDialog::~ImageSearchDialog()
{
    delete ui;
}

void ImageSearchDialog::on_screenAreaButton_clicked()
{
    dlg = new AreaSelectorDialog(this);
    dlg->setScreen(ui->screenSelector->currentIndex());
    screenshot = dlg->makeScreenshot().toImage();
    dlg->show();
    dlg->selectByWindow();
    connect(dlg, SIGNAL(sigSetAreaRect(QRect,QPointF)), this, SLOT(slotAreaSelected(QRect,QPointF)));

}


void ImageSearchDialog::on_pushButton_5_clicked()
{


    AreaSelectorDialog* dlg = new AreaSelectorDialog(this);
    dlg->setScreen(ui->screenSelector->currentIndex());
    screenshot = dlg->makeScreenshot().toImage();
    dlg->fullScreen();
    connect(dlg, SIGNAL(sigSetRect(QRect, QPointF)), this, SLOT(slotTargetSelected(QRect, QPointF)));
}

void ImageSearchDialog::slotAreaSelected(QRect rect, QPointF window_offset)
{
    selectedAreaRect = rect;
    QString text = "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Search Area Rectangle: </span></p><p>x0 = %1</p><p>y0 = %2</p><p>width = %3</p><p>height = %4</p></body></html>";//labels_text_templ[3];
    text = text.arg(rect.top())
                .arg(rect.left())
                .arg(rect.width())
                .arg(rect.height());
    ui->label_3->setText(text);


    areaImg.create(screenshot.height(), screenshot.width(), CV_8UC4);
    cv::Mat mat(screenshot.height(), screenshot.width(),CV_8UC4, screenshot.bits());
    cv::Rect rect1(rect.left(),rect.top(),rect.width(),rect.height());
    areaImg.create(screenshot.height(), screenshot.width(), CV_8UC4);
    areaImg = cv::Mat(mat, rect1);
    areaImg2  = new cv::Mat(screenshot.height(), screenshot.width(), CV_8UC4);
    *areaImg2 = cv::Mat(mat, rect1);

    QPixmap pix;
    pix.load(":/images/green_check_mark.png");
    ui->iconSearchArea->setPixmap(pix);
    cv::Size s1 = targetImg.size();
    cv::Size s2 = areaImg.size();
    if( s1.width != 0 && s2.width != 0)
    {
        ui->testClickButton->setEnabled(true);
        ui->testClickButton->setStyleSheet("");
        ui->findButton->setEnabled(true);
        ui->findButton->setStyleSheet("");
    }
    //imshow("areaImg", areaImg);
    // set target image to label
    QImage imgIn= QImage((uchar*) areaImg.data, areaImg.cols, areaImg.rows, areaImg.step, QImage::Format_ARGB32);
    ui->label_2->setPixmap(QPixmap::fromImage(imgIn));
    cvtColor( areaImg, areaImg, cv::COLOR_BGRA2BGR  );
    cv::imwrite("areaImg.bmp", areaImg);
    window_offsetG = rect.topLeft();

}

void ImageSearchDialog::slotTargetSelected(QRect rect, QPointF window_offset)
{
    selectedTargetRect = rect;
    QString text = "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Search Area Rectangle: </span></p><p>x0 = %1</p><p>y0 = %2</p><p>width = %3</p><p>height = %4</p></body></html>";//labels_text_templ[3];
    text = text.arg(rect.top())
                .arg(rect.left())
                .arg(rect.width())
                .arg(rect.height());
    ui->label_3->setText(text);
    targetImg.create(screenshot.height(), screenshot.width(), CV_8UC4);
    cv::Mat mat(screenshot.height(), screenshot.width(),CV_8UC4, screenshot.bits());
    cv::Rect rect1(rect.left(),rect.top(),rect.width(),rect.height());
    targetImg = cv::Mat(mat, rect1);

    // set check mark
    QPixmap pix;
    pix.load(":/images/green_check_mark.png");
    ui->iconTargetSelected->setPixmap(pix);

    // set Test click button to Enabled state
    cv::Size s1 = targetImg.size();
    cv::Size s2 = areaImg.size();
    if( s1.width != 0 && s2.width != 0)
    {
        ui->testClickButton->setEnabled(true);
        ui->testClickButton->setStyleSheet("");
        ui->findButton->setEnabled(true);
        ui->findButton->setStyleSheet("");
    }

    // set target image to label
    QImage imgIn= QImage((uchar*) targetImg.data, targetImg.cols, targetImg.rows, targetImg.step, QImage::Format_ARGB32);
    ui->label_2->setPixmap(QPixmap::fromImage(imgIn));
    cvtColor( targetImg, targetImg, cv::COLOR_BGRA2BGR  );
    //QDateTime currentTime = QDateTime::currentDateTime();
    QDateTime dt;
    dt = dt.currentDateTime();
    QString clickerPath = qEnvironmentVariable("UsefulClicker");
    if(clickerPath.size() == 0)
        clickerPath = QDir::currentPath();
    QString filename = clickerPath + "/images/" + dt.toString("hh.mm.ss.zzz.png");
    cv::imwrite(filename.toStdString(), targetImg);
}


void ImageSearchDialog::on_findButton_clicked()
{
    dsp->computeHaudorf();
    ui->label_4->setText(QString("<html><head/><body><p><span style=\" font-weight:700;\">Coordinates found.</span></p><p><span style=\" font-weight:700;\">X = %1 Y = %2 <br/> ofsX = %3 ofsY = %4</span></p><p><br/></p></body></html>").
                         arg(dsp->X).
                         arg(dsp->Y).
                         arg(selectedAreaRect.left()).
                         arg(selectedAreaRect.top()));
    //imshow("Target", targetImg);
    //imshow("Area", *areaImg2);


}


void ImageSearchDialog::on_testClickButton_clicked()
{
    POINT mouse_pos;
    GetCursorPos(&mouse_pos);
    mouse_pos.x =  dsp->X + selectedAreaRect.left(); //+ 100
    mouse_pos.y =  dsp->Y + selectedAreaRect.top();
    SetCursorPos(mouse_pos.x, mouse_pos.y);

    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN, mouse_pos.x, mouse_pos.y, 0, 0);
    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP, mouse_pos.x, mouse_pos.y, 0, 0);
}
