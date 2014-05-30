#ifndef SETUP_PANEL_H
#define SETUP_PANEL_H

#include <QWidget>

#include "FlowLayout.hpp"



class QPushButton;
class QRadioButton;
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

    QGroupBox *grp_timeset;
    QGroupBox *grp_toneset;
    QGroupBox *grp_system;


    QPushButton *btn_ret;
    QPushButton *btn_default;
    QPushButton *btn_save;

    QGroupBox *grp_lang;
    QRadioButton *rb_chn;
    QRadioButton *rb_eng;

    QLabel *lbl_datetime_title;
    QLabel *lbl_datetime;




    QSpinBox *sb_year;
    QSpinBox *sb_month;
    QSpinBox *sb_day;
    QPushButton *btn_setdate;

    QSpinBox *sb_hour;
    QSpinBox *sb_minute;
    QSpinBox *sb_second;
    QPushButton *btn_settime;


    QLabel *lbl_keytone;
    QSpinBox *sb_keytone; //按键音
    QSpinBox *sb_keytone_level; //按键音大小

    QLabel *lbl_hinttone;
    QSpinBox *sb_hinttone; //提示音
    QSpinBox *sb_hinttone_level; //提示音大小


    QCheckBox *cb_autotts;
    QSpinBox *sb_volum;   //音量
    QComboBox *combo_backlight; //背光
    QLabel *lbl_backlight;


    QPushButton *btn_db_backup;
    QPushButton *btn_db_export;
    QPushButton *btn_sys_upgrade;



protected:
    void timerEvent( QTimerEvent *event );
    void changeEvent(QEvent *e);
    void retranslate(QWidget *parent);
    int m_nTimerId;

private slots:
    void on_sb_keytone_valueChanged(int);
    void on_sb_keytone_level_valueChanged(int);
    void on_sb_hinttone_valueChanged(int);
    void on_sb_hinttone_level_valueChanged(int);
    void on_combo_backlight_currentIndexChanged(int);

    void on_btn_ret_clicked();
    void on_btn_default_clicked();
    void on_btn_save_clicked();

    void on_btn_setdate_clicked();
    void on_btn_settime_clicked();

    void on_btn_db_backup_clicked();
    void on_btn_db_export_clicked();
    void on_btn_sys_upgrade_clicked();

    void on_rb_chn_clicked();
    void on_rb_eng_clicked();

};

#endif // SETUP_PANEL_H
