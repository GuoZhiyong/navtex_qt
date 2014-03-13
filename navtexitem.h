#ifndef NAVTEXITEM_H
#define NAVTEXITEM_H

#include <QString>
#include <QList>


typedef struct _NavtexItem
{
    int id;     //数据库的id,会根据选择的不同而改变
    int index;  //在flowlayout中显示的位置,从0开始
    QString code;   //技术编码
    int chn;    //使用通道
    QString Broadcast;
    QString Receive;
    QString Content;
    int fRead;
    int BER;
}NAVTEXITEM;



extern QList<NAVTEXITEM *> navtexitemlist;
extern int navtexitemlist_pos;
void db_init(void);
void db_close(void);




#endif // NAVTEXITEM_H
