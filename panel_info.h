#ifndef PANEL_INFO_H
#define PANEL_INFO_H

#include "FlowLayout.hpp"
#include <QScrollArea>

#include <QtSql>
#include <QKeyEvent>


namespace Ui {
class panel_info;
}

class panel_info : public QScrollArea
{
    Q_OBJECT

public:
    explicit panel_info(QWidget *parent = 0);
    ~panel_info();
    void keyPressEvent(QKeyEvent  *event);
    void myDrawItem(int index);
    void addNavtexItem(QWidget *);


public slots:
    void serialport_rx(QByteArray bytes);
    //void btnViewClick(NAVTEXITEM *item);
    //void btnTTSClick(NAVTEXITEM *item);

private:
    Ui::panel_info *ui;
    FlowLayout *layout;             //主布局管理器，用来访问单个的panel_item

};

#endif // PANEL_INFO_H
