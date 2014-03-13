#include "panel_about.h"

#include "mainwin.h"

#include <QtGui>

panel_about::panel_about(QWidget *parent) : QWidget(parent)
{
    setFont(QFont("wenquanyi micro hei mono",20));

    btn_ret = new QPushButton("返回");
    QObject::connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_ret_clicked()));
    mainlayout = new QVBoxLayout;
    mainlayout->addWidget(btn_ret);
    setLayout(mainlayout);


    show();
}

panel_about::~panel_about()
{

}


void panel_about::on_btn_ret_clicked()
{
    MainWin::instance()->setStackIndex(0);
}
