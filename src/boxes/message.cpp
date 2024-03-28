#include "message.h"

Widget *Message::window = nullptr;
Button *Message::ok     = nullptr;
Text   *Message::icon;
Text   *Message::text;

Message::Message()
{
    File buttonOkStyle("../styles/button_ok.css");
	buttonOkStyle.open(QIODevice::ReadOnly);
	String styleButtonOk = buttonOkStyle.readAll();
	buttonOkStyle.close();

    File buttonCancelStyle("../styles/button_cancel.css");
	buttonCancelStyle.open(QIODevice::ReadOnly);
	String styleButtonCancel = buttonCancelStyle.readAll();
	buttonCancelStyle.close();

    File widgetStyle("../styles/widget.css");
	widgetStyle.open(QIODevice::ReadOnly);
	String styleWidget = widgetStyle.readAll();
	widgetStyle.close();

    window = new Widget();
    window->setFixedSize(MESSAGE_START_WIDTH, MESSAGE_START_HEIGHT);
    window->setWindowModality(Qt::ApplicationModal);
    window->setStyleSheet(styleWidget);

    icon = new Text(window);  
    icon->setGeometry(10, 20, 0, 0);

    text = new Text(window);
    text->setGeometry(125, 5, 350, 50);
    text->setFont(Font("Arial", 13));

    ok = new Button("OK", window);
    ok->setGeometry(MESSAGE_START_WIDTH - 85, MESSAGE_START_HEIGHT - 45, 80, 40);
    ok->setFont(Font("Arial", 14));
    ok->setStyleSheet(styleButtonOk);

    QObject::connect(ok, &Button::clicked, this, &Message::close);
}

Message::~Message()
{
    delete window;
}

void Message::information(const String &__message, const String &windowTitle)
{
    Pixmap pixmap("../res/message_icons/information.png");
    window->setWindowTitle(windowTitle);    
    icon->setPixmap(pixmap);
    icon->resize(pixmap.size());
    text->setText(Message::parse(__message));

    window->show();
}

void Message::warning(const String &__message, const String &windowTitle)
{
    Pixmap pixmap("../res/message_icons/warning.png");
    window->setWindowTitle(windowTitle);    
    icon->setPixmap(pixmap);
    icon->resize(pixmap.size());
    text->setText(Message::parse(__message));

    window->show();
}

void Message::error(const String &__message, const String &windowTitle)
{
    Pixmap pixmap("../res/message_icons/error.png");
    window->setWindowTitle(windowTitle);    
    icon->setPixmap(pixmap);
    icon->resize(pixmap.size());
    text->setText(Message::parse(__message));

    window->show();
}

void Message::close()
{
    window->hide();
}

String Message::parse(const String &__message)
{
    String res = __message;
    int iter = 1;
    int _size = 5;

    int size = res.size() / 36;

    for (int i = 0; i < size; ++i)
    {
        res.insert(36 * iter, "\n");
        ++iter;

        if (iter > 3)
        {
            text->setGeometry(115, 5, 350, 50 + _size);
            window->setFixedSize(MESSAGE_START_WIDTH, MESSAGE_START_HEIGHT + _size);
            ok->setGeometry(MESSAGE_START_WIDTH - 95, MESSAGE_START_HEIGHT - 45 + _size, 80, 40);
            _size += 7;
        }
    }
    
    return res;
}