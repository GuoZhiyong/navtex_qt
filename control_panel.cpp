#include "control_panel.h"
#include "ui_control_panel.h"
#include "main.h"
#include <QtGui>

control_panel::control_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::control_panel)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    showTime();

    connect(ui->btn_prev,SIGNAL(clicked()),this,SLOT(btn_prev_clicked()));
    connect(ui->btn_next,SIGNAL(clicked()),this,SLOT(btn_next_clicked()));
}


void control_panel::btn_prev_clicked()
{
    if(stack->currentIndex()==0)  //pnl_info
    {
        int i=navtexitemlist_pos;
        if(i==0)
        {
            i=navtexitemlist.size();
        }
        i--;
        qDebug()<<i;
        pnl_info->myDrawItem(i);
    }

}

void control_panel::btn_next_clicked()
{
    if(stack->currentIndex()==0)  //pnl_info
    {
        navtexitemlist_pos++;
        if(navtexitemlist_pos>=navtexitemlist.size())
        {
            navtexitemlist_pos=0;
        }
        qDebug()<<navtexitemlist_pos;
    }

}

void control_panel::showTime()
{
    QTime time = QTime::currentTime();
    QString text=time.toString("hh:mm:ss");
    ui->lcd_time->display(text);

}

control_panel::~control_panel()
{
    delete ui;
}

//根据添加页面的顺序调整

void control_panel::on_btn_pnl_info_clicked()
{
    emit mysignal(0);
}

void control_panel::on_btn_pnl_detail_clicked()
{
    emit mysignal(1);
}

void control_panel::on_btn_pnl_setup_clicked()
{
    emit mysignal(2);
}

void control_panel::on_btn_pnl_serialport_clicked()
{
    emit mysignal(3);
}

void control_panel::on_btn_pnl_about_clicked()
{
    emit mysignal(4);
}
