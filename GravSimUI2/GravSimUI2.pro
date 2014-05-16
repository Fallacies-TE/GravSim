#-------------------------------------------------
#
# Project created by QtCreator 2014-05-10T19:35:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GravSimUI2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addspaceobject.cpp \
    editspaceobject.cpp \
    deletespaceobject.cpp \
    incorrectformat.cpp

HEADERS  += mainwindow.h \
    addspaceobject.h \
    editspaceobject.h \
    deletespaceobject.h \
    incorrectformat.h

FORMS    += mainwindow.ui \
    addspaceobject.ui \
    editspaceobject.ui \
    deletespaceobject.ui \
    incorrectformat.ui

