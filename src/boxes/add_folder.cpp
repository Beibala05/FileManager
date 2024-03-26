#include "add_folder.h"

AddFolder::AddFolder(Widget *centralWidget, ListWidget *fileManager) : m_fileManager(fileManager)
{
    addFolder = new Button(centralWidget);
    addFolder->setGeometry(230, 5, 40, 40);
    addFolder->setFont(QFont("Arial", 14));
    addFolder->setIcon(Icon("../res/tool_bar_icons/add_folder.png"));
    addFolder->setIconSize(Size(40, 40));

    window = new Window();
    window->setFixedSize(400, 200);
    window->setWindowModality(Qt::ApplicationModal);
    window->setWindowTitle("Create Folder");

    title = new LineEdit(window);
    title->setGeometry(25, 20, 350, 80);
    title->setFont(QFont("Arial", 14));
    title->setPlaceholderText("Enter folder name");
    title->setAlignment(Qt::AlignCenter);

    createFolder = new Button("create", window);
    createFolder->setGeometry(205, 110, 170, 80);
    createFolder->setFont(QFont("Arial", 14));

    cancel = new Button("cancel", window);
    cancel->setGeometry(25, 110, 170, 80);
    cancel->setFont(QFont("Arial", 14));

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