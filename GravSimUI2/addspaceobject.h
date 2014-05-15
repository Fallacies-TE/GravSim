#ifndef ADDSPACEOBJECT_H
#define ADDSPACEOBJECT_H

#include <QDialog>
#include "ui_addspaceobject.h"

namespace Ui {
class AddSpaceObject;
}


class AddSpaceObject : public QDialog
{
    Q_OBJECT

public:
    explicit AddSpaceObject(QWidget *parent = 0);
    ~AddSpaceObject();
    QString name();
    double xpos();
    double ypos();
    double zpos();
    double mass();
    double xspeed();
    double yspeed();
    double zspeed();
    double radius();
    double red();
    double blue();
    double green();
    QString type();

private:
    Ui::AddSpaceObject *ui;
};

#endif // ADDSPACEOBJECT_H
