#ifndef DELETESPACEOBJECT_H
#define DELETESPACEOBJECT_H

#include <QDialog>
#include <QTableWidget>
#include <QComboBox>

namespace Ui {
class DeleteSpaceObject;
}

class DeleteSpaceObject : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteSpaceObject(QWidget *parent = 0);
    ~DeleteSpaceObject();
    void setData(QTableWidget *table);
    int getSelectedRow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteSpaceObject *ui;
};

#endif // DELETESPACEOBJECT_H
