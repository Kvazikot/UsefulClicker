#ifndef RECTANGLE_DESCRIPTOR_H
#define RECTANGLE_DESCRIPTOR_H

#include <QString>
#include <QDomNode>
#include <QMap>
#include <QPoint>
#include <QRect>
#include <QVector2D>
#include "log/logger.h"
#include <opencv2/opencv.hpp>

struct RectangleDescriptor
{
    int number;
    float area_weight;
    float ratio_weight;
    float center_weight;
    float number_weight;
    int width;
    int height;
    QPoint center;
    float ratio;
    cv::Mat hist_base1;
    int h_bins = 255, s_bins = 255;
    cv::Mat hist[3];


    RectangleDescriptor()
    {
        area_weight = 5;
        ratio_weight = 100;
        center_weight =1./10;
        number_weight = 1;
    }

    RectangleDescriptor(int w, int h, cv::Mat& im)
    {
        width = w;
        height = h;
        getHist(im);

    }

    void getHist(cv::Mat& im)
    {
        cv::Mat hsv_sample;
        cv::cvtColor( im, hsv_sample, cv::COLOR_BGR2HSV );
        std::vector<cv::Mat> channels;
        cv::split(hsv_sample, channels);

        for(int i=0; i < 3; i++)
        {
            //cv::Mat chanel_histogram = cv::calcHist({channels[i]},{0}, 0, [256],[0,256]);
            float range[] = { 0, 256 }; //the upper boundary is exclusive
            float h_ranges[] = { 0, 255 };
            float s_ranges[] = { 0, 255 };
            int histSize[] = { h_bins, s_bins };
            const float* histRange[] = { range };
            int channels[] = { 0, 1 };
            const float* ranges[] = { h_ranges, s_ranges };
            calcHist( &hsv_sample, 1, channels, cv::Mat(), hist_base1, 2, histSize, ranges, true, false );
            normalize( hist_base1, hist_base1, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );
            hist[i] = hist_base1;
            //base_base = compareHist( hist_base1, hist_base2, 2 );

        }
    }
    float calculateDifference(RectangleDescriptor& r1, RectangleDescriptor r2)
    {
        float da = abs( area(r1) - area(r2) ) * area_weight;
        float dc = abs( QVector2D(r1.center - r2.center).length() ) * center_weight;
        float dn = abs( r1.number - r2.number) * number_weight;
        float dr = ratio_weight * abs(r1.ratio - r2.ratio);
        float dh = abs(1 - cv::compareHist( hist[0], hist[0], 0 ));
        dh+= abs(1 - cv::compareHist( r1.hist[1], r2.hist[1], 0 ));
        dh+= abs(1 - cv::compareHist( r1.hist[2], r2.hist[2], 0 ));
        //qDebug("dh=%f da=%f dc=%f dn=%f dr=%f",dh,da,dc,dn,dr);
        return dh + dc + dn  + dr;
    }


    void fromDomNode(QDomNode node)
    {
        QString s = node.toElement().attribute("center").toStdString().c_str();
        QStringList l = s.split(",");
        if(l.size() == 2)
            center = QPoint(l[0].toInt(), l[1].toInt());
        width = node.toElement().attribute("width").toInt();
        height = node.toElement().attribute("height").toInt();
        ratio = float(width)/ float(height);
        number = node.toElement().attribute("number").toInt();
    }

    void writeToMap(QMap<QString, QString>& attrs)
    {
        attrs["center"] =  QString("%1,%2").arg(center.x()).arg(center.y());
        attrs["width"] = QString::number(width);
        attrs["height"] = QString::number(height);
        attrs["number"] = QString::number(number);
    }

    RectangleDescriptor(const QRect& rc, int number)
    {
        width = rc.width();
        height = rc.height();
        center = rc.center();
        this->number = number;
    }

    void setRect(QRect rect)
    {
        width = rect.width();
        height = rect.height();
        center = rect.center();
        ratio = float(rect.width())/ float(rect.height());
    }

    float area(RectangleDescriptor& r)
    {
        return r.width * r.height;
    }

    void setDimensions(QString dimension)
    {
        QStringList list = dimension.split("x");
        if( list.size() == 2 )
        {
            width = list[0].toInt();
            height = list[1].toInt();
        }
        ratio = width /  height;
    }
    void setNumber(int n)
    {
        number = n;
    }
    float procToRatio(QString procent)
    {
        procent = procent.replace(" ","");
        procent = procent.replace("%","");
        return procent.toFloat();
    }

};


#endif // RECTANGLE_DESCRIPTOR_H
