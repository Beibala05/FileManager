#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"
#include "../customes/button.h"

struct Manager;
struct Button;

struct AddFolder : Object
{
    AddFolder(Widget *parent, ListWidget *fileManager);
    ~AddFolder();

    Widget      *window;
    LineEdit    *title;
    Button      *createFolder;
    Button      *cancel;
    Button      *addFolder;
    ListWidget  *m_fileManager;
    String       m_path;

    void addShowFolderSlot();
    void createFolderSlot();
    void cancelSlot();
};
