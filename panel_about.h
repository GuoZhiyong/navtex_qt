#ifndef PANEL_ABOUT_H
#define PANEL_ABOUT_H

#include <QWidget>

namespace Ui {
class panel_about;
}

class panel_about : public QWidget
{
    Q_OBJECT

public:
    explicit panel_about(QWidget *parent = 0);
    ~panel_about();

private:
    Ui::panel_about *ui;
};

#endif // PANEL_ABOUT_H
