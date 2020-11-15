#include "ShapePainter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShapePainter w;
    w.show();
    return a.exec();
}
