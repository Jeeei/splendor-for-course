#-------------------------------------------------
#
# Project created by QtCreator 2021-04-06T21:27:02
#
#-------------------------------------------------
QT       += core gui
QT  +=  multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
UI_DIR=./UI
CONFIG += resources_big
TARGET = splendor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Card.cpp \
    Noble.cpp \
    Player.cpp \
    Table1.cpp \
    choosesurface.cpp \
    end1.cpp \
    end2.cpp \
    koucard.cpp \
        main.cpp \
        gameinterface.cpp \
    mainsurface.cpp \
    opponent_have.cpp \
    pickcard.cpp \
    pickcoin.cpp \
    richpeople.cpp \
    rightclick.cpp \
    rightrule.cpp \
    rule.cpp \
    save.cpp \
    whethercontinue.cpp

HEADERS += \
    Splendor.h \
    choosesurface.h \
    end1.h \
    end2.h \
        gameinterface.h \
    koucard.h \
    mainsurface.h \
    opponent_have.h \
    pickcard.h \
    pickcoin.h \
    richpeople.h \
    rightclick.h \
    rightrule.h \
    rule.h \
    whethercontinue.h

FORMS += \
    choosesurface.ui \
    end1.ui \
    end2.ui \
        gameinterface.ui \
    koucard.ui \
    mainsurface.ui \
    opponent_have.ui \
    pickcard.ui \
    pickcoin.ui \
    richpeople.ui \
    rightclick.ui \
    rightrule.ui \
    rule.ui \
    whethercontinue.ui

RESOURCES += \
    pictures.qrc \
    music.qrc
