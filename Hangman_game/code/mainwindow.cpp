#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "path.h"
#include <QApplication>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <QMovie>
#include <QCoreApplication>
#include <fstream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << return_path();

    cWindow = new ChoiceWindow(); // connect ChoiceWindow
//    connect(cWindow, &ChoiceWindow::firstWindow, this, &MainWindow::show);

    ui->main_label->setText("Hangman");
    QFont main_font("MV Boli", 88);
    ui->main_label->setFont(main_font);

    ui->pushButton->setText("Start");
    QFont btn_font("Noto Mono", 26);
    ui->pushButton->setFont(btn_font);

    QString path = return_path();
    QMovie* movie = new QMovie(path + "gifs/start_gif.gif");
    ui->giflabel->setMovie(movie);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // open ChoiceWindow
{
    cWindow->show();
    this->close();
}
