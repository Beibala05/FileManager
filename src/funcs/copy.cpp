#include "copy.h"

Copy::Copy(Widget *centralWidget, Text *copyText) : m_copyText(copyText)
{
    copy = new Button("c", centralWidget);
    copy->setGeometry(95, 5, 40, 40);
    copy->setFont(QFont("Arial", 14));

    QObject::connect(copy, &Button::clicked, this, &Copy::clickSlot);
}

void Copy::clickSlot()
{
    String copyText = m_copyText->text();

    FileInfo fileInfo(Manager::currentPath + (String)"/" + copyText);

    if (fileInfo.isFile())
    {
        Buffer::toBuffer(Manager::currentPath + (String)"/" + copyText);
        Buffer::isCurrentBufferTextFolder = false;
    }
    else
    {
        if (!copyText.isEmpty())
            Buffer::toBuffer(Manager::currentPath + (String)"/" + copyText);
        else
            Buffer::toBuffer(Manager::currentPath);

        Buffer::isCurrentBufferTextFolder = true;
    }
    Buffer::cpTitle = copyText;
}