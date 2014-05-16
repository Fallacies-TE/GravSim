#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addspaceobject.h"
#include "editspaceobject.h"
#include "deletespaceobject.h"
#include <unistd.h>
#include <qprocess.h>
#include <QDebug>
#include <QFile>
#include <QTableWidget>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    std::ifstream inputFile;
    inputFile.open("../GravitySimulator/PlanetsDatabase.txt");

    char* delim = (char*) " ";
    int index = 0;
    QTableWidgetItem *temp;
    char buf[512];
    char* tokens[13] = {};

    while(!inputFile.eof()){

        inputFile.getline(buf, 512);
        tokens[0] = std::strtok(buf, delim);

        if(tokens[0]) {
            ui->tableWidget->insertRow(index);

            for(int tok=1; tok<13; ++tok) {
                tokens[tok] = std::strtok(0, delim);
                if(!tokens[tok]) break;
            }

            for(int i=0; i<13; ++i) {
                temp = new QTableWidgetItem(tokens[i]);

                ui->tableWidget->setItem(index,i,temp);
            }
        }

        index++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Add
void MainWindow::on_pushButton_3_clicked()
{
    QTableWidgetItem *name, *xpos, *ypos, *zpos, *mass, *xspeed, *yspeed,
            *zspeed, *radius, *red, *blue, *green, *type;
    int row = ui->tableWidget->rowCount();
    AddSpaceObject asoDialog;
    asoDialog.setModal(true);
    int result = asoDialog.exec();

    if(result == QDialog::Accepted){
        ui->tableWidget->insertRow(row);
        name = new QTableWidgetItem(asoDialog.name());
        xpos = new QTableWidgetItem(asoDialog.xpos());
        ypos = new QTableWidgetItem(asoDialog.ypos());
        zpos = new QTableWidgetItem(asoDialog.zpos());
        mass = new QTableWidgetItem(asoDialog.mass());
        xspeed = new QTableWidgetItem(asoDialog.xspeed());
        yspeed = new QTableWidgetItem(asoDialog.yspeed());
        zspeed = new QTableWidgetItem(asoDialog.zspeed());
        radius = new QTableWidgetItem(asoDialog.radius());
        red = new QTableWidgetItem(asoDialog.red());
        blue = new QTableWidgetItem(asoDialog.blue());
        green = new QTableWidgetItem(asoDialog.green());
        type = new QTableWidgetItem(asoDialog.type());

        ui->tableWidget->setItem(row,0,name);
        ui->tableWidget->setItem(row,1,xpos);
        ui->tableWidget->setItem(row,2,ypos);
        ui->tableWidget->setItem(row,3,zpos);
        ui->tableWidget->setItem(row,4,mass);
        ui->tableWidget->setItem(row,5,xspeed);
        ui->tableWidget->setItem(row,6,yspeed);
        ui->tableWidget->setItem(row,7,zspeed);
        ui->tableWidget->setItem(row,8,radius);
        ui->tableWidget->setItem(row,9,red);
        ui->tableWidget->setItem(row,10,blue);
        ui->tableWidget->setItem(row,11,green);
        ui->tableWidget->setItem(row,12,type);

    }
}

//Edit
void MainWindow::on_pushButton_4_clicked()
{
    QTableWidgetItem *name, *xpos, *ypos, *zpos, *mass, *xspeed, *yspeed,
            *zspeed, *radius, *red, *blue, *green, *type;
    int row;

    EditSpaceObject esoDialog;
    esoDialog.setModal(true);
    esoDialog.setData((ui->tableWidget));
    int result = esoDialog.exec();

    if(result == QDialog::Accepted){
        row = esoDialog.getSelectedRow();
        name = new QTableWidgetItem(esoDialog.name());
        xpos = new QTableWidgetItem(esoDialog.xpos());
        ypos = new QTableWidgetItem(esoDialog.ypos());
        zpos = new QTableWidgetItem(esoDialog.zpos());
        mass = new QTableWidgetItem(esoDialog.mass());
        xspeed = new QTableWidgetItem(esoDialog.xspeed());
        yspeed = new QTableWidgetItem(esoDialog.yspeed());
        zspeed = new QTableWidgetItem(esoDialog.zspeed());
        radius = new QTableWidgetItem(esoDialog.radius());
        red = new QTableWidgetItem(esoDialog.red());
        blue = new QTableWidgetItem(esoDialog.blue());
        green = new QTableWidgetItem(esoDialog.green());
        type = new QTableWidgetItem(esoDialog.type());

        ui->tableWidget->setItem(row,0,name);
        ui->tableWidget->setItem(row,1,xpos);
        ui->tableWidget->setItem(row,2,ypos);
        ui->tableWidget->setItem(row,3,zpos);
        ui->tableWidget->setItem(row,4,mass);
        ui->tableWidget->setItem(row,5,xspeed);
        ui->tableWidget->setItem(row,6,yspeed);
        ui->tableWidget->setItem(row,7,zspeed);
        ui->tableWidget->setItem(row,8,radius);
        ui->tableWidget->setItem(row,9,red);
        ui->tableWidget->setItem(row,10,blue);
        ui->tableWidget->setItem(row,11,green);
        ui->tableWidget->setItem(row,12,type);

    }
}

//Delete
void MainWindow::on_pushButton_5_clicked()
{
    int row;
    DeleteSpaceObject dsoDialog;
    dsoDialog.setModal(true);
    dsoDialog.setData((ui->tableWidget));
    int result = dsoDialog.exec();

    if(result == QDialog::Accepted){
        row = dsoDialog.getSelectedRow();
        ui->tableWidget->removeRow(row);
    }
}

//Write object to input file and launch executable
void MainWindow::on_pushButton_clicked()
{
    int row = ui->tableWidget->rowCount();
    int col = 13;
    QString filename = "../GravitySimulator/test03.txt";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
      {
        QTextStream stream( &file );
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++)
                stream << (ui->tableWidget->item(i, j))->text() << " ";
            stream << endl;
         }

        file.close();
      }
    QString execPath = "../GravitySimulator/";
    QString execFile = "../GravitySimulator/gravSim";
    QProcess *process = new QProcess(this);
    process->setWorkingDirectory(execPath);
    process->start(execFile, QStringList() << execPath);

}
