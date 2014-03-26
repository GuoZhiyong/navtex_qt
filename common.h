#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QList>
#include <QMap>

#define KEY_CHN     0
#define KEY_PGUP    1
#define KEY_RET     2
#define KEY_PGDN    3
#define KEY_UP      4
#define KEY_LEFT    5
#define KEY_OK      6
#define KEY_DOWN    7
#define KEY_RIGHT   8
#define KEY_CANCEL  9
#define KEY_LOCK    10
#define KEY_486     11
#define KEY_TTS     12
#define KEY_TEST    13

#define KEY_MUTE    15
#define KEY_518     16
#define KEY_VOL_UP  17
#define KEY_SEEK    18

#define KEY_4209     20
#define KEY_DATA     21
#define KEY_VOL_DN   22
#define KEY_PRINT    23
#define KEY_CLEAR    24  //消警




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

extern QString sl_site[];
extern QString sl_info[];

extern QMap<QString,QString> qmap_site;
extern QMap<QString,QString> qmap_infotype;


extern int tts_fd;
void db_init(void);
void db_close(void);


extern int keytone;
extern int keytone_level;
extern int hinttone;
extern int hinttone_level;
extern int tts_volume;
extern int backlight;

#endif // NAVTEXITEM_H
