#include "panel_setup.h"
#include "common.h"
#include "mainwin.h"

#include <QTranslator>

panel_setup::panel_setup(QWidget *parent) : QWidget(parent)
{


    QString cb_stylesheet="QCheckBox {color:  black;font-size:24px;}"
        "QCheckBox::indicator { position: absolute;height: 27px;width: 64px;}"
       "QCheckBox::indicator:checked {image: url(:/res/checkbox_on.png);}"
       "QCheckBox::indicator:unchecked {image: url(:/res/checkbox_off.png);}";

    QString sb_stylesheet="QSpinBox{font-size:24px;border-width:1px;}"
            "QSpinBox::up-button{width:24px;height:24px;subcontrol-position:right;}"
            "QSpinBox::down-button{width:24px;height:24px;subcontrol-position:left;}";

    QString gb_stylesheet="QGroupBox{font-size:24px; border:2px solid gray; margin-top:1ex;}"
            "QGroupBox::title{subcontrol-origin:margin; subcontrol-position:top center; padding: 0 30px;}";

    setFont(QFont("kaiti",20));

    //setStyleSheet(mystyle);

    lbl_datetime_title = new QLabel(tr("Current DateTime:"));
    lbl_datetime_title->setFont(QFont("Kaiti",18));
    lbl_datetime = new QLabel(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    lbl_datetime->setFont(QFont("Kaiti",18));
    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addWidget(lbl_datetime_title);
    hbox1->addWidget(lbl_datetime);
    hbox1->addStretch(0);
    hbox1->setSpacing(20);


    sb_year = new QSpinBox;
    sb_year->setStyleSheet(sb_stylesheet);
    sb_year->setRange(2010,2030);
    sb_year->setSuffix(tr("Year"));
    sb_year->setAlignment(Qt::AlignHCenter);

    sb_month = new QSpinBox;
    sb_month->setStyleSheet(sb_stylesheet);
    sb_month->setRange(1,12);
    sb_month->setSuffix(tr("Month"));
    sb_month->setAlignment(Qt::AlignHCenter);

    sb_day = new QSpinBox;
    sb_day->setStyleSheet(sb_stylesheet);
    sb_day->setRange(1,31);
    sb_day->setSuffix(tr("Day"));
    sb_day->setAlignment(Qt::AlignHCenter);

    btn_setdate = new QPushButton(tr("  Set  "));
    btn_setdate->setFont(QFont("KaiTi",18));
    QObject::connect(btn_setdate,SIGNAL(clicked()),this,SLOT(on_btn_setdate_clicked()));
    QHBoxLayout *hbox2 = new QHBoxLayout;
    hbox2->addWidget(sb_year);
    hbox2->addWidget(sb_month);
    hbox2->addWidget(sb_day);
    hbox2->addWidget(btn_setdate);
    hbox2->addStretch(0);
    hbox2->setSpacing(20);

    sb_hour = new QSpinBox;
    sb_hour->setStyleSheet(sb_stylesheet);
    sb_hour->setRange(0,23);
    sb_hour->setSuffix(tr("Hour"));
    sb_hour->setAlignment(Qt::AlignHCenter);

    sb_minute = new QSpinBox;
    sb_minute->setStyleSheet(sb_stylesheet);
    sb_minute->setRange(0,59);
    sb_minute->setSuffix(tr("Minute"));
    sb_minute->setAlignment(Qt::AlignHCenter);

    sb_second = new QSpinBox;
    sb_second->setStyleSheet(sb_stylesheet);
    sb_second->setRange(0,59);
    sb_second->setSuffix(tr("Sec"));
    sb_second->setAlignment(Qt::AlignHCenter);

    btn_settime = new QPushButton(tr("  Set  "));
    btn_settime->setFont(QFont("KaiTi",18));
    QObject::connect(btn_settime,SIGNAL(clicked()),this,SLOT(on_btn_settime_clicked()));

    QHBoxLayout *hbox3 = new QHBoxLayout;
    hbox3->addWidget(sb_hour);
    hbox3->addWidget(sb_minute);
    hbox3->addWidget(sb_second);
    hbox3->addWidget(btn_settime);
    hbox3->addStretch(0);
    hbox3->setSpacing(20);


    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addStretch(0);
    vbox1->addLayout(hbox1);
    vbox1->addStretch(0);
    vbox1->addLayout(hbox2);
    vbox1->addStretch(0);
    vbox1->addLayout(hbox3);

    grp_timeset = new QGroupBox(tr("Date Time Setup"));
    grp_timeset->setStyleSheet(gb_stylesheet);
    grp_timeset->setLayout(vbox1);

//按键音设置

//    cb_keytone = new QCheckBox(tr("按  键  音"));
//    cb_keytone->setStyleSheet(cb_stylesheet);
//    cb_keytone->setLayoutDirection(Qt::RightToLeft);

    lbl_keytone =  new QLabel(tr("Key Press Tone"));
    lbl_keytone->setFont(QFont("kaiti",20));
    sb_keytone = new QSpinBox;
    sb_keytone->setStyleSheet(sb_stylesheet);
    sb_keytone->setRange(1,25);
    sb_keytone->setPrefix(tr("Type "));
    sb_keytone->setValue(keytone);
    QObject::connect(sb_keytone,SIGNAL(valueChanged(int)),this,SLOT(on_sb_keytone_valueChanged(int)));

    sb_keytone_level = new QSpinBox;
    sb_keytone_level->setStyleSheet(sb_stylesheet);
    sb_keytone_level->setRange(0,9);
    sb_keytone_level->setPrefix(tr("Vol "));
    sb_keytone_level->setValue(keytone_level);
    QObject::connect(sb_keytone_level,SIGNAL(valueChanged(int)),this,SLOT(on_sb_keytone_level_valueChanged(int)));


    QHBoxLayout *hl_1 = new QHBoxLayout;
    hl_1->addWidget(lbl_keytone);
    hl_1->addWidget(sb_keytone);
    hl_1->addWidget(sb_keytone_level);
    hl_1->addStretch(0);
    hl_1->setSpacing(20);

//提示音设置
    lbl_hinttone =  new QLabel(tr("Hint Tone"));
    lbl_hinttone->setFont(QFont("kaiti",20));

    sb_hinttone = new QSpinBox;
    sb_hinttone->setStyleSheet(sb_stylesheet);
    sb_hinttone->setRange(1,25);
    sb_hinttone->setPrefix(tr("Type "));
    sb_hinttone->setValue(hinttone);
    QObject::connect(sb_hinttone,SIGNAL(valueChanged(int)),this,SLOT(on_sb_hinttone_valueChanged(int)));

    sb_hinttone_level = new QSpinBox;
    sb_hinttone_level->setStyleSheet(sb_stylesheet);
    sb_hinttone_level->setRange(0,9);
    sb_hinttone_level->setPrefix(tr("Vol "));
    sb_hinttone_level->setValue(hinttone_level);
    QObject::connect(sb_hinttone_level,SIGNAL(valueChanged(int)),this,SLOT(on_sb_hinttone_level_valueChanged(int)));


    QHBoxLayout *hl_2 = new QHBoxLayout;
    hl_2->addWidget(lbl_hinttone);
    hl_2->addWidget(sb_hinttone);
    hl_2->addWidget(sb_hinttone_level);
    hl_2->addStretch(0);
    hl_2->setSpacing(20);
//自动播报
    cb_autotts = new QCheckBox(tr("Auto Text To Speech"));
    cb_autotts->setStyleSheet(cb_stylesheet);
    cb_autotts->setLayoutDirection(Qt::RightToLeft);
    sb_volum = new QSpinBox;
    sb_volum->setStyleSheet(sb_stylesheet);
    sb_volum->setRange(1,11);
    sb_volum->setPrefix(tr("Vol "));
    sb_volum->setValue(tts_volume);

    QHBoxLayout *hl_3 = new QHBoxLayout;
    hl_3->addWidget(cb_autotts);
    hl_3->addWidget(sb_volum);
    hl_3->addStretch(0);
    hl_3->setSpacing(20);

//背光设置
    lbl_backlight =  new QLabel(tr("Backlight Setup"));
    lbl_backlight->setFont(QFont("kaiti",20));
    combo_backlight =  new QComboBox;
    combo_backlight->setStyleSheet("QComboBox {font-size:24px;}");
    combo_backlight->addItem(tr("Always On"),QVariant(0x0));
    combo_backlight->addItem(tr("10 seconds"),QVariant(10));
    combo_backlight->addItem(tr("30 seconds"),QVariant(30));
    combo_backlight->addItem(tr("1 minute"),QVariant(60));
    combo_backlight->addItem(tr("5 minutes"),QVariant(300));
    combo_backlight->addItem(tr("10 minutes"),QVariant(600));

    for(int i=0;i<combo_backlight->count();i++)
    {
        if(backlight_lcd==combo_backlight->itemData(i,Qt::UserRole).toInt())
        {
            combo_backlight->setCurrentIndex(i);
            break;
        }
    }


    QObject::connect(combo_backlight,SIGNAL(currentIndexChanged(int)),this,SLOT(on_combo_backlight_currentIndexChanged(int)));

    QHBoxLayout *hl_4 = new QHBoxLayout;
    hl_4->addWidget(lbl_backlight);
    hl_4->addWidget(combo_backlight);
    hl_4->addStretch(0);

    QVBoxLayout *vl_1 = new QVBoxLayout;
    vl_1->addLayout(hl_1);
    vl_1->addLayout(hl_2);
    vl_1->addLayout(hl_3);
    vl_1->addLayout(hl_4);
    //vl_1->setContentsMargins(0,20,0,20);

    grp_toneset = new QGroupBox(tr("Tone and Backlight Setup"));
    grp_toneset->setStyleSheet(gb_stylesheet);
    grp_toneset->setLayout(vl_1);

    QHBoxLayout *hl_system = new QHBoxLayout;
    grp_system = new QGroupBox(tr("System Maintenance"));
    grp_system->setStyleSheet(gb_stylesheet);

    btn_db_backup = new QPushButton(tr("DB Backup"));
    btn_db_backup->setStyleSheet("QPushButton { font-size:20pt;}");
    QObject::connect(btn_db_backup,SIGNAL(clicked()),this,SLOT(on_btn_db_backup_clicked()));

    btn_db_export = new QPushButton(tr("DB Export"));
    btn_db_export->setStyleSheet("QPushButton { font-size:20pt;}");
    QObject::connect(btn_db_export,SIGNAL(clicked()),this,SLOT(on_btn_db_export_clicked()));

    btn_sys_upgrade = new QPushButton(tr("System Upgrade"));
    btn_sys_upgrade->setStyleSheet("QPushButton { font-size:20pt;}");
    QObject::connect(btn_sys_upgrade,SIGNAL(clicked()),this,SLOT(on_btn_sys_upgrade_clicked()));

    hl_system->addStretch(0);
    hl_system->addWidget(btn_db_backup);
    hl_system->addWidget(btn_db_export);
    hl_system->addWidget(btn_sys_upgrade);
    hl_system->addStretch(0);
    grp_system->setLayout(hl_system);


    QVBoxLayout *vbox_left = new QVBoxLayout;
    vbox_left->addWidget(grp_timeset,4);
    vbox_left->addWidget(grp_toneset,5);
    vbox_left->addWidget(grp_system,2);
    vbox_left->setContentsMargins(10,10,10,10);
    vbox_left->setSpacing(20);

//右边的按钮
    btn_ret = new QPushButton(tr("Return"));
    QObject::connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_ret_clicked()));
    btn_default = new QPushButton(tr("Default"));
    QObject::connect(btn_default,SIGNAL(clicked()),this,SLOT(on_btn_default_clicked()));
    btn_save = new QPushButton(tr("Save"));
    QObject::connect(btn_save,SIGNAL(clicked()),this,SLOT(on_btn_save_clicked()));


    grp_lang  = new QGroupBox(("Language"));
    //grp_chn->setStyleSheet("border: 1px solid lightgray;font-size:16px;");
    grp_lang->setStyleSheet("font-size:18px;");
    rb_chn  = new QRadioButton(tr("中文"));
    rb_eng  = new QRadioButton(tr("English"));
    rb_chn->setChecked(true);
    QObject::connect(rb_chn,SIGNAL(clicked()),SLOT(on_rb_chn_clicked()));
    QObject::connect(rb_eng,SIGNAL(clicked()),SLOT(on_rb_eng_clicked()));

    QVBoxLayout *vb= new QVBoxLayout;
    vb->addWidget(rb_chn);
    vb->addWidget(rb_eng);
    grp_lang->setLayout(vb);

    QVBoxLayout *vbox_right = new QVBoxLayout;
    vbox_right->addWidget(btn_ret);
    vbox_right->addStretch(1);
    vbox_right->addWidget(grp_lang);
    vbox_right->addWidget(btn_save);
    vbox_right->addWidget(btn_default);

    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addLayout(vbox_left);
    mainlayout->addLayout(vbox_right);
    setLayout(mainlayout);

    m_nTimerId = startTimer(1000);
}



