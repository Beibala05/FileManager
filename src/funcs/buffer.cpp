#include "buffer.h"

String   Buffer::cpTitle;
Text    *Buffer::buffer                    = nullptr;
bool     Buffer::isCurrentBufferTextFolder = true;

Buffer::Buffer(Widget *centralWidget)
{
    File bufferStyle("../styles/text_label.css");
	bufferStyle.open(QIODevice::ReadOnly);
	String styleBuffer = bufferStyle.readAll();
	bufferStyle.close();

    buffer = new Text(centralWidget);
    buffer->setGeometry(770, 5, UI_MINIMUM_WIDTH - 775, 40);
    buffer->setFont(QFont("Arial", 14));
    buffer->setAlignment(Qt::AlignCenter);
    buffer->setStyleSheet(styleBuffer);

    String bufferText = Buffer::fromBuffer();

    if (!bufferText.isEmpty())
        buffer->setText(bufferText);
    else
        buffer->setText("Buffer is empty");
}

void Buffer::toBuffer(const String &text)
{
	App::clipboard()->setText(text);
    buffer->setText(text);
}

String Buffer::fromBuffer()
{
	return App::clipboard()->text();
}
