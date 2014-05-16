#include "incorrectformat.h"
#include "ui_incorrectformat.h"

IncorrectFormat::IncorrectFormat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncorrectFormat)
{
    ui->setupUi(this);
}

IncorrectFormat::~IncorrectFormat()
{
    delete ui;
}

void IncorrectFormat::setText(QString name){
    QString text = name;
    text.append(" textbox");
    ui->label_2->setText(text);
}
