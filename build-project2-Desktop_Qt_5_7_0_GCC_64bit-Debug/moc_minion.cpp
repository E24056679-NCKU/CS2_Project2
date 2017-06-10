/****************************************************************************
** Meta object code from reading C++ file 'minion.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project2/minion.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'minion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Minion_t_t {
    QByteArrayData data[20];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Minion_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Minion_t_t qt_meta_stringdata_Minion_t = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Minion_t"
QT_MOC_LITERAL(1, 9, 4), // "died"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 9), // "Minion_t*"
QT_MOC_LITERAL(4, 25, 8), // "rmMinion"
QT_MOC_LITERAL(5, 34, 15), // "selectedByMouse"
QT_MOC_LITERAL(6, 50, 9), // "selMinion"
QT_MOC_LITERAL(7, 60, 17), // "request_Animation"
QT_MOC_LITERAL(8, 78, 6), // "center"
QT_MOC_LITERAL(9, 85, 6), // "period"
QT_MOC_LITERAL(10, 92, 15), // "QList<QString>&"
QT_MOC_LITERAL(11, 108, 8), // "pathList"
QT_MOC_LITERAL(12, 117, 19), // "request_RangeAttack"
QT_MOC_LITERAL(13, 137, 7), // "Life_t*"
QT_MOC_LITERAL(14, 145, 9), // "requester"
QT_MOC_LITERAL(15, 155, 5), // "range"
QT_MOC_LITERAL(16, 161, 6), // "damage"
QT_MOC_LITERAL(17, 168, 8), // "LifeTeam"
QT_MOC_LITERAL(18, 177, 10), // "targetTeam"
QT_MOC_LITERAL(19, 188, 3) // "run"

    },
    "Minion_t\0died\0\0Minion_t*\0rmMinion\0"
    "selectedByMouse\0selMinion\0request_Animation\0"
    "center\0period\0QList<QString>&\0pathList\0"
    "request_RangeAttack\0Life_t*\0requester\0"
    "range\0damage\0LifeTeam\0targetTeam\0run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Minion_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       7,    3,   45,    2, 0x06 /* Public */,
      12,    5,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Int, 0x80000000 | 10,    8,    9,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QPointF, QMetaType::Double, QMetaType::Double, 0x80000000 | 17,   14,    8,   15,   16,   18,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Minion_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Minion_t *_t = static_cast<Minion_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->died((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 1: _t->selectedByMouse((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 2: _t->request_Animation((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3]))); break;
        case 3: _t->request_RangeAttack((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< LifeTeam(*)>(_a[5]))); break;
        case 4: _t->run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Minion_t* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Minion_t* >(); break;
            }
            break;
        case 3:
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
            typedef void (Minion_t::*_t)(Minion_t * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Minion_t::died)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Minion_t::*_t)(Minion_t * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Minion_t::selectedByMouse)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Minion_t::*_t)(QPointF , int , QList<QString> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Minion_t::request_Animation)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Minion_t::*_t)(Life_t * , QPointF , double , double , LifeTeam );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Minion_t::request_RangeAttack)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Minion_t::staticMetaObject = {
    { &Life_t::staticMetaObject, qt_meta_stringdata_Minion_t.data,
      qt_meta_data_Minion_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Minion_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Minion_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Minion_t.stringdata0))
        return static_cast<void*>(const_cast< Minion_t*>(this));
    return Life_t::qt_metacast(_clname);
}

