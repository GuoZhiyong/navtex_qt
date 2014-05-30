
#include "panel_info.h"
#include "FlowLayout.hpp"
#include "panel_item.h"

#include <QDebug>
#include <QtGui>
#include <QDateTime>
#include <QElapsedTimer>
#include <QTest>

#include "mainwin.h"
#include "common.h"

panel_info::panel_info(QWidget *parent) : QWidget(parent)
{
    setFont(QFont("KaiTi",20));

    scrollarea=new QScrollArea;

    scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollarea->setWidgetResizable(true);
    scrollarea->setContentsMargins(10,0,10,0);
    scrollwidget=new QWidget(scrollarea);
    scrollarea->setWidget(scrollwidget);
    //scrollarea->setStyleSheet("min-width: 30px;");
    leftlayout = new FlowLayout(10,10,0);
    scrollwidget->setLayout(leftlayout);

    lcd_time = new QLCDNumber(8);
    lcd_time->setMinimumHeight(40);

    btn_view = new QPushButton(tr("View"));
    QObject::connect(btn_view,SIGNAL(clicked()),SLOT(on_btn_view_clicked()));
    btn_prev = new QPushButton(tr("Prev"));
    QObject::connect(btn_prev,SIGNAL(clicked()),SLOT(on_btn_prev_clicked()));
    btn_next = new QPushButton(tr("Next"));
    QObject::connect(btn_next,SIGNAL(clicked()),SLOT(on_btn_next_clicked()));

    grp_chn  = new QGroupBox(tr("Channel"));
    //grp_chn->setStyleSheet("border: 1px solid lightgray;font-size:16px;");
    grp_chn->setStyleSheet("font-size:18px;");
    rb_486  = new QRadioButton(tr("486KHz"));
    rb_518  = new QRadioButton(tr("518KHz"));
    rb_4209  = new QRadioButton(tr("4209KHz"));
    rb_all  = new QRadioButton(tr("All"));
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

    btn_setup = new QPushButton(tr("Setup"));
    QObject::connect(btn_setup,SIGNAL(clicked()),SLOT(on_btn_setup_clicked()));
    btn_about = new QPushButton(tr("About"));
    QObject::connect(btn_about,SIGNAL(clicked()),SLOT(on_btn_about_clicked()));

    btn_exit = new QPushButton(tr("Exit"));
    QObject::connect(btn_exit,SIGNAL(clicked()),SLOT(on_btn_exit_clicked()));


    rightlayout = new QVBoxLayout;
    rightlayout->addWidget(lcd_time);
    rightlayout->addWidget(btn_view);
    rightlayout->addWidget(btn_prev);
    rightlayout->addWidget(btn_next);
    rightlayout->addWidget(grp_chn);
    rightlayout->addStretch(1);
    rightlayout->addWidget(btn_setup);
    rightlayout->addWidget(btn_about);
    rightlayout->addWidget(btn_exit);
    rightlayout->setContentsMargins(5,0,5,0);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    showTime();

    mainlayout=new QHBoxLayout(parent);
    mainlayout->addWidget(scrollarea,9);
    mainlayout->addLayout(rightlayout,1);
    mainlayout->setContentsMargins(2,0,2,0);
    setLayout(mainlayout);
    show();
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


void panel_info::retranslate(QWidget *parent)
{
    btn_view->setText(tr("View"));
    btn_prev ->setText(tr("Prev"));
    btn_next->setText(tr("Next"));
    grp_chn->setTitle(tr("Channel"));
    rb_486->setText(tr("486KHz"));
    rb_518->setText(tr("518KHz"));
    rb_4209->setText(tr("4209KHz"));
    rb_all->setText(tr("All"));
    btn_setup->setText(tr("Setup"));
    btn_about->setText(tr("About"));
    btn_exit->setText(tr("Exit"));
}



void panel_info::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch(e->type())
    {
    case QEvent::LanguageChange:
        retranslate(this);
        break;
    default:
        break;
    }
}


