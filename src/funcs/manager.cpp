#include "manager.h"

String	Manager::currentPath;

Manager::Manager(Widget *centralWidget)
{
	File buttonStyle("../styles/manager.css");
	buttonStyle.open(QIODevice::ReadOnly);
	String style = buttonStyle.readAll();
	buttonStyle.close();

    fileManager = new ListWidget(centralWidget);
	fileManager->setGeometry(0, 50, 1200, 750);
	fileManager->setFont(Font("Arial", 16));
	fileManager->setStyleSheet(style);

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
		{	
			fileManager->addItem(new ListWidgetItem(Icon("../res/files_and_folders_icons/folder.png"), file_name));
		}
		else if (file.isFile())
		{
			String icon = Manager::fileFormat(Manager::currentPath + (String)"/" + file_name);
			fileManager->addItem(new ListWidgetItem(Icon(icon), file_name));
		}
	}
}

void Manager::print(const String &dirPath, ListWidget *fileManager)
{
	Manager::removeAllFromFileManager(fileManager);

	Dir directory(dirPath);
	FileInfoList files = directory.entryInfoList(Dir::Files | Dir::Dirs | Dir::NoDotAndDotDot, Dir::Name);

	for (const auto &file : files)
	{
		String file_name = file.fileName();

		if (file.isDir())
		{	
			fileManager->addItem(new ListWidgetItem(Icon("../res/files_and_folders_icons/folder.png"), file_name));
		}
		else if (file.isFile())
		{
			String icon = Manager::fileFormat(Manager::currentPath + (String)"/" + file_name);
			fileManager->addItem(new ListWidgetItem(Icon(icon), file_name));
		}
	}
}

void Manager::removeAllFromFileManager(ListWidget *fileManager)
{
	for (int i = 0; i < fileManager->count(); ++i) 
		delete fileManager->takeItem(i);

	fileManager->clear();
}

bool Manager::isItemExist(const String &path, const String &title)
{
	Dir directory(path);
	FileInfoList items = directory.entryInfoList(Dir::Files | Dir::Dirs | Dir::NoDotAndDotDot, Dir::Name);

	for (const auto &item : items)
	{
		String item_name = item.fileName();

		if (item_name == title)
			return true;
	}

	return false;
}

String Manager::fileFormat(const String& path) 
{
    FileInfo fileInfo(path);
    String extension = fileInfo.suffix().toLower();

    if (extension == "txt" || extension == "docx" || extension == "doc" || extension == "word") 
        return "../res/files_and_folders_icons/document.png";

    else if (extension == "cpp" || extension == "py" || extension == "c" || extension == "java"
	|| extension == "js" || extension == "rust" || extension == "html" || extension == "css"
	|| extension == "json" || extension == "xml" || extension == "bash" || extension == "sh"
	|| extension == "bat") 
        return "../res/files_and_folders_icons/code_file.png";

	else if (extension == "png" || extension == "jpg" || extension == "jpeg" || extension == "ico"
	|| extension == "gif" || extension == "tiff" || extension == "webp" || extension == "eps"
	|| extension == "svg")
		return "../res/files_and_folders_icons/image_file.png";

	else if (extension == "mp4" || extension == "mov" || extension == "wmv" || extension == "avi"
	|| extension == "avchd" || extension == "flv" || extension == "f4v" || extension == "swf"
	|| extension == "mkv" || extension == "webm" || extension == "html5")
		return "../res/files_and_folders_icons/video_file.png";

	else if (extension == "wav" || extension == "aiff" || extension == "ape" || extension == "flac"
	|| extension == "mp3" || extension == "ogg")
		return "../res/files_and_folders_icons/sound_file.png";

	else if (extension == "dll")
		return "../res/files_and_folders_icons/dll.png";

	else if (extension == "xls")
		return "../res/files_and_folders_icons/xls.png";

	else if (extension == "zip")
		return "../res/files_and_folders_icons/zip.png";

	else if (extension == "fb2")
		return "../res/files_and_folders_icons/fb2.png";

    else 
        return "../res/files_and_folders_icons/unknown_file.png";
}
