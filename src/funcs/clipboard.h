#pragma once

#include "../includes/include.h"
#include "../customes/button.h"
#include "../customes/text.h"
#include "../boxes/message.h"

struct Button;
struct Text;
struct Message;

struct Buffer : Object
{
    explicit Buffer(Widget *parent);

    Button          *clipboard;
    static String   cpTitle;
    static bool     isCurrentBufferTextFolder;
    
    static void     toBuffer(const String &text);
    static String   fromBuffer();
    void            showInformationFromClipboardSlot();
};
