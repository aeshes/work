QT += core sql
QT += gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas

CONFIG += c++11
CONFIG += precompile_header

PRECOMPILED_HEADER = odb-inc.hxx

TARGET = SalaryCalc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    salary.cpp \
    mainwindow.cpp \
    employee-odb.cxx \
    db.cxx \
    employee.cxx

HEADERS += \
    mainwindow.h \
    employee-odb.hxx \
    odb-inc.hxx \
    db.hxx \
    repository.hxx \
    salary.hxx \
    employee.hxx

FORMS += \
    mainwindow.ui

unix|win32: LIBS += -lodb-2.4

unix|win32: LIBS += -lodb-sqlite-2.4
