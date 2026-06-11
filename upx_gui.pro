QT       += core gui widgets network

TARGET = UPX_GUI
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

RC_ICONS = upx_Icon.ico

DESTDIR = $$PWD
