#include "panel_control.h"
#include "ui_panel_control.h"
#include "main.h"
#include <QtGui>

class MainWin;

panel_control::panel_control(QWidget *parent) :
    QWidget(parent)
{
    setFont(QFont("wenquanyi micro hei mono",20));
    lcd_time = new QLCDNumber(8);
    lcd_time->setMinimumHeight(40);
    btn_view = new QPushButton("查看");
    btn_info = new QPushButton("返回");
    btn_prev = new QPushButton("上一条");
    btn_next = new QPushButton("下一条");

    grp_chn  = new QGroupBox("通道显示");
    //grp_chn->setStyleSheet("border: 1px solid lightgray;font-size:16px;");
    grp_chn->setStyleSheet("font-size:16px;");
    rb_486  = new QRadioButton("486KHz");
    rb_518  = new QRadioButton("518KHz");
    rb_4209  = new QRadioButton("4209KHz");
    rb_all  = new QRadioButton("全部");
    rb_all->setChecked(true);
    vbox= new QVBoxLayout;
    vbox->addWidget(rb_486);
    vbox->addWidget(rb_518);
    vbox->addWidget(rb_4209);
    vbox->addWidget(rb_all);

    grp_chn->setLayout(vbox);

    btn_setup = new QPushButton("设置");
    btn_about = new QPushButton("关于");

    layout = new QVBoxLayout;
    layout->addWidget(lcd_time);
    layout->addWidget(btn_view);
    layout->addWidget(btn_info);
    layout->addWidget(btn_prev);
    layout->addWidget(btn_next);
    layout->addWidget(grp_chn);

    layout->addStretch(1);
    layout->addWidget(btn_setup);
    layout->addWidget(btn_about);
    layout->setContentsMargins(0,0,0,0);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    showTime();
    setLayout(layout);
    show();
    //connect(ui->btn_prev,SIGNAL(clicked()),this,SIGNAL(btn_prev_clicked()));
    //connect(ui->btn_next,SIGNAL(clicked()),this,SLOT(btn_next_clicked()));
}


void panel_control::btn_prev_clicked()
{
//    if(stack->currentIndex()==0)  //pnl_info
//    {
//        int i=navtexitemlist_pos;
//        if(i==0)
//        {
//            i=navtexitemlist.size();
//        }
//        i--;
//        pnl_info->myDrawItem(i);
//    }
//    setFocusProxy(pnl_info);
}

void panel_control::btn_next_clicked()
{
//    if(stack->currentIndex()==0)  //pnl_info
//    {
//        int i=navtexitemlist_pos;
//        i++;
//        if(i>=navtexitemlist.size())
//        {
//            i=0;
//        }
//        pnl_info->myDrawItem(i);
//    }

}

void panel_control::showTime()
{
    QTime time = QTime::currentTime();
    QString text=time.toString("hh:mm:ss");
    lcd_time->display(text);

}

panel_control::~panel_control()
{

}

//根据添加页面的顺序调整,使用默认的槽函数格式 on_objname_event


void panel_control::on_btn_pnl_info_clicked()
{
//    stack->setCurrentIndex(0);
}

void panel_control::on_btn_pnl_detail_clicked()
{
//    stack->setCurrentIndex(1);
}

void panel_control::on_btn_pnl_setup_clicked()
{
//    stack->setCurrentIndex(2);
}

void panel_control::on_btn_pnl_serialport_clicked()
{
//    stack->setCurrentIndex(3);
}

void panel_control::on_btn_pnl_about_clicked()
{
//    stack->setCurrentIndex(4);
}
