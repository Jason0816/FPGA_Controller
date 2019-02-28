#include "control.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    control w;
    w.show();

    return a.exec();
}
