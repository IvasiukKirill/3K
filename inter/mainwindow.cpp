#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame_3->setVisible(false);
    ui->frame->setVisible(false);
    ui->frame_4->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_vhod_clicked()
{
    ui->frame_2->setVisible(false);
    ui->frame->setVisible(true);
}

void MainWindow::on_pushButton_nach_clicked()
{
    ui->frame_3->setVisible(true);
    ui->frame->setVisible(false);
}

void MainWindow::on_pushButton_konch_clicked()
{
    ui->frame_3->setVisible(false);
    ui->frame->setVisible(true);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->frame_4->setVisible(true);
    ui->frame->setVisible(false);

}

void MainWindow::on_pushButton_vozvrat_clicked()
{
    ui->frame_4->setVisible(false);
    ui->frame->setVisible(true);
}
