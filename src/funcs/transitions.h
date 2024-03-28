#pragma once

#include "../app/ui.h"
#include "../customes/button.h"
#include "../customes/text.h"
#include "manager.h"

struct Manager;
struct Button;
struct Text;

struct Transitions : Object
{
    Transitions(Widget *parent, ListWidget *fileManager, String &path
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