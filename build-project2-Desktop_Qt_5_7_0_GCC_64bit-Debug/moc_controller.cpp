/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project2/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ControllerSlot_t_t {
    QByteArrayData data[12];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControllerSlot_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControllerSlot_t_t qt_meta_stringdata_ControllerSlot_t = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ControllerSlot_t"
QT_MOC_LITERAL(1, 17, 29), // "receivedSignal_SelectPosition"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 8), // "Position"
QT_MOC_LITERAL(4, 57, 27), // "receivedSignal_SelectMinion"
QT_MOC_LITERAL(5, 85, 9), // "Minion_t*"
QT_MOC_LITERAL(6, 95, 9), // "selMinion"
QT_MOC_LITERAL(7, 105, 25), // "receivedSignal_SelectCard"
QT_MOC_LITERAL(8, 131, 6), // "CardID"
QT_MOC_LITERAL(9, 138, 34), // "emit_ReceivedSignal_SelectPos..."
QT_MOC_LITERAL(10, 173, 32), // "emit_ReceivedSignal_SelectMinion"
QT_MOC_LITERAL(11, 206, 30) // "emit_ReceivedSignal_SelectCard"

    },
    "ControllerSlot_t\0receivedSignal_SelectPosition\0"
    "\0Position\0receivedSignal_SelectMinion\0"
    "Minion_t*\0selMinion\0receivedSignal_SelectCard\0"
    "CardID\0emit_ReceivedSignal_SelectPosition\0"
    "emit_ReceivedSignal_SelectMinion\0"
    "emit_ReceivedSignal_SelectCard"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControllerSlot_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       7,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   53,    2, 0x09 /* Protected */,
      10,    1,   56,    2, 0x09 /* Protected */,
      11,    1,   59,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void ControllerSlot_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControllerSlot_t *_t = static_cast<ControllerSlot_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedSignal_SelectPosition((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->receivedSignal_SelectMinion((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 2: _t->receivedSignal_SelectCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->emit_ReceivedSignal_SelectPosition((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->emit_ReceivedSignal_SelectMinion((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 5: _t->emit_ReceivedSignal_SelectCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Minion_t* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Minion_t* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ControllerSlot_t::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControllerSlot_t::receivedSignal_SelectPosition)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ControllerSlot_t::*_t)(Minion_t * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControllerSlot_t::receivedSignal_SelectMinion)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ControllerSlot_t::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControllerSlot_t::receivedSignal_SelectCard)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ControllerSlot_t::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ControllerSlot_t.data,
      qt_meta_data_ControllerSlot_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ControllerSlot_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControllerSlot_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ControllerSlot_t.stringdata0))
        return static_cast<void*>(const_cast< ControllerSlot_t*>(this));
    return QObject::qt_metacast(_clname);
}

int ControllerSlot_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ControllerSlot_t::receivedSignal_SelectPosition(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ControllerSlot_t::receivedSignal_SelectMinion(Minion_t * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ControllerSlot_t::receivedSignal_SelectCard(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
