#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QKeyEvent>
#include <QtSql>

#include "navtexitem.h"

class QStackedWidget;
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
public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();

    static MainWin* instance() {return INSTANCE;}

    void setStackIndex(int);

protected:
    void keyPressEvent(QKeyEvent *);
signals:

public slots:
    void slot_panel_control_btn_prev_clicked();
    void slot_panel_item_btn_view_clicked();
    void btnViewClick(NAVTEXITEM *item);
    void btnTTSClick(NAVTEXITEM *item);
private:
    QList<NAVTEXITEM *> navtexitemlist;
    int navtexitemlist_pos;
    QSqlDatabase dbconn;            //存储数据库访问的实例

    QStackedWidget *stack;
    panel_control *pnl_cp;
    panel_info *pnl_info;
    panel_setup *pnl_setup;
    panel_serial *pnl_serial;
    panel_detail *pnl_detail;
    panel_about *pnl_about;

};

#endif // MAINWIN_H
