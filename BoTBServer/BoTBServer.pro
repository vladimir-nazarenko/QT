#-------------------------------------------------
#
# Project created by QtCreator 2013-06-29T20:59:15
#
#-------------------------------------------------

QT       += core network declarative help

QT       -= gui

TARGET = BoTBServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    server.cpp \
    timershell.cpp

HEADERS += \
    server.h \
    timershell.h
