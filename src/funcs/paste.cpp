#include "paste.h"

Paste::Paste(Widget *centralWidget, ListWidget *fileManager) : m_fileManager(fileManager)
{
    File buttonStyle("../styles/button.css");
	buttonStyle.open(QIODevice::ReadOnly);
	String style = buttonStyle.readAll();
	buttonStyle.close();


    paste = new Button(centralWidget);
    paste->setGeometry(140, 5, 40, 40);
    paste->setFont(Font("Arial", 14));
    paste->setIcon(Icon("../res/tool_bar_icons/copy_to_folder.png"));
    paste->setIconSize(Size(40, 40));
    paste->setStyleSheet(style);
    paste->setTextForTip("paste file to folder");

    QObject::connect(paste, &Button::clicked, this, &Paste::clickSlot);
}

void Paste::clickSlot()
{
    String pasteText = Buffer::fromBuffer();

    if (!pasteText.isEmpty())
    {
        if (Manager::isItemExist(Manager::currentPath, Buffer::cpTitle))
        {
            Message::information("Such a file or folder already exist");

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

        if (isSuccess == 0)
        {
            m_fileManager->addItem(new ListWidgetItem(Icon("../res/files_and_folders_icons/new_item.png"), Buffer::cpTitle));
        }
    }
    else
        Message::error("Empty buffer");
}