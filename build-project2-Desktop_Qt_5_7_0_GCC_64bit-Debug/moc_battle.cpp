/****************************************************************************
** Meta object code from reading C++ file 'battle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project2/battle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'battle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BattleManager_t_t {
    QByteArrayData data[50];
    char stringdata0[631];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BattleManager_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BattleManager_t_t qt_meta_stringdata_BattleManager_t = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BattleManager_t"
QT_MOC_LITERAL(1, 16, 8), // "gameOver"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "itemAdded"
QT_MOC_LITERAL(4, 36, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(5, 51, 7), // "addItem"
QT_MOC_LITERAL(6, 59, 11), // "itemRemoved"
QT_MOC_LITERAL(7, 71, 6), // "rmItem"
QT_MOC_LITERAL(8, 78, 17), // "request_Animation"
QT_MOC_LITERAL(9, 96, 6), // "center"
QT_MOC_LITERAL(10, 103, 6), // "period"
QT_MOC_LITERAL(11, 110, 15), // "QList<QString>&"
QT_MOC_LITERAL(12, 126, 8), // "pathList"
QT_MOC_LITERAL(13, 135, 9), // "countDown"
QT_MOC_LITERAL(14, 145, 9), // "addMinion"
QT_MOC_LITERAL(15, 155, 10), // "MinionType"
QT_MOC_LITERAL(16, 166, 4), // "Type"
QT_MOC_LITERAL(17, 171, 10), // "MinionTeam"
QT_MOC_LITERAL(18, 182, 5), // "Group"
QT_MOC_LITERAL(19, 188, 8), // "Position"
QT_MOC_LITERAL(20, 197, 12), // "removeMinion"
QT_MOC_LITERAL(21, 210, 9), // "Minion_t*"
QT_MOC_LITERAL(22, 220, 8), // "rmMinion"
QT_MOC_LITERAL(23, 229, 30), // "receivedSignal1_SelectPosition"
QT_MOC_LITERAL(24, 260, 28), // "receivedSignal1_SelectMinion"
QT_MOC_LITERAL(25, 289, 9), // "selMinion"
QT_MOC_LITERAL(26, 299, 26), // "receivedSignal1_SelectCard"
QT_MOC_LITERAL(27, 326, 6), // "CardID"
QT_MOC_LITERAL(28, 333, 30), // "receivedSignal2_SelectPosition"
QT_MOC_LITERAL(29, 364, 28), // "receivedSignal2_SelectMinion"
QT_MOC_LITERAL(30, 393, 26), // "receivedSignal2_SelectCard"
QT_MOC_LITERAL(31, 420, 14), // "emit_ItemAdded"
QT_MOC_LITERAL(32, 435, 16), // "emit_ItemRemoved"
QT_MOC_LITERAL(33, 452, 15), // "findLifeInRange"
QT_MOC_LITERAL(34, 468, 7), // "Life_t*"
QT_MOC_LITERAL(35, 476, 9), // "requester"
QT_MOC_LITERAL(36, 486, 8), // "LifeTeam"
QT_MOC_LITERAL(37, 495, 7), // "tarTeam"
QT_MOC_LITERAL(38, 503, 8), // "Life_t*&"
QT_MOC_LITERAL(39, 512, 8), // "response"
QT_MOC_LITERAL(40, 521, 18), // "findAllLifeInRange"
QT_MOC_LITERAL(41, 540, 15), // "QList<Life_t*>&"
QT_MOC_LITERAL(42, 556, 8), // "addArrow"
QT_MOC_LITERAL(43, 565, 6), // "target"
QT_MOC_LITERAL(44, 572, 6), // "damage"
QT_MOC_LITERAL(45, 579, 3), // "pos"
QT_MOC_LITERAL(46, 583, 18), // "received_Animation"
QT_MOC_LITERAL(47, 602, 11), // "rangeAttack"
QT_MOC_LITERAL(48, 614, 5), // "range"
QT_MOC_LITERAL(49, 620, 10) // "targetTeam"

    },
    "BattleManager_t\0gameOver\0\0itemAdded\0"
    "QGraphicsItem*\0addItem\0itemRemoved\0"
    "rmItem\0request_Animation\0center\0period\0"
    "QList<QString>&\0pathList\0countDown\0"
    "addMinion\0MinionType\0Type\0MinionTeam\0"
    "Group\0Position\0removeMinion\0Minion_t*\0"
    "rmMinion\0receivedSignal1_SelectPosition\0"
    "receivedSignal1_SelectMinion\0selMinion\0"
    "receivedSignal1_SelectCard\0CardID\0"
    "receivedSignal2_SelectPosition\0"
    "receivedSignal2_SelectMinion\0"
    "receivedSignal2_SelectCard\0emit_ItemAdded\0"
    "emit_ItemRemoved\0findLifeInRange\0"
    "Life_t*\0requester\0LifeTeam\0tarTeam\0"
    "Life_t*&\0response\0findAllLifeInRange\0"
    "QList<Life_t*>&\0addArrow\0target\0damage\0"
    "pos\0received_Animation\0rangeAttack\0"
    "range\0targetTeam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BattleManager_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    1,  115,    2, 0x06 /* Public */,
       6,    1,  118,    2, 0x06 /* Public */,
       8,    3,  121,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  128,    2, 0x0a /* Public */,
      14,    3,  129,    2, 0x0a /* Public */,
      20,    1,  136,    2, 0x0a /* Public */,
      23,    1,  139,    2, 0x0a /* Public */,
      24,    1,  142,    2, 0x0a /* Public */,
      26,    1,  145,    2, 0x0a /* Public */,
      28,    1,  148,    2, 0x0a /* Public */,
      29,    1,  151,    2, 0x0a /* Public */,
      30,    1,  154,    2, 0x0a /* Public */,
      31,    1,  157,    2, 0x0a /* Public */,
      32,    1,  160,    2, 0x0a /* Public */,
      33,    3,  163,    2, 0x0a /* Public */,
      40,    3,  170,    2, 0x0a /* Public */,
      42,    3,  177,    2, 0x0a /* Public */,
      46,    3,  184,    2, 0x0a /* Public */,
      47,    5,  191,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    7,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Int, 0x80000000 | 11,    9,   10,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17, QMetaType::QPointF,   16,   18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::QPointF,   19,
    QMetaType::Void, 0x80000000 | 21,   25,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::QPointF,   19,
    QMetaType::Void, 0x80000000 | 21,   25,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    7,
    QMetaType::Void, 0x80000000 | 34, 0x80000000 | 36, 0x80000000 | 38,   35,   37,   39,
    QMetaType::Void, 0x80000000 | 34, 0x80000000 | 36, 0x80000000 | 41,   35,   37,   39,
    QMetaType::Void, 0x80000000 | 34, QMetaType::Double, QMetaType::QPointF,   43,   44,   45,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Int, 0x80000000 | 11,    9,   10,   12,
    QMetaType::Void, 0x80000000 | 34, QMetaType::QPointF, QMetaType::Double, QMetaType::Double, 0x80000000 | 36,   35,    9,   48,   44,   49,

       0        // eod
};

