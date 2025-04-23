/********************************************************************************
** Form generated from reading UI file 'merge.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGE_H
#define UI_MERGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_merge
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *merge_2;
    QLabel *Secimg;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *merge)
    {
        if (merge->objectName().isEmpty())
            merge->setObjectName("merge");
        merge->resize(835, 508);
        merge->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        buttonBox = new QDialogButtonBox(merge);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(560, 420, 171, 29));
        buttonBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        merge_2 = new QComboBox(merge);
        merge_2->addItem(QString());
        merge_2->addItem(QString());
        merge_2->addItem(QString());
        merge_2->setObjectName("merge_2");
        merge_2->setGeometry(QRect(460, 180, 291, 28));
        merge_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Secimg = new QLabel(merge);
        Secimg->setObjectName("Secimg");
        Secimg->setGeometry(QRect(70, 100, 291, 281));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        Secimg->setFont(font);
        Secimg->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(230, 230, 230);"));
        layoutWidget = new QWidget(merge);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(430, 100, 351, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(merge);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, merge, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, merge, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(merge);
    } // setupUi

    void retranslateUi(QDialog *merge)
    {
        merge->setWindowTitle(QCoreApplication::translate("merge", "Dialog", nullptr));
        merge_2->setItemText(0, QCoreApplication::translate("merge", "Merge the common area", nullptr));
        merge_2->setItemText(1, QCoreApplication::translate("merge", "Resize the smaller image, then merge", nullptr));
        merge_2->setItemText(2, QCoreApplication::translate("merge", "Resize the bigger image, then merge", nullptr));

        Secimg->setText(QCoreApplication::translate("merge", "                      Load the second Image!", nullptr));
        pushButton->setText(QCoreApplication::translate("merge", "Load", nullptr));
        pushButton_2->setText(QCoreApplication::translate("merge", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class merge: public Ui_merge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGE_H
