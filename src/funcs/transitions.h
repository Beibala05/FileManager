#pragma once

#include "../app/ui.h"
#include "manager.h"

struct Manager;

struct Transitions : QObject
{
    explicit Transitions(Widget *centralWidget, ListWidget *fileManager, String &path, 
    std::vector<String> &pathes);
    ~Transitions();

    Button *next;
    Button *prev;

    ListWidget	       *m_fileManager;
    String				m_path;
	std::vector<String> m_pathes;

    void nextElementSlot();
    void prevElementSlot();
};