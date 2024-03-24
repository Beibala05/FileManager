#include "manager.h"

String Manager::currentPath;

Manager::Manager(Widget *centralWidget)
{
    fileManager = new ListWidget(centralWidget);
	fileManager->setGeometry(0, 50, 1200, 750);
	fileManager->setFont(QFont("Arial", 14));

    Manager::print(path, this->fileManager, this->pathes);

	pathes.push_back(path);
}

Manager::~Manager()
{
	Manager::removeAllFromFileManager(fileManager);
}

void Manager::print(String &path, ListWidget *fileManager, std::vector<String> &pathes)
{
    FileInfo fileInfo(path);
	Manager::currentPath = path;

	if (fileInfo.isFile())
	{	
		if (pathes.size() != 1)
			pathes.pop_back();

		path = (String)pathes.at(pathes.size() - 1);

		Manager::currentPath = path;

		throw -1;
	}

	Manager::removeAllFromFileManager(fileManager);

	Dir directory(path);
	FileInfoList files = directory.entryInfoList(Dir::Files | Dir::Dirs | Dir::NoDotAndDotDot, Dir::Name);

	for (const auto &file : files)
	{
		String file_name = file.fileName();

		if (file.isDir())
			fileManager->addItem(new ListWidgetItem(QIcon("FOLDER_ICON_PATH"), file_name));
		else if (file.isFile())
			fileManager->addItem(new ListWidgetItem(QIcon("FILE_ICON_PATH"), file_name));
	}
}

void Manager::removeAllFromFileManager(ListWidget *fileManager)
{
	for (int i = 0; i < fileManager->count(); ++i) 
		delete fileManager->takeItem(i);

	fileManager->clear();
}