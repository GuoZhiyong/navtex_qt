include(3rdparty/qextserialport/src/qextserialport.pri)

QT+=sql

CONFIG += qtestlib

TRANSLATIONS=chn.ts \
            eng.ts

SOURCES += \
    main.cpp \
    FlowLayout.cpp \
    panel_info.cpp \
    panel_about.cpp \
    panel_item.cpp \
    panel_setup.cpp \
    panel_detail.cpp \
    mainwin.cpp \
    common.cpp \
    eventspy.cpp

HEADERS += \
    FlowLayout.hpp \
    panel_info.h \
    panel_about.h \
    panel_item.h \
    panel_setup.h \
    panel_detail.h \
    mainwin.h \
    common.h \
    eventspy.h

RESOURCES += \
    res.qrc

FORMS +=

TARGET = navtex

