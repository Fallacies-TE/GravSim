/****************************************************************************
** Meta object code from reading C++ file 'deletespaceobject.h'
**
** Created: Fri May 16 00:51:57 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GravSimUI2/deletespaceobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deletespaceobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeleteSpaceObject[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DeleteSpaceObject[] = {
    "DeleteSpaceObject\0\0on_pushButton_clicked()\0"
};

void DeleteSpaceObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DeleteSpaceObject *_t = static_cast<DeleteSpaceObject *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DeleteSpaceObject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DeleteSpaceObject::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DeleteSpaceObject,
      qt_meta_data_DeleteSpaceObject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeleteSpaceObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeleteSpaceObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeleteSpaceObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeleteSpaceObject))
        return static_cast<void*>(const_cast< DeleteSpaceObject*>(this));
    return QDialog::qt_metacast(_clname);
}

int DeleteSpaceObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
