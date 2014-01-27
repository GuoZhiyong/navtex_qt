#include "control_panel.h"
#include "ui_control_panel.h"

control_panel::control_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::control_panel)
{
    ui->setupUi(this);
}

control_panel::~control_panel()
{
    delete ui;
}

//�������ҳ���˳�����

void control_panel::on_btn_pnl_info_clicked()
{
    emit mysignal(0);
}

void control_panel::on_btn_pnl_detail_clicked()
{
    emit mysignal(1);
}

void control_panel::on_btn_pnl_setup_clicked()
{
    emit mysignal(2);
}

void control_panel::on_btn_pnl_serialport_clicked()
{
    emit mysignal(3);
}

void control_panel::on_btn_pnl_about_clicked()
{
    emit mysignal(4);
}
