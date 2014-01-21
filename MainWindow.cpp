#include "mainwindow.h"
#include "FlowLayout.hpp"
#include "NavtexItem_widget.hpp"

class QSpacerItem;

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    QFont font;
    font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
    btn_detail = new QPushButton(tr("详情"));
    btn_tts = new QPushButton(tr("播报"));
    btn_config = new QPushButton(tr("设置"));
    btn_about = new QPushButton(tr("关于"));
    spacer = new QSpacerItem(20,0,QSizePolicy::Minimum,QSizePolicy::Expanding);

    layout_right = new QVBoxLayout;
    layout_right->addWidget(btn_detail);
    layout_right->addWidget(btn_tts);
    layout_right->addSpacerItem(spacer);
    layout_right->addWidget(btn_config);
    layout_right->addWidget(btn_about);
//    layout_right->setContentsMargins(0,0,0,0);

    //layout_left = new QVBoxLayout;
//    QLabel* title = new QLabel(tr("Custom widgets on a QListWidget"));

//左上部界面设计
    layout_left_top = new QHBoxLayout;
    btn_486KHz = new QPushButton("486KHz");
    btn_518KHz = new QPushButton("518KHz");
    btn_4209KHz = new QPushButton("4209KHz");
    QSpacerItem* spacer_1=new QSpacerItem(0,1,QSizePolicy::Expanding,QSizePolicy::Minimum);
    layout_left_top->addWidget(btn_486KHz);
    layout_left_top->addWidget(btn_518KHz);
    layout_left_top->addWidget(btn_4209KHz);
    layout_left_top->addSpacerItem(spacer_1);

//    layout_left_top->addWidget(title);

    font.setPointSize(24);
    setFont(font);
    NavtexItem_Widget *item1=new NavtexItem_Widget;
    NavtexItem_Widget *item2=new NavtexItem_Widget;
    NavtexItem_Widget *item3=new NavtexItem_Widget;
    NavtexItem_Widget *item4=new NavtexItem_Widget;
    NavtexItem_Widget *item5=new NavtexItem_Widget;


    layout_left_bottom = new FlowLayout;
    layout_left_bottom->addWidget(item1);
    layout_left_bottom->addWidget(item2);
    layout_left_bottom->addWidget(item3);
    layout_left_bottom->addWidget(item4);
    layout_left_bottom->addWidget(item5);

    layout_main =new QGridLayout;

    layout_main->addLayout(layout_left_top,0,0,1,5,0);
    layout_main->addLayout(layout_left_bottom,1,0,19,5,0);
    layout_main->addLayout(layout_right,0,9,20,1,0);
    //layout_main->setHorizontalSpacing(2);
    //layout_main->setVerticalSpacing(2);
    //layout_main->setContentsMargins(2,2,2,2);
    setLayout(layout_main);
   // this->setWindowFlags(Qt::FramelessWindowHint); //
    setWindowTitle(tr("Navtex测试"));
    qDebug()<<"this is a test";

}
