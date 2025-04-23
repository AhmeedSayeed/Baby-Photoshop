/********************************************************************************
** Form generated from reading UI file 'rotate.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATE_H
#define UI_ROTATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rotate
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *rotation;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *rotate)
    {
        if (rotate->objectName().isEmpty())
            rotate->setObjectName("rotate");
        rotate->resize(449, 310);
        rotate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(rotate);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 401, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label);

        rotation = new QComboBox(layoutWidget);
        rotation->addItem(QString());
        rotation->addItem(QString());
        rotation->addItem(QString());
        rotation->setObjectName("rotation");
        rotation->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(rotation);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(rotate);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, rotate, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, rotate, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(rotate);
    } // setupUi

    void retranslateUi(QDialog *rotate)
    {
        rotate->setWindowTitle(QCoreApplication::translate("rotate", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("rotate", "                Choose the degree of Rotation!", nullptr));
        rotation->setItemText(0, QCoreApplication::translate("rotate", "Rotate by 90 deg", nullptr));
        rotation->setItemText(1, QCoreApplication::translate("rotate", "Rotate by 180 deg", nullptr));
        rotation->setItemText(2, QCoreApplication::translate("rotate", "Rotate by 270 deg", nullptr));

    } // retranslateUi

};

namespace Ui {
    class rotate: public Ui_rotate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATE_H
