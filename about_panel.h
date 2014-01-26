#ifndef ABOUT_PANEL_H
#define ABOUT_PANEL_H

#include <QWidget>

namespace Ui {
class about_panel;
}

class about_panel : public QWidget
{
    Q_OBJECT
    
public:
    explicit about_panel(QWidget *parent = 0);
    ~about_panel();
    
private:
    Ui::about_panel *ui;
};

#endif // ABOUT_PANEL_H
