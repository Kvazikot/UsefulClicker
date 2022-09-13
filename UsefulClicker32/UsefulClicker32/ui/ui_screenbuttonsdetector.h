/********************************************************************************
** Form generated from reading UI file 'screenbuttonsdetector.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENBUTTONSDETECTOR_H
#define UI_SCREENBUTTONSDETECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ScreenButtonsDetector
{
public:
    QLabel *tipLabel;

    void setupUi(QDialog *ScreenButtonsDetector)
    {
        if (ScreenButtonsDetector->objectName().isEmpty())
            ScreenButtonsDetector->setObjectName(QString::fromUtf8("ScreenButtonsDetector"));
        ScreenButtonsDetector->resize(1938, 1098);
        ScreenButtonsDetector->setMouseTracking(true);
        ScreenButtonsDetector->setWindowOpacity(0.400000000000000);
        tipLabel = new QLabel(ScreenButtonsDetector);
        tipLabel->setObjectName(QString::fromUtf8("tipLabel"));
        tipLabel->setGeometry(QRect(930, 450, 311, 151));
        tipLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 150);"));
        tipLabel->setAlignment(Qt::AlignCenter);
        tipLabel->setWordWrap(true);

        retranslateUi(ScreenButtonsDetector);

        QMetaObject::connectSlotsByName(ScreenButtonsDetector);
    } // setupUi

    void retranslateUi(QDialog *ScreenButtonsDetector)
    {
        ScreenButtonsDetector->setWindowTitle(QCoreApplication::translate("ScreenButtonsDetector", "Dialog", nullptr));
        tipLabel->setText(QCoreApplication::translate("ScreenButtonsDetector", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; color:#00007f;\">Press F2 to filter rectangle by</span></p><p><span style=\" font-size:24pt; font-weight:700; color:#00007f;\">width and height</span></p><p><br/></p><p><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenButtonsDetector: public Ui_ScreenButtonsDetector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENBUTTONSDETECTOR_H
