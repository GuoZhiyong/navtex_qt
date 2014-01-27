#ifndef PANEL_ITEM_H
#define PANEL_ITEM_H

#include <QWidget>

namespace Ui {
class panel_item;
}

class panel_item : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_item(QWidget *parent = 0);
    ~panel_item();
    
private:
    Ui::panel_item *ui;
};

#endif // PANEL_ITEM_H
