/********************************************************************************
** Form generated from reading UI file 'mergeview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGEVIEW_H
#define UI_MERGEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_mergeview
{
public:
    QGridLayout *gridLayout;
    QLabel *viewOverlap;

    void setupUi(QDialog *mergeview)
    {
        if (mergeview->objectName().isEmpty())
            mergeview->setObjectName("mergeview");
        mergeview->resize(728, 661);
        gridLayout = new QGridLayout(mergeview);
        gridLayout->setObjectName("gridLayout");
        viewOverlap = new QLabel(mergeview);
        viewOverlap->setObjectName("viewOverlap");

        gridLayout->addWidget(viewOverlap, 0, 0, 1, 1);


        retranslateUi(mergeview);

        QMetaObject::connectSlotsByName(mergeview);
    } // setupUi

    void retranslateUi(QDialog *mergeview)
    {
        mergeview->setWindowTitle(QCoreApplication::translate("mergeview", "Dialog", nullptr));
        viewOverlap->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mergeview: public Ui_mergeview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGEVIEW_H
