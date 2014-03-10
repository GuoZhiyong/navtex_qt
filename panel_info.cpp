#include "panel_info.h"
#include "ui_panel_info.h"
#include "FlowLayout.hpp"
#include "panel_item.h"
#include "main.h"

#include <QDebug>
#include <QtGui>
#include <QDateTime>

QList<NAVTEXITEM *> navtexitemlist;
int navtexitemlist_pos;

panel_info::panel_info(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::panel_info)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::ClickFocus);

    NAVTEXITEM *pnavtexitem;
    panel_item *ppanel_item;

    QString style = "QScrollBar:vertical {min-width: 30px;}";
    setStyleSheet(style);
    layout=new FlowLayout(0,5,0);
/*打开数据库*/
    dbconn=QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("Informationdb.db");
    if(!dbconn.open())
    {
        qDebug()<<"打开数据库错误"<<dbconn.lastError()<<endl;
    }

/*添加数据*/
    QSqlQuery query;
    query.exec("select * from Informations");
    while(query.next())
    {
        pnavtexitem = new NAVTEXITEM;
        pnavtexitem->id = query.value(0).toInt();
        pnavtexitem->code=query.value(2).toString();   //技术编码
        pnavtexitem->chn=query.value(3).toInt();    //使用通道
        pnavtexitem->Broadcast=query.value(1).toString();
        //pnavtexitem->DateTimeReceive=query.value(2).toString();
        pnavtexitem->Content=query.value(9).toString();
        pnavtexitem->fRead=query.value(7).toInt();
        pnavtexitem->BER=query.value(8).toInt();
        navtexitemlist<<pnavtexitem;

    }
//添加panel_item
    QList<NAVTEXITEM *>::iterator i;
    int index=0;
    for(i=navtexitemlist.begin(),index=0;i!=navtexitemlist.end();++i,++index)
    {
        ppanel_item=new panel_item(index,*i);
        layout->addWidget(ppanel_item);
        connect(ppanel_item,SIGNAL(viewClick(NAVTEXITEM *)),this,SLOT(btnViewClick(NAVTEXITEM *))); //关联信号槽
        connect(ppanel_item,SIGNAL(ttsClick(NAVTEXITEM *)),this,SLOT(btnTTSClick(NAVTEXITEM *)));
    }
    navtexitemlist_pos=0;

    //ui->scrollAreaWidgetContents->setLayout(layout);
    ui->scroll_widget->setLayout(layout);
    //setWidget(ui->scroll_widget);  //不需要，加上后反而不显示
    layout->itemAt(0);

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

    QPalette pal;

    item=(panel_item*)(layout->itemAt(navtexitemlist_pos));
    pal=item->palette();

    item->setAutoFillBackground(true);
    pal.setColor(QPalette::Window,pal.color(QPalette::Window));  /*默认的颜色*/
    setPalette(pal);
    navtexitemlist_pos=index;

    item=(panel_item*)(layout->itemAt(navtexitemlist_pos));
    pal=item->palette();

    item->setAutoFillBackground(true);
    pal.setColor(QPalette::Window,QColor(227,0,228));  /*新颜色*/
    setPalette(pal);

}

panel_info::~panel_info()
{
    dbconn.close();
    navtexitemlist.clear();
    delete ui;
}

void panel_info::serialport_rx(QByteArray bytes)
{
    qDebug()<<"panel_info rx:"<<bytes.size();
    qDebug()<<"bytes:"<<bytes;

}

//用户按下[详情]按钮，判断是否已读,显示详细信息
void panel_info::btnViewClick(NAVTEXITEM *item)
{
    qDebug()<<"view click "<<item->id;
    if(item->fRead==0)  //还没有阅读
    {

    }
    pnl_detail->setcontent(item);
    stack->setCurrentIndex(1);
}

void panel_info::btnTTSClick(NAVTEXITEM *item)
{
    qDebug()<<"tts click "<<item->id;
}


