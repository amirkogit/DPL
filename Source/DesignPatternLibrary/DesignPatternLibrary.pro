QT += core
QT -= gui

CONFIG += c++11

TARGET = DesignPatternLibrary
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Preliminaries/srp.cpp \
    Preliminaries/ocp.cpp \
    Preliminaries/isp.cpp \
    Preliminaries/lsp.cpp \
    Builder/person.cpp \
    Builder/personbuilder.cpp \
    Builder/buildertest.cpp \
    Preliminaries/preliminariestest.cpp \
    Builder/HTML/htmlbuilder.cpp \
    Builder/HTML/htmlelement.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    Builder/person.h \
    Builder/personbuilder.h \
    Builder/personaddressbuilder.h \
    Builder/personjobbuilder.h \
    Builder/buildertest.h \
    Preliminaries/preliminariestest.h \
    Builder/HTML/htmlbuilder.h \
    Builder/HTML/htmlelement.h
