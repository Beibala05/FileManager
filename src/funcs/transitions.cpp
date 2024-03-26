#include "transitions.h"

Transitions::Transitions(Widget *centralWidget, ListWidget *fileManager, String &path
    , Text *removeText, std::vector<String> &pathes) : m_fileManager(fileManager)
    , m_path(path)
    , m_pathes(pathes)
	, m_removeText(removeText)
{
    next = new Button(centralWidget);
	next->setGeometry(50, 5, 40, 40);
	next->setFont(Font("Arial", 14));
	next->setIcon(Icon("../res/tool_bar_icons/next_dir.png"));
    next->setIconSize(Size(40, 40));

	prev = new Button(centralWidget);
	prev->setGeometry(5, 5, 40, 40);
	prev->setFont(Font("Arial", 14));
	prev->setIcon(Icon("../res/tool_bar_icons/prev_dir.png"));
    prev->setIconSize(Size(40, 40));

	text_editor = new TextEditor();

    QObject::connect(next, &Button::clicked, this, &Transitions::nextElementSlot);
	QObject::connect(prev, &Button::clicked, this, &Transitions::prevElementSlot);
	QObject::connect(m_fileManager, &ListWidget::itemDoubleClicked, this, &Transitions::nextElementSlot);
}

Transitions::~Transitions()
{
	delete text_editor;
}

void Transitions::nextElementSlot()
{
	if (!m_fileManager->currentItem())
	{
		Message::error("Path not found");

		return;
	}

	String selectedItemText = m_fileManager->currentItem()->text();

	m_path = m_pathes.at(m_pathes.size() - 1) + (String) "/" + selectedItemText;

	m_pathes.push_back(m_path);

	String throw_path = m_path;

	try 
	{
		Manager::print(m_path, m_fileManager, m_pathes);
	}
	catch (...) 
	{
		text_editor->open(throw_path);
	}

	m_removeText->clear();
}

void Transitions::prevElementSlot()
{
	if (m_pathes.size() != 1)
	{
		m_pathes.pop_back();
	}

	m_path = m_pathes.at(m_pathes.size() - 1);

	Manager::print(m_path, m_fileManager, m_pathes);

	m_removeText->clear();
}
