#pragma once

#include "../includes/include.h"

struct Tips
{
    explicit Tips(Widget *parent);

    static Widget *window;
    static Label  *text;

    static void show(String textFromButton, int x, int y, int w);
    static void hide();
};