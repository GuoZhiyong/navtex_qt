#ifndef PANEL_ITEM_H
#define PANEL_ITEM_H

#include <QWidget>
#include <QtGui>

#include <QLabel>
#include <QPushButton>
#include <QLine>
#include <QHBoxLayout>
#include <QVBoxLayout>


#include "panel_info.h"
#include "navtexitem.h"

class panel_item : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_item(QWidget *parent = 0);
    explicit panel_item(int i,NAVTEXITEM *item,QWidget *parent = 0);
    ~panel_item();

    NAVTEXITEM *itemvalue;     //保留对应的list
signals:
    void viewClick(NAVTEXITEM *itemvalue); //按下view发送的信号，也可同tts一同发送
    void ttsClick(NAVTEXITEM *itemvalue);
protected:
    void paintEvent(QPaintEvent *event);//重绘事件处理
private:
    int index;                 //自己添加的id,对应flowlayout中的位置，从0开始
    QLabel *lbl_time_broadcast;
    QLabel *lbl_time_receive;
    QLabel *lbl_code;
    QPushButton *btn_view;
    QPushButton *btn_tts;
    QFrame *line;
    QHBoxLayout *hlayout; //水平布局
    QVBoxLayout *vlayout; //时间的layout
    QVBoxLayout *layout;  //主要的layout

private slots:
    void myviewClick();    //按下响应的事件
    void myttsClick();    //按下tts响应的事件
};

#endif // PANEL_ITEM_H
