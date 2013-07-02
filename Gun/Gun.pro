#-------------------------------------------------
#
# Project created by QtCreator 2013-03-22T00:11:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gun
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gun.cpp \
    missle.cpp \
    target.cpp

HEADERS  += mainwindow.h \
    gun.h \
    missle.h \
    target.h

FORMS    += mainwindow.ui
