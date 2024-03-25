#include "ui.h"

UserInterface::UserInterface(Widget *parent) : Window(parent)
{
    centralWidget = new Widget(this);

	this->setCentralWidget(centralWidget);
    this->setMinimumSize(UI_MINIMUM_WIDTH, UI_MINIMUM_HEIGHT);
    this->setWindowTitle("File Manager");

    manager = new Manager(centralWidget);
    add = new Create(centralWidget, manager->fileManager);
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
    delete add;
    delete remover;
    delete copy;
    delete paste;
    delete buffer;
    delete msgs;
}

void UserInterface::resizeEvent(ResizeEvent* event)
{
	manager->fileManager->setGeometry(0, 50, width(), height() - 50);
    
	Window::resizeEvent(event);
}
