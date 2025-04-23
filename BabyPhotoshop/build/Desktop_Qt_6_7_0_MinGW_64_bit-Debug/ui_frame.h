/********************************************************************************
** Form generated from reading UI file 'frame.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frame
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QComboBox *framecolor;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *simple;
    QRadioButton *fancy;
    QSpacerItem *verticalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *frame)
    {
        if (frame->objectName().isEmpty())
            frame->setObjectName("frame");
        frame->resize(665, 339);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 50, 597, 241));
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
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        framecolor = new QComboBox(layoutWidget);
        framecolor->addItem(QString());
        framecolor->addItem(QString());
        framecolor->addItem(QString());
        framecolor->addItem(QString());
        framecolor->addItem(QString());
        framecolor->setObjectName("framecolor");
        framecolor->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(framecolor);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        simple = new QRadioButton(layoutWidget);
        simple->setObjectName("simple");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font1.setBold(true);
        font1.setItalic(true);
        simple->setFont(font1);
        simple->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(simple);

        fancy = new QRadioButton(layoutWidget);
        fancy->setObjectName("fancy");
        fancy->setFont(font1);
        fancy->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(fancy);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(frame);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, frame, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, frame, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(frame);
    } // setupUi

    void retranslateUi(QDialog *frame)
    {
        frame->setWindowTitle(QCoreApplication::translate("frame", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("frame", "                              Choose a color and a type to your Frame!", nullptr));
        framecolor->setItemText(0, QCoreApplication::translate("frame", "Red", nullptr));
        framecolor->setItemText(1, QCoreApplication::translate("frame", "Green", nullptr));
        framecolor->setItemText(2, QCoreApplication::translate("frame", "Blue", nullptr));
        framecolor->setItemText(3, QCoreApplication::translate("frame", "Purple", nullptr));
        framecolor->setItemText(4, QCoreApplication::translate("frame", "Yellow", nullptr));

        simple->setText(QCoreApplication::translate("frame", "Simple", nullptr));
        fancy->setText(QCoreApplication::translate("frame", "Fancy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frame: public Ui_frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_H
