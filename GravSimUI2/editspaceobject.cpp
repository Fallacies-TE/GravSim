#include "editspaceobject.h"
#include "ui_editspaceobject.h"
#include "incorrectformat.h"

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdlib.h>

EditSpaceObject::EditSpaceObject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSpaceObject)
{
    ui->setupUi(this);
}

int selectedRow, selectedIndex;
std::vector< std::vector<QString> > tableData;
QString typeHolder;
QString textholder;

EditSpaceObject::~EditSpaceObject()
{
    delete ui;
}

void EditSpaceObject::setData(QTableWidget *table){
    //tableFromMain = new QTableWidget(table);
    int numRows = table->rowCount();
    QStringList objects;
    std::string temp;
    QString temp2;

    for(int i=0; i<numRows; ++i){
        temp = ((table->item(i, 0))->text()).toStdString();
        //std::cout << i ;
        //std::cout << ": " ;
        //std::cout << temp ;
        //std::cout << std::endl ;
        objects << ((table->item(i, 0))->text());
    }

    ui->comboBox_2->addItems(objects);

    std::vector< std::vector<QString> > tableHolder(numRows, std::vector<QString>(13));

    for(int j=0; j<numRows; ++j){
        for(int col=0; col<13; ++col){
            temp2 = ((table->item(j, col))->text());
            tableHolder[j][col] = temp2;
            //std::cout << j << "," << col << ": " << (tableHolder[j][col]).toStdString() << std::endl ;
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

    ui->lineEdit->insert(tableData[selectedRow][0]);
    ui->lineEdit_2->insert(tableData[selectedRow][1]);
    ui->lineEdit_3->insert(tableData[selectedRow][2]);
    ui->lineEdit_4->insert(tableData[selectedRow][3]);
    ui->lineEdit_5->insert(tableData[selectedRow][4]);
    ui->lineEdit_6->insert(tableData[selectedRow][5]);
    ui->lineEdit_7->insert(tableData[selectedRow][6]);
    ui->lineEdit_8->insert(tableData[selectedRow][7]);
    ui->lineEdit_9->insert(tableData[selectedRow][8]);
    ui->lineEdit_10->insert(tableData[selectedRow][9]);
    ui->lineEdit_11->insert(tableData[selectedRow][10]);
    ui->lineEdit_12->insert(tableData[selectedRow][11]);

    typeHolder = tableData[selectedRow][12];

    if(strcmp(typeHolder.toStdString().c_str(), "Star") == 0){
        selectedIndex = 0;
    } else if(strcmp(typeHolder.toStdString().c_str(), "Planet") == 0) {
        selectedIndex = 1;
    } else if(strcmp(typeHolder.toStdString().c_str(), "Satellite") == 0) {
        selectedIndex = 2;
    }

    ui->comboBox->setCurrentIndex(selectedIndex);
}

// if e at end of number add 0 at end to make it e0
// if . at end of number add 0 at end to make it .0
// if not e or . in number add .0 at end
QString EditSpaceObject::EditNumberIfNeeded(std::string s, QString s2)
{
    bool DotAtEnd = false;
    bool ContainsDot = false;
    bool EAtEnd = false;
    bool ContainsE = false;
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (std::isdigit(*it) || (*it == 'e') || (*it == '.') )){
        if(*it == 'e'){
            EAtEnd = true;
            DotAtEnd = false;
            ContainsE = true;
        } else if(*it == '.') {
            EAtEnd = false;
            DotAtEnd = true;
            ContainsDot = true;
        } else {
            EAtEnd = false;
            DotAtEnd = false;
        }

        ++it;
    }

    if(!EAtEnd && !DotAtEnd && !ContainsE && !ContainsDot){
        s2.append(".0");
    } else if(EAtEnd || DotAtEnd) {
        s2.append("0");
    }

    return s2;
}


QString EditSpaceObject::name(){
    return ui->lineEdit->text();
}

QString EditSpaceObject::xpos(){
    textholder = ui->lineEdit_2->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::ypos(){
    textholder = ui->lineEdit_3->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::zpos(){
    textholder = ui->lineEdit_4->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::mass(){
    textholder = ui->lineEdit_5->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::xspeed(){
    textholder = ui->lineEdit_6->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::yspeed(){
    textholder = ui->lineEdit_7->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::zspeed(){
    textholder = ui->lineEdit_8->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::radius(){
    textholder = ui->lineEdit_9->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::red(){
    textholder = ui->lineEdit_10->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::blue(){
    textholder = ui->lineEdit_11->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::green(){
    textholder = ui->lineEdit_12->text();

    if(textholder == ""){
        textholder = "0.0";
    }
    return this->EditNumberIfNeeded(textholder.toStdString(), textholder);
}

QString EditSpaceObject::type(){
    return ui->comboBox->currentText();
}

bool EditSpaceObject::is_number(std::string s)
{
    if(s == "")
        return true;

    bool detectedE = false;
    bool detectedDot = false;
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (std::isdigit(*it) || (*it == 'e') || (*it == '.') )){
        if(*it == 'e'){
            if(!detectedE){
                detectedE = true;
            } else if (detectedE) {
                return false;
            }
        } else if(*it == '.') {
            if(!detectedDot){
                detectedDot = true;
            } else if (detectedDot) {
                return false;
            } else if (detectedE){
                return false;
            }
        }

        ++it;
    }

    return !s.empty() && it == s.end();
}

void EditSpaceObject::on_lineEdit_2_textChanged(const QString &arg1) {
    //std::string changedText = arg1.toStdString();
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_2->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_2->text());
        numDialog.exec();
    }
}

void EditSpaceObject::on_lineEdit_3_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_3->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_3->text());
        numDialog.exec();
    }
}


void EditSpaceObject::on_lineEdit_4_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_4->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_4->text());
        numDialog.exec();
    }
}

void EditSpaceObject::on_lineEdit_5_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_5->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_5->text());
        numDialog.exec();
    }
}

void EditSpaceObject::on_lineEdit_6_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_6->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_6->text());
        numDialog.exec();
    }
}

void EditSpaceObject::on_lineEdit_7_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_7->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_7->text());
        numDialog.exec();
    }
}

void EditSpaceObject::on_lineEdit_8_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_8->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_8->text());
        numDialog.exec();
    }
}

void EditSpaceObject::on_lineEdit_9_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_9->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_9->text());
        numDialog.exec();
    }
}

void EditSpaceObject::on_lineEdit_10_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_10->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_10->text());
        numDialog.exec();
    }
}

void EditSpaceObject::on_lineEdit_11_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_11->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_11->text());
        numDialog.exec();
    }
}

void EditSpaceObject::on_lineEdit_12_textChanged(const QString &arg1)
{
    std::string holder = (arg1.toStdString());
    if( !this->is_number( holder ) ){
        std::cout << "string changed to : " << holder << std::endl;
        ui->lineEdit_12->clear();
        IncorrectFormat numDialog;
        numDialog.setModal(true);
        numDialog.setText(ui->label_12->text());
        numDialog.exec();
    }
}
