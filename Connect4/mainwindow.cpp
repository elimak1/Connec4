#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      logic_(new Logic)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete logic_;
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    int column = ui->spinBox->value();
    if(!logic_->addPiece(column)){
       qDebug() << "Not a valid move, try again\n";
    }
}
