#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QKeyEvent>
#include <QtSql>

#include "navtexitem.h"

class QStackedLayout;
class panel_control;
class panel_info;
class panel_setup;
class panel_serial;
class panel_detail;
class panel_about;


class MainWin : public QWidget
{
    Q_OBJECT
    static MainWin  *INSTANCE;
    static int item_pos;

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();
    static MainWin* instance() {return INSTANCE;}

    void setStackIndex(int);
    void btnViewClick(NAVTEXITEM *item); //panel_item 查看按鈕按下
    void btnTTSClick(NAVTEXITEM *item);
    void add_pnl_info_item(int channel_type);

protected:
    void keyPressEvent(QKeyEvent *);
signals:

public slots:
    void slot_panel_control_btn_prev_clicked();
    void slot_panel_item_btn_view_clicked();
private:
    //QList<NAVTEXITEM *> navtexitemlist;
    QSqlDatabase dbconn;            //存储数据库访问的实例

    QStackedLayout *stacklayout;
    panel_info *pnl_info;
    panel_setup *pnl_setup;
    panel_serial *pnl_serial;
    panel_detail *pnl_detail;
    panel_about *pnl_about;

};

#endif // MAINWIN_H
