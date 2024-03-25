#include "remove.h"

Remove::Remove(Widget *centralWidget, ListWidget *fileManager) : m_fileManager(fileManager)
{
    removeTitle = new Text(centralWidget);
    removeTitle->setGeometry(230, 5, 200, 40);
    removeTitle->setFont(QFont("Arial", 14));
    removeTitle->setAlignment(Qt::AlignCenter);

    remove = new Button("x", centralWidget);
    remove->setGeometry(435, 5, 40, 40);
    remove->setFont(QFont("Arial", 14));

    QObject::connect(remove, &Button::clicked, this, &Remove::removeItemSlot);
    QObject::connect(m_fileManager, &ListWidget::itemClicked, this, &Remove::crossTextFromFileManagerSlot);
}

void Remove::crossTextFromFileManagerSlot()
{
    ListWidgetItem *selectedItem = m_fileManager->currentItem();

	if (selectedItem)
	{
		String selectedItemText = selectedItem->text();
		
		removeTitle->setText(selectedItemText);
	}
}

void Remove::removeItemSlot()
{
    try 
    {
        removeItem();
    }
    catch(...) 
    {
        qDebug() << "Error: Failed to delete folder or file";
    }
    
}

void Remove::removeItem()
{
    String removeTitleText = removeTitle->text();

    if (removeTitleText.isEmpty())
    {
        qDebug() << "Error: empty remove title";

        return;
    }

    FileInfo fileInfo(removeTitleText);

    int isRemoveSuccess;
    String command;

    if (fileInfo.isFile())
    {
        command = (String)"rm " + Manager::currentPath + (String)"/" + removeTitleText;
        isRemoveSuccess = std::system(command.toStdString().c_str());
    }
    else
    {
        command = (String)"rm -rf " + Manager::currentPath + (String)"/" + removeTitleText;
        isRemoveSuccess = std::system(command.toStdString().c_str());
    }

    if (isRemoveSuccess != 0) 
        throw -1;
    else
    {
        for (int i = 0; i < m_fileManager->count(); ++i) 
        {
            ListWidgetItem *item = m_fileManager->item(i);
            if (item->text() == removeTitleText) 
            {
                delete m_fileManager->takeItem(i);
            }
        }

        removeTitle->clear();
        qDebug() << "Item was success removed";
    }
}