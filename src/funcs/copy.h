#pragma once

#include "../includes/include.h"
#include "manager.h"
#include "buffer.h"

struct Manager;
struct Buffer;

struct Copy : QObject
{
    Copy(Widget* centralWidget, Text *copyText);

    Button *copy;
    Text   *m_copyText;

    void clickSlot();
};