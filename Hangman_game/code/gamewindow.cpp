#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "path.h"
#include <vector>
#include <string>
#include <QCoreApplication>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <QPixmap>
#include <QDebug>
#include <QMovie>


std::vector <std::string> alphabet{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
std::string main_word = "default"; // default global variable
std::vector <char> used_letters; // vector with letters which user finds
std::vector <int> index_used; // vector of indexes of letter which user finds
QString complexity = "default";
int step = 0;


void GameWindow::create_window(bool result) {
    if (result) {
        QString path = return_path();
        QPixmap pix01(path + "pictures/win_end.jpg");
        ui->endlabel->setPixmap(pix01.scaled(790, 400, Qt::KeepAspectRatio));
        ui->text_end_label->setText("Oh, you win! That was exciting! I thought of this word:");
        ui->word_label->setText(QString::fromStdString(main_word));
        QMovie* movie = new QMovie(path + "gifs/wingif.gif");
        ui->gifwinwidget->setVisible(true);
        ui->labelEnd4->setMovie(movie);
        movie->start();
    }
    else {
        ui->end_widget->setVisible(true);
        QString path = return_path();
        QPixmap pix01(path + "pictures/lose_end.png");
        ui->endlabel->setPixmap(pix01.scaled(790, 400, Qt::KeepAspectRatio));
        ui->text_end_label->setText("Oh, no! You lose... RIP you. I thought of this word:");
        ui->word_label->setText(QString::fromStdString(main_word));
        QMovie* movie = new QMovie(path + "gifs/losegif.gif");
        ui->giflosewidget->setVisible(true);
        ui->labelEnd0->setMovie(movie);
        ui->labelEnd1->setMovie(movie);
        ui->labelEnd2->setMovie(movie);
        ui->labelEnd3->setMovie(movie);
        movie->start();
    }
}

void GameWindow::receiveData(QString str) { // return data from "easy/medium/hard_data.txt"
    complexity = str;
    qDebug() << str;
}

std::vector <std::string> return_data() {// return data from "easy/medium/hard_data.txt"
    QString path = return_path();
    std::ifstream in0((path + "data_txt/" + complexity + "_data.txt").toStdString());    
    std::vector <std::string> words_data;
    std::string line;
    while (in0.peek() != EOF) {
        in0 >> line;
        words_data.push_back(line);
    }
    in0.close();
    return words_data;
}

void create_word() {
    std::vector <std::string> words_data = return_data();
    srand (time(0));
    main_word = words_data[rand() % words_data.size()];
}

std::string make_word() { // make new word for mywordlabel as user quesses
    std::string new_word = "";
    for (unsigned int i = 0; i < main_word.size(); ++i) {
        if (find(index_used.begin(), index_used.end(), i) != index_used.end()) {
            new_word += main_word[i];
            new_word += " ";
        }
        else {
            new_word += "_";
            new_word += " ";
        }
    }
    return new_word;
}

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    qDebug() << 3;

//    cwidget = new ChoiceWindow();
//    connect(ui->choice_btn, SIGNAL(clicked()), cwidget, SLOT(show()));

    ui->widget_game->setVisible(false);
    ui->end_widget->setVisible(false);
    QFont btn_font0("Noto Mono", 26);
    QFont btn_font1("Noto Mono", 18);
    ui->start_btn->setText("Start game");
    ui->choice_btn->setText("Change difficulty level");
    ui->start_btn->setFont(btn_font0);
    ui->choice_btn->setFont(btn_font1);

    ui->gifwinwidget->setVisible(false);
    ui->giflosewidget->setVisible(false);

    // connect choicewidget

    QFont result_font("Rockwell Extra Bold", 28);
    QFont end_font("Noto Mono", 14);
    ui->text_end_label->setFont(end_font);
    ui->word_label->setFont(result_font);

    ui->a_btn->setText(QString::fromStdString(alphabet[0]));
    ui->b_btn->setText(QString::fromStdString(alphabet[1]));
    ui->c_btn->setText(QString::fromStdString(alphabet[2]));
    ui->d_btn->setText(QString::fromStdString(alphabet[3]));
    ui->e_btn->setText(QString::fromStdString(alphabet[4]));
    ui->f_btn->setText(QString::fromStdString(alphabet[5]));
    ui->g_btn->setText(QString::fromStdString(alphabet[6]));
    ui->h_btn->setText(QString::fromStdString(alphabet[7]));
    ui->i_btn->setText(QString::fromStdString(alphabet[8]));
    ui->j_btn->setText(QString::fromStdString(alphabet[9]));
    ui->k_btn->setText(QString::fromStdString(alphabet[10]));
    ui->l_btn->setText(QString::fromStdString(alphabet[11]));
    ui->m_btn->setText(QString::fromStdString(alphabet[12]));
    ui->n_btn->setText(QString::fromStdString(alphabet[13]));
    ui->o_btn->setText(QString::fromStdString(alphabet[14]));
    ui->p_btn->setText(QString::fromStdString(alphabet[15]));
    ui->q_btn->setText(QString::fromStdString(alphabet[16]));
    ui->r_btn->setText(QString::fromStdString(alphabet[17]));
    ui->s_btn->setText(QString::fromStdString(alphabet[18]));
    ui->t_btn->setText(QString::fromStdString(alphabet[19]));
    ui->u_btn->setText(QString::fromStdString(alphabet[20]));
    ui->v_btn->setText(QString::fromStdString(alphabet[21]));
    ui->w_btn->setText(QString::fromStdString(alphabet[22]));
    ui->x_btn->setText(QString::fromStdString(alphabet[23]));
    ui->y_btn->setText(QString::fromStdString(alphabet[24]));
    ui->z_btn->setText(QString::fromStdString(alphabet[25]));

    QFont font("Noto Mono", 15);
    ui->a_btn->setFont(font);
    ui->b_btn->setFont(font);
    ui->c_btn->setFont(font);
    ui->d_btn->setFont(font);
    ui->e_btn->setFont(font);
    ui->f_btn->setFont(font);
    ui->g_btn->setFont(font);
    ui->h_btn->setFont(font);
    ui->i_btn->setFont(font);
    ui->j_btn->setFont(font);
    ui->k_btn->setFont(font);
    ui->l_btn->setFont(font);
    ui->m_btn->setFont(font);
    ui->n_btn->setFont(font);
    ui->o_btn->setFont(font);
    ui->p_btn->setFont(font);
    ui->q_btn->setFont(font);
    ui->r_btn->setFont(font);
    ui->s_btn->setFont(font);
    ui->t_btn->setFont(font);
    ui->u_btn->setFont(font);
    ui->v_btn->setFont(font);
    ui->w_btn->setFont(font);
    ui->x_btn->setFont(font);
    ui->y_btn->setFont(font);
    ui->z_btn->setFont(font);

    ui->mywordlabel->setFont(font);
    QString path = return_path();
    QPixmap pix(path + "pictures/png0.png");
    ui->pnglabel0->setPixmap(pix);
    QPixmap pix1(path + "pictures/png1.png");
    ui->pnglabel1->setPixmap(pix1);
    QPixmap pix2(path + "pictures/png2.png");
    ui->pnglabel2->setPixmap(pix2);
    QPixmap pix3(path + "pictures/png3.png");
    ui->pnglabel3->setPixmap(pix3);
    QPixmap pix4(path + "pictures/png4.png");
    ui->pnglabel4->setPixmap(pix4);
    QPixmap pix5(path + "pictures/png5.png");
    ui->pnglabel5->setPixmap(pix5);
    QPixmap pix6(path + "pictures/png6.png");
    ui->pnglabel6->setPixmap(pix6);
    QPixmap pix7(path + "pictures/png7.png");
    ui->pnglabel7->setPixmap(pix7);
    QPixmap pix8(path + "pictures/png8.png");
    ui->pnglabel8->setPixmap(pix8);

    ui->pnglabel1->setVisible(false);
    ui->pnglabel2->setVisible(false);
    ui->pnglabel3->setVisible(false);
    ui->pnglabel4->setVisible(false);
    ui->pnglabel5->setVisible(false);
    ui->pnglabel6->setVisible(false);
    ui->pnglabel7->setVisible(false);
    ui->pnglabel8->setVisible(false);

    QFont btn_font("Noto Mono", 14);
    ui->enter_label->setText("Enter the whole word");
    ui->enter_label->setFont(font);
    ui->enter_btn->setText("Check result");
    ui->enter_btn->setFont(btn_font);

}

