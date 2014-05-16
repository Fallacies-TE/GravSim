#include "addspaceobject.h"
#include "ui_addspaceobject.h"
#include "mainwindow.h"
#include "incorrectformat.h"

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

AddSpaceObject::AddSpaceObject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSpaceObject)
{
    ui->setupUi(this);
}

bool numeric = false;
QString textHolder;

AddSpaceObject::~AddSpaceObject()
{
    delete ui;
}

// if e at end of number add 0 at end to make it e0
// if . at end of number add 0 at end to make it .0
// if not e or . in number add .0 at end
QString AddSpaceObject::EditNumberIfNeeded(std::string s, QString s2)
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

QString AddSpaceObject::name(){
    return ui->lineEdit->text();
}

QString AddSpaceObject::xpos(){
    textHolder = ui->lineEdit_2->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::ypos(){
    textHolder = ui->lineEdit_3->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::zpos(){
    textHolder = ui->lineEdit_4->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::mass(){
    textHolder = ui->lineEdit_5->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::xspeed(){
    textHolder = ui->lineEdit_6->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::yspeed(){
    textHolder = ui->lineEdit_7->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::zspeed(){
    textHolder = ui->lineEdit_8->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::radius(){
    textHolder = ui->lineEdit_9->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::red(){
    textHolder = ui->lineEdit_10->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::blue(){
    textHolder = ui->lineEdit_11->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::green(){
    textHolder = ui->lineEdit_12->text();

    if(textHolder == ""){
        textHolder = "0.0";
    }
    return this->EditNumberIfNeeded(textHolder.toStdString(), textHolder);
}

QString AddSpaceObject::type(){
    return ui->comboBox->currentText();
}

bool AddSpaceObject::is_number(std::string s)
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


void AddSpaceObject::on_lineEdit_2_textChanged(const QString &arg1) {
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

void AddSpaceObject::on_lineEdit_3_textChanged(const QString &arg1)
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


void AddSpaceObject::on_lineEdit_4_textChanged(const QString &arg1)
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

void AddSpaceObject::on_lineEdit_5_textChanged(const QString &arg1)
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

void AddSpaceObject::on_lineEdit_6_textChanged(const QString &arg1)
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

void AddSpaceObject::on_lineEdit_7_textChanged(const QString &arg1)
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

void AddSpaceObject::on_lineEdit_8_textChanged(const QString &arg1)
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

void AddSpaceObject::on_lineEdit_9_textChanged(const QString &arg1)
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

void AddSpaceObject::on_lineEdit_10_textChanged(const QString &arg1)
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

void AddSpaceObject::on_lineEdit_11_textChanged(const QString &arg1)
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

void AddSpaceObject::on_lineEdit_12_textChanged(const QString &arg1)
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
