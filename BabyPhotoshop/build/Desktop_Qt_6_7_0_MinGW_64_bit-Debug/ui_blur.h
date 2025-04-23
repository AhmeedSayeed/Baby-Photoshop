/********************************************************************************
** Form generated from reading UI file 'blur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUR_H
#define UI_BLUR_H

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

class Ui_blur
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QComboBox *Blurlevel;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *blur)
    {
        if (blur->objectName().isEmpty())
            blur->setObjectName("blur");
        blur->resize(576, 316);
        blur->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        layoutWidget = new QWidget(blur);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 40, 529, 231));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        Blurlevel = new QComboBox(layoutWidget);
        Blurlevel->addItem(QString());
        Blurlevel->addItem(QString());
        Blurlevel->addItem(QString());
        Blurlevel->setObjectName("Blurlevel");
        Blurlevel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(Blurlevel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
"\n"
""));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(blur);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, blur, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, blur, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(blur);
    } // setupUi

    void retranslateUi(QDialog *blur)
    {
        blur->setWindowTitle(QCoreApplication::translate("blur", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("blur", "                             Choose a level of bluring the Image!", nullptr));
        Blurlevel->setItemText(0, QCoreApplication::translate("blur", "Low", nullptr));
        Blurlevel->setItemText(1, QCoreApplication::translate("blur", "Medium", nullptr));
        Blurlevel->setItemText(2, QCoreApplication::translate("blur", "High", nullptr));

    } // retranslateUi

};

namespace Ui {
    class blur: public Ui_blur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUR_H
