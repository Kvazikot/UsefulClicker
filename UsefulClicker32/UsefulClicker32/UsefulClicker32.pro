#-------------------------------------------------
#
# Project created by QtCreator 2022-09-13T12:07:56
#
#-------------------------------------------------
QT += core gui widgets xml svg
#QT += multimedia

QT += core gui widgets xml svg
QT += multimedia
DEFINES += QT_DEPRECATED_WARNINGS
#QMAKE_CXXFLAGS+= -std=c++17 -Wno-write-strings
QMAKE_CXXFLAGS+=/std:c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UsefulClicker32
TEMPLATE = app

OPENCV_460_PATH = "C:\Projects\opencv"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\core\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\build_vs2017\\modules"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\build_vs2017\\"
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

win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_core460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_ml460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_flann460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_imgproc460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_photo460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_features2d460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_imgcodecs460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_videoio460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_highgui460
win32:CONFIG(release, debug|release): #LIBS+=-L$$OPENCV_460_PATH\\build_vs2017\\lib\\" -lopencv_ts460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_calib3d460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_objdetect460
win32:CONFIG(release, debug|release): #LIBS+=-L$$OPENCV_460_PATH\\build_vs2017\\lib\\ -lopencv_stitching460
win32:CONFIG(release, debug|release): #LIBS+=-L$$OPENCV_460_PATH\\build_vs2017\\lib\\ -lopencv_dnn460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_video460
win32:CONFIG(release, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Release" -lopencv_shape460


win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_core460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_ml460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_flann460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_imgproc460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_photo460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_features2d460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_imgcodecs460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_videoio460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_highgui460d
win32:CONFIG(debug, debug|release): #LIBS+=-L$$OPENCV_460_PATH\\build_vs2017\\lib\\" -lopencv_ts460
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_calib3d460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_objdetect460d
win32:CONFIG(debug, debug|release): #LIBS+=-L$$OPENCV_460_PATH\\build_vs2017\\lib\\ -lopencv_stitching460
win32:CONFIG(debug, debug|release): #LIBS+=-L$$OPENCV_460_PATH\\build_vs2017\\lib\\ -lopencv_dnn460
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_video460d
win32:CONFIG(debug, debug|release): LIBS+=-L"C:\\Projects\\opencv\\build_vs2017\\lib\\Debug" -lopencv_shape460d

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
    ui/widgets/svg_path_parser.cpp \
    interpreter/uc_shortcode_generator.cpp \
    tests/cool_tests_form.cpp \
    ui/imagesearchdialog.cpp \
    cv/rectangle_descriptor.cpp \
    tests/rectangle_descriptor_test.cpp \
    twee_bot/tweebot.cpp \
    twee_bot/regularactivity.cpp

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
    ui/widgets/svg_path_parser.h \
    interpreter/uc_shortcode_generator.h \
    tests/cool_tests_form.h \
    ui/imagesearchdialog.h \
    cv/rectangle_descriptor.h \
    tests/rectangle_descriptor_test.h \
    twee_bot/tweebot.h \
    twee_bot/regularactivity.h

FORMS    += mainwindow.ui \
    ui/aboutbox.ui \
    ui/areaselectordialog.ui \
    ui/screenbuttonsdetector.ui \
    ui/coordselector.ui \
    ui/shelldialog.ui \
    ui/typedialog.ui \
    ui/mousedialog.ui \
    ui/widgets/delaywidget.ui \
    ui/widgets/dimensionswidget.ui \
    tests/cool_tests_form.ui \
    ui/imagesearchdialog.ui \
    twee_bot/tweebot.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    tests/UsefulClicker_tests.xml \
    twee_bot/paraphrazer_rus_py37.txt

INCLUDEPATH += $$PWD/../../../opencv/build_vs2017/lib/Release
DEPENDPATH += $$PWD/../../../opencv/build_vs2017/lib/Release
