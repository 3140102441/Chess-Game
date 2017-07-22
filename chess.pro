#-------------------------------------------------
#
# Project created by QtCreator 2016-07-06T23:02:48
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chess
TEMPLATE = app


SOURCES += main.cpp \
    View.cpp \
    choose.cpp \
    Model.cpp \
    ViewModel.cpp \
    Command/InitPlayerCmd.cpp \
    Command/MouseClickCmd.cpp \
    Command/MouseMoveCmd.cpp \
    Command/RegretCmd.cpp \
    mainview.cpp \
    Computer.cpp \
    Command/InitComputerCmd.cpp \
    Command/SetModeCmd.cpp

HEADERS  += \
    View.h \
    choose.h \
    Model.h \
    Common.h \
    ViewModel.h \
    Command/Command.h \
    Command/InitPlayerCmd.h \
    Command/MouseClickCmd.h \
    Command/MouseMoveCmd.h \
    Command/RegretCmd.h \
    mainview.h \
    Command/InitComputerCmd.h \
    Command/SetModeCmd.h

FORMS    += \
    View.ui \
    choose.ui \
    mainview.ui

RESOURCES += \
    image.qrc \
    image2.qrc
