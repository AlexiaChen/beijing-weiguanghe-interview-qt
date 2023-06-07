#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "higerwidgetview.h"
#include "higerwatchview.h"
#include "gettabwindow.h"
#include "databaseview.h"
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->addTab(new HigerWidgetView(this), QString("Feature 1"));
    ui->tabWidget->addTab(new HigerWatchView(this), QString("Feature 2"));
    ui->tabWidget->addTab(new GetTabWindow(this), QString("Feature 3"));
    ui->tabWidget->addTab(new databaseview(this), QString("Feature 4"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    // 计算子QWidget的新位置和大小
    int newWidth = event->size().width();
    int newHeight = event->size().height();
    int newX = 0;
    int newY = 0;
    ui->tabWidget->setGeometry(newX, newY, newWidth, newHeight);
}
