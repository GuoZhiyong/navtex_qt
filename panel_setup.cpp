#include "panel_setup.h"

#include "mainwin.h"

panel_setup::panel_setup(QWidget *parent) : QWidget(parent)
{
    setFont(QFont("wenquanyi micro hei mono",20));
    btn_ret = new QPushButton("返回");
    QObject::connect(btn_ret,SIGNAL(clicked()),this,SLOT(on_btn_ret_clicked()));
    mainlayout = new QVBoxLayout;
    mainlayout->addWidget(btn_ret);
    setLayout(mainlayout);


    show();
}

panel_setup::~panel_setup()
{

}


void panel_setup::on_btn_ret_clicked()
{
    MainWin::instance()->setStackIndex(0);
}
