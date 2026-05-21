#include "widget.h"

#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    QPushButton* button1 = new QPushButton("按钮1");
    QPushButton* button2 = new QPushButton("按钮2");
    QPushButton* button3 = new QPushButton("按钮3");
    button1->setFlat(true);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    this->setLayout(layout);

}

Widget::~Widget() {
    delete ui;
}
