#include "mainwin.h"
#include <QDebug>

#include "FlowLayout.hpp"

#include "panel_control.h"
#include "panel_info.h"
#include "panel_serial.h"
#include "panel_setup.h"
#include "panel_about.h"
#include "panel_detail.h"
#include "panel_item.h"

MainWin* MainWin::INSTANCE=0;

MainWin::MainWin(QWidget *parent) : QWidget(parent)
{
    INSTANCE = this;

    pnl_cp = new panel_control;
    pnl_info=new panel_info;
    pnl_setup =new panel_setup;
    pnl_serial =new panel_serial;
    pnl_detail = new panel_detail;
    pnl_about = new panel_about;

    stack=new QStackedWidget();
    stack->addWidget(pnl_info);
    stack->addWidget(pnl_detail);
    stack->addWidget(pnl_setup);
    stack->addWidget(pnl_serial);
    stack->addWidget(pnl_about);

    QObject::connect(pnl_cp,SIGNAL(mysignal(int)),stack,SLOT(setCurrentIndex(int))); //关联显示内容的改变
    QObject::connect(pnl_serial,SIGNAL(signal_serialport_rx(QByteArray)),pnl_info,SLOT(serialport_rx(QByteArray)));
    QObject::connect(pnl_cp,SIGNAL(btn_prev_clicked()),SLOT(slot_panel_control_btn_prev_clicked()));


    QHBoxLayout *layout = new QHBoxLayout;
    setLayout(layout);
    layout->addWidget(stack,15,0);
    layout->addWidget(pnl_cp,1,0);
    layout->setContentsMargins(0,0,0,0);
    //win->setWindowFlags(Qt::FramelessWindowHint);

    /*打开数据库*/
    dbconn=QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("Informationdb.db");
    if(!dbconn.open())
    {
        qDebug()<<"打开数据库错误"<<dbconn.lastError()<<endl;
    }

    /*添加数据*/
    int index=0;
    NAVTEXITEM *pnavtexitem;
    panel_item *ppanel_item;

    QSqlQuery query;
    query.exec("select * from Informations");
    while(query.next())
    {
        pnavtexitem = new NAVTEXITEM;
        pnavtexitem->id = query.value(0).toInt();  //对应数据库的id
        pnavtexitem->code=query.value(2).toString();   //技术编码
        pnavtexitem->chn=query.value(3).toInt();    //使用通道
        pnavtexitem->Broadcast=query.value(1).toString();
        //pnavtexitem->DateTimeReceive=query.value(2).toString();
        pnavtexitem->Content=query.value(9).toString();
        pnavtexitem->fRead=query.value(7).toInt();
        pnavtexitem->BER=query.value(8).toInt();
        pnavtexitem->index=index;
        navtexitemlist<<pnavtexitem;
     }
//添加panel_item
    QList<NAVTEXITEM *>::iterator i;
    for(i=navtexitemlist.begin(),index=0;i!=navtexitemlist.end();++i,++index)
    {
        ppanel_item=new panel_item(index,*i);
        pnl_info->addNavtexItem(ppanel_item);
        connect(ppanel_item,SIGNAL(viewClick(NAVTEXITEM *)),this,SLOT(btnViewClick(NAVTEXITEM *))); //关联信号槽
        connect(ppanel_item,SIGNAL(ttsClick(NAVTEXITEM *)),this,SLOT(btnTTSClick(NAVTEXITEM *)));
    }
    navtexitemlist_pos=0;
    resize(800,600);
    setFocus();
}


MainWin::~MainWin()
{
    dbconn.close();
    navtexitemlist.clear();
}

void MainWin::keyPressEvent( QKeyEvent *event )
{
    if(event->key()==Qt::Key_Up)
   {
        qDebug()<<"win Q press";
   }
}

void MainWin::slot_panel_control_btn_prev_clicked()
{
        if(stack->currentIndex()==0)  //pnl_info
        {
            int i=navtexitemlist_pos;
            if(i==0)
            {
                i=navtexitemlist.size();
            }
            i--;
            pnl_info->myDrawItem(i);
        }
        setFocusProxy(pnl_info);
}


 void MainWin::slot_panel_item_btn_view_clicked()
 {

 }

//panel_item按下【查看】按钮
//检查数据库记录是否已读
//切换至panel_detail
 void MainWin::btnViewClick(NAVTEXITEM *item)
 {
    pnl_detail->setcontent(item);
    stack->setCurrentIndex(1);
 }


 void MainWin::btnTTSClick(NAVTEXITEM *item)
 {

 }


 void MainWin::setStackIndex(int i)
 {
     stack->setCurrentIndex(i);
 }
