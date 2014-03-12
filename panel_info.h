#ifndef PANEL_INFO_H
#define PANEL_INFO_H

#include "FlowLayout.hpp"
#include <QScrollArea>

#include <QtSql>
#include <QKeyEvent>


enum CHANNEL { chn_486 = 0x1, chn_518 = 0x01, chn_4209 = 0x02 };

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

namespace Ui {
class panel_info;
}

class panel_info : public QScrollArea
{
    Q_OBJECT

public:
    explicit panel_info(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent  *event);
    void myDrawItem(int index);
    ~panel_info();

public slots:
    void serialport_rx(QByteArray bytes);
    void btnViewClick(NAVTEXITEM *item);
    void btnTTSClick(NAVTEXITEM *item);

private:
    Ui::panel_info *ui;
    QSqlDatabase dbconn;            //存储数据库访问的实例
    FlowLayout *layout;             //主布局管理器，用来访问单个的panel_item

};

#endif // PANEL_INFO_H
