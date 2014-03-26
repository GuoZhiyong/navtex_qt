#include "panel_detail.h"
#include "ui_panel_detail.h"
#include "mainwin.h"
#include "common.h"

panel_detail::panel_detail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_detail)
{
    ui->setupUi(this);
}

void panel_detail::setcontent(ITEM_DATA *i)
{
    item=i;
    QString str=item->code;
    ui->lbl_code->setText(str);
    ui->lbl_site->setText(qmap_site[str.mid(0,1)]);
    ui->lbl_infotype->setText(qmap_infotype[str.mid(1,1)]);
    ui->lbl_broadcast->setText(item->Broadcast);
    ui->txt_info->setText(item->Content);
}

//按下返回键，显示panel_info
void panel_detail::on_btn_ret_clicked()
{
    MainWin::instance()->setStackIndex(0);
}

void panel_detail::on_btn_tts_clicked()
{
    MainWin::instance()->btnTTSClick(item);
}



panel_detail::~panel_detail()
{
    delete ui;
}

