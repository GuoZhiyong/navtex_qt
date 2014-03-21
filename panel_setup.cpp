#include "panel_setup.h"

#include "mainwin.h"



panel_setup::panel_setup(QWidget *parent) : QWidget(parent)
{


    QString cb_stylesheet="QCheckBox {color:  black;font-size:20px;} QCheckBox::indicator { position: absolute;height: 27px;width: 64px;}"
       "QCheckBox::indicator:checked {image: url(:/res/checkbox_on.png);}"
       "QCheckBox::indicator:unchecked {image: url(:/res/checkbox_off.png);}";

    QString sb_stylesheet="QSpinBox{font-size:24px;border-width:1px;}"
            "QSpinBox::up-button{width:24px;height:24px;subcontrol-position:right;}"
            "QSpinBox::down-button{width:24px;height:24px;subcontrol-position:left;}";

    setFont(QFont("kaiti",18));

    btn_timeset = new QPushButton(tr("时间设置"));
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
    hbox1->addWidget(sb_year);
    hbox1->addWidget(sb_month);
    hbox1->addWidget(sb_day);

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
    hbox2->addWidget(sb_hour);
    hbox2->addWidget(sb_minute);
    hbox2->addWidget(sb_second);

    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addLayout(hbox1);
    vbox1->addLayout(hbox2);

    QHBoxLayout *hb_timeset = new QHBoxLayout;
    hb_timeset->addWidget(btn_timeset);
    hb_timeset->addLayout(vbox1);
    hb_timeset->addStretch(0);


    btn_chnset = new QPushButton(tr("通道设置"));

//按键提示音设置

    cb_keytone = new QCheckBox(tr("按  键  音"));
    cb_keytone->setStyleSheet(cb_stylesheet);
    cb_keytone->setLayoutDirection(Qt::RightToLeft);

    sb_keytone = new QSpinBox;
    sb_keytone->setStyleSheet(sb_stylesheet);
    sb_keytone->setRange(1,25);
    sb_keytone->setPrefix(tr("按键音"));

    QHBoxLayout *hl_1 = new QHBoxLayout;
    hl_1->addWidget(cb_keytone);
    hl_1->addWidget(sb_keytone);
    hl_1->addStretch(0);

    cb_hinttone = new QCheckBox(tr("提  示  音"));
    cb_hinttone->setStyleSheet(cb_stylesheet);
    cb_hinttone->setLayoutDirection(Qt::RightToLeft);

    sb_hinttone = new QSpinBox;
    sb_hinttone->setStyleSheet(sb_stylesheet);
    sb_hinttone->setRange(1,25);
    sb_hinttone->setPrefix(tr("提示音"));

    QHBoxLayout *hl_2 = new QHBoxLayout;
    hl_2->addWidget(cb_hinttone);
    hl_2->addWidget(sb_hinttone);
    hl_2->addStretch(0);

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



    QVBoxLayout *vl_1 = new QVBoxLayout;
    vl_1->addLayout(hl_1);
    vl_1->addLayout(hl_2);
    vl_1->addLayout(hl_3);

    btn_toneset = new QPushButton(tr("声音设置"));
    QHBoxLayout *hb_toneset = new QHBoxLayout;
    hb_toneset->addWidget(btn_toneset);
    hb_toneset->addLayout(vl_1);
    hb_toneset->addStretch(0);


    QHBoxLayout *hl_system = new QHBoxLayout;
    QGroupBox *grp_system = new QGroupBox(tr("系统维护"));
    //grp_system->setStyleSheet("{border:3px solid}");
    btn_db_backup = new QPushButton(tr("数据库备份"));
    btn_db_export = new QPushButton(tr("数据库导出"));
    hl_system->addWidget(btn_db_backup);
    hl_system->addWidget(btn_db_export);
    grp_system->setLayout(hl_system);


    QVBoxLayout *vbox_left = new QVBoxLayout;
    vbox_left->addLayout(hb_timeset);
    vbox_left->addLayout(hb_toneset);
    vbox_left->addWidget(grp_system);
    //vbox_left->addStretch(0);

    btn_ret = new QPushButton(tr("返回"));
    QObject::connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_ret_clicked()));
    btn_default = new QPushButton(tr("默认参数"));
    QObject::connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_default_clicked()));

    QVBoxLayout *vbox_right = new QVBoxLayout;
    vbox_right->addWidget(btn_ret);
    vbox_right->addStretch(1);
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


void panel_setup::on_btn_ret_clicked()
{
    MainWin::instance()->setStackIndex(0);
}


void panel_setup::on_btn_default_clicked()
{
    MainWin::instance()->setStackIndex(0);
}
