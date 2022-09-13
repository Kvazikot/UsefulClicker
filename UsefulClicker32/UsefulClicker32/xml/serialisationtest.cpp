#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QDir>
#include <QRect>
#include "serialisationtest.h"

static QString path;


SerialisationTest::SerialisationTest()
{
    path = QDir::currentPath() + "\\xml\\serialisation_text.txt";
    save();
    restore();
}


void SerialisationTest::save()
{
   QMap<int, QString> emp;
   emp.insert(11,"Harry");
   emp.insert(22,"Ron");
   emp.insert(33,"Rajiv");
   emp.insert(44,"Kate");

   QFile file(path);
   if(!file.open(QIODevice::WriteOnly)){
      qDebug()<<"Error! Cannot open file.";
      return;
   }

   QDataStream outStream(&file);
   outStream.setVersion(QDataStream::Qt_5_13);

   QRect rect(1,2,3,4);
   QVariant v(rect);

   //QRectF

   outStream << emp;
   outStream << "rect___starts" << v.toString();

   file.flush();
   file.close();
}

void SerialisationTest::restore()
{
   QMap<int, QString> emp;
   QFile file(path);
   if(!file.open(QIODevice::ReadOnly)){
      qDebug()<<"Error! Cannot open file.";
      return;
   }
   QDataStream inStream(&file);
   inStream.setVersion(QDataStream::Qt_5_13);
   inStream >> emp;

   QMapIterator<int, QString> iter(emp);
   while (iter.hasNext()) {
      iter.next();
      qDebug() << iter.key() << ": " << iter.value() << "\n";
   }

   file.flush();
   file.close();
}

