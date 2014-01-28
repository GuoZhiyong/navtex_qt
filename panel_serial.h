#ifndef SERIAL_PANEL_H
#define SERIAL_PANEL_H

#include <QWidget>
//#include "myserialport.h"

#include "qextserialport.h"

namespace Ui {
class panel_serial;
}

class panel_serial : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_serial(QWidget *parent = 0);
    ~panel_serial();
signals:
    void signal_serialport_rx(QByteArray bytes); /*define a signal to send message*/
private slots:
    void on_btn_serialport_send_clicked();
    void onReadyRead();

private:
    Ui::panel_serial *ui;
    QextSerialPort *serialport;

};

#endif // SERIAL_PANEL_H
