#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

#include <QWidget>

class QPushButton;
class QLCDNumber;
class QGroupBox;
class QRadioButton;
class QVBoxLayout;

namespace Ui {
class panel_control;
}

class panel_control : public QWidget
{
    Q_OBJECT

public:
    explicit panel_control(QWidget *parent = 0);
    ~panel_control();

    
private slots:
    void on_btn_pnl_setup_clicked();
    void on_btn_pnl_about_clicked();
    void on_btn_pnl_info_clicked();
    void on_btn_pnl_serialport_clicked();
    void on_btn_pnl_detail_clicked();
    void showTime();

  void btn_prev_clicked();
    void btn_next_clicked();

private:
    //Ui::panel_control *ui;
    QLCDNumber *lcd_time;
    QPushButton *btn_view;  //查看
    QPushButton *btn_info;   //返回
    QPushButton *btn_prev;  //前一个
    QPushButton *btn_next;  //下一个
    QGroupBox *grp_chn;  //信道组
    QRadioButton *rb_486;
    QRadioButton *rb_518;
    QRadioButton *rb_4209;
    QRadioButton *rb_all;
    QPushButton  *btn_setup;
    QPushButton  *btn_about;
    QVBoxLayout *layout;
    QVBoxLayout *vbox;
    QTimer *timer;                   //显示时间用的timer

signals:
    void mysignal(int);

};

#endif // CONTROL_PANEL_H
