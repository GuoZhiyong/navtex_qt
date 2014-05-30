#include "panel_about.h"

#include "mainwin.h"

#include <QtGui>

panel_about::panel_about(QWidget *parent) : QWidget(parent)
{
    setFont(QFont("KaiTi",20));

    btn_ret = new QPushButton(tr("Return"));
    QObject::connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_ret_clicked()));

    lbl_title= new QLabel(tr("Navtex Receiver"));
    lbl_title->setAlignment(Qt::AlignHCenter);
    lbl_company= new QLabel(tr("TianJin 712 Communication & Broadcast Co,Ltd"));
    lbl_company->setAlignment(Qt::AlignHCenter);

    QVBoxLayout * lay_left=new QVBoxLayout();
    lay_left->addWidget(lbl_title);
    lay_left->addWidget(lbl_company);

    QVBoxLayout * lay_right=new QVBoxLayout();
    lay_right->addWidget(btn_ret);
    lay_right->addStretch(0);


    mainlayout = new QHBoxLayout;
    mainlayout->addLayout(lay_left,7);
    mainlayout->addLayout(lay_right,1);
    setLayout(mainlayout);
}



void panel_about::retranslate(QWidget *parent)
{
    btn_ret->setText(tr("Return"));
    lbl_title->setText(tr("Navtex Receiver"));
    lbl_company->setText(tr("TianJin 712 Communication & Broadcast Co,Ltd"));
}



void panel_about::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch(e->type())
    {
    case QEvent::LanguageChange:
        retranslate(this);
        break;
    default:
        break;
    }
}




panel_about::~panel_about()
{

}


void panel_about::on_btn_ret_clicked()
{
    MainWin::instance()->setStackIndex(0);
}
