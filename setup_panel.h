#ifndef SETUP_PANEL_H
#define SETUP_PANEL_H

#include <QWidget>

namespace Ui {
class setup_panel;
}

class setup_panel : public QWidget
{
    Q_OBJECT
    
public:
    explicit setup_panel(QWidget *parent = 0);
    ~setup_panel();
    
private:
    Ui::setup_panel *ui;
};

#endif // SETUP_PANEL_H
