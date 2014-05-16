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
    QString xpos();
    QString ypos();
    QString zpos();
    QString mass();
    QString xspeed();
    QString yspeed();
    QString zspeed();
    QString radius();
    QString red();
    QString blue();
    QString green();
    QString type();
    bool is_number(std::string s);
    QString EditNumberIfNeeded(std::string s, QString s2);


private slots:
    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);


    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_lineEdit_11_textChanged(const QString &arg1);

    void on_lineEdit_12_textChanged(const QString &arg1);

private:
    Ui::AddSpaceObject *ui;
};

#endif // ADDSPACEOBJECT_H
