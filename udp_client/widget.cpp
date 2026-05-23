#include "widget.h"

#include "ui_widget.h"
#include <QNetworkDatagram>

const QString& SERVER_IP = "127.0.0.1";
const quint16 SERVER_PORT = 8080;

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    socket = new QUdpSocket(this);
    this->setWindowTitle("Udp Client");

    connect(socket, &QUdpSocket::readyRead, this, &Widget::processReSpone);
    connect(ui->lineEdit, &QLineEdit::returnPressed, ui->pushButton, [this]() {
        ui->pushButton->click();
    });
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    const QString& text = ui->lineEdit->text();
    if (text.isEmpty()) return;
    // 构造UDP请求
    QNetworkDatagram requestDatagram(text.toUtf8(), QHostAddress(SERVER_IP), SERVER_PORT);
    // 发送请求
    socket->writeDatagram(requestDatagram);
    ui->listWidget->addItem("Client: " + text);
    ui->lineEdit->setText("");
}

void Widget::processReSpone()
{
    const QNetworkDatagram& responseDatagram = socket->receiveDatagram();
    QString response = responseDatagram.data();
    ui->listWidget->addItem("Server: " + response);

}

