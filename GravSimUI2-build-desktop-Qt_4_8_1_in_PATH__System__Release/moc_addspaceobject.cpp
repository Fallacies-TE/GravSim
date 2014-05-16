/****************************************************************************
** Meta object code from reading C++ file 'addspaceobject.h'
**
** Created: Fri May 16 00:51:56 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GravSimUI2/addspaceobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addspaceobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddSpaceObject[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x08,
      56,   16,   15,   15, 0x08,
      91,   16,   15,   15, 0x08,
     126,   16,   15,   15, 0x08,
     161,   16,   15,   15, 0x08,
     196,   16,   15,   15, 0x08,
     231,   16,   15,   15, 0x08,
     266,   16,   15,   15, 0x08,
     301,   16,   15,   15, 0x08,
     337,   16,   15,   15, 0x08,
     373,   16,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddSpaceObject[] = {
    "AddSpaceObject\0\0arg1\0"
    "on_lineEdit_2_textChanged(QString)\0"
    "on_lineEdit_3_textChanged(QString)\0"
    "on_lineEdit_4_textChanged(QString)\0"
    "on_lineEdit_5_textChanged(QString)\0"
    "on_lineEdit_6_textChanged(QString)\0"
    "on_lineEdit_7_textChanged(QString)\0"
    "on_lineEdit_8_textChanged(QString)\0"
    "on_lineEdit_9_textChanged(QString)\0"
    "on_lineEdit_10_textChanged(QString)\0"
    "on_lineEdit_11_textChanged(QString)\0"
    "on_lineEdit_12_textChanged(QString)\0"
};

void AddSpaceObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddSpaceObject *_t = static_cast<AddSpaceObject *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_2_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_lineEdit_3_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_lineEdit_4_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_5_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_lineEdit_6_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_7_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_8_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_lineEdit_9_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_lineEdit_10_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_lineEdit_11_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_lineEdit_12_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddSpaceObject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddSpaceObject::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddSpaceObject,
      qt_meta_data_AddSpaceObject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddSpaceObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddSpaceObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddSpaceObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddSpaceObject))
        return static_cast<void*>(const_cast< AddSpaceObject*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddSpaceObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
