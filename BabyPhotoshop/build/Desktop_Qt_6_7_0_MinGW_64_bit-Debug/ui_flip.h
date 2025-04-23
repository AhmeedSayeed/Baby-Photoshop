/********************************************************************************
** Form generated from reading UI file 'flip.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIP_H
#define UI_FLIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_flip
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QDialog *flip)
    {
        if (flip->objectName().isEmpty())
            flip->setObjectName("flip");
        flip->resize(400, 300);
        flip->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        buttonBox = new QDialogButtonBox(flip);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(flip);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(60, 140, 271, 31));
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label = new QLabel(flip);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 60, 251, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        retranslateUi(flip);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, flip, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, flip, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(flip);
    } // setupUi

    void retranslateUi(QDialog *flip)
    {
        flip->setWindowTitle(QCoreApplication::translate("flip", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("flip", "Horizontally", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("flip", "Vertically", nullptr));

        label->setText(QCoreApplication::translate("flip", "             Choose how to Flipping!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class flip: public Ui_flip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIP_H
