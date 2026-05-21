#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // 诊断按钮位置
    qDebug() << "=== 位置诊断 ===";
    qDebug() << "groupBox geometry:" << ui->groupBox->geometry();
    qDebug() << "newRowBtn geometry:" << ui->newRowBtn->geometry();
    qDebug() << "newRowBtn parent:" << ui->newRowBtn->parentWidget();
    qDebug() << "newRowBtn pos (global):" << ui->newRowBtn->mapToGlobal(QPoint(0,0));
    qDebug() << "groupBox pos (global):" << ui->groupBox->mapToGlobal(QPoint(0,0));

    // 临时将按钮移出 groupBox
    ui->newRowBtn->setParent(this);
    ui->newColBtn->setParent(this);
    ui->newRowBtn->move(50, 300);
    ui->newColBtn->move(150, 300);
    ui->newRowBtn->raise();
    ui->newColBtn->raise();

    // 测试按钮是否可点击
    connect(ui->newRowBtn, &QPushButton::clicked, this, [this](){
        qDebug() << "按钮被点击了！";
        on_newRowBtn_clicked();
    });

    // 您的表格代码...
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_newRowBtn_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
}


void Widget::on_newCowBtn_clicked()
{
    if (!ui->lineEdit->text().isEmpty()) {
        int colCount = ui->tableWidget->columnCount();
        ui->tableWidget->insertColumn(colCount);
        ui->tableWidget->setHorizontalHeaderItem(colCount, new QTableWidgetItem(ui->lineEdit->text()));
    }
}

