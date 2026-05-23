#include "widget.h"

#include "ui_widget.h"
#include <QMessageBox>
#include <QTcpSocket>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setWindowTitle("Tcp Server");

    tcpServer = new QTcpServer(this);

    connect(tcpServer, &QTcpServer::newConnection, this, [this]() {
        QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
        QString log = "[" + clientSocket->peerAddress().toString() +
                      ": " + QString::number(clientSocket->peerPort()) + "]";
        ui->listWidget->addItem(log);

        connect(clientSocket, &QTcpSocket::connected, this, [=]() {
            QString request = clientSocket->readAll();
            const QString& response = process(request);
            clientSocket->write(response.toUtf8());
            QString log = "[" + clientSocket->peerAddress().toString() +
                          ": " + QString::number(clientSocket->peerPort()) +
                          "] req: " + request + ", resp: " + response;
            ui->listWidget->addItem(log);
        });
        connect(clientSocket, &QTcpSocket::disconnected, this, [=]() {
            QString log = "[" + clientSocket->peerAddress().toString() +
                          ": " + QString::number(clientSocket->peerPort()) +
                          "] Disconnected";
            ui->listWidget->addItem(log);
            clientSocket->deleteLater();
        });
    });

    if (!tcpServer->listen(QHostAddress::Any, 8080)) {
        QMessageBox::critical(this, "Tcp Server Error", tcpServer->errorString());
        return;
    }

}

Widget::~Widget() {
    delete ui;
}

QString Widget::process(const QString &request)
{
    return request;
}
