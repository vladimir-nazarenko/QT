#-------------------------------------------------
#
# Project created by QtCreator 2013-07-02T00:51:05
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    server.h \
    client.h

FORMS    += mainwindow.ui
