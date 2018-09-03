#include "mainwindow.h"
#include <QApplication>

#include "graphics_core.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Graphics_core gc;

    return a.exec();
}
