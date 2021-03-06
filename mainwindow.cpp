#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnPlot_clicked()
{
    ui->renderScreen->startGenerator();
}

void MainWindow::on_btnAudio_clicked()
{
     ui->renderScreen->startAudio();
}
