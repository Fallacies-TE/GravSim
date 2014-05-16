#ifndef EDITSPACEOBJECT_H
#define EDITSPACEOBJECT_H

#include <QDialog>
#include <QTableWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>

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
    void setData(QTableWidget *table);
    int getSelectedRow();
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

    void on_pushButton_clicked();

private:
    Ui::EditSpaceObject *ui;
};

#endif // EDITSPACEOBJECT_H
