#ifndef PANEL_DETAIL_H
#define PANEL_DETAIL_H

#include <QWidget>

#include "panel_info.h"
#include "common.h"

class QGridLayout;
class QLabel;
class QPushButton;



class panel_detail : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_detail(QWidget *parent = 0);
    void setcontent(ITEM_DATA *i);
    ~panel_detail();
    ITEM_DATA *item;
    
private:
    QGridLayout *layout;
    QLabel *lbl_code;
    QLabel *lbl_site;
    QLabel *lbl_infotype;
    QLabel *lbl_chn_title;
    QLabel *lbl_chn;
    QLabel *lbl_ber_title;
    QLabel *lbl_ber;
    QLabel *lbl_broadcast_title;
    QLabel *lbl_broadcast;
    QLabel *lbl_receive_title;
    QLabel *lbl_receive;
    QLabel *lbl_info;

    QPushButton *btn_ret;
    QPushButton *btn_tts;
protected:
    void retranslate(QWidget *parent);
    void changeEvent(QEvent *e);
private slots:
    void on_btn_ret_clicked();
    void on_btn_tts_clicked();
};

#endif // PANEL_DETAIL_H
