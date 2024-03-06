#include "choicewindow.h"
#include "ui_choicewindow.h"
#include "path.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QCoreApplication>
#include <QDebug>

ChoiceWindow::~ChoiceWindow()
{
    delete ui;
}

void ChoiceWindow::on_easy_btn_clicked()
{
    emit sendData(QString::fromStdString("easy"));
    gWindow->show();
    this->close();
}

void ChoiceWindow::on_medium_btn_clicked()
{
    emit sendData(QString::fromStdString("medium"));
    gWindow->show();
    this->close();
}

void ChoiceWindow::on_hard_btn_clicked()
{
    emit sendData(QString::fromStdString("hard"));
    gWindow->show();
    this->close();
}

ChoiceWindow::ChoiceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChoiceWindow)
{
    ui->setupUi(this);
    qDebug() << 2;

    gWindow = new GameWindow(); // connect GameWindow
    connect(this, SIGNAL(sendData(QString)), gWindow, SLOT(receiveData(QString)));
    connect(ui->easy_btn, SIGNAL(clicked()), this, SLOT(on_easy_btn_clicked()));
    connect(ui->medium_btn, SIGNAL(clicked()), this, SLOT(on_medium_btn_clicked()));
    connect(ui->hard_btn, SIGNAL(clicked()), this, SLOT(on_hard_btn_clicked()));
    connect(gWindow, &GameWindow::choiceWindow, this, &ChoiceWindow::show);

    ui->choice_label->setText("Select difficulty level:");

    QFont main_font("Tw Cen MT", 45);
    ui->choice_label->setFont(main_font);

    ui->easy_btn->setText("Easy");

    QFont btn_font("Noto Mono", 28);
    ui->easy_btn->setFont(btn_font);
    ui->medium_btn->setText("Medium");
    ui->medium_btn->setFont(btn_font);
    ui->hard_btn->setText("Hard");
    ui->hard_btn->setFont(btn_font);
}

