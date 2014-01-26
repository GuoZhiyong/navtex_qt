#include "info_panel.h"
#include "ui_info_panel.h"

#include "FlowLayout.hpp"

info_panel::info_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info_panel)
{
    ui->setupUi(this);
    layout=new FlowLayout;
    setLayout(layout);
}

info_panel::~info_panel()
{
    delete ui;
}
