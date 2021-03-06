#-------------------------------------------------
#
# Project created by QtCreator 2016-05-17T21:30:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RiskGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    country.cpp \
    card.cpp \
    player.cpp \
    game.cpp \
    attack.cpp \
    reinforce.cpp \
    deck.cpp \
    handwindow.cpp \
    errordialog.cpp

QMAKE_CXXFLAGS += -std=c++11
HEADERS  += mainwindow.h \
    country.h \
    card.h \
    player.h \
    game.h \
    attack.h \
    reinforce.h \
    deck.h \
    handwindow.h \
    errordialog.h

FORMS    += mainwindow.ui \
    handwindow.ui \
    errordialog.ui

RESOURCES += \
    resources.qrc
