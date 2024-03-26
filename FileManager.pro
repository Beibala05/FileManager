QT += core gui widgets

TARGET = fm

SOURCES += \
    src/app/main.cpp \
    src/app/ui.cpp \
    src/funcs/transitions.cpp \
    src/funcs/manager.cpp \
    src/boxes/text_editor.cpp \
    src/boxes/add_file.cpp \
    src/boxes/add_folder.cpp \
    src/boxes/message.cpp \
    src/funcs/remove.cpp \
    src/funcs/copy.cpp \
    src/funcs/paste.cpp \
    src/funcs/buffer.cpp \

HEADERS += \
    src/app/ui.h \
	src/includes/include.h \
    src/funcs/transitions.h \
    src/funcs/manager.h \
    src/boxes/text_editor.h \
    src/boxes/add_file.h \
    src/boxes/add_folder.h \
    src/boxes/message.h \
    src/funcs/remove.h \
    src/funcs/copy.h \
    src/funcs/paste.h \
    src/funcs/buffer.h \