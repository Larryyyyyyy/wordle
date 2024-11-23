QT       += core gui
QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gameplay.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    gameplay.h \
    widget.h

FORMS += \
    gameplay.ui \
    gameplay.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc

DISTFILES += \
    musics/t+pazolite - Squeaky Mind.mp3 \
    musics/t+pazolite - Squeaky Mind.mp3 \
    text/FourLevel.txt \
    text/SixLevel.txt \
    text/words.txt
