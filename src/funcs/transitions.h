#pragma once

#include "../app/ui.h"
#include "manager.h"

struct Manager;

struct Transitions : QObject
{
    Transitions(Widget *centralWidget, ListWidget *fileManager, String &path
    , Text *removeText, std::vector<String> &pathes);

    Button *next;
    Button *prev;

    ListWidget	       *m_fileManager;
    Text               *m_removeText;
    String				m_path;
	std::vector<String> m_pathes;

    void nextElementSlot();
    void prevElementSlot();
};