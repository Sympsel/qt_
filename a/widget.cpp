#include "widget.h"

#include "ui_widget.h"

#include <QPushButton>
#include <QIcon>
#include <iostream>
// #include <Qrect>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
        ui->setupUi(this);

        QPushButton* button = new QPushButton(this);
        button->move(100, 100);

        auto moveButton = [button](DIRECT dir) {
            QRect r = button->geometry();
            switch(dir) {
                case DIRECT::UP:    r.translate(0, -5); break;
                case DIRECT::DOWN:  r.translate(0, +5); break;
                case DIRECT::LEFT:  r.translate(-5, 0); break;
                case DIRECT::RIGHT: r.translate(+5, 0); break;
            }
            button->setGeometry(r);
        };

        connect(ui->upBtn, &QPushButton::clicked, this, std::bind(moveButton, DIRECT::UP));
        connect(ui->downBtn, &QPushButton::clicked, this, std::bind(moveButton, DIRECT::DOWN));
        connect(ui->leftBtn, &QPushButton::clicked, this, std::bind(moveButton, DIRECT::LEFT));
        connect(ui->rightBtn, &QPushButton::clicked, this, std::bind(moveButton, DIRECT::RIGHT));
        QIcon icon(":/aaa.png");
        this->setWindowIcon(icon);
        float f = this->windowOpacity();
        std::cout << f <<  std::endl;
        this->setWindowOpacity(0.1);
    }

Widget::~Widget() {
    delete ui;
}
