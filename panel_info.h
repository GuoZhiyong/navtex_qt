#ifndef PANEL_INFO_H
#define PANEL_INFO_H

#include <QScrollArea>

#include <QtSql>


enum CHANNEL { chn_486 = 0x1, chn_518 = 0x01, chn_4209 = 0x02 };

typedef struct _NavtexItem
{
    int id;     //数据库的id,用不到，插入时 并不知道数值
    QString code;   //技术编码
    int chn;    //使用通道
    QString Broadcast;
    QString Receive;
    QString Content;
    int fRead;
    int BER;
    //panel_item *item;
}NAVTEXITEM;

extern QList<NAVTEXITEM *> navtexitemlist;

namespace Ui {
class panel_info;
}

class panel_info : public QScrollArea
{
    Q_OBJECT

public:
    explicit panel_info(QWidget *parent = 0);
    ~panel_info();

public slots:
    void serialport_rx(QByteArray bytes);
    void btnViewClick(NAVTEXITEM *item);
    void btnTTSClick(NAVTEXITEM *item);

private:
    Ui::panel_info *ui;
    QSqlDatabase dbconn;            //存储数据库访问的实例
};

#endif // PANEL_INFO_H
