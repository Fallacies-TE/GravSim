/********************************************************************************
** Form generated from reading UI file 'incorrectformat.ui'
**
** Created: Fri May 16 00:49:04 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCORRECTFORMAT_H
#define UI_INCORRECTFORMAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_IncorrectFormat
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;

    void setupUi(QDialog *IncorrectFormat)
    {
        if (IncorrectFormat->objectName().isEmpty())
            IncorrectFormat->setObjectName(QString::fromUtf8("IncorrectFormat"));
        IncorrectFormat->resize(370, 132);
        buttonBox = new QDialogButtonBox(IncorrectFormat);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-70, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(IncorrectFormat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 201, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(IncorrectFormat);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 30, 131, 16));
        label_2->setFont(font);
        label_4 = new QLabel(IncorrectFormat);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 50, 231, 16));
        label_4->setFont(font);

        retranslateUi(IncorrectFormat);
        QObject::connect(buttonBox, SIGNAL(accepted()), IncorrectFormat, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), IncorrectFormat, SLOT(reject()));

        QMetaObject::connectSlotsByName(IncorrectFormat);
    } // setupUi

    void retranslateUi(QDialog *IncorrectFormat)
    {
        IncorrectFormat->setWindowTitle(QApplication::translate("IncorrectFormat", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IncorrectFormat", "Alphabetical text was added to", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("IncorrectFormat", "name", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("IncorrectFormat", "please change it to numerical text.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IncorrectFormat: public Ui_IncorrectFormat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCORRECTFORMAT_H
