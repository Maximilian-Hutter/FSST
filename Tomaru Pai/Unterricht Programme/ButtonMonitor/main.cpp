#include "widget.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try {
        Widget w;
        w.show();
        return a.exec();
    }
    catch (const QString msg) {
        qDebug() << msg;
        return 1;
    }
}
