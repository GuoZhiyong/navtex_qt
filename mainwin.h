#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

#include "common.h"

class QStackedLayout;
class panel_control;
class panel_info;
class panel_setup;
class panel_detail;
class panel_about;

class QextSerialPort;

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
    void btnViewClick(ITEM_DATA *item); //panel_item 查看按鈕按下
    void btnTTSClick(ITEM_DATA *item);

protected:
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent (QMouseEvent * event);
    bool event(QEvent *event);
signals:

private slots:
    void on_stacklayout_currentChanged(int index);
    void onReadyRead();

private:
    QStackedLayout *stacklayout;
    panel_info *pnl_info;
    panel_setup *pnl_setup;
    panel_detail *pnl_detail;
    panel_about *pnl_about;

    QextSerialPort *serialport;

};

#endif // MAINWIN_H
