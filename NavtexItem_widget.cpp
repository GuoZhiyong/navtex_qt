#include "NavtexItem_widget.hpp"
#include <QtGui>

NavtexItem_Widget::NavtexItem_Widget(QWidget *parent) :
    QWidget(parent)
{
    QFont font;
    font.setFamily(tr("宋体"));
    font.setPixelSize(16);
    label_1 = new QLabel(tr("接收时间"));
    label_2 = new QLabel(tr("信息时间"));
    label_id = new QLabel(tr("ID"));
    label_type = new QLabel(tr("类型"));
    label_band = new QLabel(tr("频段"));




}
