#pragma once

#include "../includes/include.h"
#include "../funcs/manager.h"
#include "../funcs/transitions.h"

struct Manager;
struct Transitions;

struct UserInterface : Window
{
	explicit UserInterface(Widget *parent = nullptr);
	~UserInterface();

	Widget		*centralWidget;
	Manager 	*manager;
	Transitions *transitions;

protected:
	void resizeEvent(QResizeEvent* event) override;
};	