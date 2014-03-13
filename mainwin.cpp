#include "mainwin.h"
#include <QDebug>

#include "FlowLayout.hpp"


#include "panel_info.h"
#include "panel_serial.h"
#include "panel_setup.h"
#include "panel_about.h"
#include "panel_detail.h"
#include "panel_item.h"

#include "navtexitem.h"


MainWin* MainWin::INSTANCE=0;
int MainWin::item_pos=0;


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

    QObject::connect(pnl_serial,SIGNAL(signal_serialport_rx(QByteArray)),pnl_info,SLOT(serialport_rx(QByteArray)));

    db_init();

    pnl_info->updateNavtexItemList(0);
    setLayout(stacklayout);
    //win->setWindowFlags(Qt::FramelessWindowHint);
    resize(800,600);
    //setFocus();
}


MainWin::~MainWin()
{
    db_close();
    navtexitemlist.clear();
}

void MainWin::keyPressEvent( QKeyEvent *event )
{
    if(event->key()==Qt::Key_Up)
   {
        qDebug()<<"win Q press";
   }
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
