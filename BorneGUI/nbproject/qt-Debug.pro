# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = BorneGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjoutFontaine.cpp AjoutStationnement.cpp BorneGUI.cpp SupprimerBorne.cpp main.cpp
HEADERS += AjoutFontaine.h AjoutStationnement.h BorneGUI.h SupprimerBorne.h
FORMS += AjoutFontaine.ui AjoutStationnement.ui BorneGUI.ui SupprimerBorne.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += "../Tp3 Source" 
LIBS += "../Tp3 Source/dist/Debug/GNU-Linux/libtp3_source.a"  
