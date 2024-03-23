#pragma once

#include "../includes/include.h"

struct TextEditor : QObject
{
    TextEditor();
    ~TextEditor();

    Widget   *window;
    TextEdit *editor;
    Button   *save;
    Button   *increasSize; // +
    Button   *reduceSize;  // -
    String    text;
    String    path;
    int       textSize = 14;

    void print();
    void show(const String &path);
    void saveSlot();
    void increasSizeSlot();
    void reduceSizeSlot();
};
