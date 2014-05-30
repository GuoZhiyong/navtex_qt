#include "panel_detail.h"
#include "mainwin.h"
#include "common.h"

panel_detail::panel_detail(QWidget *parent) : QWidget(parent)
{
    setFont(QFont("KaiTi",20));

    lbl_code = new QLabel();
    lbl_code->setFont((QFont("KaiTi",40)));
    lbl_site = new QLabel();
    lbl_infotype= new QLabel();
    lbl_infotype->setWordWrap(true);
    lbl_infotype->setAlignment(Qt::AlignLeft|Qt::AlignTop);


    lbl_chn_title = new QLabel(tr("CHAN"));
    lbl_chn = new QLabel();
    lbl_ber_title = new QLabel(tr(" BER "));
    lbl_ber = new QLabel();
    lbl_broadcast_title= new QLabel(tr("Broadcast"));
    lbl_broadcast = new QLabel();
    lbl_receive_title= new QLabel(tr("Receive"));
    lbl_receive = new QLabel();
    btn_ret = new QPushButton(tr("Return"));
    btn_tts = new QPushButton(tr("  TTS  "));

    layout = new QGridLayout;
    layout->addWidget(lbl_code,0,0,2,1,Qt::AlignHCenter);

    layout->addWidget(lbl_site,0,3,1,1);
    layout->addWidget(lbl_infotype,1,3,1,1);

    layout->addWidget(lbl_chn_title,0,1,1,1);
    layout->addWidget(lbl_chn,0,2,1,1);

    layout->addWidget(btn_ret,0,4,2,1);
    btn_ret->setMinimumHeight(48);

    layout->addWidget(lbl_ber_title,1,1,1,1);
    layout->addWidget(lbl_ber,1,2,1,1);

    layout->addWidget(btn_tts,2,4,2,1);
    btn_tts->setMinimumHeight(48);

    layout->addWidget(lbl_broadcast_title,2,0,1,1);
    layout->addWidget(lbl_broadcast,2,1,1,-1);

    layout->addWidget(lbl_receive_title,3,0,1,1);
    layout->addWidget(lbl_receive,3,1,1,-1);

    lbl_info = new QLabel();
    lbl_info->setWordWrap(true);
    lbl_info->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    lbl_info->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    lbl_info->setStyleSheet("font-size:20px;border-width: 1px; border-style: solid;border-color: rgb(255, 170, 0);");
    layout->addWidget(lbl_info,4,0,1,-1);


    connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_ret_clicked()));
    connect(btn_tts,SIGNAL(clicked()),this,SLOT(on_btn_tts_clicked()));

    setLayout(layout);
}

void panel_detail::setcontent(ITEM_DATA *i)
{
    item=i;
    QString str=item->code;

    lbl_code->setText(str);
    lbl_site->setText(qmap_site[str.mid(0,1)]);
    //lbl_infotype->setText(qmap_infotype[str.mid(1,1)]);
    lbl_infotype->setText(sl_info[str.at(1).toAscii()-'A']);
    lbl_broadcast->setText(item->Broadcast);
    lbl_info->setText(item->Content);
}

//按下返回键，显示panel_info
void panel_detail::on_btn_ret_clicked()
{
    MainWin::instance()->setStackIndex(0);
}

void panel_detail::on_btn_tts_clicked()
{
    MainWin::instance()->btnTTSClick(item);
}

void panel_detail::retranslate(QWidget *parent)
{
    lbl_chn_title->setText(tr("Channel"));
    lbl_ber_title->setText(tr(" BER "));
    lbl_broadcast_title->setText(tr("Broadcast"));
    lbl_receive_title->setText(tr("Receive"));
    btn_ret->setText(tr("Return"));
    btn_tts->setText(tr("  TTS  "));
}



void panel_detail::changeEvent(QEvent *e)
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


panel_detail::~panel_detail()
{

}

