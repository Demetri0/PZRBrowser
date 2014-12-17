#-------------------------------------------------
#
# Project created by QtCreator 2014-11-16T03:06:54
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PZRBrowser
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

VERSION = 0.0.1.0
#Last digit:
# 0 - Pre-Alpha
# 1 - Alpha
# 2 - Beta
# 3 - Release Candidate
# 4 - Release

RC_ICONS = images/pzr.ico
QMAKE_TARGET_COMPANY = PZR
QMAKE_TARGET_PRODUCT = PZRBrowser
QMAKE_TARGET_DESCRIPTION = The orthodox browser from the channel a PZR
QMAKE_TARGET_COPYRIGHT = (CopyLeft) Demetri0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += resource.qrc

TRANSLATIONS += PZRBrowser_Ru_ru.ts
