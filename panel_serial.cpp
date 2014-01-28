#include "panel_serial.h"
#include "ui_panel_serial.h"

#include "myserialport.h"
#include "panel_info.h"

#include <QDebug>



panel_serial::panel_serial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_serial)
{
    ui->setupUi(this);
    serialport = new QextSerialPort("COM4",QextSerialPort::EventDriven);
    serialport->setBaudRate(BAUD115200);
    serialport->setFlowControl(FLOW_OFF);
    serialport->setParity(PAR_NONE);
    serialport->setDataBits(DATA_8);
    serialport->setStopBits(STOP_1);
    if(serialport->open(QIODevice::ReadWrite)==true)
    {
        connect(serialport,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    }
    else
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
/*
 *serial has received bytes,then emit to
 *sqlite=>save
 *panel_info=>display
 */
void panel_serial::onReadyRead()
{
    QByteArray bytes;
    int a = serialport->bytesAvailable();
    bytes.resize(a);
    serialport->read(bytes.data(), bytes.size());
    emit signal_serialport_rx(bytes);
    //qDebug() << "bytes read:" << bytes.size();
    //qDebug() << "bytes:" << bytes;
}

void panel_serial::on_btn_serialport_send_clicked()
{
 //   QByteArray buf[];
 //   char show1[100] = { 0 };
  //  strcpy(lineEdit->text().toUtf8().data(),show1)

}
