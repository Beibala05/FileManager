#include "text_editor.h"

TextEditor::TextEditor()
{
    window = new Window();
    window->setFixedSize(1200, 800);
    window->setWindowModality(Qt::ApplicationModal);

    editor = new TextEdit(window);
    editor->setGeometry(0, 0, 1200, 800);
    editor->setFont(QFont("Arial", 14));

    save = new Button("save", window);
    save->setGeometry(1090, 740, 100, 50);
    save->setFont(QFont("Arial", 14));

    increasSize = new Button("+", window);
    increasSize->setGeometry(970, 740, 50, 50);
    increasSize->setFont(QFont("Arial", 14));

    reduceSize = new Button("-", window);
    reduceSize->setGeometry(1030, 740, 50, 50);
    reduceSize->setFont(QFont("Arial", 14));

    QObject::connect(save, &Button::clicked, this, &TextEditor::saveSlot);
    QObject::connect(increasSize, &Button::clicked, this, &TextEditor::increasSizeSlot);
    QObject::connect(reduceSize, &Button::clicked, this, &TextEditor::reduceSizeSlot);
}

TextEditor::~TextEditor()
{
    delete window;
}

void TextEditor::print()
{
    editor->setText(text);
}

void TextEditor::show(const String &path)
{
    File file(path);
    if (file.open(QIODevice::ReadOnly))
    {
        text = file.readAll();
        file.close();
        this->path = path;
        window->show();
        print();
    }
    else
    {
        qDebug() << "Error: open file for read only";
    }
}

void TextEditor::saveSlot()
{
    File file(path);

    if (file.open(QIODevice::WriteOnly))
    {
        file.write(editor->toPlainText().toUtf8());
        file.close();
    }
    else
    {
        qDebug() << "Error: open file for write only";
    }
}

void TextEditor::increasSizeSlot() 
{
    if (textSize < 20) 
    {
        ++textSize;
        editor->setFont(QFont("Arial", textSize));
    }
}

void TextEditor::reduceSizeSlot()  
{
    if (textSize > 10)  
    {
        --textSize;
        editor->setFont(QFont("Arial", textSize));
    }
}