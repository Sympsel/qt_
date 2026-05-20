#include "widget.h"

#include "ui_widget.h"

#include <QPushButton>
#include <QLineEdit>
#include <QTimer>
#include <QIcon>
#include <QResizeEvent>
#include <QLabel>
#include <QDebug>
// #include <Qrect>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget), timer(new QTimer(this)) {
        ui->setupUi(this);

        // QPushButton* button = new QPushButton(this);
        // button->move(100, 100);
        // button->setText("JetBrainsMonoNerdFontMono");
        // button->setToolTip("aaaa");
        // button->setToolTipDuration(3000);
        // QFont font;
        // font.setFamily("JetBrains Maple Mono");
        // font.setItalic(true);
        // font.setUnderline(true);
        // font.setBold(true);
        // this->setFont(font);

        // auto moveButton = [button](DIRECT dir) {
            // QRect r = button->geometry();
            // switch(dir) {
                // case DIRECT::UP:    r.translate(0, -5); break;
                // case DIRECT::DOWN:  r.translate(0, +5); break;
                // case DIRECT::LEFT:  r.translate(-5, 0); break;
                // case DIRECT::RIGHT: r.translate(+5, 0); break;
            // }
            // button->setGeometry(r);
        // };
        // ui->upBtn->setShortcut(QKeySequence("w"));
        // ui->downBtn->setShortcut(QKeySequence("s"));
        // ui->leftBtn->setShortcut(QKeySequence("a"));
        // ui->rightBtn->setShortcut(QKeySequence("d"));

        // connect(ui->upBtn, &QPushButton::clicked, this, std::bind(moveButton, DIRECT::UP));
        // connect(ui->downBtn, &QPushButton::clicked, this, std::bind(moveButton, DIRECT::DOWN));
        // connect(ui->leftBtn, &QPushButton::clicked, this, std::bind(moveButton, DIRECT::LEFT));
        // connect(ui->rightBtn, &QPushButton::clicked, this, std::bind(moveButton, DIRECT::RIGHT));
        // QIcon icon(":/aaa.png");
        // this->setWindowIcon(icon);
        // float f = this->windowOpacity();
        // std::cout << f <<  std::endl;
        // this->setWindowOpacity(1);

        // QPixmap pixmap(":/aaa.png");
        // pixmap = pixmap.scaled(32, 32);
        // QCursor cursor(pixmap, 10, 10);
        // this->setCursor(cursor);
        // button->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));

        // QLabel* label = new QLabel(this);
        // label->setTextFormat(Qt::MarkdownText);
        // label->setText("# 你好\n\n```c++\n#include\nint main() {\n\treturn 0;\n}\n```");
        // label->setBackgroundRole(QPalette::ColorRole::Midlight);
        // label->move(100, 100);

        // QLabel* label = new QLabel(this);
        // QRect r = this->geometry();
        // label->setGeometry(0, 0, r.width(), r.height());
        // QPixmap pixmap(":/aaa.png");
        // label->setPixmap(pixmap);
        // label->setScaledContents(true); // 自动拉伸图片

        // QLabel
        // ui->label->setText("艾薇儿富二代如果让他");
        // ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        // ui->label->setFrameShape(QFrame::Box);
        // ui->label->setFrameShadow(QFrame::Sunken);
        // ui->label->setBackgroundRole(QPalette::Midlight);

        // ui->label->setStyleSheet("QLabel { border: 1px solid gray; }");
        // QTimer* timer = new QTimer(this);
        //     this->ui->lcdNumber->display(10);
        // connect(timer, &QTimer::timeout, this, [this]() {
        //     if (this->ui->lcdNumber->intValue() > 0) {
        //         this->ui->lcdNumber->display(this->ui->lcdNumber->intValue() - 1);
        //     }
        // });
        // timer->start(1000);

        ui->progressBar->setValue(0);
        // ui->progressBar->setStyleSheet();
        connect(timer, &QTimer::timeout, this, [this]() {
            int val = ui->progressBar->value();
            if (val >= 100) {
                timer->stop();
            }
            ui->progressBar->setValue(val + 1);
        });
        timer->start(100);

        QDate date = ui->calendarWidget->selectedDate();
        qDebug() << date;
        ui->calendarWidget->selectionMode();


    }

Widget::~Widget() {
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    // QLabel *label = findChild<QLabel*>();
    // if (label) {
    //     label->setGeometry(0, 0, event->size().width(), event->size().height());
    // }
}
