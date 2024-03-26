#include "text_editor.h"
#include "message.h"

TextEditor::TextEditor()
{
    this->setMinimumSize(1200, 800);
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Text Editor");

    editor = new TextEdit(this);
    editor->setGeometry(0, 0, TEXT_EDITOR_START_WIDTH, TEXT_EDITOR_START_HEIGHT);
    editor->setFont(QFont("Arial", 14));

    save = new Button(this);
    save->setGeometry(1125, 740, 100 - 50, 50);
    save->setFont(Font("Arial", 14));
    save->setIcon(Icon("../res/text_editor_icons/save_file.png"));
    save->setIconSize(Size(50, 50));

    reduceSize = new Button(this);
    reduceSize->setGeometry(1065, 740, 50, 50);
    reduceSize->setFont(Font("Arial", 14));
    reduceSize->setIcon(Icon("../res/text_editor_icons/minus.png"));
    reduceSize->setIconSize(Size(50, 50));

    increasSize = new Button(this);
    increasSize->setGeometry(1005, 740, 50, 50);
    increasSize->setFont(Font("Arial", 14));
    increasSize->setIcon(Icon("../res/text_editor_icons/plus.png"));
    increasSize->setIconSize(Size(50, 50));

    QObject::connect(save, &Button::clicked, this, &TextEditor::saveSlot);
    QObject::connect(increasSize, &Button::clicked, this, &TextEditor::increasSizeSlot);
    QObject::connect(reduceSize, &Button::clicked, this, &TextEditor::reduceSizeSlot);
}

void TextEditor::print()
{
    editor->setText(text);
}

void TextEditor::open(const String &path)
{
    File file(path);
    if (file.open(QIODevice::ReadOnly))
    {
        text = file.readAll();
        file.close();
        this->path = path;
        this->show();
        print();
    }
    else
        Message::error("Failed to open file");
}

void TextEditor::saveSlot()
{
    File file(path);

    if (file.open(QIODevice::WriteOnly))
    {
        file.write(editor->toPlainText().toUtf8());
        file.close();
        Message::information("File is saved");
    }
    else
        Message::error("Failed to save file");
}

void TextEditor::increasSizeSlot() 
{
    if (textSize < 30) 
    {
        textSize += 2;
        editor->setFont(Font("Arial", textSize));
    }
}

void TextEditor::reduceSizeSlot()  
{
    if (textSize > 10)  
    {
        textSize -= 2;
        editor->setFont(Font("Arial", textSize));
    }
}

void TextEditor::resizeEvent(ResizeEvent* event)
{
    editor->setGeometry(0, 0, width(), height());
    save->setGeometry(width() - 75, height() - 60, 100 - 50, 50);
    reduceSize->setGeometry(width() - 185 + 50, height() - 60, 50, 50);
    increasSize->setGeometry(width() - 245 + 50, height() - 60, 50, 50);
    
	Widget::resizeEvent(event);
}
