/****************************************************************************
** Meta object code from reading C++ file 'binarytreegraphic.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../BST_Visualizer/binarytreegraphic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'binarytreegraphic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BinaryTreeGraphic_t {
    const uint offsetsAndSize[20];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_BinaryTreeGraphic_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_BinaryTreeGraphic_t qt_meta_stringdata_BinaryTreeGraphic = {
    {
QT_MOC_LITERAL(0, 17), // "BinaryTreeGraphic"
QT_MOC_LITERAL(18, 10), // "insertNode"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 5), // "value"
QT_MOC_LITERAL(36, 10), // "deleteNode"
QT_MOC_LITERAL(47, 10), // "searchNode"
QT_MOC_LITERAL(58, 11), // "DFTPreOrder"
QT_MOC_LITERAL(70, 10), // "DFTInOrder"
QT_MOC_LITERAL(81, 12), // "DFTPostOrder"
QT_MOC_LITERAL(94, 3) // "BFT"

    },
    "BinaryTreeGraphic\0insertNode\0\0value\0"
    "deleteNode\0searchNode\0DFTPreOrder\0"
    "DFTInOrder\0DFTPostOrder\0BFT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BinaryTreeGraphic[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x0a,    0 /* Public */,
       4,    1,   59,    2, 0x0a,    2 /* Public */,
       5,    1,   62,    2, 0x0a,    4 /* Public */,
       6,    0,   65,    2, 0x0a,    6 /* Public */,
       7,    0,   66,    2, 0x0a,    7 /* Public */,
       8,    0,   67,    2, 0x0a,    8 /* Public */,
       9,    0,   68,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BinaryTreeGraphic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BinaryTreeGraphic *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->insertNode((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->deleteNode((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->searchNode((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: _t->DFTPreOrder(); break;
        case 4: _t->DFTInOrder(); break;
        case 5: _t->DFTPostOrder(); break;
        case 6: _t->BFT(); break;
        default: ;
        }
    }
}

const QMetaObject BinaryTreeGraphic::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BinaryTreeGraphic.offsetsAndSize,
    qt_meta_data_BinaryTreeGraphic,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_BinaryTreeGraphic_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *BinaryTreeGraphic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BinaryTreeGraphic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BinaryTreeGraphic.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BinaryTreeGraphic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
