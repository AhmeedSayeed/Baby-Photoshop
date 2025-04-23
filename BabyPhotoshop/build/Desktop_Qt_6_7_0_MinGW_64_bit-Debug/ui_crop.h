/********************************************************************************
** Form generated from reading UI file 'crop.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CROP_H
#define UI_CROP_H

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

class Ui_crop
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *imgX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *imgY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *cropWidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *cropHeight;

    void setupUi(QDialog *crop)
    {
        if (crop->objectName().isEmpty())
            crop->setObjectName("crop");
        crop->resize(667, 351);
        crop->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        buttonBox = new QDialogButtonBox(crop);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(280, 290, 341, 32));
        buttonBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_5 = new QLabel(crop);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 10, 221, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font.setPointSize(12);
        font.setBold(true);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(crop);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 60, 461, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font1.setBold(true);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(crop);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 110, 611, 143));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        imgX = new QLineEdit(layoutWidget);
        imgX->setObjectName("imgX");
        imgX->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(imgX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        imgY = new QLineEdit(layoutWidget);
        imgY->setObjectName("imgY");
        imgY->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(imgY);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        cropWidth = new QLineEdit(layoutWidget);
        cropWidth->setObjectName("cropWidth");
        cropWidth->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(cropWidth);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        cropHeight = new QLineEdit(layoutWidget);
        cropHeight->setObjectName("cropHeight");
        cropHeight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(cropHeight);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(crop);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, crop, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, crop, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(crop);
    } // setupUi

    void retranslateUi(QDialog *crop)
    {
        crop->setWindowTitle(QCoreApplication::translate("crop", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("crop", "Crop form:", nullptr));
        label_6->setText(QCoreApplication::translate("crop", "Start from (x,y) and take (width\303\227height) image", nullptr));
        label->setText(QCoreApplication::translate("crop", "Enter x:", nullptr));
        label_2->setText(QCoreApplication::translate("crop", "Enter y:", nullptr));
        label_3->setText(QCoreApplication::translate("crop", "Enter the width:", nullptr));
        label_4->setText(QCoreApplication::translate("crop", "Enter the height:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class crop: public Ui_crop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CROP_H
