/********************************************************************************
** Form generated from reading UI file 'deletespaceobject.ui'
**
** Created: Fri May 16 00:49:04 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETESPACEOBJECT_H
#define UI_DELETESPACEOBJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteSpaceObject
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_15;

    void setupUi(QDialog *DeleteSpaceObject)
    {
        if (DeleteSpaceObject->objectName().isEmpty())
            DeleteSpaceObject->setObjectName(QString::fromUtf8("DeleteSpaceObject"));
        DeleteSpaceObject->resize(371, 244);
        buttonBox = new QDialogButtonBox(DeleteSpaceObject);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-70, 200, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DeleteSpaceObject);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 20, 211, 20));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        layoutWidget = new QWidget(DeleteSpaceObject);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 140, 271, 46));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        pushButton = new QPushButton(DeleteSpaceObject);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 80, 81, 23));
        comboBox = new QComboBox(DeleteSpaceObject);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(50, 80, 161, 21));
        label_15 = new QLabel(DeleteSpaceObject);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(50, 50, 261, 20));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        label_15->setFont(font2);

        retranslateUi(DeleteSpaceObject);
        QObject::connect(buttonBox, SIGNAL(accepted()), DeleteSpaceObject, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DeleteSpaceObject, SLOT(reject()));

        QMetaObject::connectSlotsByName(DeleteSpaceObject);
    } // setupUi

    void retranslateUi(QDialog *DeleteSpaceObject)
    {
        DeleteSpaceObject->setWindowTitle(QApplication::translate("DeleteSpaceObject", "Delete fake space object", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DeleteSpaceObject", "Delete Space Object", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DeleteSpaceObject", "    Are you sure you want to delete", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DeleteSpaceObject", "                   this space object?", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DeleteSpaceObject", "Select", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DeleteSpaceObject", "Which object would you like to delete:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeleteSpaceObject: public Ui_DeleteSpaceObject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETESPACEOBJECT_H
