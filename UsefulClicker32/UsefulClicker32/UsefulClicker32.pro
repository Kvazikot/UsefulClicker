#-------------------------------------------------
#
# Project created by QtCreator 2022-09-13T12:07:56
#
#-------------------------------------------------
QT += core gui widgets xml svg
#QT += multimedia

QT += core gui widgets xml svg
QT += multimedia

QMAKE_CXXFLAGS+= -std=c++17 -Wno-write-strings

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UsefulClicker32
TEMPLATE = app

OPENCV_460_PATH = "C:\Projects\opencv"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\core\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\build_mingw32\\modules"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\build_mingw32\\"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\include\\opencv2"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\include\\"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\calib3d\\include\\"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\calib3d\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\core\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\dnn\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\features2d\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\flann\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\gapi\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\highgui\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\imgcodecs\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\imgproc\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\videoio\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\video\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\gapi\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\objdetect\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\photo\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\opencv_contrib\modules\shape\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\java\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\js\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\ml\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\objc\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\objdetect\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\photo\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\python\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\stitching\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\ts\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\video\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\videoio\\include"
#INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\world\\include"
INCLUDEPATH+= "./interpreter"

LIBS += -luser32 -lgdi32
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_core460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_ml460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_flann460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_imgproc460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_photo460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_features2d460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_imgcodecs460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_videoio460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_highgui460.dll
#LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\" -lopencv_ts460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_calib3d460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_objdetect460.dll
#LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_stitching460.dll
#LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_dnn460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_video460.dll
LIBS+=-L$$OPENCV_460_PATH\\build_mingw32\\lib\\ -lopencv_shape460.dll

#LIBS+=-L$$PYTHON_PATH\\libs\\ -lpython37
#LIBS+="$$(PYTHON_PATH)\\libs\\python39




SOURCES += main.cpp\
        mainwindow.cpp \
    xml/clickerdocument.cpp \
    xml/xmleditor.cpp \
    settings/clickersettings.cpp \
    tests/highlighter.cpp \
    interpreter/interpreter.cpp \
    interpreter/interpreterwin64.cpp \
    cv/dspmodule.cpp \
    log/logger.cpp \
    globals.cpp \
    interpreter/expression_calculator.cpp \
    ui/aboutbox.cpp \
    ui/createdialog.cpp \
    ui/areaselectordialog.cpp \
    ui/screenbuttonsdetector.cpp \
    ui/coordselector.cpp \
    ui/shelldialog.cpp \
    ui/typedialog.cpp \
    ui/mousedialog.cpp \
    ui/widgets/delaywidget.cpp \
    ui/widgets/dimensionswidget.cpp \
    ui/widgets/qconsole.cpp \
    ui/widgets/svgwidget.cpp \
    ui/widgets/svg_path_parser.cpp

HEADERS  += mainwindow.h \
    xml/clickerdocument.h \
    xml/xmleditor.h \
    settings/clickersettings.h \
    tests/highlighter.h \
    interpreter/interpreter.h \
    interpreter/interpreterwin64.h \
    cv/dspmodule.h \
    cv/rectangle_descriptor.h \
    log/logger.h \
    globals.h \
    interpreter/expression_calculator.h \
    ui/aboutbox.h \
    ui/areaselectordialog.h \
    ui/screenbuttonsdetector.h \
    ui/coordselector.h \
    ui/shelldialog.h \
    ui/typedialog.h \
    ui/mousedialog.h \
    ui/widgets/delaywidget.h \
    ui/widgets/dimensionswidget.h \
    ui/widgets/qconsole.h \
    ui/widgets/svgwidget.h \
    ui/widgets/svg_path_parser.h

FORMS    += mainwindow.ui \
    ui/aboutbox.ui \
    ui/areaselectordialog.ui \
    ui/screenbuttonsdetector.ui \
    ui/coordselector.ui \
    ui/shelldialog.ui \
    ui/typedialog.ui \
    ui/mousedialog.ui \
    ui/widgets/delaywidget.ui \
    ui/widgets/dimensionswidget.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    tests/UsefulClicker_tests.xml
