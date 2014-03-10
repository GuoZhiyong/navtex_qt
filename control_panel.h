#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

#include <QWidget>

namespace Ui {
class control_panel;
}

class control_panel : public QWidget
{
    Q_OBJECT

public:
    explicit control_panel(QWidget *parent = 0);
    ~control_panel();

private:
    QTimer *timer;                   //显示时间用的timer
    
private slots:
    void on_btn_pnl_setup_clicked();
    void on_btn_pnl_about_clicked();
    void on_btn_pnl_info_clicked();
    void on_btn_pnl_serialport_clicked();
    void on_btn_pnl_detail_clicked();
    void showTime();

    void btn_prev_clicked();
    void btn_next_clicked();

private:
    Ui::control_panel *ui;

signals:
    void mysignal(int);
};

#endif // CONTROL_PANEL_H
