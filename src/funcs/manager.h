#pragma once

#include "../app/ui.h"
#include "../funcs/remove.h"
#include "../customes/button.h"

struct Remove;
struct Button;

struct Manager
{
    explicit Manager(Widget *centralWidget);
    ~Manager();

    ListWidget	                   *fileManager;
    String				            path = "/mnt/c";
    std::vector<String>             pathes;
    static String				    currentPath;

    static void   print(String &path, ListWidget *fileManager, std::vector<String> &pathes);
    static void   print(const String &dirPath, ListWidget *fileManager);
    static void   removeAllFromFileManager(ListWidget *fileManager);
    static bool   isItemExist(const String &path, const String &title);
    static String fileFormat(const String &path);
};