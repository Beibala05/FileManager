#include "../includes/include.h"
#include "../../icons/icons_pack.h"
#include "../boxes/message.h"
#include "ui.h"

int main(int argc, char **argv)
{
    App app(argc, argv);

    UserInterface ui;
    ui.show();

    app.exec();
}