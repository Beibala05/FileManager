#include "create_dialog.h"

Create::Create(Widget *centralWidget, ListWidget *fileManager) : m_fileManager(fileManager)
{
    add = new Button("+", centralWidget);
    add->setGeometry(95, 5, 40, 40);
    add->setFont(QFont("Arial", 14));

    window = new Window();
    window->setFixedSize(400, 200);
    window->setWindowModality(Qt::ApplicationModal);

    title = new LineEdit(window);
    title->setGeometry(25, 20, 350, 80);
    title->setFont(QFont("Arial", 14));
    title->setPlaceholderText("Enter folder/file name");
    title->setAlignment(Qt::AlignCenter);

    create = new Button("create", window);
    create->setGeometry(205, 110, 170, 80);
    create->setFont(QFont("Arial", 14));

    cancel = new Button("cancel", window);
    cancel->setGeometry(25, 110, 170, 80);
    cancel->setFont(QFont("Arial", 14));

    QObject::connect(add, &Button::clicked, this, &Create::addShowSlot);
    QObject::connect(create, &Button::clicked, this, &Create::createSlot);
    QObject::connect(cancel, &Button::clicked, this, &Create::cancelSlot);
}

Create::~Create()
{
    delete window;
}

void Create::addShowSlot()
{
    window->show();
}

void Create::createSlot()
{
    String createTile = title->text();

    if (!createTile.isEmpty())
    {
        if ((createTile.contains(".") && createTile[0] == "." && createTile.count(".") == 1) 
        || !createTile.contains("."))
        {
            String command = "mkdir " + Manager::currentPath + (String)"/" + createTile;
            int is_create = std::system(command.toStdString().c_str());

            if (is_create != 0) 
                qDebug() << "Error: don't create a folder";
        }
        else
        {
            String command = "touch " + Manager::currentPath + (String)"/" + createTile;
            int is_create = std::system(command.toStdString().c_str());

            if (is_create != 0) 
                qDebug() << "Error: don't create a file";
        }
        m_fileManager->addItem(new ListWidgetItem(QIcon("UNKNOW_ICON_PATH"), createTile));
        window->hide();
    }
    else
        qDebug() << "Error: title is empty";
}

void Create::cancelSlot()
{
   window->hide();
}