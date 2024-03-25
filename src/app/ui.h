#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"
#include "../funcs/transitions.h"
#include "../boxes/add_item.h"
#include "../funcs/remove.h"
#include "../funcs/copy.h"
#include "../funcs/paste.h"
#include "../funcs/buffer.h"
#include "../boxes/message.h"

struct Manager;
struct Transitions;
struct Create;
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
	Create		*add;
	Remove		*remover;
	Copy		*copy;
	Paste		*paste;
	Buffer		*buffer;
	Message		*msgs;

protected:
	void resizeEvent(ResizeEvent* event) override;
};	