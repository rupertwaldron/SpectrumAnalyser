QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

requires(qtHaveModule(multimedia))

CONFIG += c++2a

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = QtSpecAnalyserCPP

SOURCES += \
    audiogenerator.cpp \
    audiogeneratoriodevice.cpp \
    generator.cpp \
    main.cpp \
    mainwindow.cpp \
    plotter.cpp \
    renderscreen.cpp

HEADERS += \
    audiogenerator.h \
    audiogeneratoriodevice.h \
    generator.h \
    mainwindow.h \
    plotter.h \
    renderscreen.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
