#include "deletespaceobject.h"
#include "ui_deletespaceobject.h"
#include <iostream>

DeleteSpaceObject::DeleteSpaceObject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteSpaceObject)
{
    ui->setupUi(this);
}

int rowSelected;

DeleteSpaceObject::~DeleteSpaceObject()
{
    delete ui;
}

void DeleteSpaceObject::setData(QTableWidget *table){
    int numRows = table->rowCount();
    QStringList objects;
    std::string temp;

    for(int i=0; i<numRows; ++i){
        temp = ((table->item(i, 0))->text()).toStdString();
        std::cout << i ;
        std::cout << ": " ;
        std::cout << temp ;
        std::cout << std::endl ;
        objects << ((table->item(i, 0))->text());
    }

    ui->comboBox->addItems(objects);

}

int DeleteSpaceObject::getSelectedRow(){
    return rowSelected;
}

void DeleteSpaceObject::on_pushButton_clicked()
{
    rowSelected = (ui->comboBox->currentIndex());
    std::cout << "selected: " << rowSelected << std::endl;
}
