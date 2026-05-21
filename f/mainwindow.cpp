#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <iostream>
#include <initializer_list>
// #include <typeinfo>

void addAll(QMenuBar* menuBar, std::initializer_list<QMenu*> menus) {
    for (auto menu : menus) {
        if (menu) {
            menuBar->addMenu(menu);
        }
    }
}

void addAll(QMenu* menu, std::initializer_list<QObject*> items) {
    for (auto item : items) {
        if (!item) continue;
        if (auto subMenu = qobject_cast<QMenu*>(item)) {
            menu->addMenu(subMenu);
        } else if (auto action = qobject_cast<QAction*>(item)) {
            menu->addAction(action);
        }
    }
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QMenuBar* menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    QMenu* menu1 = new QMenu("文件");
    QMenu* menu2 = new QMenu("编辑");
    QMenu* menu3 = new QMenu("视图");

    menuBar->addMenu(menu1);
    // menuBar->addMenu(menu2);
    // menuBar->addMenu(menu3);
    // menu1->addMenu(menu2);
    // menu1->addMenu(menu3);
    addAll(menuBar, {menu1});
    // addAll(menuBar, {menu1, menu2, menu3});
    QAction* action1 = new QAction("New Project");
    connect(action1, &QAction::triggered, this, []() {
        std::cout << "2222" << std::endl;
    });
    QAction* action2 = new QAction("New File");
    QAction* action3 = new QAction("Open File Or Project");
    addAll(menu1, {menu2, menu3, action1, action2, action3});
}

MainWindow::~MainWindow() {
    delete ui;
}
