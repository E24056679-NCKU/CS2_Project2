/****************************************************************************
** Meta object code from reading C++ file 'life.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project2/life.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'life.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Life_t_t {
    QByteArrayData data[22];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Life_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Life_t_t qt_meta_stringdata_Life_t = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Life_t"
QT_MOC_LITERAL(1, 7, 4), // "died"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 7), // "Life_t*"
QT_MOC_LITERAL(4, 21, 6), // "rmLife"
QT_MOC_LITERAL(5, 28, 16), // "emit_ArrowAttack"
QT_MOC_LITERAL(6, 45, 6), // "target"
QT_MOC_LITERAL(7, 52, 6), // "damage"
QT_MOC_LITERAL(8, 59, 3), // "pos"
QT_MOC_LITERAL(9, 63, 18), // "request_FindTarget"
QT_MOC_LITERAL(10, 82, 9), // "requester"
QT_MOC_LITERAL(11, 92, 8), // "LifeTeam"
QT_MOC_LITERAL(12, 101, 7), // "tarTeam"
QT_MOC_LITERAL(13, 109, 8), // "Life_t*&"
QT_MOC_LITERAL(14, 118, 8), // "response"
QT_MOC_LITERAL(15, 127, 21), // "request_FindAllTarget"
QT_MOC_LITERAL(16, 149, 15), // "QList<Life_t*>&"
QT_MOC_LITERAL(17, 165, 3), // "run"
QT_MOC_LITERAL(18, 169, 6), // "attack"
QT_MOC_LITERAL(19, 176, 11), // "arrowAttack"
QT_MOC_LITERAL(20, 188, 10), // "findTarget"
QT_MOC_LITERAL(21, 199, 13) // "findAllTarget"

    },
    "Life_t\0died\0\0Life_t*\0rmLife\0"
    "emit_ArrowAttack\0target\0damage\0pos\0"
    "request_FindTarget\0requester\0LifeTeam\0"
    "tarTeam\0Life_t*&\0response\0"
    "request_FindAllTarget\0QList<Life_t*>&\0"
    "run\0attack\0arrowAttack\0findTarget\0"
    "findAllTarget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Life_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    3,   62,    2, 0x06 /* Public */,
       9,    3,   69,    2, 0x06 /* Public */,
      15,    3,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,   83,    2, 0x0a /* Public */,
      18,    1,   84,    2, 0x0a /* Public */,
      19,    1,   87,    2, 0x0a /* Public */,
      20,    1,   90,    2, 0x0a /* Public */,
      21,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, QMetaType::QPointF,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 11, 0x80000000 | 13,   10,   12,   14,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 11, 0x80000000 | 16,   10,   12,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   14,

       0        // eod
};

void Life_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Life_t *_t = static_cast<Life_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->died((*reinterpret_cast< Life_t*(*)>(_a[1]))); break;
        case 1: _t->emit_ArrowAttack((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QPointF(*)>(_a[3]))); break;
        case 2: _t->request_FindTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< Life_t*(*)>(_a[3]))); break;
        case 3: _t->request_FindAllTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< QList<Life_t*>(*)>(_a[3]))); break;
        case 4: _t->run(); break;
        case 5: _t->attack((*reinterpret_cast< Life_t*(*)>(_a[1]))); break;
        case 6: _t->arrowAttack((*reinterpret_cast< Life_t*(*)>(_a[1]))); break;
        case 7: _t->findTarget((*reinterpret_cast< Life_t*(*)>(_a[1]))); break;
        case 8: _t->findAllTarget((*reinterpret_cast< QList<Life_t*>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Life_t::*_t)(Life_t * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Life_t::died)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Life_t::*_t)(Life_t * , double , QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Life_t::emit_ArrowAttack)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Life_t::*_t)(Life_t * , LifeTeam , Life_t * & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Life_t::request_FindTarget)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Life_t::*_t)(Life_t * , LifeTeam , QList<Life_t*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Life_t::request_FindAllTarget)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Life_t::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Life_t.data,
      qt_meta_data_Life_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Life_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Life_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Life_t.stringdata0))
        return static_cast<void*>(const_cast< Life_t*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Life_t*>(this));
    return QObject::qt_metacast(_clname);
}

int Life_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Life_t::died(Life_t * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Life_t::emit_ArrowAttack(Life_t * _t1, double _t2, QPointF _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Life_t::request_FindTarget(Life_t * _t1, LifeTeam _t2, Life_t * & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Life_t::request_FindAllTarget(Life_t * _t1, LifeTeam _t2, QList<Life_t*> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
