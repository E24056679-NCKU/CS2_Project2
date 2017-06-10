/****************************************************************************
** Meta object code from reading C++ file 'tower.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project2/tower.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tower.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tower_t_t {
    QByteArrayData data[9];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tower_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tower_t_t qt_meta_stringdata_Tower_t = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Tower_t"
QT_MOC_LITERAL(1, 8, 4), // "died"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 8), // "Tower_t*"
QT_MOC_LITERAL(4, 23, 7), // "rmTower"
QT_MOC_LITERAL(5, 31, 3), // "run"
QT_MOC_LITERAL(6, 35, 6), // "attack"
QT_MOC_LITERAL(7, 42, 7), // "Life_t*"
QT_MOC_LITERAL(8, 50, 6) // "target"

    },
    "Tower_t\0died\0\0Tower_t*\0rmTower\0run\0"
    "attack\0Life_t*\0target"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tower_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x0a /* Public */,
       6,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void Tower_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tower_t *_t = static_cast<Tower_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->died((*reinterpret_cast< Tower_t*(*)>(_a[1]))); break;
        case 1: _t->run(); break;
        case 2: _t->attack((*reinterpret_cast< Life_t*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Tower_t* >(); break;
            }
            break;
        case 2:
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
            typedef void (Tower_t::*_t)(Tower_t * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tower_t::died)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Tower_t::staticMetaObject = {
    { &Life_t::staticMetaObject, qt_meta_stringdata_Tower_t.data,
      qt_meta_data_Tower_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Tower_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tower_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Tower_t.stringdata0))
        return static_cast<void*>(const_cast< Tower_t*>(this));
    return Life_t::qt_metacast(_clname);
}

int Tower_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Life_t::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Tower_t::died(Tower_t * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_TowerManager_t_t {
    QByteArrayData data[24];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TowerManager_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TowerManager_t_t qt_meta_stringdata_TowerManager_t = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TowerManager_t"
QT_MOC_LITERAL(1, 15, 9), // "itemAdded"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(4, 41, 7), // "addItem"
QT_MOC_LITERAL(5, 49, 18), // "request_FindTarget"
QT_MOC_LITERAL(6, 68, 7), // "Life_t*"
QT_MOC_LITERAL(7, 76, 9), // "requester"
QT_MOC_LITERAL(8, 86, 8), // "LifeTeam"
QT_MOC_LITERAL(9, 95, 7), // "tarTeam"
QT_MOC_LITERAL(10, 103, 8), // "Life_t*&"
QT_MOC_LITERAL(11, 112, 8), // "response"
QT_MOC_LITERAL(12, 121, 21), // "request_FindAllTarget"
QT_MOC_LITERAL(13, 143, 15), // "QList<Life_t*>&"
QT_MOC_LITERAL(14, 159, 16), // "emit_ArrowAttack"
QT_MOC_LITERAL(15, 176, 6), // "target"
QT_MOC_LITERAL(16, 183, 6), // "damage"
QT_MOC_LITERAL(17, 190, 3), // "pos"
QT_MOC_LITERAL(18, 194, 17), // "receivedTowerDied"
QT_MOC_LITERAL(19, 212, 8), // "Tower_t*"
QT_MOC_LITERAL(20, 221, 7), // "rmTower"
QT_MOC_LITERAL(21, 229, 19), // "received_FindTarget"
QT_MOC_LITERAL(22, 249, 22), // "received_FindAllTarget"
QT_MOC_LITERAL(23, 272, 19) // "receive_arrowAttack"

    },
    "TowerManager_t\0itemAdded\0\0QGraphicsItem*\0"
    "addItem\0request_FindTarget\0Life_t*\0"
    "requester\0LifeTeam\0tarTeam\0Life_t*&\0"
    "response\0request_FindAllTarget\0"
    "QList<Life_t*>&\0emit_ArrowAttack\0"
    "target\0damage\0pos\0receivedTowerDied\0"
    "Tower_t*\0rmTower\0received_FindTarget\0"
    "received_FindAllTarget\0receive_arrowAttack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TowerManager_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    3,   57,    2, 0x06 /* Public */,
      12,    3,   64,    2, 0x06 /* Public */,
      14,    3,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,   78,    2, 0x0a /* Public */,
      21,    3,   81,    2, 0x0a /* Public */,
      22,    3,   88,    2, 0x0a /* Public */,
      23,    3,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    7,    9,   11,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 13,    7,    9,   11,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Double, QMetaType::QPointF,   15,   16,   17,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    7,    9,   11,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 13,    7,    9,   11,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Double, QMetaType::QPointF,   15,   16,   17,

       0        // eod
};

void TowerManager_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TowerManager_t *_t = static_cast<TowerManager_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemAdded((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 1: _t->request_FindTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< Life_t*(*)>(_a[3]))); break;
        case 2: _t->request_FindAllTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< QList<Life_t*>(*)>(_a[3]))); break;
        case 3: _t->emit_ArrowAttack((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QPointF(*)>(_a[3]))); break;
        case 4: _t->receivedTowerDied((*reinterpret_cast< Tower_t*(*)>(_a[1]))); break;
        case 5: _t->received_FindTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< Life_t*(*)>(_a[3]))); break;
        case 6: _t->received_FindAllTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< QList<Life_t*>(*)>(_a[3]))); break;
        case 7: _t->receive_arrowAttack((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QPointF(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
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
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Tower_t* >(); break;
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
        case 7:
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
            typedef void (TowerManager_t::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TowerManager_t::itemAdded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TowerManager_t::*_t)(Life_t * , LifeTeam , Life_t * & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TowerManager_t::request_FindTarget)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TowerManager_t::*_t)(Life_t * , LifeTeam , QList<Life_t*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TowerManager_t::request_FindAllTarget)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TowerManager_t::*_t)(Life_t * , double , QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TowerManager_t::emit_ArrowAttack)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject TowerManager_t::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TowerManager_t.data,
      qt_meta_data_TowerManager_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TowerManager_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TowerManager_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TowerManager_t.stringdata0))
        return static_cast<void*>(const_cast< TowerManager_t*>(this));
    return QObject::qt_metacast(_clname);
}

int TowerManager_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TowerManager_t::itemAdded(QGraphicsItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TowerManager_t::request_FindTarget(Life_t * _t1, LifeTeam _t2, Life_t * & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TowerManager_t::request_FindAllTarget(Life_t * _t1, LifeTeam _t2, QList<Life_t*> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TowerManager_t::emit_ArrowAttack(Life_t * _t1, double _t2, QPointF _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
