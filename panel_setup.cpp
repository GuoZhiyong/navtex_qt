#include "panel_setup.h"
#include "common.h"
#include "mainwin.h"



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

    sb_year = new QSpinBox;
    sb_year->setStyleSheet(sb_stylesheet);
    sb_year->setRange(2010,2030);
    sb_year->setSuffix(tr("年"));

    sb_month = new QSpinBox;
    sb_month->setStyleSheet(sb_stylesheet);
    sb_month->setRange(1,12);
    sb_month->setSuffix(tr("月"));

    sb_day = new QSpinBox;
    sb_day->setStyleSheet(sb_stylesheet);
    sb_day->setRange(1,31);
    sb_day->setSuffix(tr("日"));

    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addStretch(0);
    hbox1->addWidget(sb_year);
    hbox1->addWidget(sb_month);
    hbox1->addWidget(sb_day);
    hbox1->addStretch(0);
    hbox1->setSpacing(20);

    sb_hour = new QSpinBox;
    sb_hour->setStyleSheet(sb_stylesheet);
    sb_hour->setRange(0,23);
    sb_hour->setSuffix(tr("时"));

    sb_minute = new QSpinBox;
    sb_minute->setStyleSheet(sb_stylesheet);
    sb_minute->setRange(0,59);
    sb_minute->setSuffix(tr("分"));

    sb_second = new QSpinBox;
    sb_second->setStyleSheet(sb_stylesheet);
    sb_second->setRange(0,59);
    sb_second->setSuffix(tr("秒"));

    QHBoxLayout *hbox2 = new QHBoxLayout;
    hbox2->addStretch(0);
    hbox2->addWidget(sb_hour);
    hbox2->addWidget(sb_minute);
    hbox2->addWidget(sb_second);
    hbox2->addStretch(0);
    hbox2->setSpacing(20);


    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addLayout(hbox1);
    vbox1->addLayout(hbox2);


    QGroupBox *grp_timeset = new QGroupBox(tr("时间设置"));
    grp_timeset->setStyleSheet(gb_stylesheet);
    grp_timeset->setLayout(vbox1);

//按键音设置

//    cb_keytone = new QCheckBox(tr("按  键  音"));
//    cb_keytone->setStyleSheet(cb_stylesheet);
//    cb_keytone->setLayoutDirection(Qt::RightToLeft);

    sb_keytone = new QSpinBox;
    sb_keytone->setStyleSheet(sb_stylesheet);
    sb_keytone->setRange(1,25);
    sb_keytone->setPrefix(tr("按键音"));
    QObject::connect(sb_keytone,SIGNAL(valueChanged(int)),this,SLOT(on_sb_keytone_valueChanged(int)));

    sb_keytone_level = new QSpinBox;
    sb_keytone_level->setStyleSheet(sb_stylesheet);
    sb_keytone_level->setRange(0,9);
    sb_keytone_level->setPrefix(tr("按键音量"));
    QObject::connect(sb_keytone_level,SIGNAL(valueChanged(int)),this,SLOT(on_sb_keytone_level_valueChanged(int)));


    QHBoxLayout *hl_1 = new QHBoxLayout;
    //hl_1->addWidget(cb_keytone);
    hl_1->addWidget(sb_keytone);
    hl_1->addWidget(sb_keytone_level);
    hl_1->addStretch(0);
    hl_1->setSpacing(20);
//提示音设置
//    cb_hinttone = new QCheckBox(tr("提  示  音"));
//    cb_hinttone->setStyleSheet(cb_stylesheet);
//    cb_hinttone->setLayoutDirection(Qt::RightToLeft);

    sb_hinttone = new QSpinBox;
    sb_hinttone->setStyleSheet(sb_stylesheet);
    sb_hinttone->setRange(1,25);
    sb_hinttone->setPrefix(tr("提示音"));
    QObject::connect(sb_hinttone,SIGNAL(valueChanged(int)),this,SLOT(on_sb_hinttone_valueChanged(int)));

    sb_hinttone_level = new QSpinBox;
    sb_hinttone_level->setStyleSheet(sb_stylesheet);
    sb_hinttone_level->setRange(0,9);
    sb_hinttone_level->setPrefix(tr("提示音量"));
    QObject::connect(sb_hinttone_level,SIGNAL(valueChanged(int)),this,SLOT(on_sb_hinttone_level_valueChanged(int)));


    QHBoxLayout *hl_2 = new QHBoxLayout;
