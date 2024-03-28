#pragma once

#include "../includes/include.h"
#include "../customes/button.h"
#include "../customes/text.h"
#include "manager.h"
#include "buffer.h"

struct Manager;
struct Buffer;
struct Button;
struct Text;

struct Copy : QObject
{
    Copy(Widget* centralWidget, Text *copyText);

    Button *copy;
    Text   *m_copyText;

    void clickSlot();
};