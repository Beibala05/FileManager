#include "tips.h"

Widget *Tips::window = nullptr;
Label  *Tips::text   = nullptr;

Tips::Tips(Widget *parent)
{
    File widgetStyle("../styles/widget.css");
	widgetStyle.open(QIODevice::ReadOnly);
	String styleWidget = widgetStyle.readAll();
	widgetStyle.close();

    File labelStyle("../styles/tips.css");
	labelStyle.open(QIODevice::ReadOnly);
	String styleLabel = labelStyle.readAll();
	labelStyle.close();

    window = new Widget(parent);
    window->setStyleSheet(styleWidget);

    text = new Label(window);
    text->setFont(Font("Arial", 14));
    text->setAlignment(Qt::AlignCenter);
    text->setStyleSheet(styleLabel);

    window->hide();
}

void Tips::show(String textFromButton, int x, int y, int w, int _w)
{
    int x_axis = x + (_w / 2) - (w / 2);

    if (x_axis < 0)
        window->setGeometry(x, y + 45, w, 35);
    else
        window->setGeometry(x_axis, y + 45, w, 35);
    text->setGeometry(0, 0, w, 35);
    text->setText(textFromButton);

    window->show();
}

void Tips::hide()
{
    window->hide();
}