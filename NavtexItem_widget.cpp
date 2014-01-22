#include "NavtexItem_widget.hpp"
#include <QtGui>


NavtexItem_Widget::NavtexItem_Widget(QWidget *parent) :
    QWidget(parent)
{



    //font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
    btn_status = new QPushButton();
    lbl_freq = new QLabel(tr("4209"));
    lbl_freq->setFont(QFont(("Arial"), 12, QFont::Bold));
    lbl_rx = new QLabel(tr("接收时间"));
    lbl_rx->setFont(QFont(("Arial"), 11, QFont::Bold));
    lbl_rx_time = new QLabel(tr("2014-05-31 12:34:56"));
    lbl_rx_time->setFont(QFont(("Arial"), 11, QFont::Bold));

    lbl_tx = new QLabel(tr("发送时间"));
    lbl_tx->setFont(QFont(("Arial"), 11, QFont::Bold));
    lbl_tx_time = new QLabel(tr("2014-05-31 12:34:56"));
    lbl_tx_time->setFont(QFont(("Arial"), 11, QFont::Bold));


    lbl_id = new QLabel(tr("TA87"));
    lbl_id->setFont(QFont(("Arial"), 12, QFont::Bold));

    btn_view=new QPushButton(tr("查看"));
    btn_view->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    btn_view->setFont(QFont(("Arial"), 12, QFont::Bold));

    btn_tts=new QPushButton(tr("播报"));
    btn_tts->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    btn_tts->setFont(QFont(("Arial"), 12, QFont::Bold));

    //txt_info =  new QTextEdit(tr("请问"));
    //txt_info->setFrameShape(QFrame::Box);

    layout= new QGridLayout;
    layout->setVerticalSpacing(0);

    layout->addWidget(btn_status,0,0,1,2,0);
    layout->addWidget(lbl_freq,0,2,1,2,0);
    layout->addWidget(lbl_id,0,4,1,2,0);

    layout->addWidget(lbl_tx,1,0,1,2,0);
    layout->addWidget(lbl_tx_time,1,2,1,4,0);

    layout->addWidget(lbl_rx,2,0,1,2,0);
    layout->addWidget(lbl_rx_time,2,2,1,4,0);

    layout->addWidget(btn_view,3,0,1,3,0);
    layout->addWidget(btn_tts,3,3,1,3,0);

    //layout->addWidget(txt_info,2,1,2,4,0);
    layout->setContentsMargins(4,4,4,4);

//    layout->addWidget(label_freq,0,0,1,1,0);
//    layout->addWidget(label_id,0,1,1,1,0);
//    layout->addWidget(label_1,1,0,1,3,0);
//    layout->addWidget(label_2,2,0,1,3,0);
//    layout->addWidget(btn_view,3,0,1,1,0);
//    layout->addWidget(btn_tts,4,0,1,1,0);
//    layout->addWidget(txt_info,3,1,2,1,0);


    this->setAutoFillBackground(true);//这个语句很重要，没有的话，子widget背景色修改不成功
    QPalette pal;
    pal.setBrush(backgroundRole(),QColor(54,54,54));
    //pal.setBrush(backgroundRole(),QColor(79,79,79));
    //pal.setBrush(backgroundRole(),QColor(105,105,105));
    //QPixmap pm(":/res/bg1.png");
    //pal.setBrush(QPalette::Background, QBrush(pm));
    this->setPalette(pal);

    this->setStyleSheet("color:black");
    this->setLayout(layout);
    this->setFixedSize(210,100);

}
