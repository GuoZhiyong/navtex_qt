#include "NavtexItem_widget.hpp"
#include <QtGui>

NavtexItem_Widget::NavtexItem_Widget(QWidget *parent) :
    QWidget(parent)
{
    QFont font;
    font.setFamily(tr("宋体"));
    //font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));

    font.setPointSize(24);
    setFont(font);
    label_1 = new QLabel(tr("接收时间"));
    //label_2 = new QLabel(tr("信息时间"));
    label_id = new QLabel(tr("ID"));
    label_type = new QLabel(tr("类型"));
    label_band = new QLabel(tr("频段"));

    layout= new QVBoxLayout;
    layout->addWidget(label_1);
    //layout->addWidget(label_2);
    layout->addWidget(label_id);
    //layout->addWidget(label_type);
    //layout->addWidget(label_band);

    this->setAutoFillBackground(true);//这个语句很重要，没有的话，子widget背景色修改不成功
    QPalette myPalette;
    myPalette.setBrush(backgroundRole(),QColor(10,25,69));
    this->setPalette(myPalette);

    this->setStyleSheet("color:yellow");
    this->setLayout(layout);
    this->setFixedSize(210,120);

}
