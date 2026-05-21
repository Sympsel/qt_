#include "widget.h"

#include "ui_widget.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QComboBox>
#include <QShortcut>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // QRegularExpression regExp(R"(^1\d{10}$)");
    // ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp, ui->lineEdit));
    // ui->lineEdit->setEnabled(false);

    // QComboBox* qComboBox = new QComboBox(this);
    // qComboBox->move(100, 100);
    // qComboBox->addItem("a");
    // qComboBox->addItem("b");
    // qComboBox->addItem("c");
    // qComboBox->addItem("d");

    QShortcut* shortcut1 = new QShortcut(this);
    QShortcut* shortcut2 = new QShortcut(this);

    shortcut1->setKey(QKeySequence("-"));   // 减号键
    shortcut2->setKey(QKeySequence("="));   // 等号键
    connect(shortcut1, &QShortcut::activated, this, [this]() {
        int val = ui->horizontalSlider->value();
        if (val <= ui->horizontalSlider->minimum()) {
            return;
        }
        ui->horizontalSlider->setValue(val - 5);
    });
    connect(shortcut2, &QShortcut::activated, this, [this]() {
        int val = ui->horizontalSlider->value();
        if (val >= ui->horizontalSlider->maximum()) {
            return;
        }
        ui->horizontalSlider->setValue(val + 5);
    });
    // connect(ui->horizontalSlider, &, this, &Widget::on_horizontalSlider_valueChanged);


}

Widget::~Widget() {
    delete ui;
}

void Widget::on_pushButton_pressed()
{
}


void Widget::on_lineEdit_textEdited(const QString &text)
{
    QString content = text;
    int pos = 0;
    if (ui->lineEdit->validator()->validate(content, pos) == QValidator::Acceptable) {
        ui->pushButton->setEnabled(true);
    } else {
        ui->pushButton->setEnabled(false);
    }
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    qDebug() << QString::number(value);
}

