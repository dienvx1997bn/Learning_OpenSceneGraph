#-------------------------------------------------
#
# Project created by QtCreator 2019-04-24T15:26:04
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = osgearth_drawables
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -lOpenThreads
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -lOpenThreads
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -lOpenThreads

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losgDB
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losgDB
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losgDB

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losgUtil
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losgUtil
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losgUtil

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losgViewer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losgViewer
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losgViewer

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losg
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losg
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losg

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losgGA
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losgGA
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losgGA

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib64/release/ -losgEarth
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib64/debug/ -losgEarth
else:unix: LIBS += -L$$PWD/../../../usr/local/lib64/ -losgEarth

INCLUDEPATH += $$PWD/../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../usr/local/lib64
