#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"
#include "../customes/button.h"

struct Manager;
struct Button;

struct AddFile : Object
{
    AddFile(Widget *parent, ListWidget *fileManager);
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
