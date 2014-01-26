#ifndef SERIAL_PANEL_H
#define SERIAL_PANEL_H

#include <QWidget>

namespace Ui {
class panel_serial;
}

class panel_serial : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_serial(QWidget *parent = 0);
    ~panel_serial();
    
private:
    Ui::panel_serial *ui;
};

#endif // SERIAL_PANEL_H
