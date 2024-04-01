#include "clipboard.h"

String   Buffer::cpTitle;
bool     Buffer::isCurrentBufferTextFolder = true;

Buffer::Buffer(Widget *parent)
{
    File buttonStyle("../styles/button.css");
	buttonStyle.open(QIODevice::ReadOnly);
	String styleButton = buttonStyle.readAll();
	buttonStyle.close();

    clipboard = new Button(parent);
    clipboard->setGeometry(320, 5, 40, 40);
	clipboard->setFont(Font("Arial", 14));
    clipboard->setIcon(Icon(":/icons/tool_bar_icons/clipboard.png"));
    clipboard->setIconSize(Size(40, 40));
    clipboard->setStyleSheet(styleButton);
    clipboard->setTextForTip("get a clipboard information");

	QObject::connect(clipboard, &Button::clicked, this, &Buffer::showInformationFromClipboardSlot);
}

void Buffer::toBuffer(const String &text)
{
	App::clipboard()->setText(text);
}

String Buffer::fromBuffer()
{
	return App::clipboard()->text();
}

void Buffer::showInformationFromClipboardSlot()
{
	Message::information(Buffer::fromBuffer(), "Information from clipboard");
}