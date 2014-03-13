#ifndef PANEL_ABOUT_H
#define PANEL_ABOUT_H

#include <QWidget>

class QPushButton;
class QGroupBox;
class QHBoxLayout;
class QVBoxLayout;

class panel_about : public QWidget
{
    Q_OBJECT

public:
    explicit panel_about(QWidget *parent = 0);
    ~panel_about();

private:
    QPushButton *btn_ret;
    QVBoxLayout *mainlayout;

private slots:
    void on_btn_ret_clicked();
};

#endif // PANEL_ABOUT_H
