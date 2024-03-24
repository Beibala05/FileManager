QT += core gui widgets

TARGET = fm

SOURCES += \
    src/app/main.cpp \
    src/app/ui.cpp \
    src/funcs/transitions.cpp \
    src/funcs/manager.cpp \
    src/boxes/text_editor.cpp \
    src/boxes/create_dialog.cpp \
    src/funcs/remove.cpp \

HEADERS += \
    src/app/ui.h \
	src/includes/include.h \
    src/funcs/transitions.h \
    src/funcs/manager.h \
    src/boxes/text_editor.h \
    src/boxes/create_dialog.h \
    src/funcs/remove.h \
    icons/icons_pack.h \