#include "mainwin.h"
#include <QDebug>

#include "FlowLayout.hpp"

#include "panel_control.h"
#include "panel_info.h"
#include "panel_serial.h"
#include "panel_setup.h"
#include "panel_about.h"
#include "panel_detail.h"



MainWin::MainWin(QWidget *parent) :
    QWidget(parent)
{
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
    resize(800,600);
    setFocus();
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


