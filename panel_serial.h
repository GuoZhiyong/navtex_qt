#ifndef SERIAL_PANEL_H
#define SERIAL_PANEL_H

#include <QWidget>
#include "myserialport.h"

namespace Ui {
class panel_serial;
}

class panel_serial : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_serial(QWidget *parent = 0);
    ~panel_serial();
    
private slots:
    void on_btn_serialport_send_clicked();

private:
    Ui::panel_serial *ui;
    MySerialPort *serialport;
};

#endif // SERIAL_PANEL_H
