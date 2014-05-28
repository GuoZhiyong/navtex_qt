#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QList>
#include <QMap>
#include <QWidget>


#define PIN_KEYPAD_BACKLIGHT (32*1+1)  // S3C2410_GPB1
#define PIN_LCD_BACKLIGHT (32*6+4)   //S3C2410_GPG4
#define PIN_AUDIO_PA (32*1+8)       //S3c2410_GPB8

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
    QString code;   //技术编码
    int chn;    //使用通道
    QString Broadcast;
    QString Receive;
    QString Content;
    int fRead;
    int BER;
}ITEM_DATA;


//#include "panel_item.h"
//extern QList<NAVTEXITEM *> navtexitemlist;

extern QList<QWidget *> itemlist;

extern int navtexitemlist_pos;

extern QString sl_site[];
extern QString sl_info[];

extern QMap<QString,QString> qmap_site;
extern QMap<QString,QString> qmap_infotype;


extern int fd_tts;
extern int fd_gpio;

extern int keytone;
extern int keytone_level;
extern int hinttone;
extern int hinttone_level;
extern int tts_volume;
extern int tts_auto;
extern int backlight_lcd;
extern int backlight_keypad;


void db_init(void);
void db_close(void);

void config_read(void);
void config_write(int writetofile);


#endif // NAVTEXITEM_H
