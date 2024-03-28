#include "text.h"

Text::Text(Widget *parent)
{
    setAttribute(Qt::WA_Hover);
    this->setParent(parent);
}

void Text::enterEvent(Event *event)
{
    if (!textForTip.isEmpty())
    {
        Tips::show(textForTip, this->pos().x(), this->pos().y(), 400);
    }
    Label::enterEvent(event);
}

void Text::leaveEvent(Event *event)
{
    if (!textForTip.isEmpty())
    {
        Tips::hide();
    }
    Label::leaveEvent(event);
}

void Text::setTextForTip(String text)
{
    textForTip = text;
}