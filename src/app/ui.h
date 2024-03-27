#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"
#include "../funcs/transitions.h"
#include "../boxes/add_file.h"
#include "../boxes/add_folder.h"
#include "../boxes/search.h"
#include "../funcs/remove.h"
#include "../funcs/copy.h"
#include "../funcs/paste.h"
#include "../funcs/buffer.h"
#include "../boxes/message.h"

struct Manager;
struct Transitions;
struct AddFile;
struct AddFolder;
struct Search;
struct Remove;
struct Copy;
struct Paste;
struct Buffer;
struct Message;

struct UserInterface : Window
{
	explicit UserInterface(Widget *parent = nullptr);
	~UserInterface();

	Widget		*centralWidget;
	Manager 	*manager;
	Transitions *transitions;
	AddFile		*addFile;
	AddFolder	*addFolder;
	Search		*search;
	Remove		*remover;
	Copy		*copy;
	Paste		*paste;
	Buffer		*buffer;
	Message		*msgs;

protected:
	void resizeEvent(ResizeEvent* event) override;
};	