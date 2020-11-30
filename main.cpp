#include "dft.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DFT w;
    w.setWindowTitle("Disappeared Flame Town");
    w.show();
    return a.exec();
}
