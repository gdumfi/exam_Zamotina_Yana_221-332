QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testfunc.cpp \
    ../setvetToStart/func_for_server.cpp \
    ../setvetToStart/main.cpp \
    ../setvetToStart/mytcpserver.cpp

SUBDIRS += \
    ../setvetToStart/setvetToStart.pro

HEADERS += \
    ../setvetToStart/func_for_server.h \
    ../setvetToStart/mytcpserver.h
