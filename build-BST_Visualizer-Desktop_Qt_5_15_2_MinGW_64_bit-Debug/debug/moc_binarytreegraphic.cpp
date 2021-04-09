/****************************************************************************
** Meta object code from reading C++ file 'binarytreegraphic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QT_BST_Visualizer/binarytreegraphic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'binarytreegraphic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BinaryTreeGraphic_t {
    QByteArrayData data[10];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BinaryTreeGraphic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BinaryTreeGraphic_t qt_meta_stringdata_BinaryTreeGraphic = {
    {
QT_MOC_LITERAL(0, 0, 17), // "BinaryTreeGraphic"
QT_MOC_LITERAL(1, 18, 10), // "insertNode"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "value"
QT_MOC_LITERAL(4, 36, 10), // "deleteNode"
QT_MOC_LITERAL(5, 47, 10), // "searchNode"
QT_MOC_LITERAL(6, 58, 11), // "DFTPreOrder"
QT_MOC_LITERAL(7, 70, 10), // "DFTInOrder"
QT_MOC_LITERAL(8, 81, 12), // "DFTPostOrder"
QT_MOC_LITERAL(9, 94, 3) // "BFT"

    },
    "BinaryTreeGraphic\0insertNode\0\0value\0"
    "deleteNode\0searchNode\0DFTPreOrder\0"
    "DFTInOrder\0DFTPostOrder\0BFT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BinaryTreeGraphic[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    1,   52,    2, 0x0a /* Public */,
       5,    1,   55,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

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
        Q_UNUSED(_t)
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

QT_INIT_METAOBJECT const QMetaObject BinaryTreeGraphic::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BinaryTreeGraphic.data,
    qt_meta_data_BinaryTreeGraphic,
    qt_static_metacall,
    nullptr,
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
