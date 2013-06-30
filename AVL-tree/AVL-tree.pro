#-------------------------------------------------
#
# Project created by QtCreator 2013-06-19T19:41:48
#
#-------------------------------------------------

QT       -= gui

TARGET = AVL-tree
TEMPLATE = lib

DEFINES += AVLTREE_LIBRARY

SOURCES += avltree.cpp \
    node.cpp

HEADERS += avltree.h\
        avl-tree_global.h \
    node.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
