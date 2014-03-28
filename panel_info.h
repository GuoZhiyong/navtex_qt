
#ifndef PANEL_INFO_H
#define PANEL_INFO_H

#include "FlowLayout.hpp"
#include <QScrollArea>

#include <QtSql>
#include <QKeyEvent>


class QPushButton;
class QLCDNumber;
class QGroupBox;
class QRadioButton;
class QVBoxLayout;
class QHBoxLayout;
class QScrollArea;

#include "common.h"

class panel_info : public QWidget
{
    Q_OBJECT

public:
    explicit panel_info(QWidget *parent = 0);
    ~panel_info();
    //void keyPressEvent(QKeyEvent  *event);
    void myDrawItem(int index);
    void addNavtexItem(QWidget *);
    void clear() const;
    void updateNavtexItemList(int chn);

    FlowLayout *leftlayout;             //主布局管理器，用来访问单个的panel_item

public slots:
    void serialport_rx(QByteArray bytes);
    void showTime();

    void rb_show_486();
    void rb_show_518();
    void rb_show_4209();
    void rb_show_all();

    void on_btn_view_clicked();
    void on_btn_prev_clicked();
    void on_btn_next_clicked();
    void on_btn_setup_clicked();
    void on_btn_about_clicked();
    void on_btn_exit_clicked();

private:
    QHBoxLayout *mainlayout;


    QScrollArea *scrollarea;
    QWidget *scrollwidget;

    QLCDNumber *lcd_time;
    QPushButton *btn_view;  //查看
    QPushButton *btn_prev;  //前一个
    QPushButton *btn_next;  //下一个
    QGroupBox *grp_chn;  //信道组
    QRadioButton *rb_486;
    QRadioButton *rb_518;
    QRadioButton *rb_4209;
    QRadioButton *rb_all;
    QPushButton  *btn_setup;
    QPushButton  *btn_about;
    QPushButton  *btn_exit;
    QVBoxLayout *rightlayout;
    QVBoxLayout *vbox;
    QTimer *timer;                   //显示时间用的timer


};

#endif // PANEL_INFO_H