void GameWindow::do_widget() { // change widget info
    create_word();
    ui->mywordlabel->setText(QString::fromStdString(make_word()));
}

bool check_word(char letter) { // find specified letter in main_word
    if (find(main_word.begin(), main_word.end(), letter) != main_word.end()) {
        used_letters.push_back(letter);
        for (unsigned int i = 0; i < main_word.size(); ++i) {
            if (main_word[i] == letter) {
                index_used.push_back(i);
            }
        }
        return true;
    }
    return false;
}

bool check_win() { // check win or not
    if (index_used.size() == main_word.size()) return true;
    return false;
}

void GameWindow::click_the_btn(char letter) { // check btn-clicking result
    if (check_word(letter)) {
        ui->mywordlabel->setText(QString::fromStdString(make_word()));
        if (check_win()) {
            ui->pnglabel8->setVisible(false);
            ui->widget_game->setVisible(false);
            ui->end_widget->setVisible(true);
            create_window(true); // win
        }
    }
    else {
        ++step;
        if (step == 1) {
            ui->pnglabel0->setVisible(false);
            ui->pnglabel1->setVisible(true);
        }
        else if (step == 2) {
            ui->pnglabel1->setVisible(false);
            ui->pnglabel2->setVisible(true);
        }
        else if (step == 3) {
            ui->pnglabel2->setVisible(false);
            ui->pnglabel3->setVisible(true);
        }
        else if (step == 4) {
            ui->pnglabel3->setVisible(false);
            ui->pnglabel4->setVisible(true);
        }
        else if (step == 5){
            ui->pnglabel4->setVisible(false);
            ui->pnglabel5->setVisible(true);
        }
        else if (step == 6){
            ui->pnglabel5->setVisible(false);
            ui->pnglabel6->setVisible(true);
        }
        else if (step == 7){
            ui->pnglabel6->setVisible(false);
            ui->pnglabel7->setVisible(true);
        }
        else if (step == 8){
            ui->pnglabel7->setVisible(false);
            ui->pnglabel8->setVisible(true);
        }
        if (step == 9) {
            ui->pnglabel8->setVisible(false);
            ui->widget_game->setVisible(false);
            ui->end_widget->setVisible(true);
            create_window(false); // lose

        }
    }
}


