/********************************************************************************
** Form generated from reading UI file 'skewing.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKEWING_H
#define UI_SKEWING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_skewing
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *skewingDeg;

    void setupUi(QDialog *skewing)
    {
        if (skewing->objectName().isEmpty())
            skewing->setObjectName("skewing");
        skewing->resize(400, 300);
        buttonBox = new QDialogButtonBox(skewing);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_2 = new QLabel(skewing);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 381, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font.setBold(true);
        label_2->setFont(font);
        layoutWidget = new QWidget(skewing);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 130, 321, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        skewingDeg = new QLineEdit(layoutWidget);
        skewingDeg->setObjectName("skewingDeg");

        horizontalLayout->addWidget(skewingDeg);


        retranslateUi(skewing);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, skewing, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, skewing, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(skewing);
    } // setupUi

    void retranslateUi(QDialog *skewing)
    {
        skewing->setWindowTitle(QCoreApplication::translate("skewing", "Dialog", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("skewing", "Enter a degree:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class skewing: public Ui_skewing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKEWING_H
