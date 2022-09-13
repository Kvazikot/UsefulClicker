#-------------------------------------------------
#
# Project created by QtCreator 2022-09-13T12:07:56
#
#-------------------------------------------------
QT += core gui widgets xml svg
#QT += multimedia

QT += core gui widgets xml svg
QT += multimedia

QMAKE_CXXFLAGS+= -std=c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UsefulClicker32
TEMPLATE = app

#OPENCV_451_PATH = "C:\Projects\opencv"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\core\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\build_mingw\\modules"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\build_mingw\\"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\include\\opencv2"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\include\\"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\calib3d\\include\\"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\calib3d\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\core\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\dnn\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\features2d\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\flann\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\gapi\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\highgui\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\imgcodecs\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\imgproc\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\videoio\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\video\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\gapi\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\objdetect\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\photo\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\opencv_contrib-4.x\modules\shape\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\java\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\js\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\ml\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\objc\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\objdetect\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\photo\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\python\\include"
#INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\stitching\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\ts\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\video\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\videoio\\include"
##INCLUDEPATH+=-L "$$OPENCV_451_PATH\\modules\\world\\include"
#INCLUDEPATH+= "./interpreter"

#LIBS += -luser32 -lgdi32
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_core455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_ml455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_flann455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_imgproc455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_photo455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_features2d455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_imgcodecs455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_videoio455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_highgui455.dll
##LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\" -lopencv_ts455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_calib3d455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_objdetect455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_stitching455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_dnn455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_video455.dll
#LIBS+=-L$$OPENCV_451_PATH\\build_mingw\\lib\\ -lopencv_shape455.dll

#LIBS+=-L$$PYTHON_PATH\\libs\\ -lpython37
#LIBS+="$$(PYTHON_PATH)\\libs\\python39




SOURCES += main.cpp\
        mainwindow.cpp \
    xml/clickerdocument.cpp \
    xml/xmleditor.cpp \
    settings/clickersettings.cpp \
    tests/highlighter.cpp

HEADERS  += mainwindow.h \
    xml/clickerdocument.h \
    xml/xmleditor.h \
    settings/clickersettings.h \
    tests/highlighter.h

FORMS    += mainwindow.ui