panel_info::~panel_info()
{
}


//清除panel_info 中的item
void panel_info::clear() const
{
     QLayoutItem *item;
     while((item=leftlayout->takeAt(0))!=0)
     {
         item->widget()->setParent(NULL);//关键
         leftlayout->removeItem(item);
     }
}


void panel_info::showTime()
{
    QTime time = QTime::currentTime();
    QString text=time.toString("hh:mm:ss");
    lcd_time->display(text);

}

void panel_info::addNavtexItem(panel_item * item)
{
    if((current_chn==0)||(item->itemvalue->chn==current_chn))
    {
        item->index=itemlist.count();
        leftlayout->addWidget(static_cast<QWidget*>(item));
    }
}


//更新显示
//指定通道号 0:全部 486 518 4209
void panel_info::updateNavtexItemList(int chn)
{
    panel_item *ppanel_item;
    QList<QWidget *>::iterator item;

    if(itemlist.isEmpty())  //判断是否为空
    {
        navtexitemlist_pos=-1;
        return;
    }

    QElapsedTimer timer;
    timer.start();

    clear();
    current_chn=chn;
    int index=0;
    navtexitemlist_pos=0;
    for(item=itemlist.begin();item!=itemlist.end();++item)
    {
        ppanel_item=static_cast<panel_item *>(*item);
        if((ppanel_item->itemvalue->chn==chn)||(chn==0))
        {
            ppanel_item->index=index;
            leftlayout->addWidget(*item);
            index++;
        }
    }
//    qDebug() << "updateNavtexItemList: addwidget" << timer.elapsed() << "milliseconds";
//    timer.restart();
    ppanel_item=(panel_item*)(leftlayout->itemAt(0)->widget()); //绘制原来的
    ppanel_item->setFocus(Qt::OtherFocusReason);
    qDebug() << "updateNavtexItemList: repaint" << timer.elapsed() << "milliseconds";

}

//查看的slot
void panel_info::on_btn_view_clicked()
{
    panel_item *item;
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制原来的
    MainWin::instance()->btnViewClick(item->itemvalue);
}

//显示下一条
void panel_info::on_btn_prev_clicked()
{
    panel_item *item;
    if(navtexitemlist_pos==0)
    {
        navtexitemlist_pos=leftlayout->count();
    }
    navtexitemlist_pos--;
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制新的
    item->setFocus(Qt::OtherFocusReason);
}

//显示上一条
void panel_info::on_btn_next_clicked()
{
    panel_item *item;
    navtexitemlist_pos++;
    if(navtexitemlist_pos>=leftlayout->count())
    {
        navtexitemlist_pos=0;
    }
    item=(panel_item*)(leftlayout->itemAt(navtexitemlist_pos)->widget()); //绘制新的
    item->setFocus(Qt::OtherFocusReason);
}


void panel_info::on_btn_setup_clicked()
{
    MainWin::instance()->setStackIndex(2);
}

void panel_info::on_btn_about_clicked()
{
    MainWin::instance()->setStackIndex(3);
}

void panel_info::on_btn_exit_clicked()
{
    if(!(QMessageBox::information(this,tr("Exit Application"),tr("<font size=20>Confirm to quit?</font>"),tr("  OK  "),tr("CANCLE"))))
    {
        db_close();
        QApplication::quit();
        //system("reboot");
    }
}


void panel_info::rb_show_486()
{
    rb_486->setChecked(true);
    updateNavtexItemList(486);
}

void panel_info::rb_show_518()
{
    rb_518->setChecked(true);
    //MainWin::instance()->add_pnl_info_item(518);
    updateNavtexItemList(518);
}

void panel_info::rb_show_4209()
{
    rb_4209->setChecked(true);
    //MainWin::instance()->add_pnl_info_item(4209);
    updateNavtexItemList(4209);
}

void panel_info::rb_show_all()
{
    rb_all->setChecked(true);
    //MainWin::instance()->add_pnl_info_item(0);
    updateNavtexItemList(0);
}

