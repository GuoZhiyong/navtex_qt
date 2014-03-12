#ifndef SETUP_PANEL_H
#define SETUP_PANEL_H

#include <QWidget>

namespace Ui {
class panel_setup;
}

class panel_setup : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_setup(QWidget *parent = 0);
    ~panel_setup();
    
private:
    Ui::panel_setup *ui;
};

#endif // SETUP_PANEL_H
