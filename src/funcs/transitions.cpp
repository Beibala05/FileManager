#include "transitions.h"

Transitions::Transitions(Widget *centralWidget, ListWidget *fileManager, String &path
    , std::vector<String> &pathes) : m_fileManager(fileManager)
    , m_path(path)
    , m_pathes(pathes)
{
    next = new Button(centralWidget);
	next->setGeometry(50, 5, 40, 40);

	prev = new Button(centralWidget);
	prev->setGeometry(5, 5, 40, 40);

	text_editor = new TextEditor();

    QObject::connect(next, &Button::clicked, this, &Transitions::nextElementSlot);
	QObject::connect(prev, &Button::clicked, this, &Transitions::prevElementSlot);
	QObject::connect(m_fileManager, &ListWidget::itemDoubleClicked, this, &Transitions::nextElementSlot);
}

Transitions::~Transitions()
{
    delete next;
    delete prev;
	delete text_editor;
}

void Transitions::nextElementSlot()
{
	if (!m_fileManager->currentItem())
	{
        qDebug() << "Error: path not found";

		return;
	}

	String selectedItemText = m_fileManager->currentItem()->text();

	m_path = m_pathes.at(m_pathes.size() - 1) + (String) "/" + selectedItemText;

	m_pathes.push_back(m_path);

	String throw_path = m_path;

	try {
		Manager::print(m_path, m_fileManager, m_pathes);
	}
	catch (...) {
		// text_editor = new TextEditor(throw_path);
		text_editor->show(throw_path);
	}

}

void Transitions::prevElementSlot()
{
	if (m_pathes.size() != 1)
	{
		m_pathes.pop_back();
	}

	m_path = m_pathes.at(m_pathes.size() - 1);

	Manager::print(m_path, m_fileManager, m_pathes);
}
