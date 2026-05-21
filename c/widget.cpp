#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // ui->pushButton()
    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");
    ui->listWidget->addItem("Python");

    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &Widget::on_pushButton_clicked);
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    const QString& text = ui->lineEdit->text();
    ui->listWidget->addItem(text);
    ui->lineEdit->clear();
}


void Widget::on_pushButton_2_clicked()
{
    int row = ui->listWidget->currentRow();
    if (row < 0) {
        return;
    }
    ui->listWidget->takeItem(row);
}

