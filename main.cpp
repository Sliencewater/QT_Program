#include "window.h"
#include "ui_mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication shit(argc, argv);
    QTranslator oTranslator;
    windows win;
    win.show();
    return shit.exec();
}


