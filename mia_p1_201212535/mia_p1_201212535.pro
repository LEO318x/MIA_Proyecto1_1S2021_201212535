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
    clases/exec.cpp \
    clases/fdisk.cpp \
    clases/funciones.cpp \
    clases/login.cpp \
    clases/logout.cpp \
    clases/mkdisk.cpp \
    clases/mkfs.cpp \
    clases/mount.cpp \
    clases/pausa.cpp \
    clases/rep.cpp \
    clases/rmdisk.cpp \
    clases/unmount.cpp \
        main.cpp \
	parser.cpp \
	scanner.cpp

DEFINES += QT_DEPRECATED_WARNINGS

DISTFILES += \
        lexico.l \
        parser.y

HEADERS += \
	clases/exec.h \
	clases/fdisk.h \
	clases/funciones.h \
	clases/login.h \
	clases/logout.h \
	clases/mkdisk.h \
	clases/mkfs.h \
	clases/mount.h \
	clases/pausa.h \
	clases/rep.h \
	clases/rmdisk.h \
	clases/unmount.h \
	parser.h \
	scanner.h

SUBDIRS += \
        mia_p1_201212535.pro
