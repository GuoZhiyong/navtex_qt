#include "panel_item.h"
#include "mainwin.h"

panel_item::panel_item(int i,NAVTEXITEM *item, QWidget *parent) : QWidget(parent)
{
    itemvalue=item;
    index=i;

    lbl_time_broadcast = new QLabel(item->Broadcast);
    lbl_time_broadcast->setFont(QFont("Kaiti",12));

    lbl_time_receive = new QLabel(item->Receive);
    lbl_time_receive->setFont(QFont("Kaiti",12));

    vlayout = new QVBoxLayout();
    vlayout->addWidget(lbl_time_broadcast);
    vlayout->addWidget(lbl_time_receive);
    vlayout->setContentsMargins(0,0,0,0);


    lbl_code = new QLabel(item->code);
    lbl_code->setFont(QFont("Kaiti",22,QFont::Bold));

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



    hlayout = new QHBoxLayout;
    hlayout->addWidget(btn_view);
    hlayout->addWidget(lbl_code);
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


//处理btn_view的clicked事件，更新显示，发出
void panel_item::myviewClick()
{
    repaint();
    navtexitemlist_pos=index;
    repaint();
    MainWin::instance()->btnViewClick(itemvalue);
}

void panel_item::myttsClick()
{
    repaint();
    navtexitemlist_pos=index;
    repaint();
    MainWin::instance()->btnTTSClick(itemvalue);
}


panel_item::~panel_item()
{

}
