#ifndef CHOICEWINDOW_H
#define CHOICEWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

namespace Ui {
class ChoiceWindow;
}

class ChoiceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChoiceWindow(QWidget *parent = nullptr);
    ~ChoiceWindow();

private slots:
    void on_easy_btn_clicked();

    void on_medium_btn_clicked();

    void on_hard_btn_clicked();

signals:
    void sendData(QString str);

private:
    Ui::ChoiceWindow *ui;
    GameWindow *gWindow;
};

#endif // CHOICEWINDOW_H
