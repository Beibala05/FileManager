#include "copy.h"

Copy::Copy(Widget *parent, Text *copyText) : m_copyText(copyText)
{
    File buttonStyle("../styles/button.css");
	buttonStyle.open(QIODevice::ReadOnly);
	String style = buttonStyle.readAll();
	buttonStyle.close();

    copy = new Button(parent);
    copy->setGeometry(95, 5, 40, 40);
    copy->setFont(Font("Arial", 14));
    copy->setIcon(Icon(":/icons/tool_bar_icons/copy.png"));
    copy->setIconSize(Size(40, 40));
    copy->setStyleSheet(style);
    copy->setTextForTip("copy file/folder");

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