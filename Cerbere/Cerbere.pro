#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T21:33:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cerbere
TEMPLATE = app

# Add SFML window library, where Joystick is located
LIBS += -lsfml-window



SOURCES += main.cpp\
    xinputGamepad.cpp \
    windowmanette.cpp \
    mainwindow.cpp

HEADERS  += \
    xqTblMgr.h \
    xinputGamepad.h \
    windowmanette.h \
    mainwindow.h \
    ressource.h

FORMS    += \
    windowmanette.ui \
    mainwindow.ui
