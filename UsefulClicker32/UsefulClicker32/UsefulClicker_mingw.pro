QT += core gui widgets xml svg
QT += multimedia
QT += multimediawidgets

CONFIG += c++17
#QMAKE_CXXFLAGS += /FS /std:c++17 /Zc:__cplusplus
#QMAKE_CXXFLAGS +=  -Zc:rvalueCast -Zc:inline -Zc:strictStrings -Zc:throwingNew -permissive- -Zc:externConstexpr -utf-8 -w34100 -w34189 -w44996 -w44456 -w44457 -w44458
QMAKE_CXXFLAGS += -std=c++17
QMAKE_CXXFLAGS += -v
TARGET = UsefulClicker
UI_DIR = "./ui"
TEMPLATE = app

#QMAKE_FLAGS_RELEASE += -O3 -msse4.1 -mssse3 -msse3 -msse2 -msse -Wno-unused-variable
#QMAKE_CXXFLAGS_RELEASE += -O3 -msse4.1 -mssse3 -msse3 -msse2 -msse
OPENCV_460_PATH = C:\\Projects\\opencv
OPENCV_460_LIB_PATH = C:\\Projects\\opencv\\build_mingw\\lib
#PYTHON_PATH = "C:\\Program Files\\Python37"
#INCLUDEPATH += "C:\\Program Files\\Python37\\include"
INCLUDEPATH += -L "C:\\Projects\\opencv\\include"
INCLUDEPATH += -L "C:\\Projects\\opencv\\build_mingw32\\opencv2"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\modules\\core\\include"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\build_mingw\\modules"
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\build_mingw\\"
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
INCLUDEPATH+=-L "$$OPENCV_460_PATH\\opencv_contrib\\modules\\shape\\include"
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
INCLUDEPATH+=-L "./interpreter"

LIBS += -luser32 -lgdi32


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_core460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_ml460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_imgproc460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_imgproc460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_features2d460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_features2d460



INCLUDEPATH += $$PWD/../opencv/build_mingw/include
DEPENDPATH += $$PWD/../opencv/build_mingw/include

LIBS+=-L$$OPENCV_460_LIB_PATH\\opencv_core460.lib
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_ml460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_flann460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_imgproc460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_photo460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_features2d460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_imgcodecs460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_videoio460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_highgui460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_ts460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_calib3d460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_objdetect460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_stitching460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_dnn460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_video460
LIBS+=-L$$OPENCV_460_LIB_PATH -lopencv_shape460

#import os
#path = "C:\\Projects\\opencv_new\\build\\lib\\release"
#for root,d_names,f_names in os.walk(path):
#    for f in f_names:
#        if (".lib" in f) and (".exp" not in f):
#            f=f.replace(".lib","")
#            s= f"win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -l{f}\n"
#            s+= f"else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -l{f}"
#            print(s)

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_aruco460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_aruco460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_barcode460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_barcode460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_bgsegm460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_bgsegm460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_bioinspired460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_bioinspired460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_calib3d460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_calib3d460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_ccalib460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_ccalib460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_core460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_core460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_datasets460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_datasets460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_dnn460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_dnn460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_dnn_objdetect460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_dnn_objdetect460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_dnn_superres460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_dnn_superres460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_dpm460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_dpm460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_face460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_face460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_features2d460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_features2d460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_flann460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_flann460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_fuzzy460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_fuzzy460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_gapi460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_gapi460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_hfs460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_hfs460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_highgui460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_highgui460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_imgcodecs460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_imgcodecs460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_imgproc460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_imgproc460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_img_hash460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_img_hash460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_intensity_transform460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_intensity_transform460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_line_descriptor460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_line_descriptor460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_mcc460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_mcc460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_ml460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_ml460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_objdetect460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_objdetect460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_optflow460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_optflow460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_phase_unwrapping460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_phase_unwrapping460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_photo460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_photo460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_plot460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_plot460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_quality460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_quality460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_rapid460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_rapid460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_reg460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_reg460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_rgbd460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_rgbd460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_saliency460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_saliency460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_shape460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_shape460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_stereo460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_stereo460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_stitching460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_stitching460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_structured_light460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_structured_light460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_superres460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_superres460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_surface_matching460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_surface_matching460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_text460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_text460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_tracking460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_tracking460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_ts460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_ts460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_video460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_video460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_videoio460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_videoio460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_videostab460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_videostab460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_wechat_qrcode460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_wechat_qrcode460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_xfeatures2d460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_xfeatures2d460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_ximgproc460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_ximgproc460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_xobjdetect460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_xobjdetect460
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/release/ -lopencv_xphoto460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../opencv/build_mingw/lib/debug/ -lopencv_xphoto460
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
    twee_bot/regularactivity.cpp \
    twee_bot/searchwindow.cpp \
    twee_bot/twitteractivity.cpp

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
    twee_bot/regularactivity.h \
    twee_bot/searchwindow.h \
    twee_bot/twitteractivity.h

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
    twee_bot/paraphrazer_rus_py37.txt \
    twee_bot/clipboard.txt