int Minion_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Life_t::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Minion_t::died(Minion_t * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Minion_t::selectedByMouse(Minion_t * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Minion_t::request_Animation(QPointF _t1, int _t2, QList<QString> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Minion_t::request_RangeAttack(Life_t * _t1, QPointF _t2, double _t3, double _t4, LifeTeam _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_DerivedMinion_t_t {
    QByteArrayData data[3];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DerivedMinion_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DerivedMinion_t_t qt_meta_stringdata_DerivedMinion_t = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DerivedMinion_t"
QT_MOC_LITERAL(1, 16, 3), // "run"
QT_MOC_LITERAL(2, 20, 0) // ""

    },
    "DerivedMinion_t\0run\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DerivedMinion_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DerivedMinion_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DerivedMinion_t *_t = static_cast<DerivedMinion_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->run(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DerivedMinion_t::staticMetaObject = {
    { &Minion_t::staticMetaObject, qt_meta_stringdata_DerivedMinion_t.data,
      qt_meta_data_DerivedMinion_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DerivedMinion_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DerivedMinion_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DerivedMinion_t.stringdata0))
        return static_cast<void*>(const_cast< DerivedMinion_t*>(this));
    return Minion_t::qt_metacast(_clname);
}

int DerivedMinion_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Minion_t::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_MinionManager_t_t {
    QByteArrayData data[38];
    char stringdata0[461];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MinionManager_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MinionManager_t_t qt_meta_stringdata_MinionManager_t = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MinionManager_t"
QT_MOC_LITERAL(1, 16, 18), // "request_FindTarget"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "Life_t*"
QT_MOC_LITERAL(4, 44, 9), // "requester"
QT_MOC_LITERAL(5, 54, 8), // "LifeTeam"
QT_MOC_LITERAL(6, 63, 7), // "tarTeam"
QT_MOC_LITERAL(7, 71, 8), // "Life_t*&"
QT_MOC_LITERAL(8, 80, 8), // "response"
QT_MOC_LITERAL(9, 89, 21), // "request_FindAllTarget"
QT_MOC_LITERAL(10, 111, 15), // "QList<Life_t*>&"
QT_MOC_LITERAL(11, 127, 16), // "emit_ArrowAttack"
QT_MOC_LITERAL(12, 144, 6), // "target"
QT_MOC_LITERAL(13, 151, 6), // "damage"
QT_MOC_LITERAL(14, 158, 3), // "pos"
QT_MOC_LITERAL(15, 162, 17), // "request_Animation"
QT_MOC_LITERAL(16, 180, 6), // "center"
QT_MOC_LITERAL(17, 187, 6), // "period"
QT_MOC_LITERAL(18, 194, 15), // "QList<QString>&"
QT_MOC_LITERAL(19, 210, 8), // "pathList"
QT_MOC_LITERAL(20, 219, 19), // "request_RangeAttack"
QT_MOC_LITERAL(21, 239, 5), // "range"
QT_MOC_LITERAL(22, 245, 10), // "targetTeam"
QT_MOC_LITERAL(23, 256, 9), // "addMinion"
QT_MOC_LITERAL(24, 266, 9), // "Minion_t*"
QT_MOC_LITERAL(25, 276, 10), // "MinionType"
QT_MOC_LITERAL(26, 287, 4), // "Type"
QT_MOC_LITERAL(27, 292, 10), // "MinionTeam"
QT_MOC_LITERAL(28, 303, 4), // "Team"
QT_MOC_LITERAL(29, 308, 8), // "Position"
QT_MOC_LITERAL(30, 317, 12), // "removeMinion"
QT_MOC_LITERAL(31, 330, 8), // "rmMinion"
QT_MOC_LITERAL(32, 339, 18), // "receivedMinionDied"
QT_MOC_LITERAL(33, 358, 19), // "received_FindTarget"
QT_MOC_LITERAL(34, 378, 22), // "received_FindAllTarget"
QT_MOC_LITERAL(35, 401, 19), // "receive_ArrowAttack"
QT_MOC_LITERAL(36, 421, 18), // "received_Animation"
QT_MOC_LITERAL(37, 440, 20) // "received_RangeAttack"

    },
    "MinionManager_t\0request_FindTarget\0\0"
    "Life_t*\0requester\0LifeTeam\0tarTeam\0"
    "Life_t*&\0response\0request_FindAllTarget\0"
    "QList<Life_t*>&\0emit_ArrowAttack\0"
    "target\0damage\0pos\0request_Animation\0"
    "center\0period\0QList<QString>&\0pathList\0"
    "request_RangeAttack\0range\0targetTeam\0"
    "addMinion\0Minion_t*\0MinionType\0Type\0"
    "MinionTeam\0Team\0Position\0removeMinion\0"
    "rmMinion\0receivedMinionDied\0"
    "received_FindTarget\0received_FindAllTarget\0"
    "receive_ArrowAttack\0received_Animation\0"
    "received_RangeAttack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MinionManager_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,
       9,    3,   86,    2, 0x06 /* Public */,
      11,    3,   93,    2, 0x06 /* Public */,
      15,    3,  100,    2, 0x06 /* Public */,
      20,    5,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    3,  118,    2, 0x0a /* Public */,
      30,    1,  125,    2, 0x0a /* Public */,
      32,    1,  128,    2, 0x0a /* Public */,
      33,    3,  131,    2, 0x0a /* Public */,
      34,    3,  138,    2, 0x0a /* Public */,
      35,    3,  145,    2, 0x0a /* Public */,
      36,    3,  152,    2, 0x0a /* Public */,
      37,    5,  159,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 10,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, QMetaType::QPointF,   12,   13,   14,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Int, 0x80000000 | 18,   16,   17,   19,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPointF, QMetaType::Double, QMetaType::Double, 0x80000000 | 5,    4,   16,   21,   13,   22,

 // slots: parameters
    0x80000000 | 24, 0x80000000 | 25, 0x80000000 | 27, QMetaType::QPointF,   26,   28,   29,
    QMetaType::Void, 0x80000000 | 24,   31,
    QMetaType::Void, 0x80000000 | 24,   31,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 10,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, QMetaType::QPointF,   12,   13,   14,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Int, 0x80000000 | 18,   16,   17,   19,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPointF, QMetaType::Double, QMetaType::Double, 0x80000000 | 5,    4,   16,   21,   13,   22,

       0        // eod
};

void MinionManager_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MinionManager_t *_t = static_cast<MinionManager_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->request_FindTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< Life_t*(*)>(_a[3]))); break;
        case 1: _t->request_FindAllTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< QList<Life_t*>(*)>(_a[3]))); break;
        case 2: _t->emit_ArrowAttack((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QPointF(*)>(_a[3]))); break;
        case 3: _t->request_Animation((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3]))); break;
        case 4: _t->request_RangeAttack((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< LifeTeam(*)>(_a[5]))); break;
        case 5: { Minion_t* _r = _t->addMinion((*reinterpret_cast< MinionType(*)>(_a[1])),(*reinterpret_cast< MinionTeam(*)>(_a[2])),(*reinterpret_cast< QPointF(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< Minion_t**>(_a[0]) = _r; }  break;
        case 6: _t->removeMinion((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 7: _t->receivedMinionDied((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 8: _t->received_FindTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< Life_t*(*)>(_a[3]))); break;
        case 9: _t->received_FindAllTarget((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< QList<Life_t*>(*)>(_a[3]))); break;
        case 10: _t->receive_ArrowAttack((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QPointF(*)>(_a[3]))); break;
        case 11: _t->received_Animation((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3]))); break;
        case 12: _t->received_RangeAttack((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< LifeTeam(*)>(_a[5]))); break;
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
        case 4:
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
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 12:
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
            typedef void (MinionManager_t::*_t)(Life_t * , LifeTeam , Life_t * & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MinionManager_t::request_FindTarget)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MinionManager_t::*_t)(Life_t * , LifeTeam , QList<Life_t*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MinionManager_t::request_FindAllTarget)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MinionManager_t::*_t)(Life_t * , double , QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MinionManager_t::emit_ArrowAttack)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MinionManager_t::*_t)(QPointF , int , QList<QString> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MinionManager_t::request_Animation)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MinionManager_t::*_t)(Life_t * , QPointF , double , double , LifeTeam );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MinionManager_t::request_RangeAttack)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MinionManager_t::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MinionManager_t.data,
      qt_meta_data_MinionManager_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MinionManager_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MinionManager_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MinionManager_t.stringdata0))
        return static_cast<void*>(const_cast< MinionManager_t*>(this));
    return QObject::qt_metacast(_clname);
}

int MinionManager_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MinionManager_t::request_FindTarget(Life_t * _t1, LifeTeam _t2, Life_t * & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MinionManager_t::request_FindAllTarget(Life_t * _t1, LifeTeam _t2, QList<Life_t*> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MinionManager_t::emit_ArrowAttack(Life_t * _t1, double _t2, QPointF _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MinionManager_t::request_Animation(QPointF _t1, int _t2, QList<QString> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MinionManager_t::request_RangeAttack(Life_t * _t1, QPointF _t2, double _t3, double _t4, LifeTeam _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
