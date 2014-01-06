#ifndef NAVTEXITEM_WIDGET_H
#define NAVTEXITEM_WIDGET_H

#include <QWidget>

class QLabel;

class NavtexItem_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit NavtexItem_Widget(QWidget *parent = 0);

private:
    QLabel *label_1 ;
    QLabel *label_2;
    QLabel *label_id;
    QLabel *label_type;
    QLabel *label_band;

signals:

public slots:

};

#endif // NAVTEXINFO_WIDGET_H
