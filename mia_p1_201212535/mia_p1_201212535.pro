QT += core
QT -= gui

CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clases/mbr.cpp \
    clases/mkdisk.cpp \
    clases/rmdisk.cpp \
        main.cpp \
	parser.cpp \
	scanner.cpp

DEFINES += QT_DEPRECATED_WARNINGS

DISTFILES += \
        lexico.l \
        parser.y

HEADERS += \
	clases/mbr.h \
	clases/mkdisk.h \
	clases/rmdisk.h \
	parser.h \
	scanner.h

SUBDIRS += \
        mia_p1_201212535.pro