panel_setup::~panel_setup()
{
    if ( m_nTimerId != 0 )  killTimer(m_nTimerId);
}




void panel_setup::retranslate(QWidget *parent)
{
    lbl_datetime_title->setText(tr("Current DateTime:"));
    sb_year->setSuffix(tr("Year"));
    sb_month->setSuffix(tr("Month"));
    sb_day->setSuffix(tr("Day"));

    btn_setdate->setText(tr("  Set  "));
    sb_hour->setSuffix(tr("Hour"));
    sb_minute->setSuffix(tr("Minute"));
    sb_second->setSuffix(tr("Sec"));
    btn_settime->setText(tr("  Set  "));
    grp_timeset->setTitle(tr("Date Time Setup"));

    lbl_keytone->setText(tr("Key Press Tone"));
    sb_keytone->setPrefix(tr("Type "));
    sb_keytone_level->setPrefix(tr("Vol "));
//提示音设置
    lbl_hinttone->setText(tr("Hint Tone"));
    sb_hinttone->setPrefix(tr("Type "));
    sb_hinttone_level->setPrefix(tr("Vol "));

//自动播报
    cb_autotts->setText(tr("Auto Text To Speech"));
    sb_volum->setPrefix(tr("Vol "));
//背光设置
    lbl_backlight->setText(tr("Backlight Setup"));

    combo_backlight->clear();
    combo_backlight->addItem(tr("Always On"),QVariant(0x0));
    combo_backlight->addItem(tr("10 seconds"),QVariant(10));
    combo_backlight->addItem(tr("30 seconds"),QVariant(30));
    combo_backlight->addItem(tr("1 minute"),QVariant(60));
    combo_backlight->addItem(tr("5 minutes"),QVariant(300));
    combo_backlight->addItem(tr("10 minutes"),QVariant(600));

    grp_toneset->setTitle(tr("Tone and Backlight Setup"));
    grp_system->setTitle(tr("System Maintenance"));

    btn_db_backup->setText(tr("DB Backup"));
    btn_db_export->setText(tr("DB Export"));
    btn_sys_upgrade->setText(tr("System Upgrade"));

//右边的按钮
    btn_ret->setText(tr("Return"));
    btn_default->setText(tr("Default"));
    btn_save->setText(tr("Save"));



    grp_lang->setTitle(("Language"));
    //grp_chn->setStyleSheet("border: 1px solid lightgray;font-size:16px;");
    grp_lang->setStyleSheet("font-size:18px;");
    rb_chn->setText(tr("中文"));
    rb_eng->setText(tr("English"));
}



