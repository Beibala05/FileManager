#pragma once

#include "../includes/include.h"
#include "../boxes/tips.h"

struct Tips;

struct Button : PushButton
{
    explicit Button(Widget *parent);    
    Button(String text, Widget *parent);

    String textForTip;

    void setTextForTip(String text);
    protected: void enterEvent(Event *event) override;
    protected: void leaveEvent(Event *event) override;
};