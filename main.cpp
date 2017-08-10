#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
       Widget mw(0);




       mw.resize(500, 500);
       mw.show();


       return app.exec();
}
