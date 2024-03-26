#include "add_file.h"

AddFile::AddFile(Widget *centralWidget, ListWidget *fileManager) : m_fileManager(fileManager)
{
    addFile = new Button(centralWidget);
    addFile->setGeometry(185, 5, 40, 40);
    addFile->setFont(QFont("Arial", 14));
    addFile->setIcon(Icon("../res/tool_bar_icons/add_file.png"));
    addFile->setIconSize(Size(40, 40));

    window = new Window();
    window->setFixedSize(400, 200);
    window->setWindowModality(Qt::ApplicationModal);
    window->setWindowTitle("Create File");

    title = new LineEdit(window);
    title->setGeometry(25, 20, 350, 80);
    title->setFont(QFont("Arial", 14));
    title->setPlaceholderText("Enter file name");
    title->setAlignment(Qt::AlignCenter);

    createFile = new Button("create", window);
    createFile->setGeometry(205, 110, 170, 80);
    createFile->setFont(QFont("Arial", 14));

    cancel = new Button("cancel", window);
    cancel->setGeometry(25, 110, 170, 80);
    cancel->setFont(QFont("Arial", 14));

    QObject::connect(cancel, &Button::clicked, this, &AddFile::cancelSlot);   
    QObject::connect(addFile, &Button::clicked, this, &AddFile::addShowFileAddSlot);;
    QObject::connect(createFile, &Button::clicked, this, &AddFile::createFileSlot); 
}

AddFile::~AddFile()
{
    delete window;
}

void AddFile::addShowFileAddSlot()
{
    window->show();
}

void AddFile::createFileSlot()
{
    String createTile = title->text();

    if (!createTile.isEmpty())
    {
        String command = "touch " + Manager::currentPath + (String)"/" + createTile;
        int is_create = std::system(command.toStdString().c_str());

        if (is_create != 0) 
            Message::error("failed to create file");
        else
        {
            String icon = Manager::fileFormat(Manager::currentPath + (String)"/" + createTile);
            m_fileManager->addItem(new ListWidgetItem(Icon(icon), createTile));
            window->hide();
            title->clear(); 
        }
    }
    else
        Message::error("file name is empty");
}

void AddFile::cancelSlot()
{
   window->hide();
}