void BattleManager_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BattleManager_t *_t = static_cast<BattleManager_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameOver(); break;
        case 1: _t->itemAdded((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 2: _t->itemRemoved((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 3: _t->request_Animation((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3]))); break;
        case 4: _t->countDown(); break;
        case 5: _t->addMinion((*reinterpret_cast< MinionType(*)>(_a[1])),(*reinterpret_cast< MinionTeam(*)>(_a[2])),(*reinterpret_cast< QPointF(*)>(_a[3]))); break;
        case 6: _t->removeMinion((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 7: _t->receivedSignal1_SelectPosition((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 8: _t->receivedSignal1_SelectMinion((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 9: _t->receivedSignal1_SelectCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->receivedSignal2_SelectPosition((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 11: _t->receivedSignal2_SelectMinion((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 12: _t->receivedSignal2_SelectCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->emit_ItemAdded((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 14: _t->emit_ItemRemoved((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 15: _t->findLifeInRange((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< Life_t*(*)>(_a[3]))); break;
        case 16: _t->findAllLifeInRange((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< LifeTeam(*)>(_a[2])),(*reinterpret_cast< QList<Life_t*>(*)>(_a[3]))); break;
        case 17: _t->addArrow((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QPointF(*)>(_a[3]))); break;
        case 18: _t->received_Animation((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3]))); break;
        case 19: _t->rangeAttack((*reinterpret_cast< Life_t*(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< LifeTeam(*)>(_a[5]))); break;
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
        case 6:
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Minion_t* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Minion_t* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Life_t* >(); break;
            }
            break;
        case 19:
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
            typedef void (BattleManager_t::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleManager_t::gameOver)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BattleManager_t::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleManager_t::itemAdded)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BattleManager_t::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleManager_t::itemRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BattleManager_t::*_t)(QPointF , int , QList<QString> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleManager_t::request_Animation)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject BattleManager_t::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BattleManager_t.data,
      qt_meta_data_BattleManager_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BattleManager_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BattleManager_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BattleManager_t.stringdata0))
        return static_cast<void*>(const_cast< BattleManager_t*>(this));
    return QObject::qt_metacast(_clname);
}

int BattleManager_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void BattleManager_t::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void BattleManager_t::itemAdded(QGraphicsItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BattleManager_t::itemRemoved(QGraphicsItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BattleManager_t::request_Animation(QPointF _t1, int _t2, QList<QString> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
