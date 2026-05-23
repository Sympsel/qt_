#include "widget.h"

#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setWindowTitle("Tcp Client");
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 8080);
    connect(socket, &QTcpSocket::readyRead, this, [=]() {
        QString response = socket->readAll();
        ui->listWidget->addItem("server: " + response);
    });
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        const QString& text = ui->lineEdit->text();
        socket->write(text.toUtf8());
        ui->listWidget->addItem(text);
        ui->lineEdit->setText("");
    });
    if (!socket->waitForConnected()) {
        QMessageBox::critical(this, "Tcp Client error", socket->errorString());
        exit(1);
    }

}

Widget::~Widget() {
    delete ui;
}
