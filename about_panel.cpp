#include "about_panel.h"
#include "ui_about_panel.h"

about_panel::about_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about_panel)
{
    ui->setupUi(this);
}

about_panel::~about_panel()
{
    delete ui;
}
