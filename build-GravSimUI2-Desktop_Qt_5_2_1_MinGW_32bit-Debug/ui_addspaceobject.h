/********************************************************************************
** Form generated from reading UI file 'addspaceobject.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSPACEOBJECT_H
#define UI_ADDSPACEOBJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddSpaceObject
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QDoubleSpinBox *doubleSpinBox_4;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_10;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_11;

    void setupUi(QDialog *AddSpaceObject)
    {
        if (AddSpaceObject->objectName().isEmpty())
            AddSpaceObject->setObjectName(QStringLiteral("AddSpaceObject"));
        AddSpaceObject->resize(580, 426);
        buttonBox = new QDialogButtonBox(AddSpaceObject);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(380, 270, 141, 241));
        buttonBox->setMinimumSize(QSize(0, 241));
        buttonBox->setMaximumSize(QSize(16777215, 241));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(AddSpaceObject);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 60, 121, 27));
        doubleSpinBox_4 = new QDoubleSpinBox(AddSpaceObject);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(140, 250, 121, 27));
        doubleSpinBox_4->setDecimals(3);
        doubleSpinBox_4->setMaximum(1e+09);
        comboBox = new QComboBox(AddSpaceObject);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(410, 250, 111, 27));
        label = new QLabel(AddSpaceObject);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 101, 21));
        label_2 = new QLabel(AddSpaceObject);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 190, 81, 21));
        label_3 = new QLabel(AddSpaceObject);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 160, 81, 21));
        label_4 = new QLabel(AddSpaceObject);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 120, 81, 21));
        label_5 = new QLabel(AddSpaceObject);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 250, 81, 21));
        label_6 = new QLabel(AddSpaceObject);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 380, 81, 21));
        label_7 = new QLabel(AddSpaceObject);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 350, 81, 21));
        label_8 = new QLabel(AddSpaceObject);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 310, 81, 21));
        label_9 = new QLabel(AddSpaceObject);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(340, 160, 61, 21));
        label_10 = new QLabel(AddSpaceObject);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(340, 190, 61, 21));
        label_11 = new QLabel(AddSpaceObject);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(340, 120, 61, 21));
        label_12 = new QLabel(AddSpaceObject);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(310, 250, 101, 21));
        label_13 = new QLabel(AddSpaceObject);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(130, 10, 341, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_13->setFont(font);
        layoutWidget = new QWidget(AddSpaceObject);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 310, 121, 95));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_5 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setDecimals(3);
        doubleSpinBox_5->setMaximum(1e+09);

        verticalLayout->addWidget(doubleSpinBox_5);

        doubleSpinBox_6 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(3);
        doubleSpinBox_6->setMaximum(1e+09);

        verticalLayout->addWidget(doubleSpinBox_6);

        doubleSpinBox_7 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setDecimals(3);
        doubleSpinBox_7->setMaximum(1e+09);

        verticalLayout->addWidget(doubleSpinBox_7);

        layoutWidget1 = new QWidget(AddSpaceObject);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 120, 121, 95));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(3);
        doubleSpinBox->setMaximum(1e+09);

        verticalLayout_2->addWidget(doubleSpinBox);

        doubleSpinBox_2 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(3);
        doubleSpinBox_2->setMaximum(1e+09);

        verticalLayout_2->addWidget(doubleSpinBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(3);
        doubleSpinBox_3->setMaximum(1e+09);

        verticalLayout_2->addWidget(doubleSpinBox_3);

        layoutWidget2 = new QWidget(AddSpaceObject);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(410, 120, 111, 95));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_8 = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setDecimals(3);
        doubleSpinBox_8->setMaximum(1e+09);

        verticalLayout_3->addWidget(doubleSpinBox_8);

        doubleSpinBox_9 = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setDecimals(3);
        doubleSpinBox_9->setMaximum(1e+09);

        verticalLayout_3->addWidget(doubleSpinBox_9);

        doubleSpinBox_10 = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setDecimals(3);
        doubleSpinBox_10->setMaximum(1e+09);

        verticalLayout_3->addWidget(doubleSpinBox_10);

        label_14 = new QLabel(AddSpaceObject);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(340, 60, 51, 21));
        doubleSpinBox_11 = new QDoubleSpinBox(AddSpaceObject);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setGeometry(QRect(400, 60, 121, 31));
        doubleSpinBox_11->setDecimals(3);
        doubleSpinBox_11->setMaximum(1e+09);

        retranslateUi(AddSpaceObject);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddSpaceObject, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddSpaceObject, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddSpaceObject);
    } // setupUi

    void retranslateUi(QDialog *AddSpaceObject)
    {
        AddSpaceObject->setWindowTitle(QApplication::translate("AddSpaceObject", "Add fake space object", 0));
        lineEdit->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("AddSpaceObject", "Sun", 0)
         << QApplication::translate("AddSpaceObject", "Planet", 0)
         << QApplication::translate("AddSpaceObject", "Satellite", 0)
        );
        label->setText(QApplication::translate("AddSpaceObject", "Object's Name", 0));
        label_2->setText(QApplication::translate("AddSpaceObject", "Z position", 0));
        label_3->setText(QApplication::translate("AddSpaceObject", "Y position", 0));
        label_4->setText(QApplication::translate("AddSpaceObject", "X position", 0));
        label_5->setText(QApplication::translate("AddSpaceObject", "Mass", 0));
        label_6->setText(QApplication::translate("AddSpaceObject", "Z speed", 0));
        label_7->setText(QApplication::translate("AddSpaceObject", "Y speed", 0));
        label_8->setText(QApplication::translate("AddSpaceObject", "X speed", 0));
        label_9->setText(QApplication::translate("AddSpaceObject", "Blue", 0));
        label_10->setText(QApplication::translate("AddSpaceObject", "Green", 0));
        label_11->setText(QApplication::translate("AddSpaceObject", "Red", 0));
        label_12->setText(QApplication::translate("AddSpaceObject", "Object's Type", 0));
        label_13->setText(QApplication::translate("AddSpaceObject", "Create your own fake space object", 0));
        label_14->setText(QApplication::translate("AddSpaceObject", "Radius", 0));
    } // retranslateUi

};

namespace Ui {
    class AddSpaceObject: public Ui_AddSpaceObject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSPACEOBJECT_H