void GameWindow::on_a_btn_clicked()
{
    click_the_btn('a');
    ui->a_btn->setVisible(false);
}

void GameWindow::on_b_btn_clicked()
{
    click_the_btn('b');
    ui->b_btn->setVisible(false);
}

void GameWindow::on_c_btn_clicked()
{
    click_the_btn('c');
    ui->c_btn->setVisible(false);
}

void GameWindow::on_d_btn_clicked()
{
    click_the_btn('d');
    ui->d_btn->setVisible(false);
}

void GameWindow::on_e_btn_clicked()
{
    click_the_btn('e');
    ui->e_btn->setVisible(false);
}

void GameWindow::on_f_btn_clicked()
{
    click_the_btn('f');
    ui->f_btn->setVisible(false);
}

void GameWindow::on_g_btn_clicked()
{
    click_the_btn('g');
    ui->g_btn->setVisible(false);
}

void GameWindow::on_h_btn_clicked()
{
    click_the_btn('h');
    ui->h_btn->setVisible(false);
}

void GameWindow::on_i_btn_clicked()
{
    click_the_btn('i');
    ui->i_btn->setVisible(false);
}

void GameWindow::on_j_btn_clicked()
{
    click_the_btn('j');
    ui->j_btn->setVisible(false);
}

void GameWindow::on_k_btn_clicked()
{
    click_the_btn('k');
    ui->k_btn->setVisible(false);
}

