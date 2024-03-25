#pragma once

#include "../includes/include.h"

struct Message : QObject
{
    Message();
    ~Message();

    static Widget *window;
    static Button *ok;  
    static Text   *icon;
    static Text   *text;

    static void information(const String &__message);
    static void warning(const   String &__message);
    static void error(const String &__message);

    void close();
};