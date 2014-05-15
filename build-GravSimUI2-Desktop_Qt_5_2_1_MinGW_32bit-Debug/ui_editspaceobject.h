/********************************************************************************
** Form generated from reading UI file 'editspaceobject.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSPACEOBJECT_H
#define UI_EDITSPACEOBJECT_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditSpaceObject
{
public:
    QLabel *label_13;
    QLabel *label_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_14;
    QLabel *label_5;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_11;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_2;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_10;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_15;
    QLabel *label_16;
    QComboBox *comboBox_2;
    QPushButton *pushButton;

    void setupUi(QDialog *EditSpaceObject)
    {
        if (EditSpaceObject->objectName().isEmpty())
            EditSpaceObject->setObjectName(QStringLiteral("EditSpaceObject"));
        EditSpaceObject->resize(546, 524);
        label_13 = new QLabel(EditSpaceObject);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(140, 10, 341, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_13->setFont(font);
        label_6 = new QLabel(EditSpaceObject);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 480, 81, 21));
        layoutWidget = new QWidget(EditSpaceObject);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 410, 121, 95));
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

        label_7 = new QLabel(EditSpaceObject);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 450, 81, 21));
        lineEdit = new QLineEdit(EditSpaceObject);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 160, 121, 27));
        label_10 = new QLabel(EditSpaceObject);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(330, 290, 61, 21));
        doubleSpinBox_4 = new QDoubleSpinBox(EditSpaceObject);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(130, 350, 121, 31));
        doubleSpinBox_4->setDecimals(3);
        doubleSpinBox_4->setMaximum(1e+09);
        label_14 = new QLabel(EditSpaceObject);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(330, 160, 51, 21));
        label_5 = new QLabel(EditSpaceObject);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 350, 81, 20));
        label_11 = new QLabel(EditSpaceObject);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(330, 220, 61, 21));
        doubleSpinBox_11 = new QDoubleSpinBox(EditSpaceObject);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setGeometry(QRect(390, 160, 121, 31));
        doubleSpinBox_11->setDecimals(3);
        doubleSpinBox_11->setMaximum(1e+09);
        buttonBox = new QDialogButtonBox(EditSpaceObject);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(370, 370, 141, 241));
        buttonBox->setMinimumSize(QSize(0, 241));
        buttonBox->setMaximumSize(QSize(16777215, 241));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(EditSpaceObject);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 160, 101, 21));
        layoutWidget_2 = new QWidget(EditSpaceObject);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 220, 121, 95));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(3);
        doubleSpinBox->setMaximum(1e+09);

        verticalLayout_2->addWidget(doubleSpinBox);

        doubleSpinBox_2 = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(3);
        doubleSpinBox_2->setMaximum(1e+09);

        verticalLayout_2->addWidget(doubleSpinBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(3);
        doubleSpinBox_3->setMaximum(1e+09);

        verticalLayout_2->addWidget(doubleSpinBox_3);

        label_2 = new QLabel(EditSpaceObject);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 290, 81, 21));
        layoutWidget_3 = new QWidget(EditSpaceObject);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(400, 220, 111, 95));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_8 = new QDoubleSpinBox(layoutWidget_3);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setDecimals(3);
        doubleSpinBox_8->setMaximum(1e+09);

        verticalLayout_3->addWidget(doubleSpinBox_8);

        doubleSpinBox_9 = new QDoubleSpinBox(layoutWidget_3);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setDecimals(3);
        doubleSpinBox_9->setMaximum(1e+09);

        verticalLayout_3->addWidget(doubleSpinBox_9);

        doubleSpinBox_10 = new QDoubleSpinBox(layoutWidget_3);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setDecimals(3);
        doubleSpinBox_10->setMaximum(1e+09);

        verticalLayout_3->addWidget(doubleSpinBox_10);

        label_3 = new QLabel(EditSpaceObject);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 260, 81, 21));
        comboBox = new QComboBox(EditSpaceObject);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(400, 350, 111, 27));
        label_9 = new QLabel(EditSpaceObject);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(330, 260, 61, 21));
        label_12 = new QLabel(EditSpaceObject);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(300, 350, 101, 21));
        label_4 = new QLabel(EditSpaceObject);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 220, 81, 21));
        label_8 = new QLabel(EditSpaceObject);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 410, 81, 21));
        label_15 = new QLabel(EditSpaceObject);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 70, 131, 20));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        label_15->setFont(font1);
        label_16 = new QLabel(EditSpaceObject);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(40, 80, 101, 21));
        label_16->setFont(font1);
        comboBox_2 = new QComboBox(EditSpaceObject);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(180, 80, 161, 21));
        pushButton = new QPushButton(EditSpaceObject);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 80, 81, 23));

        retranslateUi(EditSpaceObject);
        QObject::connect(buttonBox, SIGNAL(rejected()), EditSpaceObject, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), EditSpaceObject, SLOT(accept()));

        QMetaObject::connectSlotsByName(EditSpaceObject);
    } // setupUi

    void retranslateUi(QDialog *EditSpaceObject)
    {
        EditSpaceObject->setWindowTitle(QApplication::translate("EditSpaceObject", "Edit fake space object", 0));
        label_13->setText(QApplication::translate("EditSpaceObject", "Edit your fake space object", 0));
        label_6->setText(QApplication::translate("EditSpaceObject", "Z speed", 0));
        label_7->setText(QApplication::translate("EditSpaceObject", "Y speed", 0));
        lineEdit->setText(QString());
        label_10->setText(QApplication::translate("EditSpaceObject", "Green", 0));
        label_14->setText(QApplication::translate("EditSpaceObject", "Radius", 0));
        label_5->setText(QApplication::translate("EditSpaceObject", "Mass", 0));
        label_11->setText(QApplication::translate("EditSpaceObject", "Red", 0));
        label->setText(QApplication::translate("EditSpaceObject", "Object's Name", 0));
        label_2->setText(QApplication::translate("EditSpaceObject", "Z position", 0));
        label_3->setText(QApplication::translate("EditSpaceObject", "Y position", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("EditSpaceObject", "Sun", 0)
         << QApplication::translate("EditSpaceObject", "Planet", 0)
         << QApplication::translate("EditSpaceObject", "Satellite", 0)
        );
        label_9->setText(QApplication::translate("EditSpaceObject", "Blue", 0));
        label_12->setText(QApplication::translate("EditSpaceObject", "Object's Type", 0));
        label_4->setText(QApplication::translate("EditSpaceObject", "X position", 0));
        label_8->setText(QApplication::translate("EditSpaceObject", "X speed", 0));
        label_15->setText(QApplication::translate("EditSpaceObject", "Which object would", 0));
        label_16->setText(QApplication::translate("EditSpaceObject", "you like to edit:", 0));
        pushButton->setText(QApplication::translate("EditSpaceObject", "Select", 0));
    } // retranslateUi

};

namespace Ui {
    class EditSpaceObject: public Ui_EditSpaceObject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSPACEOBJECT_H
