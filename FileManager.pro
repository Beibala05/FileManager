QT += core gui widgets

TARGET = fm

SOURCES += \
    src/app/main.cpp \
    src/app/ui.cpp \
    src/funcs/transitions.cpp \
    src/funcs/manager.cpp \
    src/boxes/add_file.cpp \
    src/boxes/add_folder.cpp \
    src/boxes/message.cpp \
    src/boxes/search.cpp \
    src/boxes/tips.cpp \
    src/funcs/remove.cpp \
    src/funcs/copy.cpp \
    src/funcs/paste.cpp \
    src/funcs/clipboard.cpp \
    src/customes/button.cpp \
    src/customes/text.cpp \

HEADERS += \
    src/app/ui.h \
	src/includes/include.h \
    src/funcs/transitions.h \
    src/funcs/manager.h \
    src/boxes/add_file.h \
    src/boxes/add_folder.h \
    src/boxes/message.h \
    src/boxes/search.h \
    src/boxes/tips.h \
    src/funcs/remove.h \
    src/funcs/copy.h \
    src/funcs/paste.h \
    src/funcs/clipboard.h \
    src/customes/button.h \
    src/customes/text.h \

DISTFILES += \
    styles/button.css \
    styles/manager.css \
    styles/text_edit.css \
    styles/text_label.css \
    styles/tips.css \
    styles/window.css \
    styles/widget.css \
    styles/button_ok.css \
    styles/button_cancel.css \

RESOURCES += \
    res/icons.qrc \

RC_ICONS += \
    res/logo.ico \