#pragma once

#include "../app/ui.h"
#include "../boxes/text_editor.h"
#include "manager.h"

struct Manager;
struct TextEditor;

struct Transitions : QObject
{
    explicit Transitions(Widget *centralWidget, ListWidget *fileManager, String &path, 
    std::vector<String> &pathes);
    ~Transitions();

    Button *next;
    Button *prev;

    ListWidget	       *m_fileManager;
    TextEditor         *text_editor;
    String				m_path;
	std::vector<String> m_pathes;

    void nextElementSlot();
    void prevElementSlot();
};