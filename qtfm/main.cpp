#include "qtfm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtfm w;

    w.show();

    return a.exec();
}
