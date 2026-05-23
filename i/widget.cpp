#include "widget.h"

#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    // this->setStyleSheet("");
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("一个按钮");
    button->setStyleSheet("QPushButton { color: #ffaa00; }");
}

Widget::~Widget() {
    delete ui;
}
