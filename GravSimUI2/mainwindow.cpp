#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addspaceobject.h"
#include "editspaceobject.h"
#include "deletespaceobject.h"
#include <unistd.h>
#include <qprocess.h>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
        xpos = new QTableWidgetItem(QString::number(asoDialog.xpos()));
        ypos = new QTableWidgetItem(QString::number(asoDialog.ypos()));
        zpos = new QTableWidgetItem(QString::number(asoDialog.zpos()));
        mass = new QTableWidgetItem(QString::number(asoDialog.mass()));
        xspeed = new QTableWidgetItem(QString::number(asoDialog.xspeed()));
        yspeed = new QTableWidgetItem(QString::number(asoDialog.yspeed()));
        zspeed = new QTableWidgetItem(QString::number(asoDialog.zspeed()));
        radius = new QTableWidgetItem(QString::number(asoDialog.radius()));
        red = new QTableWidgetItem(QString::number(asoDialog.red()));
        blue = new QTableWidgetItem(QString::number(asoDialog.blue()));
        green = new QTableWidgetItem(QString::number(asoDialog.green()));
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
        xpos = new QTableWidgetItem(QString::number(esoDialog.xpos()));
        ypos = new QTableWidgetItem(QString::number(esoDialog.ypos()));
        zpos = new QTableWidgetItem(QString::number(esoDialog.zpos()));
        mass = new QTableWidgetItem(QString::number(esoDialog.mass()));
        xspeed = new QTableWidgetItem(QString::number(esoDialog.xspeed()));
        yspeed = new QTableWidgetItem(QString::number(esoDialog.yspeed()));
        zspeed = new QTableWidgetItem(QString::number(esoDialog.zspeed()));
        radius = new QTableWidgetItem(QString::number(esoDialog.radius()));
        red = new QTableWidgetItem(QString::number(esoDialog.red()));
        blue = new QTableWidgetItem(QString::number(esoDialog.blue()));
        green = new QTableWidgetItem(QString::number(esoDialog.green()));
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
    QString filename = "/home/Desktop/test.txt";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
      {
        QTextStream stream( &file );
        stream <<  endl;
        file.close();
      }
    QString execPath = "../GravitySimulator";
    QString execFile = "../GravitySimulator/gravSim";
    QProcess *process = new QProcess(this);
    process->setWorkingDirectory(execPath);
    process->start(execFile, QStringList() << execPath);

}
