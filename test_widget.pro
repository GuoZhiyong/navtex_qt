include(3rdparty/qextserialport/src/qextserialport.pri)

SOURCES += \
    main.cpp \
    FlowLayout.cpp \
    control_panel.cpp \
    panel_info.cpp \
    panel_about.cpp \
    panel_serial.cpp \
    panel_item.cpp \
    panel_setup.cpp \
    panel_detail.cpp

HEADERS += \
    FlowLayout.hpp \
    control_panel.h \
    panel_info.h \
    panel_about.h \
    panel_serial.h \
    panel_item.h \
    panel_setup.h \
    panel_detail.h

RESOURCES += \
    res.qrc

FORMS += \
    navtex_item.ui \
    listwidget_item.ui \
    control_panel.ui \
    panel_info.ui \
    panel_about.ui \
    panel_serial.ui \
    panel_item.ui \
    panel_setup.ui \
    panel_detail.ui
