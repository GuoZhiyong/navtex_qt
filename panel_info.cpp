#include "panel_info.h"
#include "FlowLayout.hpp"
#include "panel_item.h"

#include <QDebug>
#include <QtGui>
#include <QDateTime>

#include "mainwin.h"
#include "navtexitem.h"

panel_info::panel_info(QWidget *parent) : QWidget(parent)
{
    setFont(QFont("wenquanyi micro hei mono",20));

    scrollarea=new QScrollArea;
    scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollarea->setStyleSheet("min-width: 30px;");
    scrollarea->setWidgetResizable(true);
    scrollwidget=new QWidget(scrollarea);
    scrollarea->setWidget(scrollwidget);

    leftlayout = new FlowLayout(0,5,0);
    scrollwidget->setLayout(leftlayout);

    lcd_time = new QLCDNumber(8);
    lcd_time->setMinimumHeight(40);

    btn_view = new QPushButton("查看");
    QObject::connect(btn_view,SIGNAL(clicked()),SLOT(on_btn_view_clicked()));
    btn_prev = new QPushButton("上一条");
    QObject::connect(btn_prev,SIGNAL(clicked()),SLOT(on_btn_prev_clicked()));
    btn_next = new QPushButton("下一条");
    QObject::connect(btn_next,SIGNAL(clicked()),SLOT(on_btn_next_clicked()));

    grp_chn  = new QGroupBox("通道显示");
    //grp_chn->setStyleSheet("border: 1px solid lightgray;font-size:16px;");
    grp_chn->setStyleSheet("font-size:16px;");
    rb_486  = new QRadioButton("486KHz");
    rb_518  = new QRadioButton("518KHz");
    rb_4209  = new QRadioButton("4209KHz");
    rb_all  = new QRadioButton("全部");
    QObject::connect(rb_486,SIGNAL(clicked()),SLOT(rb_show_486()));
    QObject::connect(rb_518,SIGNAL(clicked()),SLOT(rb_show_518()));
    QObject::connect(rb_4209,SIGNAL(clicked()),SLOT(rb_show_4209()));
    QObject::connect(rb_all,SIGNAL(clicked()),SLOT(rb_show_all()));


    rb_all->setChecked(true);
    vbox= new QVBoxLayout;
    vbox->addWidget(rb_486);
    vbox->addWidget(rb_518);
    vbox->addWidget(rb_4209);
    vbox->addWidget(rb_all);

    grp_chn->setLayout(vbox);

    btn_setup = new QPushButton("设置");
    QObject::connect(btn_setup,SIGNAL(clicked()),SLOT(on_btn_setup_clicked()));
    btn_about = new QPushButton("关于");
    QObject::connect(btn_about,SIGNAL(clicked()),SLOT(on_btn_about_clicked()));

    rightlayout = new QVBoxLayout;
    rightlayout->addWidget(lcd_time);
    rightlayout->addWidget(btn_view);
    rightlayout->addWidget(btn_prev);
    rightlayout->addWidget(btn_next);
    rightlayout->addWidget(grp_chn);
    rightlayout->addStretch(1);
    rightlayout->addWidget(btn_setup);
    rightlayout->addWidget(btn_about);
    rightlayout->setContentsMargins(0,0,0,0);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    showTime();

    mainlayout=new QHBoxLayout(parent);
    mainlayout->addWidget(scrollarea,15);
    mainlayout->addLayout(rightlayout,1);
    mainlayout->setContentsMargins(2,0,2,0);
    setLayout(mainlayout);
    show();
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
    panel_item *item;
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制原来的
    navtexitemlist_pos=index;
    item->repaint();
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制新的
    item->repaint();
}


panel_info::~panel_info()
{
}


//清除panel_info 中的item
void panel_info::clear() const
{
     QLayoutItem *item;
     while ((item = leftlayout->takeAt(0)))
     {
         delete item->widget();  //删除item绑定的Widget
         leftlayout->removeItem(item);
     }
}


void panel_info::serialport_rx(QByteArray bytes)
{
    qDebug()<<"panel_info rx:"<<bytes.size();
    qDebug()<<"bytes:"<<bytes;

}

void panel_info::showTime()
{
    QTime time = QTime::currentTime();
    QString text=time.toString("hh:mm:ss");
    lcd_time->display(text);

}

void panel_info::updateNavtexItemList(int chn)
{

    int index=0;
    panel_item *ppanel_item;
    QList<NAVTEXITEM *>::iterator item;

    if(navtexitemlist.isEmpty())  //判断是否为空
    {
        navtexitemlist_pos=-1;
        return;
    }
    clear();

    for(item=navtexitemlist.begin();item!=navtexitemlist.end();++item)
    {
        if(((*item)->chn==chn)||(chn==0))
        {
            ppanel_item=new panel_item(index,*item);
            leftlayout->addWidget(ppanel_item);
            index++;
        }
    }
    navtexitemlist_pos=0;
    panel_item *i;
    i=(panel_item*)(leftlayout->itemAt(0)->widget()); //绘制原来的
    i->repaint();

}

//查看的slot
void panel_info::on_btn_view_clicked()
{
    panel_item *item;
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制原来的
    MainWin::instance()->btnViewClick(item->itemvalue);
}

void panel_info::on_btn_prev_clicked()
{
    panel_item *item;
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制原来的
    if(navtexitemlist_pos==0)
    {
        navtexitemlist_pos=leftlayout->count();
    }
    navtexitemlist_pos--;
    item->repaint();
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制新的
    item->repaint();

}

void panel_info::on_btn_next_clicked()
{
    panel_item *item;
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制原来的
    navtexitemlist_pos++;
    if(navtexitemlist_pos>=leftlayout->count())
    {
        navtexitemlist_pos=0;
    }

    item->repaint();
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制新的
    item->repaint();
}


void panel_info::on_btn_setup_clicked()
{
    MainWin::instance()->setStackIndex(2);
}

void panel_info::on_btn_about_clicked()
{
    MainWin::instance()->setStackIndex(4);
}


void panel_info::rb_show_486()
{
    updateNavtexItemList(486);
}

void panel_info::rb_show_518()
{
    //MainWin::instance()->add_pnl_info_item(518);
    updateNavtexItemList(518);
}

void panel_info::rb_show_4209()
{
    //MainWin::instance()->add_pnl_info_item(4209);
    updateNavtexItemList(4209);
}

void panel_info::rb_show_all()
{
    //MainWin::instance()->add_pnl_info_item(0);
    updateNavtexItemList(0);
}

