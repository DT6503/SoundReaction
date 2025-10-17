QT       += core gui
#
QT += core gui sql
QT += core gui widgets multimedia
QT += core gui widgets sql
QT += sql
QT += gui network core multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form.cpp \
    hello.cpp \
    main.cpp \
    play.cpp \
    registration.cpp

HEADERS += \
    form.h \
    hello.h \
    play.h \
    registration.h

FORMS += \
    form.ui \
    hello.ui \
    play.ui \
    registration.ui

FORMS += form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
