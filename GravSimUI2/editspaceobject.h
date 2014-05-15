#ifndef EDITSPACEOBJECT_H
#define EDITSPACEOBJECT_H

#include <QDialog>
#include <QTableWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
//#include <QtWidgets/QTableWidget>
//#include <QtWidgets/QLineEdit>
//#include <QtWidgets/QDoubleSpinBox>
//#include <QtWidgets/QComboBox>

namespace Ui {
class EditSpaceObject;
}

class EditSpaceObject : public QDialog
{
    Q_OBJECT

public:
    explicit EditSpaceObject(QWidget *parent = 0);
    ~EditSpaceObject();
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
    void setData(QTableWidget *table);
    int getSelectedRow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::EditSpaceObject *ui;
};

#endif // EDITSPACEOBJECT_H
