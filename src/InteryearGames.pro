TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
          Interface/menu.c \
          Interface/utils/input.c \
          Interface/utils/output.c \
          Interface/menus/reportMenu.c \
          Interface/menus/insertMenu.c \
          Interface/menus/autoMenu.c \
          Logic/logic.c \
          Logic/utils.c

HEADERS += \
          Interface/menu.h \
          Interface/utils/input.h \
          Interface/utils/output.h \
          Interface/utils/colors.h \
          Interface/menus/reportMenu.h \
          Interface/menus/insertMenu.h \
          Interface/menus/autoMenu.h \
          Logic/data.h \
          Logic/logic.h \
          Logic/utils.h
