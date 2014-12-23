#-------------------------------------------------
#
# Project created by QtCreator 2014-12-23T02:34:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageManager
TEMPLATE = app


SOURCES += main.cpp\
        imagemng.cpp \
    adddirwidget.cpp \
    adddirdialog.cpp

HEADERS  += imagemng.h \
    adddirwidget.h \
    adddirdialog.h

FORMS    += imagemng.ui \
    adddirwidget.ui \
    adddirdialog.ui
