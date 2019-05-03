SOURCES += \
    main.cpp \

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/release/ -losgEarth
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib64/debug/ -losgEarth
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib64/ -losgEarth

INCLUDEPATH += $$PWD/../../../../../usr/local/lib64
DEPENDPATH += $$PWD/../../../../../usr/local/lib64
