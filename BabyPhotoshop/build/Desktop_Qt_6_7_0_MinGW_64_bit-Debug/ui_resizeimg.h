/********************************************************************************
** Form generated from reading UI file 'resizeimg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEIMG_H
#define UI_RESIZEIMG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resizeimg
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *resizeWidth;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *resizeHeight;

    void setupUi(QDialog *resizeimg)
    {
        if (resizeimg->objectName().isEmpty())
            resizeimg->setObjectName("resizeimg");
        resizeimg->resize(434, 258);
        resizeimg->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        buttonBox = new QDialogButtonBox(resizeimg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 190, 341, 32));
        buttonBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(resizeimg);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 50, 391, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(label);

        resizeWidth = new QLineEdit(layoutWidget);
        resizeWidth->setObjectName("resizeWidth");

        horizontalLayout->addWidget(resizeWidth);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label_2);

        resizeHeight = new QLineEdit(layoutWidget);
        resizeHeight->setObjectName("resizeHeight");

        horizontalLayout_2->addWidget(resizeHeight);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(resizeimg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, resizeimg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, resizeimg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(resizeimg);
    } // setupUi

    void retranslateUi(QDialog *resizeimg)
    {
        resizeimg->setWindowTitle(QCoreApplication::translate("resizeimg", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("resizeimg", "Enter new width:", nullptr));
        label_2->setText(QCoreApplication::translate("resizeimg", "Enter new height:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resizeimg: public Ui_resizeimg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEIMG_H
