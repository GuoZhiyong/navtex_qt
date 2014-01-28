/****************************************************************************
** Meta object code from reading C++ file 'control_panel.h'
**
** Created: Tue Jan 28 15:48:30 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "control_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'control_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_control_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   14,   14,   14, 0x08,
      56,   14,   14,   14, 0x08,
      83,   14,   14,   14, 0x08,
     109,   14,   14,   14, 0x08,
     141,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_control_panel[] = {
    "control_panel\0\0mysignal(int)\0"
    "on_btn_pnl_setup_clicked()\0"
    "on_btn_pnl_about_clicked()\0"
    "on_btn_pnl_info_clicked()\0"
    "on_btn_pnl_serialport_clicked()\0"
    "on_btn_pnl_detail_clicked()\0"
};

void control_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        control_panel *_t = static_cast<control_panel *>(_o);
        switch (_id) {
        case 0: _t->mysignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btn_pnl_setup_clicked(); break;
        case 2: _t->on_btn_pnl_about_clicked(); break;
        case 3: _t->on_btn_pnl_info_clicked(); break;
        case 4: _t->on_btn_pnl_serialport_clicked(); break;
        case 5: _t->on_btn_pnl_detail_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData control_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject control_panel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_control_panel,
      qt_meta_data_control_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &control_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *control_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *control_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_control_panel))
        return static_cast<void*>(const_cast< control_panel*>(this));
    return QWidget::qt_metacast(_clname);
}

int control_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void control_panel::mysignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
