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
    QLCDNumber *lcdnumber_freq; //freq band
    QLabel *label_1;    //receive time
    QLabel *label_2;    //broad time
    QLabel *label_id;   //B1B2B3B4
    QPushButton *btn_view;  //view status
    QPushButton *btn_tts; // TTS button
    QTextEdit *txt_info;
    QGridLayout *layout;

signals:

public slots:

};

#endif // NAVTEXINFO_WIDGET_H
