#ifndef PANEL_DETAIL_H
#define PANEL_DETAIL_H

#include <QWidget>

namespace Ui {
class panel_detail;
}

class panel_detail : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_detail(QWidget *parent = 0);
    ~panel_detail();
    
private:
    Ui::panel_detail *ui;
};

#endif // PANEL_DETAIL_H
