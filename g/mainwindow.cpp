#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QToolBar>
#include <iostream>
#include <QProgressBar>
#include <QDockWidget>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QToolBar* toolBar = new QToolBar(this);
    QAction* action1 = new QAction("保存");
    QAction* action2 = new QAction("打开");
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    action1->setIcon(QIcon(":/保存.png"));
    action2->setIcon(QIcon(":/打开.png"));
    toolBar->addAction(action1);
    toolBar->addAction(action2);
    this->addToolBar(Qt::LeftToolBarArea, toolBar);

    connect(action1, &QAction::triggered, this, []() {
        std::cout << "保存" << std::endl;
    });
    connect(action2, &QAction::triggered, this, []() {
        std::cout << "打开" << std::endl;
    });

    QStatusBar* statusBar = this->statusBar();
    statusBar->showMessage("Init...", 3000);
    statusBar->setVisible(true);

    QProgressBar* progressBar = new QProgressBar();
    progressBar->setRange(0, 100);
    progressBar->setValue(50);
    statusBar->addPermanentWidget(progressBar);

    QDockWidget* dockWidget = new QDockWidget();
    this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    dockWidget->setWindowTitle("A Float Window");

    QWidget* treeWidget = new QWidget();
    QVBoxLayout*  layout = new QVBoxLayout();
    treeWidget->setLayout(layout);
    QPushButton* aButton = new QPushButton();
    QPushButton* bButton = new QPushButton();
    layout->addWidget(aButton);
    layout->addWidget(bButton);
    dockWidget->setWidget(treeWidget);

}

MainWindow::~MainWindow() {
    delete ui;
}
