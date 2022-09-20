#ifndef RECTANGLE_DESCRIPTOR_H
#define RECTANGLE_DESCRIPTOR_H

#include <QScreen>
#include <QApplication>
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

QImage mat2img(cv::Mat& mat, int channels);
cv::Mat img2mat(QImage& img);

struct RectangleDescriptor
{
    int number;
    int width;
    int height;
    QPoint center;
    cv::Mat hist_base1;
    int h_bins = 100;
    cv::Mat hist;
    cv::MatND HistB, HistG, HistR;


    RectangleDescriptor()
    {
    }

    RectangleDescriptor(int w, int h, cv::Mat& im)
    {
        width = w;
        height = h;
        getHist(im);
        int type = HistR.type();

    }

    void getHist(cv::Mat& im)
    {
        //cv::cvtColor( im, im, cv::COLOR_BGR2HSV );
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

    float area()
    {
       return width*height;
    }

    float ratio()
    {
        float small = std::min(width, height);
        float big = std::max(width, height);
        return float(small/big);
    }

    float calculateDifference(RectangleDescriptor& r1, RectangleDescriptor& r2)
    {
        float dh = abs(1 - cv::compareHist( r1.HistR, r2.HistR, 0 ));
        dh+= abs(1 - cv::compareHist( r1.HistG, r2.HistG, 0 ));
        QScreen* screen = QApplication::screens()[0];
        float screen_area = screen->geometry().width() * screen->geometry().height();
        float da = abs(r2.area() - r1.area()) / screen_area;
        float dr = abs(r2.ratio() - r1.ratio());
        float d = dh + da + dr;
        return d;
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
            if( (next!=0 || i == h_bins-2) && cur==0    )
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
        out=s.sprintf("%dx%d,", width, height);
        for(auto it=mostly_zeroes_pairs.begin(); it!=mostly_zeroes_pairs.end(); it++)
        {
            if( it->first!=it->second )
              out+="#" + QString::number(int(it->second- it->first))+',';
            else
              out+=s.sprintf("%0.3f,", it->second);
        }


        return out;
    }

    void decompressHistogram(QString h_str)
    {
        QStringList hist_parts = h_str.split("_");
        decompressHistogram(hist_parts[0], HistR);
        decompressHistogram(hist_parts[1], HistG);
    }

    QString decompressHistogram(QString h_str, cv::Mat& out_hist)
    {
        QString out;
        int i=0;

        QStringList toks = h_str.split(',');
        foreach (QString t, toks)
        {
            if( t.contains('x') )
            {
                auto p = t.split('x');
                width = p[0].toInt();
                height = p[1].toInt();
                out_hist = cv::MatND::zeros(h_bins,1,5);
                out+=t;
            }
            else if( t.contains('#') )
            {
                int n_zeroes = t.right(t.size()-1).toInt();
                while(--n_zeroes >= 0)
                {
                    out+="0.000,";
                    if(i < h_bins)
                        out_hist.at<int>(i) = 0;
                    i++;
                }
            }
            else
            {
               out+=t+",";
               if(i < h_bins)
                out_hist.at<int>(i) = t.toFloat();
               i++;
            }
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
        QString decompressed = decompressHistogram(compressed, HistR);
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
