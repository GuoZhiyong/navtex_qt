#include "mainwindow.h"

#include "FlowLayout.hpp"

#include "NavtexItem_widget.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    QFont font;
    font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
    font.setPointSize(24);
    setFont(font);

    btn_detail = new QPushButton(tr("详情"));
    btn_486KHz = new QPushButton("486KHz");
    btn_518KHz = new QPushButton("518KHz");
    btn_4209KHz = new QPushButton("4209KHz");
    btn_tts = new QPushButton(tr("播报"));
    btn_config = new QPushButton(tr("设置"));
    btn_about = new QPushButton(tr("关于"));
    spacer = new QSpacerItem(20,0,QSizePolicy::Minimum,QSizePolicy::Expanding);

    layout_right = new QVBoxLayout;
    layout_right->addWidget(btn_detail);
    layout_right->addWidget(btn_486KHz);
    layout_right->addWidget(btn_518KHz);
    layout_right->addWidget(btn_4209KHz);
    layout_right->addWidget(btn_tts);
    layout_right->addSpacerItem(spacer);
    layout_right->addWidget(btn_config);
    layout_right->addWidget(btn_about);

    //layout_left = new QVBoxLayout;
    QLabel* title = new QLabel(tr("Custom widgets on a QListWidget"));

    layout_left_top = new QHBoxLayout;
    layout_left_top->addWidget(title);

//    QListWidget* list = new QListWidget;
//    list->addItem("foo");

//    QListWidgetItem* item;
//    item = new QListWidgetItem(list);
//    list->addItem(item);
//    QPushButton* button = new QPushButton("hey");
//    item->setSizeHint(button->minimumSizeHint());
//    list->setItemWidget(item, button);
//    list->addItem("bar");
font.setPointSize(24);
setFont(font);
    NavtexItem_Widget *item1=new NavtexItem_Widget;
NavtexItem_Widget *item2=new NavtexItem_Widget;
NavtexItem_Widget *item3=new NavtexItem_Widget;
NavtexItem_Widget *item4=new NavtexItem_Widget;
NavtexItem_Widget *item5=new NavtexItem_Widget;

//    layout_left_bottom = new QVBoxLayout;
//    layout_left_bottom->addWidget(list);
    layout_left_bottom = new FlowLayout;
    layout_left_bottom->addWidget(item1);
    layout_left_bottom->addWidget(item2);
    layout_left_bottom->addWidget(item3);
    layout_left_bottom->addWidget(item4);
    layout_left_bottom->addWidget(item5);

    layout_main =new QGridLayout;

    layout_main->addLayout(layout_left_top,0,0,1,9,0);
    layout_main->addLayout(layout_left_bottom,1,0,9,9,0);
    layout_main->addLayout(layout_right,0,9,10,1,0);

    setLayout(layout_main);
   // this->setWindowFlags(Qt::FramelessWindowHint); //
    setWindowTitle(tr("Navtex测试"));
    qDebug()<<"this is a test";

}
