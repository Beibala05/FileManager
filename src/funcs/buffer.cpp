#include "buffer.h"

String   Buffer::cpTitle;
Text    *Buffer::buffer                    = nullptr;
bool     Buffer::isCurrentBufferTextFolder = true;

Buffer::Buffer(Widget *centralWidget)
{
    buffer = new Text(centralWidget);
    buffer->setGeometry(480 + 50, 5, 400, 40);
    buffer->setFont(QFont("Arial", 14));
    buffer->setAlignment(Qt::AlignCenter);

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
