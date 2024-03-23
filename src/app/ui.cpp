#include "ui.h"

UserInterface::UserInterface(Widget *parent) : Window(parent)
{
    centralWidget = new Widget(this);
	this->setCentralWidget(centralWidget);
    this->setMinimumSize(1200, 800);

    manager = new Manager(centralWidget);
    transitions = new Transitions(centralWidget, manager->fileManager, manager->path, manager->pathes);
}

UserInterface::~UserInterface()
{
    delete manager;
    delete transitions;
}

void UserInterface::resizeEvent(QResizeEvent* event)
{
	manager->fileManager->setGeometry(0, 50, width(), height() - 50);
    transitions->next->setGeometry(50, 5, 40, 40);
    transitions->prev->setGeometry(5, 5, 40, 40);

	Window::resizeEvent(event);
}
