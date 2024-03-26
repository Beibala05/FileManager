#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"

struct Manager;

struct AddFolder : QObject
{
    AddFolder(Widget *centralWidget, ListWidget *fileManager);
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
