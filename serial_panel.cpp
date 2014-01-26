#include "serial_panel.h"
#include "ui_serial_panel.h"

serial_panel::serial_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serial_panel)
{
    ui->setupUi(this);
}

serial_panel::~serial_panel()
{
    delete ui;
}
