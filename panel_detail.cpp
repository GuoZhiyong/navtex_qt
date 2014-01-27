#include "panel_detail.h"
#include "ui_panel_detail.h"

panel_detail::panel_detail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_detail)
{
    ui->setupUi(this);
}

panel_detail::~panel_detail()
{
    delete ui;
}
