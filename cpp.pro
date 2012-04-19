#-------------------------------------------------
#
# Project created by QtCreator 2012-04-16T23:29:44
#
#-------------------------------------------------

QT       += core gui \
            opengl

TARGET = cpp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    engine.cpp \
    scene.cpp \
    camera.cpp \
    cube.cpp \
    player.cpp \
    light.cpp

HEADERS  += mainwindow.h \
    engine.h \
    scene.h \
    camera.h \
    cube.h \
    player.h \
    light.h

FORMS    += mainwindow.ui

RESOURCES += \
    ressources.qrc