void panel_setup::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch(e->type())
    {
    case QEvent::LanguageChange:
        retranslate(this);
        break;
    default:
        break;
    }
}



void panel_setup::timerEvent( QTimerEvent *event )
{
    lbl_datetime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}


void panel_setup::on_btn_setdate_clicked()
{
    QString str;
    str.sprintf("date -s %d%02d%02d%02d%02d.%02d",sb_year->value(),sb_month->value(),sb_day->value(),sb_hour->value(),sb_minute->value(),sb_second->value());
    system(str.toLatin1().data());
}


void panel_setup::on_btn_settime_clicked()
{
    QString str;
    str.sprintf("date -s %02d:%02d:%02d",sb_hour->value(),sb_minute->value(),sb_second->value());
    system(str.toLatin1().data());
}


void panel_setup::on_btn_ret_clicked()
{
    keytone=sb_keytone->value();
    keytone_level=sb_keytone_level->value();
    hinttone=sb_hinttone->value();
    hinttone_level=sb_hinttone_level->value();
    tts_volume=sb_volum->value();
    tts_auto = cb_autotts->isChecked()?1:0;

    backlight_lcd=combo_backlight->itemData(combo_backlight->currentIndex(),Qt::UserRole).toInt();

    config_write(0);  //不写到文件中

    MainWin::instance()->setStackIndex(0);
}


