/****************************************************************************
** Meta object code from reading C++ file 'system.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project2/system.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'system.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_System_t {
    QByteArrayData data[23];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_System_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_System_t qt_meta_stringdata_System = {
    {
QT_MOC_LITERAL(0, 0, 6), // "System"
QT_MOC_LITERAL(1, 7, 16), // "receivedGameOver"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "itemAdded"
QT_MOC_LITERAL(4, 35, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(5, 50, 7), // "addItem"
QT_MOC_LITERAL(6, 58, 11), // "itemRemoved"
QT_MOC_LITERAL(7, 70, 6), // "rmItem"
QT_MOC_LITERAL(8, 77, 30), // "receivedSignal1_SelectPosition"
QT_MOC_LITERAL(9, 108, 8), // "Position"
QT_MOC_LITERAL(10, 117, 28), // "receivedSignal1_SelectMinion"
QT_MOC_LITERAL(11, 146, 9), // "Minion_t*"
QT_MOC_LITERAL(12, 156, 9), // "selMinion"
QT_MOC_LITERAL(13, 166, 26), // "receivedSignal1_SelectCard"
QT_MOC_LITERAL(14, 193, 6), // "CardID"
QT_MOC_LITERAL(15, 200, 30), // "receivedSignal2_SelectPosition"
QT_MOC_LITERAL(16, 231, 28), // "receivedSignal2_SelectMinion"
QT_MOC_LITERAL(17, 260, 26), // "receivedSignal2_SelectCard"
QT_MOC_LITERAL(18, 287, 12), // "addAnimation"
QT_MOC_LITERAL(19, 300, 6), // "center"
QT_MOC_LITERAL(20, 307, 6), // "period"
QT_MOC_LITERAL(21, 314, 15), // "QList<QString>&"
QT_MOC_LITERAL(22, 330, 8) // "pathList"

    },
    "System\0receivedGameOver\0\0itemAdded\0"
    "QGraphicsItem*\0addItem\0itemRemoved\0"
    "rmItem\0receivedSignal1_SelectPosition\0"
    "Position\0receivedSignal1_SelectMinion\0"
    "Minion_t*\0selMinion\0receivedSignal1_SelectCard\0"
    "CardID\0receivedSignal2_SelectPosition\0"
    "receivedSignal2_SelectMinion\0"
    "receivedSignal2_SelectCard\0addAnimation\0"
    "center\0period\0QList<QString>&\0pathList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_System[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x09 /* Protected */,
       3,    1,   65,    2, 0x09 /* Protected */,
       6,    1,   68,    2, 0x09 /* Protected */,
       8,    1,   71,    2, 0x09 /* Protected */,
      10,    1,   74,    2, 0x09 /* Protected */,
      13,    1,   77,    2, 0x09 /* Protected */,
      15,    1,   80,    2, 0x09 /* Protected */,
      16,    1,   83,    2, 0x09 /* Protected */,
      17,    1,   86,    2, 0x09 /* Protected */,
      18,    3,   89,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    7,
    QMetaType::Void, QMetaType::QPointF,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QPointF,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Int, 0x80000000 | 21,   19,   20,   22,

       0        // eod
};

void System::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        System *_t = static_cast<System *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedGameOver(); break;
        case 1: _t->itemAdded((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 2: _t->itemRemoved((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 3: _t->receivedSignal1_SelectPosition((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->receivedSignal1_SelectMinion((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 5: _t->receivedSignal1_SelectCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->receivedSignal2_SelectPosition((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 7: _t->receivedSignal2_SelectMinion((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 8: _t->receivedSignal2_SelectCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->addAnimation((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Minion_t* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Minion_t* >(); break;
            }
            break;
        }
    }
}

const QMetaObject System::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_System.data,
      qt_meta_data_System,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *System::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *System::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_System.stringdata0))
        return static_cast<void*>(const_cast< System*>(this));
    return QObject::qt_metacast(_clname);
}

int System::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
