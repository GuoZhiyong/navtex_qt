#include "NavtexItem_widget.hpp"
#include <QtGui>


NavtexItem_Widget::NavtexItem_Widget(QWidget *parent) :
    QWidget(parent)
{

    //font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
    lcdnumber_freq=new QLCDNumber;
    lcdnumber_freq->display(485);

    label_1 = new QLabel(tr("接收时间"));
    label_1->setFont(QFont(("Arial"), 12, QFont::Bold));
    label_2 = new QLabel(tr("信息时间"));
    label_2->setFont(QFont(("Arial"), 12, QFont::Bold));
    label_id = new QLabel(tr("TA87"));
    label_id->setFont(QFont(("Arial"), 12, QFont::Bold));

    btn_view=new QPushButton("View");
    btn_view->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    btn_tts=new QPushButton("TTS");
    btn_tts->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);

    txt_info =  new QTextEdit("请问");
    txt_info->setFrameShape(QFrame::Box);

    layout= new QGridLayout;
    layout->setVerticalSpacing(0);
    layout->addWidget(lcdnumber_freq,0,0,1,1,0);
    layout->addWidget(label_1,0,1,1,1,0);

    layout->addWidget(label_id,1,0,1,1,0);
    layout->addWidget(label_2,1,1,1,1,0);

    layout->addWidget(btn_view,2,0,1,1,0);
    layout->addWidget(btn_tts,3,0,1,1,0);

    layout->addWidget(txt_info,2,1,2,1,0);

    this->setAutoFillBackground(true);//这个语句很重要，没有的话，子widget背景色修改不成功
    QPalette pal;
    pal.setBrush(backgroundRole(),QColor(10,25,69));
    this->setPalette(pal);

    this->setStyleSheet("color:yellow");
    this->setLayout(layout);
    this->setFixedSize(210,160);

}
