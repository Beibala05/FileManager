cmake_minimum_required(VERSION 3.14)
project(fm VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(SOURCES 
    src/app/main.cpp
    src/app/ui.cpp
    src/funcs/transitions.cpp
    src/funcs/manager.cpp
    src/boxes/add_file.cpp
    src/boxes/add_folder.cpp
    src/boxes/message.cpp
    src/boxes/search.cpp
    src/boxes/tips.cpp
    src/funcs/remove.cpp
    src/funcs/copy.cpp
    src/funcs/paste.cpp
    src/funcs/clipboard.cpp
    src/customes/button.cpp
    src/customes/text.cpp
)

set(HEADERS
    src/app/ui.h
    src/includes/include.h
    src/funcs/transitions.h
    src/funcs/manager.h
    src/boxes/add_file.h
    src/boxes/add_folder.h
    src/boxes/message.h
    src/boxes/search.h
    src/boxes/tips.h
    src/funcs/remove.h
    src/funcs/copy.h
    src/funcs/paste.h
    src/funcs/clipboard.h
    src/customes/button.h
    src/customes/text.h
)

qt5_add_resources(RESOURCES res/icons.qrc)

set(ICON_SOURCES res/logo.ico)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES} ${ICON_SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)


set(CSS_FILES
    styles/button.css
    styles/manager.css
    styles/text_edit.css
    styles/text_label.css
    styles/tips.css
    styles/window.css
    styles/widget.css
    styles/button_ok.css
    styles/button_cancel.css
)

foreach(CSS_FILE ${CSS_FILES})
    configure_file(${CSS_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${CSS_FILE} COPYONLY)
endforeach()
