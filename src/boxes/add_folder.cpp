#include "add_folder.h"

AddFolder::AddFolder(Widget *parent, ListWidget *fileManager) : m_fileManager(fileManager)
{
    File buttonStyle("../styles/button.css");
	buttonStyle.open(QIODevice::ReadOnly);
	String styleButton = buttonStyle.readAll();
	buttonStyle.close();

    File buttonOkStyle("../styles/button_ok.css");
	buttonOkStyle.open(QIODevice::ReadOnly);
	String styleButtonOk = buttonOkStyle.readAll();
	buttonOkStyle.close();

    File buttonCancelStyle("../styles/button_cancel.css");
	buttonCancelStyle.open(QIODevice::ReadOnly);
	String styleButtonCancel = buttonCancelStyle.readAll();
	buttonCancelStyle.close();

    File editStyle("../styles/text_edit.css");
	editStyle.open(QIODevice::ReadOnly);
	String styleEdit = editStyle.readAll();
	editStyle.close();

    File widgetStyle("../styles/widget.css");
	widgetStyle.open(QIODevice::ReadOnly);
	String styleWidget = widgetStyle.readAll();
	widgetStyle.close();

    addFolder = new Button(parent);
    addFolder->setGeometry(230, 5, 40, 40);
    addFolder->setFont(Font("Arial", 14));
    addFolder->setIcon(Icon(":/icons/tool_bar_icons/add_folder.png"));
    addFolder->setIconSize(Size(40, 40));
    addFolder->setStyleSheet(styleButton);
    addFolder->setTextForTip("add folder");

    window = new Window();
    window->setFixedSize(400, 150);
    window->setWindowModality(Qt::ApplicationModal);
    window->setWindowTitle("Create Folder");
    window->setStyleSheet(styleWidget);

    title = new LineEdit(window);
    title->setGeometry(25, 20, 350, 50);
    title->setFont(Font("Arial", 14));
    title->setPlaceholderText("Enter folder name");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet(styleEdit);

    createFolder = new Button("create folder", window);
    createFolder->setGeometry(205, 90, 170, 50);
    createFolder->setFont(Font("Arial", 14));
    createFolder->setStyleSheet(styleButtonOk);

    cancel = new Button("cancel", window);
    cancel->setGeometry(25, 90, 170, 50);
    cancel->setFont(Font("Arial", 14));
    cancel->setStyleSheet(styleButtonCancel);

    QObject::connect(cancel, &Button::clicked, this, &AddFolder::cancelSlot);   
    QObject::connect(addFolder, &Button::clicked, this, &AddFolder::addShowFolderSlot);
    QObject::connect(createFolder, &Button::clicked, this, &AddFolder::createFolderSlot); 
}

AddFolder::~AddFolder()
{
    delete window;
}

void AddFolder::addShowFolderSlot()
{
    window->show();
}


void AddFolder::createFolderSlot()
{
    String createTile = title->text();

    if (!createTile.isEmpty())
    {
        String command = "mkdir " + Manager::currentPath + (String)"/" + createTile;
        int is_create = std::system(command.toStdString().c_str());

        if (is_create != 0) 
            Message::error("failed to create folder");
        else
        {
            m_fileManager->addItem(new ListWidgetItem(Icon("../res/files_and_folders_icons/folder.png"), createTile));
            window->hide(); 
            title->clear();
        }
    }
    else
        Message::error("folder name is empty");
}

void AddFolder::cancelSlot()
{
   window->hide();
}