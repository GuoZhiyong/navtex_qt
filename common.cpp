#include "common.h"
#include <QtSql>

#include <sys/ioctl.h>
#include <fcntl.h>

#include <QMap>
#include "panel_item.h"

static QSqlDatabase dbconn;            //存储数据库访问的实例

//QList<NAVTEXITEM *> navtexitemlist;

QList<QWidget *> itemlist;

int navtexitemlist_pos=-1;


QString sl_site[]={"A","B","C","D","E","F","G",\
                   "H","I","J","K","L","三亚","广州","福州",\
                   "P","上海","大连","S","天津","U","V","W","X","Y","湛江"};

QString sl_info[]={"航行警告","气象警告","冰况报告","搜救信息","气象预报","引航业务信息","船舶自动识别系统",\
                   "劳兰信息","奥米加信息","卫星导航信息","其它电子导航信息","航行警告(附)","M","N","O",\
                   "P","Q","渔政信息","S","语音专用信息","U","V","W","X","Y","Z"};

QMap<QString,QString> qmap_site;
QMap<QString,QString> qmap_infotype;



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



//打开数据库
void db_init(void)
{

    qmap_site["A"]=QObject::tr("未知岸台");
    qmap_site["B"]=QObject::tr("未知岸台");
    qmap_site["C"]=QObject::tr("未知岸台");
    qmap_site["D"]=QObject::tr("未知岸台");
    qmap_site["E"]=QObject::tr("未知岸台");
    qmap_site["F"]=QObject::tr("未知岸台");
    qmap_site["G"]=QObject::tr("未知岸台");
    qmap_site["H"]=QObject::tr("未知岸台");
    qmap_site["I"]=QObject::tr("未知岸台");
    qmap_site["J"]=QObject::tr("未知岸台");
    qmap_site["K"]=QObject::tr("未知岸台");
    qmap_site["L"]=QObject::tr("未知岸台");
    qmap_site["M"]=QObject::tr("三亚");
    qmap_site["N"]=QObject::tr("广州");
    qmap_site["O"]=QObject::tr("福州");
    qmap_site["P"]=QObject::tr("未知岸台");
    qmap_site["Q"]=QObject::tr("上海");
    qmap_site["R"]=QObject::tr("大连");
    qmap_site["S"]=QObject::tr("未知岸台");
    qmap_site["T"]=QObject::tr("天津");
    qmap_site["U"]=QObject::tr("未知岸台");
    qmap_site["V"]=QObject::tr("未知岸台");
    qmap_site["W"]=QObject::tr("未知岸台");
    qmap_site["X"]=QObject::tr("未知岸台");
    qmap_site["Y"]=QObject::tr("未知岸台");
    qmap_site["Z"]=QObject::tr("湛江");

    qmap_infotype["A"]=QObject::tr("航行警告");
    qmap_infotype["B"]=QObject::tr("气象警告");
    qmap_infotype["C"]=QObject::tr("冰况报告");
    qmap_infotype["D"]=QObject::tr("搜救信息");
    qmap_infotype["E"]=QObject::tr("气象预报");
    qmap_infotype["F"]=QObject::tr("引航业务信息");
    qmap_infotype["G"]=QObject::tr("船舶自动识别系统");
    qmap_infotype["H"]=QObject::tr("劳兰信息");
    qmap_infotype["I"]=QObject::tr("奥米加信息");
    qmap_infotype["J"]=QObject::tr("卫星导航信息");
    qmap_infotype["K"]=QObject::tr("其它电子导航信息");
    qmap_infotype["L"]=QObject::tr("航行警告(附)");
    qmap_infotype["M"]=QObject::tr("保留待定信息");
    qmap_infotype["N"]=QObject::tr("保留待定信息");
    qmap_infotype["O"]=QObject::tr("保留待定信息");
    qmap_infotype["P"]=QObject::tr("保留待定信息");
    qmap_infotype["Q"]=QObject::tr("保留待定信息");
    qmap_infotype["R"]=QObject::tr("渔政信息");
    qmap_infotype["S"]=QObject::tr("保留待定信息");
    qmap_infotype["T"]=QObject::tr("语音专用信息");
    qmap_infotype["U"]=QObject::tr("保留待定信息");
    qmap_infotype["V"]=QObject::tr("特别业务信息");
    qmap_infotype["W"]=QObject::tr("特别业务信息");
    qmap_infotype["X"]=QObject::tr("特别业务信息");
    qmap_infotype["Y"]=QObject::tr("特别业务信息");
    qmap_infotype["Z"]=QObject::tr("现无电报");





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
   //qDebug()<<"keytone"<<keytone;
   //qDebug()<<"keytone_level"<<keytone_level;
   //qDebug()<<"hinttone"<<hinttone;
   //qDebug()<<"hinetone_level"<<hinttone_level;

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


