#include "widget.h"

#include "ui_widget.h"
#include <QNetworkReply>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setWindowTitle("Client");
    manager = new QNetworkAccessManager(this);
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        QUrl url(ui->lineEdit->text());
        QNetworkRequest request(url);
        QNetworkReply* response = manager->get(request);
        connect(response, &QNetworkReply::finished, this, [=]() {
            if (response->error() == QNetworkReply::NoError) {
                const QString& html = response->readAll();
                ui->plainTextEdit->setPlainText(html);
            } else {
                ui->plainTextEdit->setPlainText(response->errorString());
            }
            response->deleteLater();
        });

    });
}

Widget::~Widget() {
    delete ui;
}
