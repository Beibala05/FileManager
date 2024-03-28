#pragma once

#include "../includes/include.h"
#include "../customes/button.h"
#include "../customes/text.h"
#include "manager.h"

struct Manager;
struct Button;
struct Text;

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
