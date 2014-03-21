#ifndef SETUP_PANEL_H
#define SETUP_PANEL_H

#include <QWidget>

#include "FlowLayout.hpp"

class QPushButton;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QHBoxLayout;
class QVBoxLayout;
class QSpinBox;

class panel_setup : public QWidget
{
    Q_OBJECT

public:
    explicit panel_setup(QWidget *parent = 0);
    ~panel_setup();

private:
    QPushButton *btn_ret;
    QPushButton *btn_default;

    QPushButton *btn_timeset;  //时间设置
    QSpinBox *sb_year;
    QSpinBox *sb_month;
    QSpinBox *sb_day;
    QSpinBox *sb_hour;
    QSpinBox *sb_minute;
    QSpinBox *sb_second;

    QPushButton *btn_chnset;   //通道设置
    QPushButton *btn_toneset;  //提示音设置
    QPushButton *btn_backlight; //背光设置

    QPushButton btn_keytone;
    QCheckBox *cb_keytone;
    QSpinBox *sb_keytone; //按键音

    QPushButton btn_hinttone;
    QCheckBox *cb_hinttone;
    QSpinBox *sb_hinttone; //提示音


    QCheckBox *cb_autotts;
    QSpinBox *sb_volum;   //音量
    QComboBox *combo_backlight; //背光

    QPushButton *btn_db_backup;
    QPushButton *btn_db_export;



private slots:
    void on_btn_ret_clicked();
    void on_btn_default_clicked();

};


#endif // SETUP_PANEL_H
