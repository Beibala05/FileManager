#pragma once

#include "../app/ui.h"
#include "../funcs/remove.h"

struct Remove;

struct Manager
{
    explicit Manager(Widget *centralWidget);
    ~Manager();

    ListWidget	                   *fileManager;
    String				            path = "/mnt/c";
    std::vector<String>             pathes;
    static String				    currentPath;

    static void print(String &path, ListWidget *fileManager, std::vector<String> &pathes);
    static void removeAllFromFileManager(ListWidget *fileManager);
    static bool isItemExist(const String &path, const String &title);
};