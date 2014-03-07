
#include <QtGui>
#include <QSplashScreen>
#include <QTest>

#include "main.h"
#include "FlowLayout.hpp"

QStackedWidget *stack;
control_panel *cp;
panel_info *pnl_info;
panel_setup *pnl_setup;
panel_serial *pnl_serial;
panel_detail *pnl_detail;
panel_about *pnl_about;




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/res/navtex.png"));
    splash->show();
    splash->setFont(QFont("ubuntu",16));
    splash->showMessage("加载窗体        ",Qt::AlignVCenter|Qt::AlignHCenter,Qt::yellow);
    QWidget *win =new QWidget;

    cp = new control_panel;
    pnl_info=new panel_info;
    pnl_setup =new panel_setup;
    pnl_serial =new panel_serial;
    pnl_detail = new panel_detail;
    pnl_about = new panel_about;

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


    stack=new QStackedWidget();
    stack->addWidget(pnl_info);
    stack->addWidget(pnl_detail);
    stack->addWidget(pnl_setup);
    stack->addWidget(pnl_serial);
    stack->addWidget(pnl_about);

    QObject::connect(cp,SIGNAL(mysignal(int)),stack,SLOT(setCurrentIndex(int))); //关联显示内容的改变

    QObject::connect(pnl_serial,SIGNAL(signal_serialport_rx(QByteArray)),pnl_info,SLOT(serialport_rx(QByteArray)));

    //QTest::qSleep(3000);
    splash->showMessage("显示窗体",Qt::AlignBottom|Qt::AlignVCenter,Qt::red);

    QHBoxLayout *layout = new QHBoxLayout;
    win->setLayout(layout);
    layout->addWidget(stack,15,0);
    layout->addWidget(cp,1,0);
    layout->setContentsMargins(0,0,0,0);
    win->setWindowFlags(Qt::FramelessWindowHint);
    win->resize(800,600);
    win->show();
    splash->finish(win);
    delete splash;

    return a.exec();
}