//    hl_2->addWidget(cb_hinttone);
    hl_2->addWidget(sb_hinttone);
    hl_2->addWidget(sb_hinttone_level);
    hl_2->addStretch(0);
    hl_2->setSpacing(20);
//自动播报
    cb_autotts = new QCheckBox(tr("自动播报"));
    cb_autotts->setStyleSheet(cb_stylesheet);
    cb_autotts->setLayoutDirection(Qt::RightToLeft);
    sb_volum = new QSpinBox;
    sb_volum->setStyleSheet(sb_stylesheet);
    sb_volum->setRange(1,11);
    sb_volum->setPrefix(tr(" 音量 "));
    sb_volum->setValue(5);

    QHBoxLayout *hl_3 = new QHBoxLayout;
    hl_3->addWidget(cb_autotts);
    hl_3->addWidget(sb_volum);
    hl_3->addStretch(0);
    hl_3->setSpacing(20);

//背光设置
    QLabel *lbl_backlight =  new QLabel(tr("背光设置"));
    lbl_backlight->setFont(QFont("kaiti",20));
    combo_backlight =  new QComboBox;
    combo_backlight->setStyleSheet("QComboBox {font-size:24px;}");
    combo_backlight->addItem(tr("常亮"),QVariant(0));
    combo_backlight->addItem(tr("10秒没有操作"),QVariant(10));
    combo_backlight->addItem(tr("30秒没有操作"),QVariant(30));
    combo_backlight->addItem(tr("1分钟没有操作"),QVariant(60));
    combo_backlight->addItem(tr("5分钟没有操作"),QVariant(300));
    combo_backlight->addItem(tr("10分钟没有操作"),QVariant(600));

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

    QGroupBox *grp_toneset = new QGroupBox(tr("声音背光设置"));
    grp_toneset->setStyleSheet(gb_stylesheet);
    grp_toneset->setLayout(vl_1);



    QHBoxLayout *hl_system = new QHBoxLayout;
    QGroupBox *grp_system = new QGroupBox(tr("系统维护"));
    grp_system->setStyleSheet(gb_stylesheet);
    btn_db_backup = new QPushButton(tr("数据库备份"));
    btn_db_backup->setStyleSheet("QPushButton { font-size:20pt;}");
    btn_db_export = new QPushButton(tr("数据库导出"));
    btn_db_export->setStyleSheet("QPushButton { font-size:20pt;}");
    btn_sys_upgrade = new QPushButton(tr("系统升级"));
    btn_sys_upgrade->setStyleSheet("QPushButton { font-size:20pt;}");
    hl_system->addStretch(0);
    hl_system->addWidget(btn_db_backup);
    hl_system->addWidget(btn_db_export);
    hl_system->addWidget(btn_sys_upgrade);
    hl_system->addStretch(0);
    grp_system->setLayout(hl_system);


    QVBoxLayout *vbox_left = new QVBoxLayout;
    vbox_left->addWidget(grp_timeset);
    vbox_left->addWidget(grp_toneset);
    vbox_left->addWidget(grp_system);
    vbox_left->setContentsMargins(10,10,10,10);
    vbox_left->setSpacing(20);

    btn_ret = new QPushButton(tr("返回"));
    QObject::connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_ret_clicked()));
    btn_default = new QPushButton(tr("默认参数"));
    QObject::connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_default_clicked()));
    btn_save = new QPushButton(tr("保存参数"));
    QObject::connect(btn_save,SIGNAL(clicked()),this,SLOT(on_btn_save_clicked()));

    QVBoxLayout *vbox_right = new QVBoxLayout;
    vbox_right->addWidget(btn_ret);
    vbox_right->addStretch(1);
    vbox_right->addWidget(btn_save);
    vbox_right->addWidget(btn_default);



    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addLayout(vbox_left);
    mainlayout->addLayout(vbox_right);
    setLayout(mainlayout);
    show();
}

panel_setup::~panel_setup()
{

}


void panel_setup::paintEvent(QPaintEvent*)
{
//    QStyleOption opt;
//    opt.init(this);
//    QPainter p(this);
//    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

void panel_setup::on_btn_ret_clicked()
{
    MainWin::instance()->setStackIndex(0);
}


void panel_setup::on_btn_default_clicked()
{

}

void panel_setup::on_btn_save_clicked()
{
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
    //backlight_lcd=
    qDebug()<<"current index"<<index;

}
