#include "message.h"

Widget *Message::window = nullptr;
Button *Message::ok     = nullptr;
Text   *Message::icon;
Text   *Message::text;

Message::Message()
{
    window = new Widget();
    window->setFixedSize(MESSAGE_START_WIDTH, MESSAGE_START_HEIGHT);

    icon = new Text(window);  
    icon->setGeometry(0, 0, 0, 0);

    text = new Text(window);
    text->setGeometry(105, 5, 350, 50);
    text->setFont(QFont("Arial", 12));

    ok = new Button("OK", window);
    ok->setGeometry(MESSAGE_START_WIDTH - 85, MESSAGE_START_HEIGHT - 45, 80, 40);
    ok->setFont(QFont("Arial", 14));

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
    text->setText(__message);

    window->show();
}

void Message::warning(const String &__message)
{

}

void Message::error(const String &__message)
{

}

void Message::close()
{
    window->hide();
}