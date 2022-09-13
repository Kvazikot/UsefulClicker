#ifndef RECTANGLE_DESCRIPTOR_H
#define RECTANGLE_DESCRIPTOR_H

#include <QString>
#include <QDomNode>
#include <QMap>
#include <QPoint>
#include <QRect>
#include <QVector2D>
#include "log/logger.h"

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

    RectangleDescriptor()
    {
        area_weight = 5;
        ratio_weight = 100;
        center_weight =1./10;
        number_weight = 1;
    }

    float calculateDifference(RectangleDescriptor& r1, RectangleDescriptor r2)
    {
        //QVector4D v1(float(r1.number) * number_weight, r1.ratio * ratio_weight, r1.center.x(), r1.center.y());
        //QVector4D v2(float(r2.number) * number_weight, r2.ratio * ratio_weight, r2.center.x(), r2.center.y());
        //return (v1-v2).lengthSquared();
        float da = abs( area(r1) - area(r2) ) * area_weight;
        float dc = abs( QVector2D(r1.center - r2.center).length() ) * center_weight;
        float dn = abs( r1.number - r2.number) * number_weight;
        float dr = ratio_weight * abs(r1.ratio - r2.ratio);
        qDebug("da=%f dc=%f dn=%f dr=%f",da,dc,dn,dr);
        return dc + dn  + dr;
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
