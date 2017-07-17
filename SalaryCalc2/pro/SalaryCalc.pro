QT += core sql
QT += gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

CONFIG += c++11

TARGET = SalaryCalc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    db.cpp \
    employee.cpp \
    salary.cpp \
    repository.cpp \
    mainwindow.cpp \
    constants.cpp

HEADERS += \
    db.h \
    employee.h \
    salary.h \
    repository.h \
    mainwindow.h \
    constants.h

FORMS += \
    mainwindow.ui
