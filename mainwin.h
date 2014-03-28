#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QKeyEvent>


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
signals:

private slots:
    void on_stacklayout_currentChanged(int index);
    void onReadyRead();
    void on_tmr_lcd_backlight_timeout();
    void on_tmr_keypad_backlight_timeout();



private:
    QStackedLayout *stacklayout;
    panel_info *pnl_info;
    panel_setup *pnl_setup;
    panel_detail *pnl_detail;
    panel_about *pnl_about;

    QextSerialPort *serialport;
    QTimer *tmr_keypad_backlight;  //按键板的背光
    QTimer *tmr_lcd_backlight;     //LCD的背光



};

#endif // MAINWIN_H