void GameWindow::on_l_btn_clicked()
{
    click_the_btn('l');
    ui->l_btn->setVisible(false);
}

void GameWindow::on_m_btn_clicked()
{
    click_the_btn('m');
    ui->m_btn->setVisible(false);
}

void GameWindow::on_n_btn_clicked()
{
    click_the_btn('n');
    ui->n_btn->setVisible(false);
}

void GameWindow::on_o_btn_clicked()
{
    click_the_btn('o');
    ui->o_btn->setVisible(false);
}

void GameWindow::on_p_btn_clicked()
{
    click_the_btn('p');
    ui->p_btn->setVisible(false);
}

void GameWindow::on_q_btn_clicked()
{
    click_the_btn('q');
    ui->q_btn->setVisible(false);
}

void GameWindow::on_r_btn_clicked()
{
    click_the_btn('r');
    ui->r_btn->setVisible(false);
}

void GameWindow::on_s_btn_clicked()
{
    click_the_btn('s');
    ui->s_btn->setVisible(false);
}

void GameWindow::on_t_btn_clicked()
{
    click_the_btn('t');
    ui->t_btn->setVisible(false);
}

void GameWindow::on_u_btn_clicked()
{
    click_the_btn('u');
    ui->u_btn->setVisible(false);
}

void GameWindow::on_v_btn_clicked()
{
    click_the_btn('v');
    ui->v_btn->setVisible(false);
}

void GameWindow::on_w_btn_clicked()
{
    click_the_btn('w');
    ui->w_btn->setVisible(false);
}

void GameWindow::on_x_btn_clicked()
{
    click_the_btn('x');
    ui->x_btn->setVisible(false);
}

void GameWindow::on_y_btn_clicked()
{
    click_the_btn('y');
    ui->y_btn->setVisible(false);
}

void GameWindow::on_z_btn_clicked()
{
    click_the_btn('z');
    ui->z_btn->setVisible(false);
}

void GameWindow::on_enter_btn_clicked()
{
    QString word = ui->enter_lineEdit->text();
    if (word.toStdString() == main_word) {
        ui->widget_game->setVisible(false);
        ui->end_widget->setVisible(true);
        create_window(true); // win

    }
    else {
        ui->enter_lineEdit->setText("");
        ++step;
        if (step == 1) {
            ui->pnglabel0->setVisible(false);
            ui->pnglabel1->setVisible(true);
        }
        else if (step == 2) {
            ui->pnglabel1->setVisible(false);
            ui->pnglabel2->setVisible(true);
        }
        else if (step == 3) {
            ui->pnglabel2->setVisible(false);
            ui->pnglabel3->setVisible(true);
        }
        else if (step == 4) {
            ui->pnglabel3->setVisible(false);
            ui->pnglabel4->setVisible(true);
        }
        else if (step == 5){
            ui->pnglabel4->setVisible(false);
            ui->pnglabel5->setVisible(true);
        }
        else if (step == 6){
            ui->pnglabel5->setVisible(false);
            ui->pnglabel6->setVisible(true);
        }
        else if (step == 7){
            ui->pnglabel6->setVisible(false);
            ui->pnglabel7->setVisible(true);
        }
        else if (step == 8){
            ui->pnglabel7->setVisible(false);
            ui->pnglabel8->setVisible(true);
        }
        else if (step == 9) {
            ui->pnglabel8->setVisible(false);
            ui->widget_game->setVisible(false);
            ui->end_widget->setVisible(true);
            create_window(false); // lose

        }
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_start_btn_clicked() // start game
{
    ui->startgamewidget->setVisible(false);
    ui->widget_game->setVisible(true);
    do_widget();
}

void GameWindow::on_choice_btn_clicked()
{
    this->close();
    emit choiceWindow();
}
