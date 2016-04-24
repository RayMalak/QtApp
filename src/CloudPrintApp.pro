#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T20:02:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CloudPrintApp
TEMPLATE = app


SOURCES += main.cpp\
    ui/mainhomepage.cpp \
    ui/mainfunctionpage.cpp \
    ui/printpagewidget.cpp \
    ui/numkeyboard.cpp \
    ui/maindialog.cpp

HEADERS  += \
    ui/mainhomepage.h \
    ui/mainfunctionpage.h \
    ui/printpagewidget.h \
    ui/numkeyboard.h \
    ui/maindialog.h

FORMS    += \
    ui/mainhomepage.ui \
    ui/mainfunctionpage.ui \
    ui/printpagewidget.ui \
    ui/numkeyboard.ui \
    ui/maindialog.ui

RESOURCES += \
    ui/image.qrc
