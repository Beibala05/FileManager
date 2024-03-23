#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"
#include "../funcs/transitions.h"
#include "../boxes/create_dialog.h"

struct Manager;
struct Transitions;
struct Create;

struct UserInterface : Window
{
	explicit UserInterface(Widget *parent = nullptr);
	~UserInterface();

	Widget		*centralWidget;
	Manager 	*manager;
	Transitions *transitions;
	Create		*add;

protected:
	void resizeEvent(QResizeEvent* event) override;
};	