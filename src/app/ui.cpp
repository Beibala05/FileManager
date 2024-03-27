#include "ui.h"

UserInterface::UserInterface(Widget *parent) : Window(parent)
{
    File buttonStyle("../styles/window.css");
	buttonStyle.open(QIODevice::ReadOnly);
	String style = buttonStyle.readAll();
	buttonStyle.close();

    centralWidget = new Widget(this);

	this->setCentralWidget(centralWidget);
    this->setMinimumSize(UI_MINIMUM_WIDTH, UI_MINIMUM_HEIGHT);
    this->setWindowTitle("File Manager");
    this->setStyleSheet(style);

    manager = new Manager(centralWidget);
    addFile = new AddFile(centralWidget, manager->fileManager);
    addFolder = new AddFolder(centralWidget, manager->fileManager);
    search = new Search(centralWidget, manager->fileManager);
    remover = new Remove(centralWidget, manager->fileManager);
    copy = new Copy(centralWidget, remover->removeTitle);
    paste = new Paste(centralWidget, manager->fileManager);
    transitions = new Transitions(centralWidget, manager->fileManager, manager->path, remover->removeTitle
    , manager->pathes);
    buffer = new Buffer(centralWidget);
    msgs = new Message();
}

UserInterface::~UserInterface()
{
    delete manager;
    delete transitions;
    delete addFile;
    delete addFolder;
    delete search;
    delete remover;
    delete copy;
    delete paste;
    delete buffer;
    delete msgs;
}

void UserInterface::resizeEvent(ResizeEvent* event)
{
	manager->fileManager->setGeometry(0, 50, width(), height() - 50);
    buffer->buffer->setGeometry(770, 5, width() - 775, 40);
    
	Window::resizeEvent(event);
}
