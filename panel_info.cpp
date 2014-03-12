#include "panel_info.h"
#include "ui_panel_info.h"
#include "FlowLayout.hpp"
#include "panel_item.h"
#include "main.h"

#include <QDebug>
#include <QtGui>
#include <QDateTime>


panel_info::panel_info(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::panel_info)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::ClickFocus);

    QString style = "QScrollBar:vertical {min-width: 30px;}";
    setStyleSheet(style);
    layout=new FlowLayout(0,5,0);
    //ui->scrollAreaWidgetContents->setLayout(layout);
    ui->scroll_widget->setLayout(layout);
    //setWidget(ui->scroll_widget);  //不需要，加上后反而不显示
    //layout->itemAt(0); //定位到第一条
}
//按键事件处理
void panel_info::keyPressEvent( QKeyEvent *event )
{
    if(event->key()==Qt::Key_Up)
   {
        qDebug()<<"Q press";
   }
}

//重绘自己的item，擦除原来了，绘制新的actived
void panel_info::myDrawItem(int index)
{
//    panel_item *item;
//    item=(panel_item*)(layout->itemAt(navtexitemlist_pos)->widget()); //绘制原来的
//    navtexitemlist_pos=index;
//    item->repaint();
//    item=(panel_item*)(layout->itemAt(navtexitemlist_pos)->widget()); //绘制新的
//    item->repaint();
}

void panel_info::addNavtexItem(QWidget *widget)
{
    layout->addWidget(widget);
}

panel_info::~panel_info()
{
    delete ui;
}

void panel_info::serialport_rx(QByteArray bytes)
{
    qDebug()<<"panel_info rx:"<<bytes.size();
    qDebug()<<"bytes:"<<bytes;

}

////用户按下[详情]按钮，判断是否已读,显示详细信息
//void panel_info::btnViewClick(NAVTEXITEM *item)
//{
//    myDrawItem(item->index);//绘制panel_info
//    if(item->fRead==0)  //还没有阅读,修改数据库记录
//    {

//    }
////    pnl_detail->setcontent(item);
////    stack->setCurrentIndex(1);
//}
////按下播报
//void panel_info::btnTTSClick(NAVTEXITEM *item)
//{
//    myDrawItem(item->index);

//}


