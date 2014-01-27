#include "panel_serial.h"
#include "ui_panel_serial.h"

#include "myserialport.h"
#include <QDebug>

panel_serial::panel_serial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_serial)
{
    ui->setupUi(this);
    serialport = new MySerialPort;
    if(serialport->open("COM3",BAUD115200,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,1,0)==false)
    {
        qDebug("´®¿Ú´ò¿ªÊ§°Ü");
    }

}

panel_serial::~panel_serial()
{
    if(serialport->isOpen())
    {
        serialport->close();
    }
    delete ui;
}

void panel_serial::on_btn_serialport_send_clicked()
{
 //   QByteArray buf[];
 //   char show1[100] = { 0 };
  //  strcpy(lineEdit->text().toUtf8().data(),show1)

}
