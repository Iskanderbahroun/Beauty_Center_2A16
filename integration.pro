QT        += core gui sql core network multimedia multimediawidgets charts widgets serialport printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    connection.cpp \
    employe.cpp \
    fournisseur.cpp \
    historique.cpp \
    main.cpp \
    mainwindow.cpp \
    materiels.cpp \
    offre.cpp \
    produitcosmetiques.cpp \
    smtp.cpp \
    statistique.cpp \
    statistiques.cpp \
    stats.cpp \
    video.cpp

HEADERS += \
    client.h \
    connection.h \
    employe.h \
    fournisseur.h \
    historique.h \
    mainwindow.h \
    materiels.h \
    offre.h \
    produitcosmetiques.h \
    smtp.h \
    statistique.h \
    statistiques.h \
    stats.h \
    video.h

FORMS += \
    mainwindow.ui \
    statistique.ui \
    statistiques.ui \
    stats.ui \
    video.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc