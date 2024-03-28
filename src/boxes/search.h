#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"
#include "message.h" 
#include "../customes/button.h"

struct Manager;
struct Button;

struct Search : Object
{
    Search(Widget *parent, ListWidget *fileManager);
    ~Search();

    Widget      *window;
    LineEdit    *title;
    Button      *search;
    Button      *cancel;
    Button      *serchButton;
    ListWidget  *m_fileManager;
    bool         isSearch = false;

    void showSlot();
    void searchButtonSlot();
    void searchLocal();
    void searchCancel();
    void cancelSlot();
};