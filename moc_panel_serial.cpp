/****************************************************************************
** Meta object code from reading C++ file 'panel_serial.h'
**
** Created: Tue Jan 28 15:48:32 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "panel_serial.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panel_serial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_panel_serial[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   13,   13,   13, 0x08,
      86,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_panel_serial[] = {
    "panel_serial\0\0bytes\0"
    "signal_serialport_rx(QByteArray)\0"
    "on_btn_serialport_send_clicked()\0"
    "onReadyRead()\0"
};

void panel_serial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        panel_serial *_t = static_cast<panel_serial *>(_o);
        switch (_id) {
        case 0: _t->signal_serialport_rx((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->on_btn_serialport_send_clicked(); break;
        case 2: _t->onReadyRead(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData panel_serial::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject panel_serial::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_panel_serial,
      qt_meta_data_panel_serial, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &panel_serial::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *panel_serial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *panel_serial::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_panel_serial))
        return static_cast<void*>(const_cast< panel_serial*>(this));
    return QWidget::qt_metacast(_clname);
}

int panel_serial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void panel_serial::signal_serialport_rx(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
