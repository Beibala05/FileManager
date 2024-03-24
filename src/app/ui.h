#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"
#include "../funcs/transitions.h"
#include "../boxes/create_dialog.h"
#include "../funcs/remove.h"

struct Manager;
struct Transitions;
struct Create;
struct Remove;

struct UserInterface : Window
{
	explicit UserInterface(Widget *parent = nullptr);
	~UserInterface();

	Widget		*centralWidget;
	Manager 	*manager;
	Transitions *transitions;
	Create		*add;
	Remove		*remover;

protected:
	void resizeEvent(QResizeEvent* event) override;
};	