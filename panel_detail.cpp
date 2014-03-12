#include "panel_detail.h"
#include "ui_panel_detail.h"
#include "mainwin.h"

panel_detail::panel_detail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_detail)
{
    ui->setupUi(this);
}

void panel_detail::setcontent(NAVTEXITEM *item)
{
    ui->lbl_code->setText(item->code);
    ui->lbl_broadcast->setText(item->Broadcast);
    ui->lbl_content->setText(item->Content);
}


void panel_detail::on_btn_ret_clicked()
{
    MainWin::instance()->setStackIndex(0);
}

panel_detail::~panel_detail()
{
    delete ui;
}

