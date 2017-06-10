/****************************************************************************
** Meta object code from reading C++ file 'display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project2/display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Button_t_t {
    QByteArrayData data[4];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Button_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Button_t_t qt_meta_stringdata_Button_t = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Button_t"
QT_MOC_LITERAL(1, 9, 15), // "selectedByMouse"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2) // "ID"

    },
    "Button_t\0selectedByMouse\0\0ID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Button_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Button_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Button_t *_t = static_cast<Button_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectedByMouse((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Button_t::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Button_t::selectedByMouse)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Button_t::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Button_t.data,
      qt_meta_data_Button_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Button_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Button_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Button_t.stringdata0))
        return static_cast<void*>(const_cast< Button_t*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Button_t*>(this));
    return QObject::qt_metacast(_clname);
}

int Button_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Button_t::selectedByMouse(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MyQGraphicsScene_t {
    QByteArrayData data[12];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQGraphicsScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQGraphicsScene_t qt_meta_stringdata_MyQGraphicsScene = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MyQGraphicsScene"
QT_MOC_LITERAL(1, 17, 16), // "positionSelected"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "Position"
QT_MOC_LITERAL(4, 44, 17), // "updateBlackScreen"
QT_MOC_LITERAL(5, 62, 22), // "renderFlashlightEffect"
QT_MOC_LITERAL(6, 85, 7), // "QImage&"
QT_MOC_LITERAL(7, 93, 5), // "Image"
QT_MOC_LITERAL(8, 99, 6), // "Source"
QT_MOC_LITERAL(9, 106, 11), // "Light_Theta"
QT_MOC_LITERAL(10, 118, 1), // "R"
QT_MOC_LITERAL(11, 120, 12) // "Rotate_Theta"

    },
    "MyQGraphicsScene\0positionSelected\0\0"
    "Position\0updateBlackScreen\0"
    "renderFlashlightEffect\0QImage&\0Image\0"
    "Source\0Light_Theta\0R\0Rotate_Theta"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQGraphicsScene[] = {

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
       4,    0,   32,    2, 0x0a /* Public */,
       5,    5,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QPointF, QMetaType::Double, QMetaType::Int, QMetaType::Double,    7,    8,    9,   10,   11,

       0        // eod
};

void MyQGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyQGraphicsScene *_t = static_cast<MyQGraphicsScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionSelected((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->updateBlackScreen(); break;
        case 2: _t->renderFlashlightEffect((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyQGraphicsScene::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyQGraphicsScene::positionSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MyQGraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_MyQGraphicsScene.data,
      qt_meta_data_MyQGraphicsScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyQGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyQGraphicsScene.stringdata0))
        return static_cast<void*>(const_cast< MyQGraphicsScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int MyQGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyQGraphicsScene::positionSelected(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ControllableDisplay_t_t {
    QByteArrayData data[7];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControllableDisplay_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControllableDisplay_t_t qt_meta_stringdata_ControllableDisplay_t = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ControllableDisplay_t"
QT_MOC_LITERAL(1, 22, 14), // "minionSelected"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "Minion_t*"
QT_MOC_LITERAL(4, 48, 9), // "selMinion"
QT_MOC_LITERAL(5, 58, 16), // "positionSelected"
QT_MOC_LITERAL(6, 75, 8) // "Position"

    },
    "ControllableDisplay_t\0minionSelected\0"
    "\0Minion_t*\0selMinion\0positionSelected\0"
    "Position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControllableDisplay_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       5,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QPointF,    6,

       0        // eod
};

void ControllableDisplay_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControllableDisplay_t *_t = static_cast<ControllableDisplay_t *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->minionSelected((*reinterpret_cast< Minion_t*(*)>(_a[1]))); break;
        case 1: _t->positionSelected((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
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
        }
    }
}

const QMetaObject ControllableDisplay_t::staticMetaObject = {
    { &ControllerSlot_t::staticMetaObject, qt_meta_stringdata_ControllableDisplay_t.data,
      qt_meta_data_ControllableDisplay_t,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ControllableDisplay_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControllableDisplay_t::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ControllableDisplay_t.stringdata0))
        return static_cast<void*>(const_cast< ControllableDisplay_t*>(this));
    if (!strcmp(_clname, "Display_t"))
        return static_cast< Display_t*>(const_cast< ControllableDisplay_t*>(this));
    return ControllerSlot_t::qt_metacast(_clname);
}

int ControllableDisplay_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ControllerSlot_t::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
