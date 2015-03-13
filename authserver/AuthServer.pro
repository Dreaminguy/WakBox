#---------------------------
# QT include
#---------------------------

QT       += core network sql
QT       -= gui

#---------------------------
# basic configuration
#---------------------------

TARGET = authserver #target app name
CONFIG   += console #is a console
CONFIG   -= app_bundle #not need the app bundle

TEMPLATE = app #app template

#---------------------------
#  build configuration
#---------------------------

release : DESTDIR = $${WAKBOX_TOP_DIR}/build/release
debug : DESTDIR = $${WAKBOX_TOP_DIR}/build/debug

OBJECTS_DIR = $${WAKBOX_TOP_DIR}/build/.obj/$$TARGET
MOC_DIR = $${WAKBOX_TOP_DIR}/build/.moc/$$TARGET
RCC_DIR = $${WAKBOX_TOP_DIR}/build/.qrc/$$TARGET
UI_DIR = $${WAKBOX_TOP_DIR}/build/.ui/$$TARGET

#---------------------------
# library and dep
#---------------------------

# openssl
unix {
   PKGCONFIG += openssl
}

win32 {
    LIBS += -LC:/OpenSSL-Win32/lib -lubsec
    LIBS += -LC:/OpenSSL-Win32/lib -lssleay32
    LIBS += -LC:/OpenSSL-Win32/lib -llibeay32
    INCLUDEPATH += C:/OpenSSL-Win32/include
}

# shared
LIBS += -L../shared -l"$$DESTDIR/shared"

#----------------------------
# include file
#----------------------------

INCLUDEPATH += . ../shared
DEPENDPATH  += . ../shared


#---------------------------
# project file
#---------------------------

SOURCES += main.cpp \
    AuthServer.cpp \
    AuthSession.cpp

HEADERS += AuthServer.h \
    AuthSession.h
