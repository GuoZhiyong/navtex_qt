#include "mainwin.h"
#include <QDebug>

#include <sys/ioctl.h>
#include <fcntl.h>

#include "FlowLayout.hpp"
#include "panel_info.h"
#include "panel_serial.h"
#include "panel_setup.h"
#include "panel_about.h"
#include "panel_detail.h"
#include "panel_item.h"

#include "common.h"


MainWin* MainWin::INSTANCE=0;
int MainWin::item_pos=0;


MainWin::MainWin(QWidget *parent) : QWidget(parent)
{
    INSTANCE = this;



    QFontDatabase database;
  //  database.addApplicationFont("DIGITALDREAMNARROW.ttf");
    foreach (const QString &family, database.families(QFontDatabase::SimplifiedChinese))
    {
        qDebug()<<family;
    }



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

    stacklayout->setContentsMargins(0,0,0,0);
    stacklayout->setCurrentIndex(0);

    QObject::connect(pnl_serial,SIGNAL(signal_serialport_rx(QByteArray)),pnl_info,SLOT(serialport_rx(QByteArray)));

    tts_fd=::open("/dev/xf5251_drv",O_RDWR);
    if(tts_fd<0)
    {
        qDebug()<<"open tts failed";
    }
    db_init();


    pnl_info->updateNavtexItemList(0);
    setLayout(stacklayout);
    setWindowFlags(Qt::FramelessWindowHint);
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
   qDebug()<<"MainWin type "<<event->type()<<" key "<<event->key();
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

// int id;     //数据库的id,会根据选择的不同而改变
// int index;  //在flowlayout中显示的位置,从0开始
// QString code;   //技术编码
// int chn;    //使用通道
// QString Broadcast;
// QString Receive;
// QString Content;
// int fRead;
// int BER;

 void MainWin::btnTTSClick(NAVTEXITEM *item)
 {
     QString info;
     QByteArray ba_info;
     QString site,infotype;
     QString datetime;
     QByteArray ba=(item->code).toLatin1();

     switch(ba[0])
     {
     case 'M': site=tr("三亚");break;
     case 'N': site=tr("广州");break;
     case 'O': site=tr("福州");break;
     case 'Q': site=tr("上海");break;
     case 'R': site=tr("大连");break;
     case 'T': site=tr("天津");break;
     case 'Z': site=tr("湛江");break;
     default:site=tr("未知岸播台");break;
     }

     switch(ba[1])
     {
     case 'A':infotype=tr("[f0][s1]航行警告[s5][f1]");break;
     case 'B':infotype=tr("[f0]气象警告[f1]");break;
     case 'C':infotype=tr("[f0]冰况报告[f1]");break;
     case 'D':infotype=tr("[f0]搜救信息");break;
     case 'E':infotype=tr("气象预报");break;
     case 'F':infotype=tr("引航业务信息");break;
     case 'G':infotype=tr("船舶自动识别系统");break;
     case 'H':infotype=tr("劳兰信息");break;
     case 'I':infotype=tr("奥米加信息");break;
     case 'J':infotype=tr("卫星导航信息");break;
     case 'K':infotype=tr("其它电子导航信息");break;
     case 'L':infotype=tr("航行警告(附)");break;
     case 'R':infotype=tr("渔政信息");break;
     case 'T':infotype=tr("语音专用信息");break;
     case 'Z':infotype=tr("现无电报");break;
     default:infotype=tr("未知信息");break;
     }

     QDateTime dt=QDateTime::fromString(item->Broadcast,"yyyy-MM-dd HH:mm:ss");

     info= dt.toString(tr("yyyy年M月d日h时m分s秒"))+ site+tr("播发")+infotype+tr("内容如下:")+item->Content;

     ba_info.resize(9);
     ba_info[0]=0xFD;
     ba_info[3]=0x01;
     ba_info[4]=0x00;
     ba_info[5]='[';
     ba_info[6]='h';
     ba_info[7]='2';
     ba_info[8]=']';

     ba_info.append(info);
     if(tts_fd)
     {
         qDebug()<<"ba_info.size="<<ba_info.size();
         ba_info[1]=(ba_info.size()-3)>>8;
         ba_info[2]=(ba_info.size()-3)&0xFF;
         /*
         for(int i=0;i<ba_info.size();++i)
         {
             if(i%16==0)
             {
                 qDebug()<<endl;
             }
             fprintf(stderr, "%02x ",ba_info.at(i));
         }
         */
         ::write(tts_fd,ba_info,ba_info.size());
     }
 }


 void MainWin::setStackIndex(int i)
 {
     stacklayout->setCurrentIndex(i);
 }
