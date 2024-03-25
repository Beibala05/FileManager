#include "paste.h"

Paste::Paste(Widget *centralWidget, ListWidget *fileManager) : m_fileManager(fileManager)
{
    paste = new Button("p", centralWidget);
    paste->setGeometry(140, 5, 40, 40);
    paste->setFont(QFont("Arial", 14));

    QObject::connect(paste, &Button::clicked, this, &Paste::clickSlot);
}

void Paste::clickSlot()
{
    String pasteText = Buffer::fromBuffer();

    if (!pasteText.isEmpty())
    {
        if (Manager::isItemExist(Manager::currentPath, Buffer::cpTitle))
        {
            qDebug() << "error: such a file/folder already exist";

            Message::information("error: such a file/folder already exist");

            return;
        }

        String command;
        int    isSuccess;

        if (Buffer::isCurrentBufferTextFolder)
        {
            command = (String)"cp -r " + pasteText + (String)"/ " + Manager::currentPath + (String)"/";

            isSuccess = std::system(command.toStdString().c_str());
        }
        else
        {
            command = (String)"cp " + pasteText + (String)" " + Manager::currentPath + (String)"/" 
            + Buffer::cpTitle;

            isSuccess = std::system(command.toStdString().c_str());
        }

        if (isSuccess != 0)
            qDebug() << "Error: copy past is failed";
        else
        {
            qDebug() << "copy past is successed";

            m_fileManager->addItem(new ListWidgetItem(QIcon("UNKNOW_ICON_PATH"), Buffer::cpTitle));
        }
    }
    else
        qDebug() << "Error: empty buffer";
}