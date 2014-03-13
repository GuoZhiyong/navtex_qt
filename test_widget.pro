include(3rdparty/qextserialport/src/qextserialport.pri)

QT+=sql

CONFIG += qtestlib

SOURCES += \
    main.cpp \
    FlowLayout.cpp \
    panel_info.cpp \
    panel_about.cpp \
    panel_serial.cpp \
    panel_item.cpp \
    panel_setup.cpp \
    panel_detail.cpp \
    mainwin.cpp \
    naxtexitem.cpp

HEADERS += \
    FlowLayout.hpp \
    panel_info.h \
    panel_about.h \
    panel_serial.h \
    panel_item.h \
    panel_setup.h \
    panel_detail.h \
    mainwin.h \
    navtexitem.h

RESOURCES += \
    res.qrc

FORMS += \
    panel_about.ui \
    panel_serial.ui \
    panel_item.ui \
    panel_setup.ui \
    panel_detail.ui
