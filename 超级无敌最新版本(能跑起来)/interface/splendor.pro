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
        main.cpp \
        gameinterface.cpp \
    mainsurface.cpp \
<<<<<<< HEAD \
    save.cpp \
    start.cpp
    rule.cpp \
    save.cpp
=======
    pickcard.cpp \
    pickcoin.cpp \
    rule.cpp
>>>>>>> 6b4578099f349b9a0017a0831df40d5e4ffeb174

HEADERS += \
    Splendor.h \
        gameinterface.h \
    mainsurface.h \
    pickcard.h \
    pickcoin.h \
    rule.h

FORMS += \
        gameinterface.ui \
    mainsurface.ui \
    pickcard.ui \
    pickcoin.ui \
    rule.ui

RESOURCES += \
    pictures.qrc \
    music.qrc
