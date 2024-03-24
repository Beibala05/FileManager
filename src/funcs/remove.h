#pragma once

#include "../includes/include.h"
#include "manager.h"

struct Manager;

struct Remove : QObject
{
    Remove(Widget *centralWidget, ListWidget *fileManager);

    Text          *removeTitle;
    Button        *remove;
    ListWidget    *m_fileManager;

    void crossTextFromFileManagerSlot();
    void removeItemSlot();
    void removeItem();
};
