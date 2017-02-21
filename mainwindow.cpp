#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sixhex.h"
#include "sixhexgraph.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    SixHexGraph *shg = new SixHexGraph(5,5);
    shg->BorderTable[1][1][1] = Stream;
    ui->label->setNum(shg->getTotalRow());
    ui->label_2->setNum(shg->getTotalColumn());
    ui->label_3->setNum(shg->TerrainTable[1][1]);
    ui->label_4->setNum(shg->BorderTable[1][1][1]);

}
