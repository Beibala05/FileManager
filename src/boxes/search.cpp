#include "search.h"

Search::Search(Widget *centralWidget, ListWidget *fileManager) : m_fileManager(fileManager)
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

    serchButton = new Button(centralWidget);
    serchButton->setGeometry(275, 5, 40, 40);
    serchButton->setFont(Font("Arial", 14));
    serchButton->setIcon(Icon("../res/tool_bar_icons/search.png"));
    serchButton->setIconSize(Size(40, 40));
    serchButton->setStyleSheet(styleButton);

    window = new Window();
    window->setFixedSize(400, 150);
    window->setWindowModality(Qt::ApplicationModal);
    window->setWindowTitle("Search");
    window->setStyleSheet(styleWidget);

    title = new LineEdit(window);
    title->setGeometry(25, 20, 350, 50);
    title->setFont(Font("Arial", 14));
    title->setPlaceholderText("Enter folder/file name");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet(styleEdit);

    search = new Button("search", window);
    search->setGeometry(205, 90, 170, 50);
    search->setFont(Font("Arial", 14));
    search->setStyleSheet(styleButtonOk);

    cancel = new Button("cancel", window);
    cancel->setGeometry(25, 90, 170, 50);
    cancel->setFont(Font("Arial", 14));
    cancel->setStyleSheet(styleButtonCancel);

	QObject::connect(serchButton, &Button::clicked, this, &Search::showSlot);
	QObject::connect(search, &Button::clicked, this, &Search::searchButtonSlot);
	QObject::connect(cancel, &Button::clicked, this, &Search::cancelSlot);
}

Search::~Search()
{
    delete window;
}

void Search::showSlot()
{
    if (!isSearch)
	    window->show();
    else
        searchCancel();
}

void Search::searchButtonSlot()
{
    searchLocal();
}

void Search::searchLocal()
{
    if (title->text().isEmpty())
    {
        Message::warning("empty title");

        return;
    }

    bool isFind = false;
    String searchTitle = title->text().toLower();

    std::vector<String> findFilesTitles;

    for (int i = 0; i < m_fileManager->count(); ++i) 
    {
        ListWidgetItem *item = m_fileManager->item(i);
        String upTextItemText = item->text();
        String currentItemText = upTextItemText.toLower();

        if (currentItemText.contains(searchTitle))
        {
            findFilesTitles.push_back(upTextItemText);
            isFind = true;
        }
    }

    if (isFind)
	{
        Manager::removeAllFromFileManager(m_fileManager);

        for (int i = 0; i < findFilesTitles.size(); ++i)
        {
            FileInfo fileInfo(Manager::currentPath + (String)"/" + findFilesTitles[i]);

            if (fileInfo.isFile())
            {	
                String icon = Manager::fileFormat(Manager::currentPath + (String)"/" + findFilesTitles[i]);
			    m_fileManager->addItem(new ListWidgetItem(Icon(icon), findFilesTitles[i]));
            }
            else
            {
                m_fileManager->addItem(new ListWidgetItem(Icon("../res/files_and_folders_icons/folder.png"), findFilesTitles[i]));
            }
        }

        isSearch = true;
        serchButton->setIcon(Icon("../res/tool_bar_icons/cancel_search.png"));

        title->clear();
        window->hide();
    }
    else
        Message::warning("Could not find a file or folder with that name");
}

void Search::searchCancel()
{
    Manager::print(Manager::currentPath, m_fileManager);
    isSearch = false;
    serchButton->setIcon(Icon("../res/tool_bar_icons/search.png"));
}

void Search::cancelSlot()
{
	window->hide();
}