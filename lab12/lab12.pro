QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    img/285628_O.jpg \
    img/VLC-Logo.png \
    img/cone-s-image-vlc-icon-transparent-png-137215.png \
    img/disk_icon.png \
    img/dot_icon.png \
    img/exit_icon.png \
    img/file_icon.png \
    img/filters_icon.png \
    img/free-icon-fast-forward-7881795.png \
    img/free-icon-rewind-7881840.png \
    img/mute_icon.png \
    img/pause.png \
    img/play-button-arrowhead.png \
    img/png-transparent-vlc-media-player-codec-logo-computer-file-cones-orange-media-player-product.png \
    img/settings_icon.png \
    img/stop.png \
    img/v_down_icon.png \
    img/v_up_icon.png \
    img/www.png

