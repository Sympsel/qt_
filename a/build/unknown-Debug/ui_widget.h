/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *leftBtn;
    QPushButton *upBtn;
    QPushButton *rightBtn;
    QPushButton *downBtn;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QProgressBar *progressBar;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        leftBtn = new QPushButton(Widget);
        leftBtn->setObjectName("leftBtn");
        leftBtn->setGeometry(QRect(240, 350, 91, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrains Maple Mono")});
        leftBtn->setFont(font);
        upBtn = new QPushButton(Widget);
        upBtn->setObjectName("upBtn");
        upBtn->setGeometry(QRect(330, 300, 91, 51));
        upBtn->setFont(font);
        rightBtn = new QPushButton(Widget);
        rightBtn->setObjectName("rightBtn");
        rightBtn->setGeometry(QRect(420, 350, 91, 51));
        rightBtn->setFont(font);
        downBtn = new QPushButton(Widget);
        downBtn->setObjectName("downBtn");
        downBtn->setGeometry(QRect(330, 400, 91, 51));
        downBtn->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(440, 110, 241, 81));
        label->setFrameShape(QFrame::Shape::Box);
        label->setFrameShadow(QFrame::Shadow::Plain);
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(190, 160, 191, 81));
        lcdNumber->setFrameShadow(QFrame::Shadow::Plain);
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(447, 270, 241, 23));
        progressBar->setValue(24);
        progressBar->setOrientation(Qt::Orientation::Horizontal);
        progressBar->setInvertedAppearance(false);
        calendarWidget = new QCalendarWidget(Widget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(400, 380, 352, 190));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        leftBtn->setText(QCoreApplication::translate("Widget", "left", nullptr));
        upBtn->setText(QCoreApplication::translate("Widget", "up", nullptr));
        rightBtn->setText(QCoreApplication::translate("Widget", "right", nullptr));
        downBtn->setText(QCoreApplication::translate("Widget", "down", nullptr));
        label->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
