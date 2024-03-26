#include "message.h"

Widget *Message::window = nullptr;
Button *Message::ok     = nullptr;
Text   *Message::icon;
Text   *Message::text;

Message::Message()
{
    window = new Widget();
    window->setFixedSize(MESSAGE_START_WIDTH, MESSAGE_START_HEIGHT);
    window->setWindowModality(Qt::ApplicationModal);

    icon = new Text(window);  
    icon->setGeometry(0, 0, 0, 0);

    text = new Text(window);
    text->setGeometry(105, 5, 350, 50);
    text->setFont(Font("Arial", 13));

    ok = new Button("OK", window);
    ok->setGeometry(MESSAGE_START_WIDTH - 85, MESSAGE_START_HEIGHT - 45, 80, 40);
    ok->setFont(Font("Arial", 14));

    QObject::connect(ok, &Button::clicked, this, &Message::close);
}

Message::~Message()
{
    delete window;
}

void Message::information(const String &__message)
{
    Pixmap pixmap("../res/message_icons/information.png");
    window->setWindowTitle("Information");    
    icon->setPixmap(pixmap);
    icon->resize(pixmap.size());
    text->setText(Message::parse(__message));

    window->show();
}

void Message::warning(const String &__message)
{
    Pixmap pixmap("../res/message_icons/warning.png");
    window->setWindowTitle("Warning");    
    icon->setPixmap(pixmap);
    icon->resize(pixmap.size());
    text->setText(Message::parse(__message));

    window->show();
}

void Message::error(const String &__message)
{
    Pixmap pixmap("../res/message_icons/error.png");
    window->setWindowTitle("Error");    
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

    int size = res.size() / 33;

    for (int i = 0; i < size; ++i)
    {
        res.insert(33 * iter, "\n");
        ++iter;

        if (iter > 3)
        {
            text->setGeometry(105, 5, 350, 50 + _size);
            window->setFixedSize(MESSAGE_START_WIDTH, MESSAGE_START_HEIGHT + _size);
            ok->setGeometry(MESSAGE_START_WIDTH - 85, MESSAGE_START_HEIGHT - 45 + _size, 80, 40);
            _size += 7;
        }
    }
    return res;
}