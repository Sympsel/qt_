// widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QSlider>
#include <QProgressBar>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QListWidget>
#include <QTableWidget>
#include <QTabWidget>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QFrame>
#include <QScrollBar>
#include <QHeaderView>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("QSS 样式展示");
    resize(900, 700);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

            // ========== 按钮区域 ==========
    QGroupBox *btnGroup = new QGroupBox("按钮 (QPushButton)");
    QHBoxLayout *btnLayout = new QHBoxLayout(btnGroup);

    QPushButton *btnNormal = new QPushButton("普通按钮");
    QPushButton *btnPrimary = new QPushButton("主要按钮");
    btnPrimary->setObjectName("primaryButton");  // 可在qss中单独定义样式
    QPushButton *btnDanger = new QPushButton("危险按钮");
    btnDanger->setObjectName("dangerButton");
    QPushButton *btnDisabled = new QPushButton("禁用按钮");
    btnDisabled->setEnabled(false);

    btnLayout->addWidget(btnNormal);
    btnLayout->addWidget(btnPrimary);
    btnLayout->addWidget(btnDanger);
    btnLayout->addWidget(btnDisabled);
    btnLayout->addStretch();
    mainLayout->addWidget(btnGroup);

            // ========== 输入区域 ==========
    QGroupBox *inputGroup = new QGroupBox("输入控件 (QLineEdit / QComboBox / QSpinBox)");
    QHBoxLayout *inputLayout = new QHBoxLayout(inputGroup);

    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("请输入文本...");

    QComboBox *comboBox = new QComboBox();
    comboBox->addItems({"选项一", "选项二", "选项三", "选项四"});
    comboBox->setEditable(true);

    QSpinBox *spinBox = new QSpinBox();
    spinBox->setRange(0, 100);
    spinBox->setValue(50);

    inputLayout->addWidget(lineEdit);
    inputLayout->addWidget(comboBox);
    inputLayout->addWidget(spinBox);
    mainLayout->addWidget(inputGroup);

            // ========== 选择区域 ==========
    QGroupBox *checkGroup = new QGroupBox("选择控件 (QCheckBox / QRadioButton)");
    QHBoxLayout *checkLayout = new QHBoxLayout(checkGroup);

    QCheckBox *check1 = new QCheckBox("未选中");
    QCheckBox *check2 = new QCheckBox("已选中");
    check2->setChecked(true);
    QCheckBox *check3 = new QCheckBox("禁用");
    check3->setEnabled(false);

    QRadioButton *radio1 = new QRadioButton("选项 A");
    QRadioButton *radio2 = new QRadioButton("选项 B");
    radio2->setChecked(true);
    QRadioButton *radio3 = new QRadioButton("禁用");
    radio3->setEnabled(false);

    checkLayout->addWidget(check1);
    checkLayout->addWidget(check2);
    checkLayout->addWidget(check3);
    checkLayout->addSpacing(20);
    checkLayout->addWidget(radio1);
    checkLayout->addWidget(radio2);
    checkLayout->addWidget(radio3);
    checkLayout->addStretch();
    mainLayout->addWidget(checkGroup);

            // ========== 滑块与进度条 ==========
    QGroupBox *sliderGroup = new QGroupBox("滑块与进度 (QSlider / QProgressBar / QScrollBar)");
    QVBoxLayout *sliderLayout = new QVBoxLayout(sliderGroup);

    QSlider *hSlider = new QSlider(Qt::Horizontal);
    hSlider->setRange(0, 100);
    hSlider->setValue(30);

    QProgressBar *progressBar = new QProgressBar();
    progressBar->setValue(65);
    progressBar->setFormat("进度: %p%");

    QScrollBar *hScrollBar = new QScrollBar(Qt::Horizontal);
    hScrollBar->setRange(0, 100);
    hScrollBar->setValue(40);

    sliderLayout->addWidget(hSlider);
    sliderLayout->addWidget(progressBar);
    sliderLayout->addWidget(hScrollBar);
    mainLayout->addWidget(sliderGroup);

            // ========== 标签与分隔线 ==========
    QGroupBox *labelGroup = new QGroupBox("标签与分隔 (QLabel / QFrame)");
    QVBoxLayout *labelLayout = new QVBoxLayout(labelGroup);

    QLabel *labelNormal = new QLabel("普通标签文本");
    QLabel *labelLink = new QLabel("<a href='#'>带链接的标签</a>");
    labelLink->setOpenExternalLinks(true);

    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    QLabel *labelTip = new QLabel("提示信息样式");
    labelTip->setObjectName("tipLabel");

    labelLayout->addWidget(labelNormal);
    labelLayout->addWidget(labelLink);
    labelLayout->addWidget(line);
    labelLayout->addWidget(labelTip);
    mainLayout->addWidget(labelGroup);

            // ========== 中部：列表 + 表格 + 文本编辑 ==========
    QHBoxLayout *midLayout = new QHBoxLayout();

    // 列表
    QGroupBox *listGroup = new QGroupBox("列表 (QListWidget)");
    QVBoxLayout *listLayout = new QVBoxLayout(listGroup);
    QListWidget *listWidget = new QListWidget();
    listWidget->addItems({"项目 1", "项目 2", "项目 3", "项目 4", "项目 5"});
    listWidget->setCurrentRow(1);
    listLayout->addWidget(listWidget);
    midLayout->addWidget(listGroup, 1);

            // 表格
    QGroupBox *tableGroup = new QGroupBox("表格 (QTableWidget)");
    QVBoxLayout *tableLayout = new QVBoxLayout(tableGroup);
    QTableWidget *tableWidget = new QTableWidget(4, 3);
    tableWidget->setHorizontalHeaderLabels({"姓名", "年龄", "城市"});
    tableWidget->setItem(0, 0, new QTableWidgetItem("张三"));
    tableWidget->setItem(0, 1, new QTableWidgetItem("25"));
    tableWidget->setItem(0, 2, new QTableWidgetItem("北京"));
    tableWidget->setItem(1, 0, new QTableWidgetItem("李四"));
    tableWidget->setItem(1, 1, new QTableWidgetItem("30"));
    tableWidget->setItem(1, 2, new QTableWidgetItem("上海"));
    tableWidget->setItem(2, 0, new QTableWidgetItem("王五"));
    tableWidget->setItem(2, 1, new QTableWidgetItem("28"));
    tableWidget->setItem(2, 2, new QTableWidgetItem("广州"));
    tableWidget->setItem(3, 0, new QTableWidgetItem("赵六"));
    tableWidget->setItem(3, 1, new QTableWidgetItem("35"));
    tableWidget->setItem(3, 2, new QTableWidgetItem("深圳"));
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableLayout->addWidget(tableWidget);
    midLayout->addWidget(tableGroup, 2);

            // 文本编辑
    QGroupBox *editGroup = new QGroupBox("文本编辑 (QTextEdit)");
    QVBoxLayout *editLayout = new QVBoxLayout(editGroup);
    QTextEdit *textEdit = new QTextEdit();
    textEdit->setPlainText("这是一段示例文本。\n可以测试选中、高亮等样式效果。");
    editLayout->addWidget(textEdit);
    midLayout->addWidget(editGroup, 2);

    mainLayout->addLayout(midLayout);

            // ========== Tab 控件 ==========
    QTabWidget *tabWidget = new QTabWidget();
    QWidget *tab1 = new QWidget();
    tab1->setLayout(new QVBoxLayout());
    tab1->layout()->addWidget(new QLabel("Tab 1 内容区域"));
    tab1->layout()->addWidget(new QPushButton("Tab 1 按钮"));

    QWidget *tab2 = new QWidget();
    tab2->setLayout(new QVBoxLayout());
    tab2->layout()->addWidget(new QLabel("Tab 2 内容区域"));
    tab2->layout()->addWidget(new QLineEdit("Tab 2 输入框"));

    QWidget *tab3 = new QWidget();
    tab3->setLayout(new QVBoxLayout());
    tab3->layout()->addWidget(new QProgressBar());
    ((QProgressBar*)tab3->layout()->itemAt(0)->widget())->setValue(80);

    tabWidget->addTab(tab1, "基础组件");
    tabWidget->addTab(tab2, "表单输入");
    tabWidget->addTab(tab3, "状态显示");
    tabWidget->setTabEnabled(2, true);

    mainLayout->addWidget(tabWidget);

            // ========== 状态栏模拟 ==========
    QStatusBar *statusBar = new QStatusBar();
    statusBar->showMessage("就绪");
    statusBar->addPermanentWidget(new QLabel("QSS 预览模式"));
    mainLayout->addWidget(statusBar);
}

Widget::~Widget()
{
    delete ui;
}