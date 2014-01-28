#ifndef PANEL_INFO_H
#define PANEL_INFO_H

#include <QScrollArea>

namespace Ui {
class panel_info;
}

class panel_info : public QScrollArea
{
    Q_OBJECT

public:
    explicit panel_info(QWidget *parent = 0);
    ~panel_info();

public slots:
    void serialport_rx(QByteArray bytes);

private:
    Ui::panel_info *ui;
};

#endif // PANEL_INFO_H
