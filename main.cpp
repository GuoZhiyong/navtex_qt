
#include <QtGui>

#include "mainwindow.h"
#include "control_panel.h"
#include "info_panel.h"
#include "FlowLayout.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QWidget *win =new QWidget;
    control_panel *cp = new control_panel;
    info_panel *info = new info_panel;

//    QWidget *scrollarea_widget=new QWidget;
//    FlowLayout *scrollarea_layout = new FlowLayout;
////    for(int i=0;i<24;i++)
////    {
////         NavtexItem_Widget *item=new NavtexItem_Widget;
////         layout_left_bottom->addWidget(item);
////    }
//    scrollarea_widget->setLayout(scrollarea_layout);

//    QScrollArea *scrollarea=new QScrollArea();
//    scrollarea->setWidgetResizable(true);
//    scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    scrollarea->setWidget(scrollarea_widget);

    QHBoxLayout *layout = new QHBoxLayout;

    win->setLayout(layout);
    layout->addWidget(info,10,0);
    layout->addWidget(cp,1,0);
    win->resize(800,600);


    win->show();

    return a.exec();
}
