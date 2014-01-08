#include "NavtexItem_widget.hpp"
#include <QtGui>


NavtexItem_Widget::NavtexItem_Widget(QWidget *parent) :
    QWidget(parent)
{

    //font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
    lcdnumber_freq=new QLCDNumber;
    //lcdnumber_freq->value(1);

    label_1 = new QLabel(tr("接收时间"));
    label_1->setFont(QFont(("Arial"), 12, QFont::Bold));
    //label_2 = new QLabel(tr("信息时间"));
    label_id = new QLabel(tr("ID"));
    label_id->setFont(QFont(("Arial"), 16, QFont::Bold));
    //label_type = new QLabel(tr("类型"));
    //label_type->setFont(QFont(("Arial"), 16, QFont::Bold));
    //label_band = new QLabel(tr("频段"));
    //label_band->setFont(QFont(("Arial"), 16, QFont::Bold));

    layout= new QGridLayout;
    layout->addWidget(label_1);
    //layout->addWidget(label_2);
    layout->addWidget(label_id);
   // layout->addWidget(label_type);
    //layout->addWidget(label_band);

    this->setAutoFillBackground(true);//这个语句很重要，没有的话，子widget背景色修改不成功
    QPalette pal;
    pal.setBrush(backgroundRole(),QColor(10,25,69));
    this->setPalette(pal);

    this->setStyleSheet("color:yellow");
    this->setLayout(layout);
    this->setFixedSize(210,160);

}
