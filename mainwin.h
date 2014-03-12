#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QKeyEvent>

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
public:
    explicit MainWin(QWidget *parent = 0);
protected:
    void keyPressEvent(QKeyEvent *);
signals:

public slots:
    void slot_panel_control_btn_prev_clicked();
    void slot_panel_item_btn_view_clicked();
private:
    QStackedWidget *stack;
    panel_control *pnl_cp;
    panel_info *pnl_info;
    panel_setup *pnl_setup;
    panel_serial *pnl_serial;
    panel_detail *pnl_detail;
    panel_about *pnl_about;

};

#endif // MAINWIN_H
