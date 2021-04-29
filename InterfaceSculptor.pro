QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FiguraGeometrica.cpp \
    Sculptor.cpp \
    cutBox.cpp \
    cutEllipsoid.cpp \
    cutSphere.cpp \
    cutVoxel.cpp \
    dialog.cpp \
    interpretador.cpp \
    main.cpp \
    mainwindow.cpp \
    outSphere.cpp \
    plotter.cpp \
    putBox.cpp \
    putEllipsoid.cpp \
    putSphere.cpp \
    putVoxel.cpp

HEADERS += \
    FiguraGeometrica.h \
    Sculptor.h \
    cutBox.h \
    cutEllipsoid.h \
    cutSphere.h \
    cutVoxel.h \
    dialog.h \
    interpretador.h \
    mainwindow.h \
    outSphere.h \
    plotter.h \
    putBox.h \
    putEllipsoid.h \
    putSphere.h \
    putVoxel.h \
    voxel.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
