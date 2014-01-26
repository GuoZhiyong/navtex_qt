#include "panel_about.h"
#include "ui_panel_about.h"

panel_about::panel_about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_about)
{
    ui->setupUi(this);
}

panel_about::~panel_about()
{
    delete ui;
}
