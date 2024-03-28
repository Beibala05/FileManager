#pragma once

#include "../includes/include.h"
#include "../boxes/message.h"
#include "../customes/button.h"
#include "manager.h"
#include "buffer.h"

struct Manager;
struct Buffer;
struct Message;
struct Button;

struct Paste : QObject
{
    Paste(Widget* centralWidget, ListWidget *fileManager);

    Button      *paste;
    ListWidget  *m_fileManager;

    void clickSlot();
};
