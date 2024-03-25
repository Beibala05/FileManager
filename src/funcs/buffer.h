#pragma once

#include "../includes/include.h"

struct Buffer
{
    explicit Buffer(Widget *centralWidget);

    static Text    *buffer;
    static String   cpTitle;
    static bool     isCurrentBufferTextFolder;
    
    static void     toBuffer(const String &text);
    static String   fromBuffer();
};
