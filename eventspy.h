#ifndef EVENTSPY_H
#define EVENTSPY_H

#include <QObject>

class EventSpy : public QObject
{
    Q_OBJECT
public:
    explicit EventSpy(QObject *parent = 0);

protected:
   bool eventFilter(QObject *obj, QEvent *event);
    
signals:
    
public slots:
    
};

#endif // EVENTSPY_H
