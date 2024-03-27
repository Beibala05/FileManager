#include "add_file.h"

AddFile::AddFile(Widget *centralWidget, ListWidget *fileManager) : m_fileManager(fileManager)
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

    addFile = new Button(centralWidget);
    addFile->setGeometry(185, 5, 40, 40);
    addFile->setFont(Font("Arial", 14));
    addFile->setIcon(Icon("../res/tool_bar_icons/add_file.png"));
    addFile->setIconSize(Size(40, 40));
    addFile->setStyleSheet(styleButton);

    window = new Window();
    window->setFixedSize(400, 150);
    window->setWindowModality(Qt::ApplicationModal);
    window->setWindowTitle("Create File");
    window->setStyleSheet(styleWidget);

    title = new LineEdit(window);
    title->setGeometry(25, 20, 350, 50);
    title->setFont(Font("Arial", 14));
    title->setPlaceholderText("Enter file name");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet(styleEdit);

    createFile = new Button("create file", window);
    createFile->setGeometry(205, 90, 170, 50);
    createFile->setFont(Font("Arial", 14));
    createFile->setStyleSheet(styleButtonOk);

    cancel = new Button("cancel", window);
    cancel->setGeometry(25, 90, 170, 50);
    cancel->setFont(Font("Arial", 14));
    cancel->setStyleSheet(styleButtonCancel);

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