#-------------------------------------------------
#
# Project created by QtCreator 2016-01-05T15:51:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlackAndWhite
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    reversi.cpp

HEADERS  += mainwindow.h \
    view.h \
    reversi.h

RESOURCES += \
    src.qrc
