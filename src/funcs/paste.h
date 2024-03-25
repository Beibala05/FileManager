#pragma once

#include "../includes/include.h"
#include "../boxes/message.h"
#include "manager.h"
#include "buffer.h"

struct Manager;
struct Buffer;
struct Message;

struct Paste : QObject
{
    Paste(Widget* centralWidget, ListWidget *fileManager);

    Button      *paste;
    ListWidget  *m_fileManager;

    void clickSlot();
};
