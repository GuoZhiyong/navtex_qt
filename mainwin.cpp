#include "mainwin.h"
#include <QDebug>

#include "FlowLayout.hpp"


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

   // pnl_cp = new panel_control;
    pnl_info=new panel_info;
    pnl_setup =new panel_setup;
    pnl_serial =new panel_serial;
    pnl_detail = new panel_detail;
    pnl_about = new panel_about;

    stacklayout=new QStackedLayout();
    stacklayout->addWidget(pnl_info);
    stacklayout->addWidget(pnl_detail);
    stacklayout->addWidget(pnl_setup);
    stacklayout->addWidget(pnl_serial);
    stacklayout->addWidget(pnl_about);


    stacklayout->setCurrentIndex(0);

   // QObject::connect(pnl_cp,SIGNAL(mysignal(int)),stack,SLOT(setCurrentIndex(int))); //关联显示内容的改变
    QObject::connect(pnl_serial,SIGNAL(signal_serialport_rx(QByteArray)),pnl_info,SLOT(serialport_rx(QByteArray)));
   // QObject::connect(pnl_cp,SIGNAL(btn_prev_clicked()),SLOT(slot_panel_control_btn_prev_clicked()));

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
    add_pnl_info_item(0);
    navtexitemlist_pos=0;
    setLayout(stacklayout);
    //win->setWindowFlags(Qt::FramelessWindowHint);
    resize(800,600);
    //setFocus();
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
        if(stacklayout->currentIndex()==0)  //pnl_info
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
    if(item->fRead==0)  //尚未閱讀，更新數據庫
    {
        item->fRead=1;
    }
    pnl_detail->setcontent(item);
    stacklayout->setCurrentIndex(1);
 }


 void MainWin::btnTTSClick(NAVTEXITEM *item)
 {

 }


 void MainWin::setStackIndex(int i)
 {
     stacklayout->setCurrentIndex(i);
 }

 //向panel_info中添加item内容,根据channel类型
 void MainWin::add_pnl_info_item(int channel_type)
 {
    int index=0;
    panel_item *ppanel_item;
    QList<NAVTEXITEM *>::iterator item;
    pnl_info->clear();
    for(item=navtexitemlist.begin();item!=navtexitemlist.end();++item,++index)
    {
        if(((*item)->chn==channel_type)||(channel_type==0))
        {
            ppanel_item=new panel_item(index,*item);
            pnl_info->addNavtexItem(ppanel_item);
        }
    }
 }
