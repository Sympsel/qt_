#include "widget.h"

#include "ui_widget.h"
#include <QMessageBox>
#include <QNetworkDatagram>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    socket = new QUdpSocket(this);
    this->setWindowTitle("Udp Server");

    // 先连接信号槽
    connect(socket, &QUdpSocket::readyRead, this, &Widget::processRequest);

    // 后绑定端口
    if (!socket->bind(QHostAddress::Any, 8080)) {
        QMessageBox::critical(this, "Server Error", socket->errorString());
        return;
    }

}

Widget::~Widget() {
    delete ui;
}

void Widget::processRequest() {
    // 1. 获取请求并解析
    const QNetworkDatagram& requireDatagram = socket->receiveDatagram();
    const QString& request = requireDatagram.data();
    // 2. 根据请求计算响应
    QString response;
    process(request, response);
    if (request.isEmpty()) return;
    // 3. 把响应写回客户端
    QNetworkDatagram responseDatagram(response.toUtf8(), requireDatagram.senderAddress(), requireDatagram.senderPort());
    QString log = "[" + requireDatagram.senderAddress().toString() +
                  ": " + QString::number(requireDatagram.senderPort()) +
                  "] req: " + request + ", resp: " + response;
    ui->listWidget->addItem(log);
}

void Widget::process(const QString &request, QString &response)
{
    response = request;
}
