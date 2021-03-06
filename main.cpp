
#include <QtGui>

#include "control_panel.h"

#include "FlowLayout.hpp"
#include "panel_info.h"
#include "panel_serial.h"
#include "panel_setup.h"
#include "panel_about.h"
#include "panel_detail.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));

    QWidget *win =new QWidget;
    control_panel *cp = new control_panel;
    panel_info *pnl_info=new panel_info;
    panel_setup *pnl_setup =new panel_setup;
    panel_serial *pnl_serial =new panel_serial;
    panel_detail *pnl_detail = new panel_detail;
    panel_about *pnl_about = new panel_about;

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


    QStackedWidget *stack=new QStackedWidget();
    stack->addWidget(pnl_info);
    stack->addWidget(pnl_detail);
    stack->addWidget(pnl_setup);
    stack->addWidget(pnl_serial);
    stack->addWidget(pnl_about);
    QObject::connect(cp,SIGNAL(mysignal(int)),stack,SLOT(setCurrentIndex(int)));
    QObject::connect(pnl_serial,SIGNAL(signal_serialport_rx(QByteArray)),pnl_info,SLOT(serialport_rx(QByteArray)));


    QHBoxLayout *layout = new QHBoxLayout;
    win->setLayout(layout);
    layout->addWidget(stack,15,0);
    layout->addWidget(cp,1,0);
    win->resize(800,600);
    win->show();

    return a.exec();
}
