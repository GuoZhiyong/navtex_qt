#include "setup_panel.h"
#include "ui_setup_panel.h"

setup_panel::setup_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setup_panel)
{
    ui->setupUi(this);
}

setup_panel::~setup_panel()
{
    delete ui;
}
