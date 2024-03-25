#include "text_editor.h"

TextEditor::TextEditor()
{
    this->setMinimumSize(1200, 800);
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Text Editor");

    editor = new TextEdit(this);
    editor->setGeometry(0, 0, TEXT_EDITOR_START_WIDTH, TEXT_EDITOR_START_HEIGHT);
    editor->setFont(QFont("Arial", 14));

    save = new Button("save", this);
    save->setGeometry(1075, 740, 100, 50);
    save->setFont(QFont("Arial", 14));

    reduceSize = new Button("-", this);
    reduceSize->setGeometry(1015, 740, 50, 50);
    reduceSize->setFont(QFont("Arial", 14));

    increasSize = new Button("+", this);
    increasSize->setGeometry(955, 740, 50, 50);
    increasSize->setFont(QFont("Arial", 14));

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
    if (textSize < 30) 
    {
        textSize += 2;
        editor->setFont(QFont("Arial", textSize));
    }
}

void TextEditor::reduceSizeSlot()  
{
    if (textSize > 10)  
    {
        textSize -= 2;
        editor->setFont(QFont("Arial", textSize));
    }
}

void TextEditor::resizeEvent(ResizeEvent* event)
{
    editor->setGeometry(0, 0, width(), height());
    save->setGeometry(width() - 125, height() - 60, 100, 50);
    reduceSize->setGeometry(width() - 185, height() - 60, 50, 50);
    increasSize->setGeometry(width() - 245, height() - 60, 50, 50);
    
	Widget::resizeEvent(event);
}
