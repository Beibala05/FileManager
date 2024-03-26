#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"

struct Manager;

struct AddFile : QObject
{
    AddFile(Widget *centralWidget, ListWidget *fileManager);
    ~AddFile();

    Widget      *window;
    LineEdit    *title;
    Button      *createFile;
    Button      *cancel;
    Button      *addFile;
    ListWidget  *m_fileManager;
    String       m_path;

    void addShowFileAddSlot();
    void createFileSlot();
    void cancelSlot();
};
