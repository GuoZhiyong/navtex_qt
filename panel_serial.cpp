#include "panel_serial.h"
#include "ui_panel_serial.h"

panel_serial::panel_serial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_serial)
{
    ui->setupUi(this);
}

panel_serial::~panel_serial()
{
    delete ui;
}
