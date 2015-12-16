#-------------------------------------------------
#
# Project created by QtCreator 2015-12-16T10:43:17
#
#-------------------------------------------------

QT       += core
QT       += declarative webkit
contains(QT_VERSION, ^5.*) {
       QT += webkitwidgets
   }
QT       += gui

CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

TARGET = test_qwebjs

SOURCES += main.cpp \
    gui.cpp

HEADERS += \
    gui.h

DISTFILES += \
    test.html \
    test.js

deployguifiles.files = $$_PRO_FILE_PWD_/$$DISTFILES
deployguifiles.path =$$OUT_PWD

INSTALLS += deployguifiles

DEFINES += TESTDIR=\\\"$${_PRO_FILE_PWD_}\\\"

message($${_PRO_FILE_PWD_})
