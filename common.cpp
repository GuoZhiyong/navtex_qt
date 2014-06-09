#include "common.h"
#include <QtSql>
#include <QObject>

#include <sys/ioctl.h>
#include <fcntl.h>

#include <QMap>
#include "panel_item.h"

static QSqlDatabase dbconn;            //存储数据库访问的实例

//QList<NAVTEXITEM *> navtexitemlist;

QList<QWidget *> itemlist;

int navtexitemlist_pos=-1;


int keytone=1;   //sound101-sound125
int keytone_level=5;

int hinttone=1;
int hinttone_level=5;

int tts_volume=5;
int tts_auto=0;

int backlight_keypad=5;
int backlight_lcd=30;



int fd_tts=-1; //tts操作
int fd_gpio=-1;  //gpio操作

QTranslator *trans;

//打开数据库
void db_init(void)
{

    dbconn=QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("Informationdb.db");
    if(!dbconn.open())
    {
        qDebug()<<"打开数据库错误"<<dbconn.lastError()<<endl;
    }

    /*添加数据*/
    ITEM_DATA *item_data;
    panel_item *pitem;
    QSqlQuery query;
    query.exec("select * from message");
    while(query.next())
    {
        item_data = new ITEM_DATA;
        item_data->id = query.value(0).toInt();  //对应数据库的id
        item_data->Broadcast=query.value(1).toString().mid(0,16);  //只顯示到分钟
        item_data->code=query.value(2).toString();   //技术编码
        item_data->chn=query.value(3).toInt();    //使用通道
        item_data->fRead=query.value(7).toInt();
        item_data->BER=query.value(8).toInt();
        item_data->Content=query.value(9).toString();
        item_data->Receive=query.value(10).toString().mid(0,16);
        pitem= new panel_item(item_data);
        itemlist<<pitem;

    }
}

//读取配置信息
void config_read(void)
{
    QSettings *cfg = new QSettings("navtex.ini",QSettings::IniFormat);

    keytone=cfg->value("keytone/id",1).toInt();
    keytone_level=cfg->value("keytone/level",5).toInt();

    hinttone=cfg->value("hinttone/id",1).toInt();
    hinttone_level=cfg->value("hinttone/level",5).toInt();

    tts_volume=cfg->value("tts/volume",5).toInt();
    tts_auto=cfg->value("tts/auto",0).toInt();

    backlight_keypad=cfg->value("backlight/keypad",5).toInt();
    backlight_lcd=cfg->value("backlight/lcd",30).toInt();
    if(fd_gpio)
    {
        ::ioctl(fd_gpio,0x01,backlight_keypad);
        ::ioctl(fd_gpio,0x02,backlight_lcd);
    }

    delete cfg;
}

void config_write(int writetofile)
{
    if(writetofile)
    {
        QSettings *cfg = new QSettings("navtex.ini",QSettings::IniFormat);
        cfg->setValue("keytone/id",keytone);
        cfg->setValue("keytone/level",keytone_level);

        cfg->setValue("hinttone/id",hinttone);
        cfg->setValue("hinttone/level",hinttone_level);

        cfg->setValue("tts/volume",tts_volume);
        cfg->setValue("tts/auto",tts_auto);

        cfg->setValue("backlight/keypad",backlight_keypad);
        cfg->setValue("backlight/lcd",backlight_lcd);
        delete cfg;
    }
    if(fd_gpio)
    {
        ::ioctl(fd_gpio,0x01,backlight_keypad);
        ::ioctl(fd_gpio,0x02,backlight_lcd);
    }

}





void db_create(void)
{

}

void db_close(void)
{
    dbconn.close();
}


QString getSite(QChar B1)
{
    if(B1=='M') return QObject::tr("SANYA");
    if(B1=='N') return QObject::tr("GUANGZHOU");
    if(B1=='O') return QObject::tr("FUZHOU");
    if(B1=='Q') return QObject::tr("SHANGHAI");
    if(B1=='R') return QObject::tr("DALIAN");
    if(B1=='T') return QObject::tr("TIANJIN");
    if(B1=='Z') return QObject::tr("ZHENJIANG");
    return QObject::tr("Unknown Site");
}


QString getInfo(QChar B2)
{
    switch(B2.toAscii())
    {
    case 'A':return QObject::tr("Navigational warnings");
    case 'B':return QObject::tr("Metrorological warnings");                           //B
    case 'C':return QObject::tr("Ice reports");                                       //C
    case 'D':return QObject::tr("Search & rescue information"); //D
    case 'E':return QObject::tr("Meteorological forecasts");                         //E
    case 'F':return QObject::tr("Pilot service messages");                          //F
    case 'G':return QObject::tr("AIS messages");                                     //G
    case 'H':return QObject::tr("LORAM messages");                                   //H
    case 'I':return QObject::tr("Omega messages");                                   //I
    case 'J':return QObject::tr("SATNAV messages");                                   //J
    case 'K':return QObject::tr("Other electronic navaid mesages");                   //K
    case 'L':return QObject::tr("Navigational warnings-additional to letter A");      //L
    case 'R':return QObject::tr("fishery administration");                           //R
    case 'T':return QObject::tr("Test transmissions");                               //T
    case 'Z':return QObject::tr("No message on hand");                               //Z
    default:return QObject::tr("Not used");
    }
}


