#pragma once

#include "../includes/include.h"

struct TextEditor : Widget
{
    TextEditor();

    TextEdit *editor;
    Button   *save;
    Button   *reduceSize;
    Button   *increasSize;
    String    text;
    String    path;
    int       textSize = 14;

    void print();
    void open(const String &path);
    void saveSlot();
    void reduceSizeSlot();
    void increasSizeSlot();

protected:
	void resizeEvent(ResizeEvent* event) override;
};
