#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"
#include "message.h"

struct Manager;

struct Search : QObject
{
    Search(Widget *centralWidget, ListWidget *fileManager);
    ~Search();

    Widget      *window;
    LineEdit    *title;
    Button      *search;
    Button      *cancel;
    Button      *serchButton;
    ListWidget  *m_fileManager;

    void showSlot();
    void searchSlot();
    void cancelSlot();
};