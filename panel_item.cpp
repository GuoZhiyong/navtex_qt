#include "panel_item.h"
#include "ui_panel_item.h"

panel_item::panel_item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_item)
{
    ui->setupUi(this);
}

panel_item::~panel_item()
{
    delete ui;
}