void panel_setup::on_btn_default_clicked()
{
    keytone=1;   //sound101-sound125
    sb_keytone->setValue(keytone);
    keytone_level=5;
    sb_keytone_level->setValue(keytone_level);
    hinttone=1;
    sb_hinttone->setValue(hinttone);
    hinttone_level=5;
    sb_hinttone_level->setValue(hinttone_level);

    tts_volume=5;
    sb_volum->setValue(tts_volume);
    tts_auto=0;
    cb_autotts->setChecked(false);


    backlight_lcd=30;
    combo_backlight->setCurrentIndex(2);
}

void panel_setup::on_btn_save_clicked()
{
    tts_auto = cb_autotts->isChecked()?1:0;  //这个没有使用signal触发
    config_write(1);
}

//按键音的类型
void panel_setup::on_sb_keytone_valueChanged(int value)
{
    char buf[21]={0xfd,0x00,0x12,0x01,0x00,'[','v','0',']','[','x','1',']','s','o','u','n','d','1','0','0'};
    keytone=value;
    if(fd_tts)
    {
       buf[7]+=keytone_level;
       buf[19]+=keytone/10;
       buf[20]+=keytone%10;
       ::write(fd_tts,buf,21);
    }
}
//按键音的音量
void panel_setup::on_sb_keytone_level_valueChanged(int value)
{
    char buf[21]={0xfd,0x00,0x12,0x01,0x00,'[','v','0',']','[','x','1',']','s','o','u','n','d','1','0','0'};
    keytone_level=value;
    if(fd_tts)
    {
       buf[7]+=keytone_level;
       buf[19]+=keytone/10;
       buf[20]+=keytone%10;
       ::write(fd_tts,buf,21);
    }
}


