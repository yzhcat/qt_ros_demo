#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlainText("hello");
    this->_aQNode = new RQNode();
    connect(
        ui->pushButton, &QPushButton::clicked, this, [=]()
        { 
            this->_aQNode->_pub_msgs(ui->plainTextEdit->toPlainText());
            _aQNode->sping(); });

    connect(this->_aQNode, &RQNode::TopicData, this, [=](QString msg)
            { ui->label->setText(msg); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
