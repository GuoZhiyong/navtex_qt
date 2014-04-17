#include "eventspy.h"

#include <QEvent>

EventSpy::EventSpy(QObject *parent) : QObject(parent)
{
}




bool EventSpy::eventFilter(QObject *obj, QEvent *event)
{
    qDebug("%d", event->type());
     return QObject::eventFilter(obj, event);

//    if (event->type() == QEvent::KeyPress) {
//        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
//        qDebug("Ate key press %d", keyEvent->key());
//        return true;
//    } else {
//        // standard event processing
//        return QObject::eventFilter(obj, event);
//    }
}
