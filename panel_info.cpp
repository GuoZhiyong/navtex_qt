#include "panel_info.h"
#include "ui_panel_info.h"
#include "FlowLayout.hpp"

panel_info::panel_info(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::panel_info)
{
    ui->setupUi(this);
    FlowLayout *layout=new FlowLayout;
    setLayout(layout);
    for(int i=0;i<20;i++)
    {
        QLabel *lbl=new QLabel;
        lbl->setText("Label              ");
        layout->addWidget(lbl);
    }

}

panel_info::~panel_info()
{
    delete ui;
}
