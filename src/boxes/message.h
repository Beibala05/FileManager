#pragma once

#include "../includes/include.h"
#include "../customes/button.h"
#include "../customes/text.h"

struct Button;
struct Text;

struct Message : Object
{
    Message();
    ~Message();

    static Widget *window;
    static Button *ok;  
    static Text   *icon;
    static Text   *text;

    static void information(const String &__message, const String &windowTitle = "Information");
    static void warning(const String &__message, const String &windowTitle = "Warning");
    static void error(const String &__message, const String &windowTitle = "Error");
    void        close();

    private: static String parse(const String &__message);
};