void panel_setup::on_sb_hinttone_valueChanged(int value)
{
    char buf[21]={0xfd,0x00,0x12,0x01,0x00,'[','v','0',']','[','x','1',']','s','o','u','n','d','1','0','0'};

    hinttone=value;
    if(fd_tts)
    {
       buf[7]+=hinttone_level;
       buf[19]+=hinttone/10;
       buf[20]+=hinttone%10;
       ::write(fd_tts,buf,21);
    }
}


void panel_setup::on_sb_hinttone_level_valueChanged(int value)
{
    char buf[21]={0xfd,0x00,0x12,0x01,0x00,'[','v','0',']','[','x','1',']','s','o','u','n','d','1','0','0'};

    hinttone_level=value;
    if(fd_tts)
    {
       buf[7]+=hinttone_level;
       buf[19]+=hinttone/10;
       buf[20]+=hinttone%10;
       ::write(fd_tts,buf,21);
    }
}

void panel_setup::on_combo_backlight_currentIndexChanged(int index)
{
    backlight_lcd=combo_backlight->itemData(index,Qt::UserRole).toInt();
    //qDebug()<<"backlight_lcd="<<backlight_lcd;
}

/*数据备份*/
void panel_setup::on_btn_db_backup_clicked()
{

    QString str;
    str.sprintf("cp /Informationdb.db /db%s.db",QDateTime::currentDateTime().toString("yyyyMMddhhmmss").toLatin1().data());
    system(str.toLatin1().data());  //不包含中文没有问题，否则的话要通过QByteArray中转
}

/*拷贝当前记录到U盘*/
void panel_setup::on_btn_db_export_clicked()
{

}
/*系统升级*/
void panel_setup::on_btn_sys_upgrade_clicked()
{
    QFileInfo fi("/mnt/udisk/navtex");
    if(fi.exists())
    {
        QString str;
        str.sprintf("cp //mnt/udisk/navtex /");
        system(str.toLatin1().data());  //不包含中文没有问题，否则的话要通过QByteArray中转
    }
    else
    {
        QMessageBox::information(this,tr("Hint"),tr("<font size=20>File not exist!</font>"));
    }
}

void panel_setup::on_rb_chn_clicked()
{
    qApp->removeTranslator(trans);
    trans=new QTranslator();
    qDebug()<<"load chn.qm "<<trans->load("chn.qm",qApp->applicationDirPath());
    qApp->installTranslator(trans);
    this->repaint();
}

void panel_setup::on_rb_eng_clicked()
{
    qApp->removeTranslator(trans);
//    trans=new QTranslator();
//    qDebug()<<"load eng.qm "<<trans->load("eng.qm",qApp->applicationDirPath());
//    qApp->installTranslator(trans);
//    this->repaint();
}
