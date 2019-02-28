#-------------------------------------------------
#
# Project created by QtCreator 2018-10-14T15:29:55
#
#-------------------------------------------------

QT       += core gui
# 添加串口通信相关的库;
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = control_3
TEMPLATE = app


SOURCES += main.cpp\
        control.cpp

HEADERS  += control.h

FORMS    += control.ui

RC_ICONS = hit.ico
