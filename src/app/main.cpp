#include "../includes/include.h"
#include "../../icons/icons_pack.h"
#include "ui.h"

int main(int argc, char **argv)
{
    App app(argc, argv);

    UserInterface ui;
    ui.show();

    app.exec();
}