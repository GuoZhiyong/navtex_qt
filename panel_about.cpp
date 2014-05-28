#include "panel_about.h"

#include "mainwin.h"

#include <QtGui>

panel_about::panel_about(QWidget *parent) : QWidget(parent)
{
    setFont(QFont("KaiTi",20));

    btn_ret = new QPushButton(tr("返回"));
    QObject::connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_ret_clicked()));

    QLabel *lbl_1= new QLabel(tr("奈伏泰斯(Navtex)接收机"));
    lbl_1->setAlignment(Qt::AlignHCenter);
    QLabel *lbl_2= new QLabel(tr("天津七一二通信广播有限公司"));
    lbl_2->setAlignment(Qt::AlignHCenter);

    QVBoxLayout * lay_left=new QVBoxLayout();
    lay_left->addWidget(lbl_1);
    lay_left->addWidget(lbl_2);

    QVBoxLayout * lay_right=new QVBoxLayout();
    lay_right->addWidget(btn_ret);
    lay_right->addStretch(0);


    mainlayout = new QHBoxLayout;
    mainlayout->addLayout(lay_left,7);
    mainlayout->addLayout(lay_right,1);
    setLayout(mainlayout);
}

panel_about::~panel_about()
{

}


void panel_about::on_btn_ret_clicked()
{
    MainWin::instance()->setStackIndex(0);
}
