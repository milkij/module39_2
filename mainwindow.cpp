#include "mainwindow.h"
#include "./ui_mainwindow.h"
//
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Check phone number");
    resize(200,50);
    //
    connect(ui->lineEdit, &QLineEdit::textChanged, [this](QString curText){
          QRegularExpression hasPhoneMatch("^\\+\[0-9]{11}$");
        if(hasPhoneMatch.match(curText).hasMatch()) setGreenColor();
        else setRedColor();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
void MainWindow::setRedColor()
{
    ui->label->setText("INVALID");
    ui->label->setStyleSheet("QLabel {color: red;}");
}

void MainWindow::setGreenColor()
{
    ui->label->setText("VALID");
    ui->label->setStyleSheet("QLabel {color: green;}");
}
