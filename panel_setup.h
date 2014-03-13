#ifndef SETUP_PANEL_H
#define SETUP_PANEL_H

#include <QWidget>

#include "FlowLayout.hpp"

class QPushButton;
class QGroupBox;
class QHBoxLayout;
class QVBoxLayout;


class panel_setup : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_setup(QWidget *parent = 0);
    ~panel_setup();
    
private:
    QPushButton *btn_ret;
    QList<QPushButton *> btn_list_486_site;
    QList<QPushButton *> btn_list_486_info;
    QList<QPushButton *> btn_list_518_site;
    QList<QPushButton *> btn_list_518_info;
    QList<QPushButton *> btn_list_4209_site;
    QList<QPushButton *> btn_list_4209_info;


    FlowLayout *layout_486_site;

    QVBoxLayout *mainlayout;

private slots:
    void on_btn_ret_clicked();

};

#endif // SETUP_PANEL_H
