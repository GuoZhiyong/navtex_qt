#include "qextserialport.h"
#include "panel_serial.h"
#include "ui_panel_serial.h"
#include "panel_info.h"
#include <QDebug>



panel_serial::panel_serial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel_serial)
{
    ui->setupUi(this);
    PortSettings settings = {BAUD115200, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    serialport = new QextSerialPort("ttyS0",settings,QextSerialPort::EventDriven);
    serialport->open(QIODevice::ReadWrite);
    if(serialport->isOpen())
    {
        connect(serialport,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    }
    else
    {
        qDebug()<<"串口打开失败"<<endl;
    }

}

panel_serial::~panel_serial()
{
    if(serialport->isOpen())
    {
        serialport->close();
    }
    delete ui;
    delete serialport;
}
/*
 *serial has received bytes,then emit to
 *sqlite=>save
 *panel_info=>display
 */
void panel_serial::onReadyRead()
{
    QByteArray bytes;

    //qDebug() << "bytes read:" << bytes.size();
    //qDebug() << "bytes:" << bytes;
    //if (serialport->bytesAvailable()) {
    //    ui->recvEdit->moveCursor(QTextCursor::End);
    //    ui->recvEdit->insertPlainText(QString::fromLatin1(serialport->readAll()));
    //}
    int a = serialport->bytesAvailable();
    bytes.resize(a);
    serialport->read(bytes.data(), bytes.size());
    emit signal_serialport_rx(bytes);




}

void panel_serial::on_btn_serialport_send_clicked()
{
 //   QByteArray buf[];
 //   char show1[100] = { 0 };
  //  strcpy(lineEdit->text().toUtf8().data(),show1)

}
