QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    character.cpp \
    fight.cpp \
    fightwindow.cpp \
    main.cpp \
    dft.cpp \
    mybutton.cpp \
    plot.cpp \
    view.cpp

HEADERS += \
    character.h \
    dft.h \
    fight.h \
    fightwindow.h \
    mybutton.h \
    plot.h \
    view.h

FORMS += \
    dft.ui \
    fightwindow.ui \
    plot.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsc.qrc
