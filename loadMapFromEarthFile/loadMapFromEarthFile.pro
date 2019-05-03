SOURCES += \
    main.cpp

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losgEarthAnnotation
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losgEarthAnnotation
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losgEarthAnnotation

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losgEarthFeatures
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losgEarthFeatures
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losgEarthFeatures

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losgEarthSplat
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losgEarthSplat
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losgEarthSplat

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losgEarthSymbology
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losgEarthSymbology
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losgEarthSymbology

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64
