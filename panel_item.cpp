#include "panel_item.h"
#include "mainwin.h"

//静态成员函数
QPixmap panel_item::pix_lock=0;
QPixmap panel_item::pix_unlock=0;



panel_item::panel_item(int i,ITEM_DATA *item_data, QWidget *parent) : QWidget(parent)
{
    itemvalue=item_data;
    index=i;

    lbl_time_broadcast = new QLabel(itemvalue->Broadcast);
    lbl_time_broadcast->setFont(QFont("Kaiti",12));

    lbl_time_receive = new QLabel(itemvalue->Receive);
    lbl_time_receive->setFont(QFont("Kaiti",12));

    vlayout = new QVBoxLayout();
    vlayout->addWidget(lbl_time_broadcast);
    vlayout->addWidget(lbl_time_receive);
    vlayout->setContentsMargins(0,0,0,0);


    lbl_code = new QLabel(itemvalue->code);
    lbl_code->setFont(QFont("Kaiti",22,QFont::Bold));

    pix_lock.load(":/res/lock_16.png");
    pix_unlock.load(":/res/unlock_16.png");

    lbl_lock = new QLabel;
    lbl_lock->setPixmap(pix_lock);

    lbl_chn = new QLabel(QString::number(itemvalue->chn,10));
    lbl_chn->setFont(QFont("kaiti",10,QFont::Bold));

    QHBoxLayout *hb1=new QHBoxLayout;
    hb1->addWidget(lbl_lock);
    hb1->addWidget(lbl_chn);
    hb1->setContentsMargins(0,0,0,0);

    QVBoxLayout *vb1=new QVBoxLayout;
    vb1->addLayout(hb1);
    vb1->addWidget(lbl_code);
    vb1->setContentsMargins(0,0,0,0);

    btn_view = new QPushButton();
    if(itemvalue->fRead)
    {
        btn_view->setIcon(QIcon(":/res/mail_1_open.png"));
    }
    else
    {
        btn_view->setIcon(QIcon(":/res/mail_1_close.png"));
    }
    btn_view->setIconSize(QSize(32,32));
    btn_tts = new QPushButton();
    btn_tts->setIcon(QIcon(":/res/spk_blue_on.png"));
    btn_tts->setIconSize(QSize(32,32));
    btn_tts->setStyleSheet(tr("QPushButton:hover{background-color:green;}QPushButton:pressed{background-color:red;}"));



    hlayout = new QHBoxLayout;
    hlayout->addWidget(btn_view);
    hlayout->addLayout(vb1);
    hlayout->addLayout(vlayout);
    hlayout->addWidget(btn_tts);
    hlayout->setContentsMargins(0,0,0,0);
    hlayout->setSpacing(4);

    layout = new QVBoxLayout;
    line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addLayout(hlayout);
    layout->addWidget(line);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);

    setLayout(layout);
    adjustSize();

    connect(btn_view,SIGNAL(clicked()),this,SLOT(myviewClick()));
    connect(btn_tts,SIGNAL(clicked()),this,SLOT(myttsClick()));

}



void panel_item::focusInEvent(QFocusEvent *evt)
{
    qDebug()<<itemvalue->code<<"focus in";
    navtexitemlist_pos=index;
    QPalette pal;//=palette();
    setAutoFillBackground(true);
    pal.setColor(QPalette::Window, Qt::darkGray);
    setPalette(pal);
}

void panel_item::focusOutEvent(QFocusEvent *evt)
{
    qDebug()<<itemvalue->code<<"focus out reason"<<evt->reason();
    QPalette pal;//=palette();
    setAutoFillBackground(true);
    pal.setColor(QPalette::Window,pal.color(QPalette::Window));  /*默认的颜色*/
    setPalette(pal);
}


//处理btn_view的clicked事件，更新显示，发出
void panel_item::myviewClick()
{
    setFocus(Qt::OtherFocusReason);
    MainWin::instance()->btnViewClick(itemvalue);
}

void panel_item::myttsClick()
{
    setFocus(Qt::OtherFocusReason);
    MainWin::instance()->btnTTSClick(itemvalue);
}


panel_item::~panel_item()
{

}
