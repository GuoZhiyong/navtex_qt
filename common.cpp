#include "common.h"
#include <QtSql>

#include <QMap>

static QSqlDatabase dbconn;            //存储数据库访问的实例

QList<NAVTEXITEM *> navtexitemlist;
int navtexitemlist_pos=-1;


QString sl_site[]={"A","B","C","D","E","F","G",\
                   "H","I","J","K","L","三亚","广州","福州",\
                   "P","上海","大连","S","天津","U","V","W","X","Y","湛江"};

QString sl_info[]={"航行警告","气象警告","冰况报告","搜救信息","气象预报","引航业务信息","船舶自动识别系统",\
                   "劳兰信息","奥米加信息","卫星导航信息","其它电子导航信息","航行警告(附)","M","N","O",\
                   "P","Q","渔政信息","S","语音专用信息","U","V","W","X","Y","Z"};

static QMap<QString,QString> qmap_site;
static QMap<QString,QString> qmap_infotype;


int tts_fd=-1;


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
    int index=0;
    NAVTEXITEM *pnavtexitem;
    QSqlQuery query;
    query.exec("select * from Informations");
    while(query.next())
    {
        pnavtexitem = new NAVTEXITEM;
        pnavtexitem->id = query.value(0).toInt();  //对应数据库的id
        pnavtexitem->code=query.value(2).toString();   //技术编码
        pnavtexitem->chn=query.value(3).toInt();    //使用通道
        pnavtexitem->Broadcast=query.value(1).toString();
        pnavtexitem->Receive=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        pnavtexitem->Content=query.value(9).toString();
        pnavtexitem->fRead=query.value(7).toInt();
        pnavtexitem->BER=query.value(8).toInt();
        pnavtexitem->index=index;
        navtexitemlist<<pnavtexitem;
    }
}

void db_create(void)
{

}

void db_close(void)
{
    dbconn.close();
}
