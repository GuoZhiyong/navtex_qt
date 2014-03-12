#include "panel_item.h"
//#include "ui_panel_item.h"

panel_item::panel_item(int i,NAVTEXITEM *item, QWidget *parent) :
    QWidget(parent)
{
    itemvalue=item;
    index=i;

    lbl_time_broadcast = new QLabel(item->Broadcast);
    lbl_time_broadcast->setFont(QFont("wenquanyi micro hei mono",12));

    lbl_time_receive = new QLabel(item->Receive);
    lbl_time_receive->setFont(QFont("wenquanyi micro hei mono",12));

    lbl_code = new QLabel(item->code);
    lbl_code->setFont(QFont("wenquanyi micro hei mono",22,QFont::Bold));

    vlayout = new QVBoxLayout();
    hlayout = new QHBoxLayout;
    layout = new QVBoxLayout;
    line = new QFrame();
    btn_view = new QPushButton();
    if(item->fRead)
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

    vlayout->addWidget(lbl_time_broadcast);
    vlayout->addWidget(lbl_time_receive);
    vlayout->setContentsMargins(0,0,0,0);


    hlayout->addWidget(btn_view);
    hlayout->addWidget(lbl_code);
    hlayout->addLayout(vlayout);
    hlayout->addWidget(btn_tts);
    hlayout->setContentsMargins(0,0,0,0);
    hlayout->setSpacing(0);
    layout->addLayout(hlayout);

    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);

    setLayout(layout);
    adjustSize();
//设置颜色
//    QPalette pal= this->palette();
//    pal.setColor(QPalette::Active,QPalette::Window,Qt::lightGray);
//    pal.setColor(QPalette::Inactive,QPalette::Window,Qt::darkGray);
//    setPalette(pal);

    connect(btn_view,SIGNAL(clicked()),this,SLOT(myviewClick()));
    connect(btn_tts,SIGNAL(clicked()),this,SLOT(myttsClick()));

}

//重绘事件处理
void panel_item::paintEvent(QPaintEvent *event)
{
    QPalette pal;//=palette();
    setAutoFillBackground(true);
    if(index==navtexitemlist_pos)
    {
        pal.setColor(QPalette::Window, Qt::darkGray);
    }
    else
    {
        pal.setColor(QPalette::Window,pal.color(QPalette::Window));  /*默认的颜色*/
    }
    setPalette(pal);
}


//处理btn_view的clicked事件，发出
void panel_item::myviewClick()
{
    emit viewClick(itemvalue);
}

void panel_item::myttsClick()
{
    emit ttsClick(itemvalue);
}


panel_item::~panel_item()
{

}
