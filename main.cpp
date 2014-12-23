#include "imagemng.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageMng w;
    w.show();

    return a.exec();
}
