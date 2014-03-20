#ifndef PANEL_DETAIL_H
#define PANEL_DETAIL_H

#include <QWidget>

#include "panel_info.h"
#include "common.h"


namespace Ui {
class panel_detail;
}

class panel_detail : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_detail(QWidget *parent = 0);
    void setcontent(NAVTEXITEM *i);
    ~panel_detail();
    NAVTEXITEM *item;
    
private:
    Ui::panel_detail *ui;
private slots:
    void on_btn_ret_clicked();
    void on_btn_tts_clicked();
};

#endif // PANEL_DETAIL_H
