#include "mainwin.h"
#include <QDebug>

#include <sys/ioctl.h>
#include <fcntl.h>

#include <QSettings>
#include <QtSql>

#include "FlowLayout.hpp"
#include "panel_info.h"
#include "panel_setup.h"
#include "panel_about.h"
#include "panel_detail.h"
#include "panel_item.h"

#include "common.h"


#include "qextserialport.h"

MainWin* MainWin::INSTANCE=0;
int MainWin::item_pos=0;


MainWin::MainWin(QWidget *parent) : QWidget(parent)
{
    INSTANCE = this;

    QFontDatabase database;

    config_read();

    pnl_info=new panel_info;
    pnl_setup =new panel_setup;
    pnl_detail = new panel_detail;
    pnl_about = new panel_about;

    stacklayout=new QStackedWidget(this);
    stacklayout->addWidget(pnl_info);
    stacklayout->addWidget(pnl_detail);
    stacklayout->addWidget(pnl_setup);
    stacklayout->addWidget(pnl_about);

    stacklayout->setContentsMargins(0,0,0,0);

    PortSettings settings = {BAUD115200, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    serialport = new QextSerialPort("ttyS1",settings,QextSerialPort::EventDriven);
    serialport->open(QIODevice::ReadWrite);
    if(serialport->isOpen())
    {
        connect(serialport,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    }
    else
    {
        qDebug()<<tr("串口打开失败")<<endl;
    }

    QObject::connect(stacklayout,SIGNAL(currentChanged(int)),this,SLOT(on_stacklayout_currentChanged(int)));

    //setLayout(stacklayout);
    stacklayout->setGeometry(QRect(0,0,800,600));
    //addWidget(stacklayout);
    setWindowFlags(Qt::FramelessWindowHint);
    resize(800,600);
    //创建完成后再添加数据
    db_init();
    pnl_info->updateNavtexItemList(0);
    stacklayout->setCurrentIndex(0);

    setAttribute(Qt::WA_AcceptTouchEvents);

    timerid=startTimer(50);     //50ms定时器，检测电源按键
}


MainWin::~MainWin()
{
    if(timerid!=0) killTimer(timerid);
    db_close();
    itemlist.clear();
    if(serialport->isOpen())
    {
        serialport->close();
    }
    delete serialport;
}

/*检测电源关机键 GPF2*/
void MainWin::timerEvent( QTimerEvent *event )
{
    unsigned long buf[2]={32*5+2,0};
    static unsigned int powerkey_timer=0;
    int ret;
    if(fd_gpio)
    {
        ret=::read(fd_gpio,buf,8);
        if(ret==0) //按下
        {
            ::ioctl(fd_gpio,0x0,0);  //更新显示背光计时
            powerkey_timer+=50;
            if(powerkey_timer>=1500) //按下1.5秒 时间有些不准？
            {
                if(!(QMessageBox::information(this,tr("退出程序"),tr("<font size=20>确定退出程序吗？</font>"),tr("确认"),tr("取消"))))
                {
                    db_close();
                    QApplication::quit();
                    //system("reboot");
                }
            }
        }
        else
        {
            powerkey_timer=0;
        }
    }
}

void MainWin::keyPressEvent( QKeyEvent *event )
{
    char buf[21]={0xfd,0x00,0x12,0x01,0x00,'[','v','0',']','[','x','1',']','s','o','u','n','d','1','0','0'};
    //qDebug()<<"key"<<event->key();

    if(fd_tts)
    {
        if(event->key()!=KEY_TTS) //不播报，发提示音
        {
            buf[7]+=hinttone_level;
            buf[19]+=hinttone/10;
            buf[20]+=hinttone%10;
            ::write(fd_tts,buf,21);
        }
    }

    //根据界面判断按键还是根据按键判断界面

    switch(stacklayout->currentIndex())
    {
    case 0: //panel_info
        switch(event->key())
        {
        case KEY_UP:
        case KEY_LEFT:  pnl_info->on_btn_prev_clicked();break;
        case KEY_DOWN:
        case KEY_RIGHT: pnl_info->on_btn_next_clicked();break;
        case KEY_OK: pnl_info->on_btn_view_clicked();break;
        case KEY_486: pnl_info->rb_show_486(); break;
        case KEY_518: pnl_info->rb_show_518(); break;
        case KEY_4209:pnl_info->rb_show_4209(); break;
        case KEY_DATA:pnl_info->rb_show_all();break;
        case KEY_TTS:
            panel_item *item;
            item=static_cast<panel_item *>(itemlist.at(navtexitemlist_pos));
            btnTTSClick(item->itemvalue);
            break;

        }
        break;
    case 1: //panel_detail
        switch(event->key())
        {
        case KEY_RET:setStackIndex(0);break;
        case KEY_TTS:btnTTSClick(pnl_detail->item);break;

        }
        break;
    case 2: //panel_setup
        switch(event->key())
        {
        case KEY_UP:
        case KEY_LEFT:  pnl_info->on_btn_prev_clicked();break;
        case KEY_DOWN:
        case KEY_RIGHT: pnl_info->on_btn_next_clicked();break;
        case KEY_OK: pnl_info->on_btn_view_clicked();break;
        }
        break;
    case 3: //panel_about
        switch(event->key())
        {
        case KEY_UP:
        case KEY_LEFT:  pnl_info->on_btn_prev_clicked();break;
        case KEY_DOWN:
        case KEY_RIGHT: pnl_info->on_btn_next_clicked();break;
        case KEY_OK: pnl_info->on_btn_view_clicked();break;
        }
        break;

    }



}


//panel_item按下【查看】按钮
//检查数据库记录是否已读
//切换至panel_detail
void MainWin::btnViewClick(ITEM_DATA *item)
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

void MainWin::btnTTSClick(ITEM_DATA *item)
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
    case 'A':infotype=tr("航行警告");break;
    case 'B':infotype=tr("气象警告");break;
    case 'C':infotype=tr("冰况报告");break;
    case 'D':infotype=tr("搜救信息");break;
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
    if(fd_tts)
    {
        //qDebug()<<"ba_info.size="<<ba_info.size();
        ba_info[1]=(ba_info.size()-3)>>8;
        ba_info[2]=(ba_info.size()-3)&0xFF;
        ::write(fd_tts,ba_info,ba_info.size());
    }
}


void MainWin::setStackIndex(int i)
{
    stacklayout->setCurrentIndex(i);
}


void MainWin::on_stacklayout_currentChanged(int index)
{
    qDebug()<<"stackedlayout change"<<index;
    if(index==0)
    {
       // (pnl_info->leftlayout->itemAt(navtexitemlist_pos)->widget())->setFocus(Qt::OtherFocusReason);
    }
}




/*
分析数据 ZCZC<space>B1B2B3B4<CR><LF><电文>NNNN
会不会有以下情况
ZCZC......NNNN  暂时只考虑这种情况,中间有可能夹杂其他无用数据（如回车换行等）
ZCZC......ZCZC
NNNN......NNNN

没有频点和误码率？
*/
void MainWin::analy_serial_data(QByteArray ba_info)
{
    ITEM_DATA *item_data;
    panel_item *pitem;

    qDebug()<<"******ba_info***********";
    qDebug()<<ba_info;

    if(ba_serial.at(4)!=' ') return; //格式不对
    if((ba_serial.at(5)<'A')||(ba_serial.at(5)>'Z')) return;
    if((ba_serial.at(6)<'A')||(ba_serial.at(6)>'Z')) return;
    if((ba_serial.at(7)<'0')||(ba_serial.at(7)>'9')) return;
    if((ba_serial.at(8)<'0')||(ba_serial.at(8)>'9')) return;
    if(ba_serial.at(9)!=0x0d) return;
    if(ba_serial.at(10)!=0x0a) return;


    item_data = new ITEM_DATA;
    if(item_data->chn==518)  //英文 日期格式 ddhhmmUTC MMM YYYY  还会有其他格式
    {
        //item_data->Broadcast=;              //始发报文时间

    }
    else   //中文信息格式  YYMMddhhmm
    {

    }

    item_data->code=QString(ba_serial.mid(5,4));      //技术编码
    item_data->fRead=1;         //默认未读
    item_data->BER=0;           //todo:误码率信息如何确认
    item_data->chn=4209;        //todo:通道信息如何确认
    item_data->Receive=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
    item_data->Content=QString(ba_info.mid(11));
    pitem= new panel_item(item_data);
    itemlist<<pitem;
    pnl_info->addNavtexItem(pitem);

#if 0
    QSqlQuery query;
    query.prepare("INSERT INTO message (:Time,:Type,:Passage,:Latch,:SAR,:Warn,:Read,:BER,:Message,:time_broadcast");
    query.bindValue(":Time",QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(":Type",item_data->code);
    query.bindValue(":Passage",item_data->chn);
    query.bindValue(":Latch",0);
    query.bindValue(":SAR",0);
    query.bindValue(":Warn", 0);
    query.bindValue(":Read",item_data->fRead);
    query.bindValue(":BER",item_data->BER);
    query.bindValue(":Message",item_data->Content);
    query.bindValue(":time_broadcast",item_data->Broadcast);
    query.exec();
#endif
}



//串口收到数据
void MainWin::onReadyRead()
{
    QByteArray ba;
    QByteArray ba_info;

    int pos_start,pos_end;
    int a = serialport->bytesAvailable();
    ba.resize(a);
    serialport->read(ba.data(), ba.size());
    ba_serial.append(ba);
    qDebug() << "serial(" << ba.size()<<")"<< ba;

    while((pos_end=ba_serial.indexOf("NNNN"))!=-1)  //找到结束标志
    {
        pos_start=ba_serial.indexOf("ZCZC");
        if(pos_start>=0)  //找到开始头
        {
            ba_info=ba_serial.mid(pos_start,pos_end); //没有包括结束的NNNN
            analy_serial_data(ba_info);
        }
        ba_serial.remove(0,pos_end+5);  //从0开始
    }
    qDebug()<<"ba_serial size:"<<ba_serial.size();
}

