#ifndef INFO_PANEL_H
#define INFO_PANEL_H

#include <QWidget>

#include "FlowLayout.hpp"

namespace Ui {
class info_panel;
}

class info_panel : public QWidget
{
    Q_OBJECT
    
public:
    explicit info_panel(QWidget *parent = 0);
    ~info_panel();
    
private:
    Ui::info_panel *ui;
    FlowLayout *layout;
};

#endif // INFO_PANEL_H
