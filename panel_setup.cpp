#include "panel_setup.h"
#include "ui_panel_setup.h"

panel_setup::panel_setup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_setup)
{
    ui->setupUi(this);
}

panel_setup::~panel_setup()
{
    delete ui;
}
