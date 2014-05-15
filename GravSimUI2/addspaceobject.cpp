#include "addspaceobject.h"
#include "ui_addspaceobject.h"
#include "mainwindow.h"

AddSpaceObject::AddSpaceObject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSpaceObject)
{
    ui->setupUi(this);
}

AddSpaceObject::~AddSpaceObject()
{
    delete ui;
}

QString AddSpaceObject::name(){
    return ui->lineEdit->text();
}

double AddSpaceObject::xpos(){
    return ui->doubleSpinBox->value();
}

double AddSpaceObject::ypos(){
    return ui->doubleSpinBox_2->value();
}

double AddSpaceObject::zpos(){
    return ui->doubleSpinBox_3->value();
}

double AddSpaceObject::mass(){
    return ui->doubleSpinBox_4->value();
}

double AddSpaceObject::xspeed(){
    return ui->doubleSpinBox_5->value();
}

double AddSpaceObject::yspeed(){
    return ui->doubleSpinBox_6->value();
}

double AddSpaceObject::zspeed(){
    return ui->doubleSpinBox_7->value();
}

double AddSpaceObject::red(){
    return ui->doubleSpinBox_8->value();
}

double AddSpaceObject::blue(){
    return ui->doubleSpinBox_9->value();
}

double AddSpaceObject::green(){
    return ui->doubleSpinBox_10->value();
}

double AddSpaceObject::radius(){
    return ui->doubleSpinBox_11->value();
}

QString AddSpaceObject::type(){
    return ui->comboBox->currentText();
}
