QT       += core gui widgets network

TARGET = UPX_GUI_Static
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

RC_ICONS = upx_Icon.ico

DESTDIR = $$PWD

# 静态链接配置
CONFIG += static
QTPLUGIN += qwindows
QMAKE_LFLAGS += -static
QMAKE_CXXFLAGS += -static
LIBS += -luser32 -lgdi32 -lcomdlg32 -lole32 -luuid -lwinmm -lws2_32 -ladvapi32 -lshell32 -lversion
