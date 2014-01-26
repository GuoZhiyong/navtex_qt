#ifndef SERIAL_PANEL_H
#define SERIAL_PANEL_H

#include <QWidget>

namespace Ui {
class serial_panel;
}

class serial_panel : public QWidget
{
    Q_OBJECT
    
public:
    explicit serial_panel(QWidget *parent = 0);
    ~serial_panel();
    
private:
    Ui::serial_panel *ui;
};

#endif // SERIAL_PANEL_H
