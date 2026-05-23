#include <QApplication>

#include "widget.h"
#include <QFile>

QString loadQSS() {
    QFile file(":/style.qss");
    QFile file(":/style.qss");

}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    Widget w;
    w.show();
    return QApplication::exec();
}
