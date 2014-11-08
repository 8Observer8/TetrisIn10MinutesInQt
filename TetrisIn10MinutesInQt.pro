#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T17:32:32
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TetrisIn10MinutesInQt
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Well.cpp \
    Tetromino.cpp \
    Painter.cpp \
    Game.cpp \
    Scene.cpp

HEADERS  += MainWindow.h \
    Well.h \
    Tetromino.h \
    Painter.h \
    Game.h \
    Scene.h

FORMS    += MainWindow.ui
