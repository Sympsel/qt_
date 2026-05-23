// main.cpp
#include <QApplication>
#include "widget.h"
#include <QFile>

QString loadQSS() {
    QFile file(":/vscode-light.qss");
    if (!file.open(QFile::ReadOnly)) {
        qWarning() << "无法打开 QSS 文件";
        return QString();
    }
    QString style = file.readAll();
    file.close();
    return style;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString qss = loadQSS();
    if (!qss.isEmpty()) {
        a.setStyleSheet(qss);
    }

    Widget w;
    w.show();
    return a.exec();
}