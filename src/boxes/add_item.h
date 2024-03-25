#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"

struct Manager;

struct Create : QObject
{
    Create(Widget *centralWidget, ListWidget *fileManager);
    ~Create();

    Widget      *window;
    LineEdit    *title;
    Button      *create;
    Button      *cancel;
    Button      *add;
    ListWidget  *m_fileManager;
    String       m_path;

    void addShowSlot();
    void createSlot();
    void cancelSlot();
};
