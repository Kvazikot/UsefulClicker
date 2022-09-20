#ifndef RECTANGLE_DESCRIPTOR_H
#define RECTANGLE_DESCRIPTOR_H

#include <QString>
#include <QDomNode>
#include <QMap>
#include <QPoint>
#include <QRect>
#include <QVector2D>
#include <vector>
#include "log/logger.h"
#include <opencv2/opencv.hpp>

using namespace  std;

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
    int h_bins = 100;
    cv::Mat hist;
    cv::MatND HistB, HistG, HistR;



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
        cv::cvtColor( im, im, cv::COLOR_BGR2HSV );
        int channels[] = { 0 }; //index of channel
        int histSize[] = { h_bins };
        float hranges[] = { 0, 255 };
        const float* ranges[] = { hranges };

        //split rgb
        vector<cv::Mat> bgr_planes;
        cv::split(im, bgr_planes);

        //cal histogram & normalization
        cv::calcHist(&bgr_planes[0], 1, 0, cv::Mat(), HistB, 1, histSize, ranges, true, false);
        cv::calcHist(&bgr_planes[1], 1, 0, cv::Mat(), HistG, 1, histSize, ranges, true, false);
        cv::calcHist(&bgr_planes[2], 1, 0, cv::Mat(), HistR, 1, histSize, ranges, true, false);

        cv::normalize(HistB, HistB, 0, 255, cv::NORM_MINMAX);
        cv::normalize(HistG, HistG, 0, 255, cv::NORM_MINMAX);
        cv::normalize(HistR, HistR, 0, 255, cv::NORM_MINMAX);

        //normalize( hist, hist, 0, 255, cv::NORM_MINMAX, -1, cv::Mat() );
        //base_base = compareHist( hist_base1, hist_base2, 2 );


    }
    float calculateDifference(RectangleDescriptor& r1, RectangleDescriptor r2)
    {
        float da = abs( area(r1) - area(r2) ) * area_weight;
        float dc = abs( QVector2D(r1.center - r2.center).length() ) * center_weight;
        float dn = 0;//abs( r1.number - r2.number) * number_weight;
        float dr = ratio_weight * abs(r1.ratio - r2.ratio);
        float dh = abs(1 - cv::compareHist( r1.hist, r2.hist, 0 ));
        //qDebug("dh=%f da=%f dc=%f dn=%f dr=%f",dh,da,dc,dn,dr);
        return dh + dc + dn  + dr;
    }

    QString compressHistogram(cv::MatND& h)
    {
        QString out;

        vector<pair<float,float>> mostly_zeroes_pairs;

        float start=0, end=h_bins-1;
        for(int i = 1; i < h_bins-1; i++)
        {
            float prev = h.at<float>(i-1);
            float cur = h.at<float>(i);
            float next = h.at<float>(i+1);

            if( prev!=0 && cur==0  )
            {
                start = i;
                continue;
            }
            if( next!=0 && cur==0  )
            {
                end = i+1;
                mostly_zeroes_pairs.push_back(make_pair(start, end));
                continue;
            }
            if(cur!=0)
               mostly_zeroes_pairs.push_back(make_pair(cur, cur));
        }

        // output compressed string
        QString s;
        for(auto it=mostly_zeroes_pairs.begin(); it!=mostly_zeroes_pairs.end(); it++)
        {
            if( it->first!=it->second )
              out+="#" + QString::number(int(it->second- it->first))+',';
            else
              out+=s.sprintf("%0.3f,", it->second);
        }


        return out;
    }

    QString decompressHistogram(QString h_str)
    {
        QString out;

        QStringList toks = h_str.split(',');
        foreach (QString t, toks)
        {
            if( t.contains('#') )
            {
                int n_zeroes = t.right(t.size()-1).toInt();
                while(--n_zeroes >= 0)
                    out+="0.000,";
            }
            else
               out+=t+",";
        }

        return out;
    }

    QString toString()
    {
        QString sout;
        sout = sout.sprintf("%dx%d,", width, height);
        QString s;
        for(int i = 0; i < h_bins; i++)
           sout+=s.sprintf("%0.3f,", HistR.at<float>(i));
        //for(int i = 0; i < h_bins; i++)
         //   sout+=s.sprintf("%0.3f,", HistG.at<float>(i));
        QString compressed = compressHistogram(HistR);
        QString decompressed = decompressHistogram(compressed);
        sout+="\n\ncompressed="+compressed;
        sout+="\n\ndecompressed="+decompressed;
        return sout;
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
