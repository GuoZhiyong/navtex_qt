#include "panel_info.h"
#include "ui_panel_info.h"
#include "FlowLayout.hpp"

#include "panel_item.h"

panel_info::panel_info(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::panel_info)
{
    ui->setupUi(this);
    QString style = "QScrollBar:vertical {min-width: 20px;}";
    setStyleSheet(style);
    FlowLayout *layout=new FlowLayout(0,0,0);
    for(int i=0;i<100;i++)
    {
        panel_item *item=new panel_item;
        layout->addWidget(item);
    }
    //ui->scrollAreaWidgetContents->setLayout(layout);
    ui->scroll_widget->setLayout(layout);
    //setWidget(ui->scroll_widget);  //不需要，加上后反而不显示
}

panel_info::~panel_info()
{
    delete ui;
}
