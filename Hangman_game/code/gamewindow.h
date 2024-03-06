#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>


namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void on_a_btn_clicked();

    void on_b_btn_clicked();

    void on_c_btn_clicked();

    void on_d_btn_clicked();

    void on_e_btn_clicked();

    void on_f_btn_clicked();

    void on_g_btn_clicked();

    void on_h_btn_clicked();

    void on_i_btn_clicked();

    void on_j_btn_clicked();

    void on_k_btn_clicked();

    void on_l_btn_clicked();

    void on_m_btn_clicked();

    void on_n_btn_clicked();

    void on_o_btn_clicked();

    void on_p_btn_clicked();

    void on_q_btn_clicked();

    void on_r_btn_clicked();

    void on_s_btn_clicked();

    void on_t_btn_clicked();

    void on_u_btn_clicked();

    void on_v_btn_clicked();

    void on_w_btn_clicked();

    void on_x_btn_clicked();

    void on_y_btn_clicked();

    void on_z_btn_clicked();

    void on_enter_btn_clicked();

    void click_the_btn(char letter);

    void on_start_btn_clicked();

    void on_choice_btn_clicked();

    void do_widget();

    void create_window(bool result);

public slots:
    void receiveData(QString str);

signals:
    void choiceWindow();

private:
    Ui::GameWindow *ui;
//    ChoiceWindow *cwidget;
};

#endif // GAMEWINDOW_H
