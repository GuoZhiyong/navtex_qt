#ifndef NAVTEXITEM_WIDGET_H
#define NAVTEXITEM_WIDGET_H

#include <QWidget>

class QLabel;
class QGridLayout;
class QLCDNumber;
class QPushButton;
class QTextEdit;

class NavtexItem_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit NavtexItem_Widget(QWidget *parent = 0);

private:
    QPushButton *btn_status;
    QLabel *lbl_freq; //freq band
    QLabel *lbl_rx;    //receive time
    QLabel *lbl_rx_time;
    QLabel *lbl_tx_time;
    QLabel *lbl_tx;    //broad time
    QLabel *lbl_id;   //B1B2B3B4
    QPushButton *btn_view;  //view status
    QPushButton *btn_tts; // TTS button
    QTextEdit *txt_info;
    QGridLayout *layout;

signals:

public slots:

};

#endif // NAVTEXINFO_WIDGET_H
