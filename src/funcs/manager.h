#pragma once

#include "../app/ui.h"

struct Manager
{
    explicit Manager(Widget *centralWidget);
    ~Manager();

    ListWidget	                   *fileManager;
    String				            path = "/mnt/c";
    static String				    currentPath;
	std::vector<String>             pathes;

    static void print(String &path, ListWidget *fileManager, std::vector<String> &pathes);
};