#include "button.h"

Button::Button(Widget *parent)
{
    setAttribute(Qt::WA_Hover);
    this->setParent(parent);
    this->textForTip = textForTip;
}

Button::Button(String text, Widget *parent)
{
    setAttribute(Qt::WA_Hover);
    this->setParent(parent);
    this->setText(text);
    this->textForTip = textForTip;
}

void Button::enterEvent(Event *event)
{
    if (!textForTip.isEmpty())
    {
        Tips::show(textForTip, this->pos().x(), this->pos().y(), textForTip.size() * 12, this->width());
    }
    PushButton::enterEvent(event);
}

void Button::leaveEvent(Event *event)
{
    if (!textForTip.isEmpty())
    {
        Tips::hide();
    }
    PushButton::leaveEvent(event);
}

void Button::setTextForTip(String text)
{
    textForTip = text;
}