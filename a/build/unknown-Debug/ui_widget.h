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

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        leftBtn = new QPushButton(Widget);
        leftBtn->setObjectName("leftBtn");
        leftBtn->setGeometry(QRect(240, 350, 91, 51));
        upBtn = new QPushButton(Widget);
        upBtn->setObjectName("upBtn");
        upBtn->setGeometry(QRect(330, 300, 91, 51));
        rightBtn = new QPushButton(Widget);
        rightBtn->setObjectName("rightBtn");
        rightBtn->setGeometry(QRect(420, 350, 91, 51));
        downBtn = new QPushButton(Widget);
        downBtn->setObjectName("downBtn");
        downBtn->setGeometry(QRect(330, 400, 91, 51));

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
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
