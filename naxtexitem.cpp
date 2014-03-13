#include "navtexitem.h"
#include <QtSql>

static QSqlDatabase dbconn;            //存储数据库访问的实例

QList<NAVTEXITEM *> navtexitemlist;
int navtexitemlist_pos=-1;


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
        //pnavtexitem->DateTimeReceive=query.value(2).toString();
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
