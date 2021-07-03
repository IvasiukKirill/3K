QT += testlib
QT -= gui
QT += sql
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testfunc.cpp \
            functions.cpp


HEADERS += functions.h

