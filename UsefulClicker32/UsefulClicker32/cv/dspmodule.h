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

#ifndef DSPMODULE_H
#define DSPMODULE_H

#include <QObject>
#include <QImage>
#include <vector>
#include <opencv.hpp>
#include "cv/rectangle_descriptor.h"

class DspModule : public QObject
{
    Q_OBJECT
public:
    std::vector<cv::Rect> text_areas;
    QImage last_screenshot;
    int kernel_size=4;
    const int maxRectWidth = 500;
    const int maxRectHeight = 500;

    DspModule();
    void computeHaudorf();
    QRect searchImage(std::string TargetIn_path, int screenNum=0);
    QRect searchRect(int screen_num, int kernel, RectangleDescriptor targetDescriptor);
    void detectButtons(int screen_num, int kernel_size, std::vector<QRect>& rects, bool doInvertImage=false);
    QImage saveImage(QRect roi, QString& filename);
    QString getHistogramString(QRect roi);
    void findTextAreas();
    int X, Y;
    QRect matchedRectangle;


signals:
    void sigSendImage(QImage& image, int n_screen);
};

#endif // DSPMODULE_H
