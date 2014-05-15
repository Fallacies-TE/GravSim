#include "editspaceobject.h"
#include "ui_editspaceobject.h"
#include <iostream>
#include <vector>

EditSpaceObject::EditSpaceObject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSpaceObject)
{
    ui->setupUi(this);
}

//QTableWidget *tableFromMain;
int selectedRow;
std::vector< std::vector<QString> > tableData;
QString typeHolder;

EditSpaceObject::~EditSpaceObject()
{
    delete ui;
}

void EditSpaceObject::setData(QTableWidget *table){
    //tableFromMain = new QTableWidget(table);
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

    ui->comboBox_2->addItems(objects);

    std::vector< std::vector<QString> > tableHolder(numRows, std::vector<QString>(13));

    for(int j=0; j<numRows; ++j){
        for(int col=0; col<13; ++col){
            tableHolder[j][col] = (table->item(j, col))->text();
        }
    }

    tableData = tableHolder;


}

int EditSpaceObject::getSelectedRow(){
    return selectedRow;
}

void EditSpaceObject::on_pushButton_clicked()
{
    selectedRow = (ui->comboBox_2->currentIndex());
    std::cout << "selected: " << selectedRow << std::endl;

    std::vector<QString> temp = tableData[selectedRow];

    ui->lineEdit->insert(temp[0]);
    ui->doubleSpinBox->valueFromText(temp[1]);
    ui->doubleSpinBox_2->valueFromText(temp[2]);
    ui->doubleSpinBox_3->valueFromText(temp[3]);
    ui->doubleSpinBox_4->valueFromText(temp[4]);
    ui->doubleSpinBox_5->valueFromText(temp[5]);
    ui->doubleSpinBox_6->valueFromText(temp[6]);
    ui->doubleSpinBox_7->valueFromText(temp[7]);
    ui->doubleSpinBox_8->valueFromText(temp[8]);
    ui->doubleSpinBox_9->valueFromText(temp[9]);
    ui->doubleSpinBox_10->valueFromText(temp[10]);
    ui->doubleSpinBox_11->valueFromText(temp[11]);

    typeHolder = temp[12];

    //if(typeHolder.)

   // ui->comboBox->setCurrentIndex(temp[12]);
}


QString EditSpaceObject::name(){
    return ui->lineEdit->text();
}

double EditSpaceObject::xpos(){
    return ui->doubleSpinBox->value();
}

double EditSpaceObject::ypos(){
    return ui->doubleSpinBox_2->value();
}

double EditSpaceObject::zpos(){
    return ui->doubleSpinBox_3->value();
}

double EditSpaceObject::mass(){
    return ui->doubleSpinBox_4->value();
}

double EditSpaceObject::xspeed(){
    return ui->doubleSpinBox_5->value();
}

double EditSpaceObject::yspeed(){
    return ui->doubleSpinBox_6->value();
}

double EditSpaceObject::zspeed(){
    return ui->doubleSpinBox_7->value();
}

double EditSpaceObject::red(){
    return ui->doubleSpinBox_8->value();
}

double EditSpaceObject::blue(){
    return ui->doubleSpinBox_9->value();
}

double EditSpaceObject::green(){
    return ui->doubleSpinBox_10->value();
}

double EditSpaceObject::radius(){
    return ui->doubleSpinBox_11->value();
}

QString EditSpaceObject::type(){
    return ui->comboBox->currentText();
}
