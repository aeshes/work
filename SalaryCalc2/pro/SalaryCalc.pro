QT += core sql
QT -= gui

CONFIG += c++11

TARGET = SalaryCalc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    db.cpp \
    employee.cpp \
    salary.cpp

HEADERS += \
    db.h \
    employee.h \
    salary.h
