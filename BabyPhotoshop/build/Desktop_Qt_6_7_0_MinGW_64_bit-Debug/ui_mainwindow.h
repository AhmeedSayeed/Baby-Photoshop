/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QLabel *Edited_img;
    QLabel *Loaded_img;
    QLabel *label;
    QSlider *horizontalSliderdarken;
    QSlider *horizontalSliderLighten;
    QPushButton *applyLighten;
    QPushButton *applyDarken;
    QPushButton *applyFlip;
    QComboBox *flipDir;
    QComboBox *rotDeg;
    QPushButton *applyRot;
    QComboBox *mrgarea;
    QPushButton *applyMerge;
    QPushButton *apply_resize;
    QSlider *blurlvl;
    QPushButton *applyBlur;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_width;
    QLineEdit *lineEdit_width;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_height;
    QLineEdit *lineEdit_height;
    QPushButton *applycrop;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *crop_width;
    QLineEdit *lineEdit_cropw;
    QHBoxLayout *horizontalLayout_9;
    QLabel *crop_height;
    QLineEdit *lineEdit_croph;
    QLabel *label_style;
    QPushButton *apply_frame;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *simple;
    QRadioButton *fancy;
    QPushButton *applySkew;
    QSlider *skewDeg;
    QLabel *label_thick;
    QSlider *horizontalSlider_thick;
    QPushButton *Info;
    QComboBox *comboBox_resizehow;
    QPushButton *apply_chooseresize;
    QPushButton *back_resize;
    QLabel *label_ratio;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout;
    QRadioButton *quartre;
    QRadioButton *third;
    QRadioButton *half;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *one;
    QRadioButton *two;
    QRadioButton *three;
    QRadioButton *four;
    QLabel *label_imagewidth;
    QLabel *label_imageheight;
    QLineEdit *lineEdit_x;
    QLabel *x;
    QLabel *y;
    QLineEdit *lineEdit_y;
    QPushButton *DetectEdges;
    QPushButton *Skewing;
    QPushButton *Purple;
    QPushButton *OilPainting;
    QPushButton *Blur;
    QPushButton *Crop;
    QPushButton *GrayScale;
    QPushButton *Premiumedge;
    QPushButton *InvertColors;
    QPushButton *FlipImage;
    QPushButton *RotateImage;
    QPushButton *Infrared;
    QPushButton *AddFrame;
    QPushButton *Resize;
    QPushButton *BlackWhite;
    QPushButton *OldTV;
    QPushButton *MergeImages;
    QPushButton *Sunlight;
    QPushButton *Saltpeppernoise;
    QPushButton *Lighten;
    QPushButton *Darken;
    QPushButton *Clear;
    QPushButton *Load;
    QPushButton *undo;
    QPushButton *redo;
    QPushButton *Save;
    QLabel *version;
    QPushButton *applymirror;
    QLabel *label_mirror;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout;
    QRadioButton *up;
    QRadioButton *down;
    QRadioButton *right;
    QRadioButton *left;
    QPushButton *Mirror;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *Mode;
    QPushButton *frameColor;
    QLabel *degree;
    QLabel *Logo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1350, 766);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 249, 246);\n"
"\n"
"color: rgb(0, 0, 0);\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-image: url(:/i18n/BabyPhotoshop_en_US.qm);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(450, 140, 81, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 121, 188);"));
        Edited_img = new QLabel(centralwidget);
        Edited_img->setObjectName("Edited_img");
        Edited_img->setGeometry(QRect(450, 170, 391, 371));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        Edited_img->setFont(font1);
        Edited_img->setCursor(QCursor(Qt::ArrowCursor));
        Edited_img->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(230, 230, 230);"));
        Loaded_img = new QLabel(centralwidget);
        Loaded_img->setObjectName("Loaded_img");
        Loaded_img->setGeometry(QRect(40, 170, 391, 371));
        Loaded_img->setFont(font1);
        Loaded_img->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(230, 230, 230);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 140, 71, 27));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 121, 188);"));
        horizontalSliderdarken = new QSlider(centralwidget);
        horizontalSliderdarken->setObjectName("horizontalSliderdarken");
        horizontalSliderdarken->setGeometry(QRect(110, 600, 301, 31));
        horizontalSliderdarken->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalSliderdarken->setAutoFillBackground(false);
        horizontalSliderdarken->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        horizontalSliderdarken->setMaximum(90);
        horizontalSliderdarken->setOrientation(Qt::Horizontal);
        horizontalSliderdarken->setInvertedAppearance(false);
        horizontalSliderdarken->setInvertedControls(false);
        horizontalSliderLighten = new QSlider(centralwidget);
        horizontalSliderLighten->setObjectName("horizontalSliderLighten");
        horizontalSliderLighten->setGeometry(QRect(110, 600, 301, 31));
        horizontalSliderLighten->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalSliderLighten->setAutoFillBackground(false);
        horizontalSliderLighten->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        horizontalSliderLighten->setMaximum(100);
        horizontalSliderLighten->setOrientation(Qt::Horizontal);
        horizontalSliderLighten->setInvertedAppearance(false);
        horizontalSliderLighten->setInvertedControls(false);
        applyLighten = new QPushButton(centralwidget);
        applyLighten->setObjectName("applyLighten");
        applyLighten->setGeometry(QRect(590, 600, 121, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font2.setBold(true);
        applyLighten->setFont(font2);
        applyLighten->setCursor(QCursor(Qt::PointingHandCursor));
        applyLighten->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        applyDarken = new QPushButton(centralwidget);
        applyDarken->setObjectName("applyDarken");
        applyDarken->setGeometry(QRect(590, 600, 121, 41));
        applyDarken->setFont(font2);
        applyDarken->setCursor(QCursor(Qt::PointingHandCursor));
        applyDarken->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        applyFlip = new QPushButton(centralwidget);
        applyFlip->setObjectName("applyFlip");
        applyFlip->setGeometry(QRect(590, 600, 121, 41));
        applyFlip->setFont(font2);
        applyFlip->setCursor(QCursor(Qt::PointingHandCursor));
        applyFlip->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        flipDir = new QComboBox(centralwidget);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/flip_horizontal.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon.addFile(QString::fromUtf8(":/img/flip_horizontal.png"), QSize(), QIcon::Selected, QIcon::On);
        flipDir->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/flip_vertical.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/img/flip_vertical.png"), QSize(), QIcon::Selected, QIcon::On);
        flipDir->addItem(icon1, QString());
        flipDir->setObjectName("flipDir");
        flipDir->setGeometry(QRect(100, 600, 321, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font3.setPointSize(9);
        font3.setWeight(QFont::DemiBold);
        font3.setItalic(false);
        flipDir->setFont(font3);
        flipDir->setCursor(QCursor(Qt::PointingHandCursor));
        flipDir->setStyleSheet(QString::fromUtf8("font: 600 9pt \"Sitka Text Semibold\";\n"
"background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));
        rotDeg = new QComboBox(centralwidget);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/depositphotos_114877492-stock-illustration-angle-90-degrees-sign.jpg"), QSize(), QIcon::Disabled, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/img/depositphotos_114877492-stock-illustration-angle-90-degrees-sign.jpg"), QSize(), QIcon::Selected, QIcon::On);
        rotDeg->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/depositphotos_124561746-stock-illustration-angle-180-degrees-sign-icon.jpg"), QSize(), QIcon::Disabled, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/img/depositphotos_124561746-stock-illustration-angle-180-degrees-sign-icon.jpg"), QSize(), QIcon::Selected, QIcon::On);
        rotDeg->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/stock-vector-angle-degrees-circle-icons-geometry-math-signs-symbols-full-complete-rotation-arrow-chat-454393438.jpg"), QSize(), QIcon::Disabled, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/img/stock-vector-angle-degrees-circle-icons-geometry-math-signs-symbols-full-complete-rotation-arrow-chat-454393438.jpg"), QSize(), QIcon::Selected, QIcon::On);
        rotDeg->addItem(icon4, QString());
        rotDeg->setObjectName("rotDeg");
        rotDeg->setGeometry(QRect(100, 600, 321, 21));
        rotDeg->setFont(font3);
        rotDeg->setCursor(QCursor(Qt::PointingHandCursor));
        rotDeg->setStyleSheet(QString::fromUtf8("font: 600 9pt \"Sitka Text Semibold\";\n"
"background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));
        applyRot = new QPushButton(centralwidget);
        applyRot->setObjectName("applyRot");
        applyRot->setGeometry(QRect(590, 600, 121, 41));
        applyRot->setFont(font2);
        applyRot->setCursor(QCursor(Qt::PointingHandCursor));
        applyRot->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        mrgarea = new QComboBox(centralwidget);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/two-overlapping-square.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/img/two-overlapping-square.png"), QSize(), QIcon::Selected, QIcon::On);
        mrgarea->addItem(icon5, QString());
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/resize.png"), QSize(), QIcon::Normal, QIcon::On);
        icon6.addFile(QString::fromUtf8(":/img/resize.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/img/resize.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon6.addFile(QString::fromUtf8(":/img/resize.png"), QSize(), QIcon::Selected, QIcon::On);
        mrgarea->addItem(icon6, QString());
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/18851764.jpg"), QSize(), QIcon::Disabled, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/img/18851764.jpg"), QSize(), QIcon::Selected, QIcon::On);
        mrgarea->addItem(icon7, QString());
        mrgarea->setObjectName("mrgarea");
        mrgarea->setGeometry(QRect(90, 600, 331, 21));
        mrgarea->setFont(font3);
        mrgarea->setCursor(QCursor(Qt::PointingHandCursor));
        mrgarea->setStyleSheet(QString::fromUtf8("font: 600 9pt \"Sitka Text Semibold\";\n"
"background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));
        applyMerge = new QPushButton(centralwidget);
        applyMerge->setObjectName("applyMerge");
        applyMerge->setGeometry(QRect(590, 600, 121, 41));
        applyMerge->setFont(font2);
        applyMerge->setCursor(QCursor(Qt::PointingHandCursor));
        applyMerge->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        apply_resize = new QPushButton(centralwidget);
        apply_resize->setObjectName("apply_resize");
        apply_resize->setGeometry(QRect(590, 600, 121, 41));
        apply_resize->setCursor(QCursor(Qt::PointingHandCursor));
        apply_resize->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
""));
        blurlvl = new QSlider(centralwidget);
        blurlvl->setObjectName("blurlvl");
        blurlvl->setGeometry(QRect(110, 600, 301, 31));
        blurlvl->setCursor(QCursor(Qt::PointingHandCursor));
        blurlvl->setAutoFillBackground(false);
        blurlvl->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        blurlvl->setMaximum(100);
        blurlvl->setOrientation(Qt::Horizontal);
        blurlvl->setInvertedAppearance(false);
        blurlvl->setInvertedControls(false);
        applyBlur = new QPushButton(centralwidget);
        applyBlur->setObjectName("applyBlur");
        applyBlur->setGeometry(QRect(590, 600, 121, 41));
        applyBlur->setFont(font2);
        applyBlur->setCursor(QCursor(Qt::PointingHandCursor));
        applyBlur->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(120, 570, 281, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_width = new QLabel(layoutWidget);
        label_width->setObjectName("label_width");
        label_width->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout_4->addWidget(label_width);

        lineEdit_width = new QLineEdit(layoutWidget);
        lineEdit_width->setObjectName("lineEdit_width");
        lineEdit_width->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
""));

        horizontalLayout_4->addWidget(lineEdit_width);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(120, 630, 283, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_height = new QLabel(layoutWidget1);
        label_height->setObjectName("label_height");
        label_height->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout_5->addWidget(label_height);

        lineEdit_height = new QLineEdit(layoutWidget1);
        lineEdit_height->setObjectName("lineEdit_height");
        lineEdit_height->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"\n"
""));

        horizontalLayout_5->addWidget(lineEdit_height);

        applycrop = new QPushButton(centralwidget);
        applycrop->setObjectName("applycrop");
        applycrop->setGeometry(QRect(590, 600, 121, 41));
        applycrop->setFont(font2);
        applycrop->setCursor(QCursor(Qt::PointingHandCursor));
        applycrop->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(140, 650, 251, 35));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        crop_width = new QLabel(layoutWidget2);
        crop_width->setObjectName("crop_width");
        crop_width->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout_7->addWidget(crop_width);

        lineEdit_cropw = new QLineEdit(layoutWidget2);
        lineEdit_cropw->setObjectName("lineEdit_cropw");
        lineEdit_cropw->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));

        horizontalLayout_7->addWidget(lineEdit_cropw);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        crop_height = new QLabel(layoutWidget2);
        crop_height->setObjectName("crop_height");
        crop_height->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout_9->addWidget(crop_height);

        lineEdit_croph = new QLineEdit(layoutWidget2);
        lineEdit_croph->setObjectName("lineEdit_croph");
        lineEdit_croph->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));

        horizontalLayout_9->addWidget(lineEdit_croph);


        horizontalLayout_7->addLayout(horizontalLayout_9);

        label_style = new QLabel(centralwidget);
        label_style->setObjectName("label_style");
        label_style->setGeometry(QRect(160, 670, 231, 20));
        label_style->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        apply_frame = new QPushButton(centralwidget);
        apply_frame->setObjectName("apply_frame");
        apply_frame->setGeometry(QRect(520, 670, 111, 41));
        apply_frame->setFont(font2);
        apply_frame->setCursor(QCursor(Qt::PointingHandCursor));
        apply_frame->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(160, 690, 229, 26));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        simple = new QRadioButton(layoutWidget3);
        simple->setObjectName("simple");
        simple->setCursor(QCursor(Qt::PointingHandCursor));
        simple->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout_10->addWidget(simple);

        fancy = new QRadioButton(layoutWidget3);
        fancy->setObjectName("fancy");
        fancy->setCursor(QCursor(Qt::PointingHandCursor));
        fancy->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout_10->addWidget(fancy);

        applySkew = new QPushButton(centralwidget);
        applySkew->setObjectName("applySkew");
        applySkew->setGeometry(QRect(590, 600, 121, 41));
        applySkew->setFont(font2);
        applySkew->setCursor(QCursor(Qt::PointingHandCursor));
        applySkew->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        skewDeg = new QSlider(centralwidget);
        skewDeg->setObjectName("skewDeg");
        skewDeg->setGeometry(QRect(110, 600, 301, 31));
        skewDeg->setCursor(QCursor(Qt::PointingHandCursor));
        skewDeg->setAutoFillBackground(false);
        skewDeg->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        skewDeg->setMaximum(62);
        skewDeg->setOrientation(Qt::Horizontal);
        skewDeg->setInvertedAppearance(false);
        skewDeg->setInvertedControls(false);
        label_thick = new QLabel(centralwidget);
        label_thick->setObjectName("label_thick");
        label_thick->setGeometry(QRect(10, 600, 81, 31));
        label_thick->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        horizontalSlider_thick = new QSlider(centralwidget);
        horizontalSlider_thick->setObjectName("horizontalSlider_thick");
        horizontalSlider_thick->setGeometry(QRect(100, 600, 301, 31));
        horizontalSlider_thick->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalSlider_thick->setAutoFillBackground(false);
        horizontalSlider_thick->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        horizontalSlider_thick->setMinimum(5);
        horizontalSlider_thick->setMaximum(100);
        horizontalSlider_thick->setOrientation(Qt::Horizontal);
        horizontalSlider_thick->setInvertedAppearance(false);
        horizontalSlider_thick->setInvertedControls(false);
        Info = new QPushButton(centralwidget);
        Info->setObjectName("Info");
        Info->setGeometry(QRect(1260, 8, 51, 41));
        Info->setCursor(QCursor(Qt::PointingHandCursor));
        Info->setStyleSheet(QString::fromUtf8("image: url(:/img/info.png);\n"
"border-radius: 20px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        comboBox_resizehow = new QComboBox(centralwidget);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/dimensions.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/img/dimensions.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon8.addFile(QString::fromUtf8(":/img/dimensions.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/img/dimensions.png"), QSize(), QIcon::Selected, QIcon::On);
        comboBox_resizehow->addItem(icon8, QString());
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/ratio.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/img/ratio.png"), QSize(), QIcon::Disabled, QIcon::Off);
        comboBox_resizehow->addItem(icon9, QString());
        comboBox_resizehow->setObjectName("comboBox_resizehow");
        comboBox_resizehow->setGeometry(QRect(90, 600, 331, 21));
        comboBox_resizehow->setCursor(QCursor(Qt::PointingHandCursor));
        comboBox_resizehow->setStyleSheet(QString::fromUtf8("font: 600 9pt \"Sitka Text Semibold\";\n"
"background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));
        apply_chooseresize = new QPushButton(centralwidget);
        apply_chooseresize->setObjectName("apply_chooseresize");
        apply_chooseresize->setGeometry(QRect(660, 680, 111, 41));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(apply_chooseresize->sizePolicy().hasHeightForWidth());
        apply_chooseresize->setSizePolicy(sizePolicy);
        apply_chooseresize->setFont(font2);
        apply_chooseresize->setCursor(QCursor(Qt::PointingHandCursor));
        apply_chooseresize->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        back_resize = new QPushButton(centralwidget);
        back_resize->setObjectName("back_resize");
        back_resize->setGeometry(QRect(530, 680, 111, 41));
        sizePolicy.setHeightForWidth(back_resize->sizePolicy().hasHeightForWidth());
        back_resize->setSizePolicy(sizePolicy);
        back_resize->setFont(font2);
        back_resize->setCursor(QCursor(Qt::PointingHandCursor));
        back_resize->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        label_ratio = new QLabel(centralwidget);
        label_ratio->setObjectName("label_ratio");
        label_ratio->setGeometry(QRect(750, 550, 121, 21));
        label_ratio->setFont(font3);
        label_ratio->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(760, 570, 109, 109));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        quartre = new QRadioButton(layoutWidget4);
        quartre->setObjectName("quartre");
        quartre->setCursor(QCursor(Qt::PointingHandCursor));
        quartre->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        verticalLayout->addWidget(quartre);

        third = new QRadioButton(layoutWidget4);
        third->setObjectName("third");
        third->setCursor(QCursor(Qt::PointingHandCursor));
        third->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        verticalLayout->addWidget(third);

        half = new QRadioButton(layoutWidget4);
        half->setObjectName("half");
        half->setCursor(QCursor(Qt::PointingHandCursor));
        half->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        verticalLayout->addWidget(half);


        horizontalLayout_11->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        one = new QRadioButton(layoutWidget4);
        one->setObjectName("one");
        one->setCursor(QCursor(Qt::PointingHandCursor));
        one->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        verticalLayout_2->addWidget(one);

        two = new QRadioButton(layoutWidget4);
        two->setObjectName("two");
        two->setCursor(QCursor(Qt::PointingHandCursor));
        two->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        verticalLayout_2->addWidget(two);

        three = new QRadioButton(layoutWidget4);
        three->setObjectName("three");
        three->setCursor(QCursor(Qt::PointingHandCursor));
        three->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        verticalLayout_2->addWidget(three);

        four = new QRadioButton(layoutWidget4);
        four->setObjectName("four");
        four->setCursor(QCursor(Qt::PointingHandCursor));
        four->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        verticalLayout_2->addWidget(four);


        horizontalLayout_11->addLayout(verticalLayout_2);

        label_imagewidth = new QLabel(centralwidget);
        label_imagewidth->setObjectName("label_imagewidth");
        label_imagewidth->setGeometry(QRect(520, 550, 261, 16));
        label_imagewidth->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        label_imageheight = new QLabel(centralwidget);
        label_imageheight->setObjectName("label_imageheight");
        label_imageheight->setGeometry(QRect(520, 570, 261, 16));
        label_imageheight->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        lineEdit_x = new QLineEdit(centralwidget);
        lineEdit_x->setObjectName("lineEdit_x");
        lineEdit_x->setGeometry(QRect(170, 600, 83, 19));
        lineEdit_x->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));
        x = new QLabel(centralwidget);
        x->setObjectName("x");
        x->setGeometry(QRect(150, 600, 16, 16));
        x->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        y = new QLabel(centralwidget);
        y->setObjectName("y");
        y->setGeometry(QRect(260, 600, 16, 16));
        y->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        lineEdit_y = new QLineEdit(centralwidget);
        lineEdit_y->setObjectName("lineEdit_y");
        lineEdit_y->setGeometry(QRect(280, 600, 83, 19));
        lineEdit_y->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"\n"
""));
        DetectEdges = new QPushButton(centralwidget);
        DetectEdges->setObjectName("DetectEdges");
        DetectEdges->setGeometry(QRect(880, 340, 111, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DetectEdges->sizePolicy().hasHeightForWidth());
        DetectEdges->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setItalic(false);
        DetectEdges->setFont(font4);
        DetectEdges->setCursor(QCursor(Qt::PointingHandCursor));
        DetectEdges->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        DetectEdges->setIconSize(QSize(20, 20));
        Skewing = new QPushButton(centralwidget);
        Skewing->setObjectName("Skewing");
        Skewing->setGeometry(QRect(880, 580, 221, 61));
        sizePolicy1.setHeightForWidth(Skewing->sizePolicy().hasHeightForWidth());
        Skewing->setSizePolicy(sizePolicy1);
        Skewing->setFont(font4);
        Skewing->setCursor(QCursor(Qt::PointingHandCursor));
        Skewing->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Skewing->setIconSize(QSize(20, 20));
        Purple = new QPushButton(centralwidget);
        Purple->setObjectName("Purple");
        Purple->setGeometry(QRect(880, 520, 221, 61));
        sizePolicy1.setHeightForWidth(Purple->sizePolicy().hasHeightForWidth());
        Purple->setSizePolicy(sizePolicy1);
        Purple->setFont(font4);
        Purple->setCursor(QCursor(Qt::PointingHandCursor));
        Purple->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Purple->setIconSize(QSize(20, 20));
        OilPainting = new QPushButton(centralwidget);
        OilPainting->setObjectName("OilPainting");
        OilPainting->setGeometry(QRect(880, 460, 221, 61));
        sizePolicy1.setHeightForWidth(OilPainting->sizePolicy().hasHeightForWidth());
        OilPainting->setSizePolicy(sizePolicy1);
        OilPainting->setFont(font4);
        OilPainting->setCursor(QCursor(Qt::PointingHandCursor));
        OilPainting->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        OilPainting->setIconSize(QSize(20, 20));
        Blur = new QPushButton(centralwidget);
        Blur->setObjectName("Blur");
        Blur->setGeometry(QRect(880, 400, 221, 61));
        sizePolicy1.setHeightForWidth(Blur->sizePolicy().hasHeightForWidth());
        Blur->setSizePolicy(sizePolicy1);
        Blur->setFont(font4);
        Blur->setCursor(QCursor(Qt::PointingHandCursor));
        Blur->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Blur->setIconSize(QSize(20, 20));
        Crop = new QPushButton(centralwidget);
        Crop->setObjectName("Crop");
        Crop->setGeometry(QRect(880, 280, 221, 61));
        sizePolicy1.setHeightForWidth(Crop->sizePolicy().hasHeightForWidth());
        Crop->setSizePolicy(sizePolicy1);
        Crop->setFont(font4);
        Crop->setCursor(QCursor(Qt::PointingHandCursor));
        Crop->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Crop->setIconSize(QSize(20, 20));
        GrayScale = new QPushButton(centralwidget);
        GrayScale->setObjectName("GrayScale");
        GrayScale->setGeometry(QRect(880, 100, 221, 61));
        sizePolicy1.setHeightForWidth(GrayScale->sizePolicy().hasHeightForWidth());
        GrayScale->setSizePolicy(sizePolicy1);
        GrayScale->setFont(font4);
        GrayScale->setCursor(QCursor(Qt::PointingHandCursor));
        GrayScale->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-left-color: rgb(250, 249, 246);\n"
"border-top-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(255, 255, 255);\n"
"background-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        GrayScale->setIconSize(QSize(20, 20));
        Premiumedge = new QPushButton(centralwidget);
        Premiumedge->setObjectName("Premiumedge");
        Premiumedge->setGeometry(QRect(990, 340, 111, 61));
        sizePolicy1.setHeightForWidth(Premiumedge->sizePolicy().hasHeightForWidth());
        Premiumedge->setSizePolicy(sizePolicy1);
        Premiumedge->setFont(font4);
        Premiumedge->setCursor(QCursor(Qt::PointingHandCursor));
        Premiumedge->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Premiumedge->setIconSize(QSize(20, 20));
        InvertColors = new QPushButton(centralwidget);
        InvertColors->setObjectName("InvertColors");
        InvertColors->setGeometry(QRect(880, 640, 221, 61));
        sizePolicy1.setHeightForWidth(InvertColors->sizePolicy().hasHeightForWidth());
        InvertColors->setSizePolicy(sizePolicy1);
        InvertColors->setFont(font4);
        InvertColors->setCursor(QCursor(Qt::PointingHandCursor));
        InvertColors->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(255, 255, 255);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"border-bottom-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        InvertColors->setIconSize(QSize(20, 20));
        FlipImage = new QPushButton(centralwidget);
        FlipImage->setObjectName("FlipImage");
        FlipImage->setGeometry(QRect(880, 160, 221, 61));
        sizePolicy1.setHeightForWidth(FlipImage->sizePolicy().hasHeightForWidth());
        FlipImage->setSizePolicy(sizePolicy1);
        FlipImage->setFont(font4);
        FlipImage->setCursor(QCursor(Qt::PointingHandCursor));
        FlipImage->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        FlipImage->setIconSize(QSize(20, 20));
        RotateImage = new QPushButton(centralwidget);
        RotateImage->setObjectName("RotateImage");
        RotateImage->setGeometry(QRect(1100, 220, 221, 61));
        sizePolicy1.setHeightForWidth(RotateImage->sizePolicy().hasHeightForWidth());
        RotateImage->setSizePolicy(sizePolicy1);
        RotateImage->setFont(font4);
        RotateImage->setCursor(QCursor(Qt::PointingHandCursor));
        RotateImage->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        RotateImage->setIconSize(QSize(20, 20));
        Infrared = new QPushButton(centralwidget);
        Infrared->setObjectName("Infrared");
        Infrared->setGeometry(QRect(1100, 520, 221, 61));
        sizePolicy1.setHeightForWidth(Infrared->sizePolicy().hasHeightForWidth());
        Infrared->setSizePolicy(sizePolicy1);
        Infrared->setFont(font4);
        Infrared->setCursor(QCursor(Qt::PointingHandCursor));
        Infrared->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Infrared->setIconSize(QSize(20, 20));
        AddFrame = new QPushButton(centralwidget);
        AddFrame->setObjectName("AddFrame");
        AddFrame->setGeometry(QRect(1100, 280, 221, 61));
        sizePolicy1.setHeightForWidth(AddFrame->sizePolicy().hasHeightForWidth());
        AddFrame->setSizePolicy(sizePolicy1);
        AddFrame->setFont(font4);
        AddFrame->setCursor(QCursor(Qt::PointingHandCursor));
        AddFrame->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        AddFrame->setIconSize(QSize(20, 20));
        Resize = new QPushButton(centralwidget);
        Resize->setObjectName("Resize");
        Resize->setGeometry(QRect(1100, 340, 221, 61));
        sizePolicy1.setHeightForWidth(Resize->sizePolicy().hasHeightForWidth());
        Resize->setSizePolicy(sizePolicy1);
        Resize->setFont(font4);
        Resize->setCursor(QCursor(Qt::PointingHandCursor));
        Resize->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Resize->setIconSize(QSize(20, 20));
        BlackWhite = new QPushButton(centralwidget);
        BlackWhite->setObjectName("BlackWhite");
        BlackWhite->setGeometry(QRect(1100, 100, 221, 61));
        sizePolicy1.setHeightForWidth(BlackWhite->sizePolicy().hasHeightForWidth());
        BlackWhite->setSizePolicy(sizePolicy1);
        BlackWhite->setFont(font4);
        BlackWhite->setCursor(QCursor(Qt::PointingHandCursor));
        BlackWhite->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(255, 255, 255);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"border-top-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        BlackWhite->setIconSize(QSize(20, 20));
        OldTV = new QPushButton(centralwidget);
        OldTV->setObjectName("OldTV");
        OldTV->setGeometry(QRect(1100, 460, 221, 61));
        sizePolicy1.setHeightForWidth(OldTV->sizePolicy().hasHeightForWidth());
        OldTV->setSizePolicy(sizePolicy1);
        OldTV->setFont(font4);
        OldTV->setCursor(QCursor(Qt::PointingHandCursor));
        OldTV->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        OldTV->setIconSize(QSize(20, 20));
        MergeImages = new QPushButton(centralwidget);
        MergeImages->setObjectName("MergeImages");
        MergeImages->setGeometry(QRect(1100, 160, 221, 61));
        sizePolicy1.setHeightForWidth(MergeImages->sizePolicy().hasHeightForWidth());
        MergeImages->setSizePolicy(sizePolicy1);
        MergeImages->setFont(font4);
        MergeImages->setCursor(QCursor(Qt::PointingHandCursor));
        MergeImages->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        MergeImages->setIconSize(QSize(20, 20));
        Sunlight = new QPushButton(centralwidget);
        Sunlight->setObjectName("Sunlight");
        Sunlight->setGeometry(QRect(1100, 400, 221, 61));
        sizePolicy1.setHeightForWidth(Sunlight->sizePolicy().hasHeightForWidth());
        Sunlight->setSizePolicy(sizePolicy1);
        Sunlight->setFont(font4);
        Sunlight->setCursor(QCursor(Qt::PointingHandCursor));
        Sunlight->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Sunlight->setIconSize(QSize(20, 20));
        Saltpeppernoise = new QPushButton(centralwidget);
        Saltpeppernoise->setObjectName("Saltpeppernoise");
        Saltpeppernoise->setGeometry(QRect(1100, 580, 221, 61));
        sizePolicy1.setHeightForWidth(Saltpeppernoise->sizePolicy().hasHeightForWidth());
        Saltpeppernoise->setSizePolicy(sizePolicy1);
        Saltpeppernoise->setFont(font4);
        Saltpeppernoise->setCursor(QCursor(Qt::PointingHandCursor));
        Saltpeppernoise->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Saltpeppernoise->setIconSize(QSize(20, 20));
        Lighten = new QPushButton(centralwidget);
        Lighten->setObjectName("Lighten");
        Lighten->setGeometry(QRect(880, 220, 111, 61));
        sizePolicy1.setHeightForWidth(Lighten->sizePolicy().hasHeightForWidth());
        Lighten->setSizePolicy(sizePolicy1);
        Lighten->setFont(font4);
        Lighten->setCursor(QCursor(Qt::PointingHandCursor));
        Lighten->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Lighten->setIconSize(QSize(20, 20));
        Darken = new QPushButton(centralwidget);
        Darken->setObjectName("Darken");
        Darken->setGeometry(QRect(990, 220, 111, 61));
        sizePolicy1.setHeightForWidth(Darken->sizePolicy().hasHeightForWidth());
        Darken->setSizePolicy(sizePolicy1);
        Darken->setFont(font4);
        Darken->setCursor(QCursor(Qt::PointingHandCursor));
        Darken->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-bottom-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Darken->setIconSize(QSize(20, 20));
        Clear = new QPushButton(centralwidget);
        Clear->setObjectName("Clear");
        Clear->setGeometry(QRect(300, 100, 121, 41));
        sizePolicy.setHeightForWidth(Clear->sizePolicy().hasHeightForWidth());
        Clear->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(true);
        Clear->setFont(font5);
        Clear->setCursor(QCursor(Qt::PointingHandCursor));
        Clear->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 3px solid;\n"
"border-left-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-top-color: rgb(250, 249, 246);\n"
"border-bottom-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);"));
        Load = new QPushButton(centralwidget);
        Load->setObjectName("Load");
        Load->setGeometry(QRect(60, 100, 121, 41));
        sizePolicy.setHeightForWidth(Load->sizePolicy().hasHeightForWidth());
        Load->setSizePolicy(sizePolicy);
        Load->setFont(font5);
        Load->setCursor(QCursor(Qt::PointingHandCursor));
        Load->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 3px solid;\n"
"border-right-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"border-top-color: rgb(250, 249, 246);\n"
"border-bottom-color: rgb(250, 249, 246);"));
        Load->setIconSize(QSize(20, 35));
        undo = new QPushButton(centralwidget);
        undo->setObjectName("undo");
        undo->setGeometry(QRect(520, 100, 121, 41));
        sizePolicy.setHeightForWidth(undo->sizePolicy().hasHeightForWidth());
        undo->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font6.setPointSize(12);
        font6.setBold(true);
        undo->setFont(font6);
        undo->setCursor(QCursor(Qt::PointingHandCursor));
        undo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 3px solid;\n"
"background-color: rgb(250, 249, 246);\n"
"border-left-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-top-color: rgb(250, 249, 246);\n"
"border-bottom-color: rgb(250, 249, 246);\n"
"\n"
"\n"
""));
        redo = new QPushButton(centralwidget);
        redo->setObjectName("redo");
        redo->setGeometry(QRect(640, 100, 121, 41));
        sizePolicy.setHeightForWidth(redo->sizePolicy().hasHeightForWidth());
        redo->setSizePolicy(sizePolicy);
        redo->setFont(font6);
        redo->setCursor(QCursor(Qt::PointingHandCursor));
        redo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 3px solid;\n"
"border-left-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-top-color: rgb(250, 249, 246);\n"
"border-bottom-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
""));
        Save = new QPushButton(centralwidget);
        Save->setObjectName("Save");
        Save->setGeometry(QRect(180, 100, 121, 41));
        sizePolicy.setHeightForWidth(Save->sizePolicy().hasHeightForWidth());
        Save->setSizePolicy(sizePolicy);
        Save->setFont(font5);
        Save->setCursor(QCursor(Qt::PointingHandCursor));
        Save->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(0, 0, 0);\n"
"border: 3px solid;\n"
"border-right-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-top-color: rgb(250, 249, 246);\n"
"border-bottom-color: rgb(250, 249, 246);"));
        Save->setIconSize(QSize(20, 35));
        version = new QLabel(centralwidget);
        version->setObjectName("version");
        version->setGeometry(QRect(20, 690, 101, 91));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font7.setPointSize(24);
        font7.setBold(true);
        font7.setItalic(true);
        version->setFont(font7);
        version->setStyleSheet(QString::fromUtf8("color: rgb(0, 121, 188);\n"
"shadow: 5px 5px 5px rgp(0,0,0);"));
        version->setFrameShadow(QFrame::Raised);
        version->setLineWidth(1);
        version->setMidLineWidth(0);
        applymirror = new QPushButton(centralwidget);
        applymirror->setObjectName("applymirror");
        applymirror->setGeometry(QRect(590, 600, 121, 41));
        applymirror->setFont(font2);
        applymirror->setCursor(QCursor(Qt::PointingHandCursor));
        applymirror->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        label_mirror = new QLabel(centralwidget);
        label_mirror->setObjectName("label_mirror");
        label_mirror->setGeometry(QRect(80, 550, 171, 20));
        label_mirror->setCursor(QCursor(Qt::ArrowCursor));
        label_mirror->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
""));
        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(270, 550, 242, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        up = new QRadioButton(layoutWidget5);
        up->setObjectName("up");
        up->setCursor(QCursor(Qt::PointingHandCursor));
        up->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout->addWidget(up);

        down = new QRadioButton(layoutWidget5);
        down->setObjectName("down");
        down->setCursor(QCursor(Qt::PointingHandCursor));
        down->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout->addWidget(down);

        right = new QRadioButton(layoutWidget5);
        right->setObjectName("right");
        right->setCursor(QCursor(Qt::PointingHandCursor));
        right->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout->addWidget(right);

        left = new QRadioButton(layoutWidget5);
        left->setObjectName("left");
        left->setCursor(QCursor(Qt::PointingHandCursor));
        left->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 9pt \"Sitka Text Semibold\";\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));

        horizontalLayout->addWidget(left);

        Mirror = new QPushButton(centralwidget);
        Mirror->setObjectName("Mirror");
        Mirror->setGeometry(QRect(1100, 640, 221, 61));
        sizePolicy1.setHeightForWidth(Mirror->sizePolicy().hasHeightForWidth());
        Mirror->setSizePolicy(sizePolicy1);
        Mirror->setFont(font4);
        Mirror->setCursor(QCursor(Qt::PointingHandCursor));
        Mirror->setStyleSheet(QString::fromUtf8("border: 3px solid;\n"
"border-top-color: rgb(0, 121, 188);\n"
"border-left-color: rgb(0, 121, 188);\n"
"background-color: rgb(250, 249, 246);\n"
"border-right-color: rgb(250, 249, 246);\n"
"border-bottom-color: rgb(250, 249, 246);\n"
"color: rgb(9, 9, 9);\n"
"\n"
"\n"
""));
        Mirror->setIconSize(QSize(20, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 8, 31, 51));
        label_2->setFont(font7);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 121, 188);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 8, 61, 51));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font8.setPointSize(22);
        font8.setBold(true);
        font8.setItalic(true);
        label_4->setFont(font8);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(66, 66, 66);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(140, 8, 31, 51));
        label_5->setFont(font7);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 121, 188);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(160, 8, 181, 51));
        label_6->setFont(font8);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(66, 66, 66);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 60, 1361, 41));
        label_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(201, 201, 201, 255), stop:1 rgba(251, 249, 246, 255));"));
        Mode = new QPushButton(centralwidget);
        Mode->setObjectName("Mode");
        Mode->setGeometry(QRect(1070, 10, 121, 41));
        Mode->setFont(font2);
        Mode->setCursor(QCursor(Qt::PointingHandCursor));
        Mode->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);\n"
"background-color:rgb(89, 176, 227);"));
        frameColor = new QPushButton(centralwidget);
        frameColor->setObjectName("frameColor");
        frameColor->setGeometry(QRect(500, 610, 151, 41));
        frameColor->setFont(font2);
        frameColor->setCursor(QCursor(Qt::PointingHandCursor));
        frameColor->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"color: rgb(9, 9, 9);\n"
"border-radius: 7px;\n"
"box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);"));
        degree = new QLabel(centralwidget);
        degree->setObjectName("degree");
        degree->setGeometry(QRect(430, 660, 41, 21));
        Logo = new QLabel(centralwidget);
        Logo->setObjectName("Logo");
        Logo->setGeometry(QRect(10, 9, 41, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "After", nullptr));
        Edited_img->setText(QString());
        Loaded_img->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Before", nullptr));
        applyLighten->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        applyDarken->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        applyFlip->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        flipDir->setItemText(0, QCoreApplication::translate("MainWindow", "Horizontally", nullptr));
        flipDir->setItemText(1, QCoreApplication::translate("MainWindow", "Vertically", nullptr));

        rotDeg->setItemText(0, QCoreApplication::translate("MainWindow", "Rotate by 90 deg", nullptr));
        rotDeg->setItemText(1, QCoreApplication::translate("MainWindow", "Rotate by 180 deg", nullptr));
        rotDeg->setItemText(2, QCoreApplication::translate("MainWindow", "Rotate br 270 deg", nullptr));

        applyRot->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        mrgarea->setItemText(0, QCoreApplication::translate("MainWindow", "Merge the common area", nullptr));
        mrgarea->setItemText(1, QCoreApplication::translate("MainWindow", "Resize the smaller image, then merge", nullptr));
        mrgarea->setItemText(2, QCoreApplication::translate("MainWindow", "Resize both to the bigger of dimensions, then merge", nullptr));

        applyMerge->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        apply_resize->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        applyBlur->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        label_width->setText(QCoreApplication::translate("MainWindow", "Enter the width", nullptr));
        label_height->setText(QCoreApplication::translate("MainWindow", "Enter the height", nullptr));
        applycrop->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        crop_width->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        crop_height->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        label_style->setText(QCoreApplication::translate("MainWindow", "Choose a style:", nullptr));
        apply_frame->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        simple->setText(QCoreApplication::translate("MainWindow", "Simple", nullptr));
        fancy->setText(QCoreApplication::translate("MainWindow", "Fancy", nullptr));
        applySkew->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        label_thick->setText(QCoreApplication::translate("MainWindow", "Thickness:", nullptr));
        Info->setText(QString());
        comboBox_resizehow->setItemText(0, QCoreApplication::translate("MainWindow", "Enter dimensions", nullptr));
        comboBox_resizehow->setItemText(1, QCoreApplication::translate("MainWindow", "Enter ratio", nullptr));

        apply_chooseresize->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        back_resize->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_ratio->setText(QCoreApplication::translate("MainWindow", "Choose the ratio:", nullptr));
        quartre->setText(QCoreApplication::translate("MainWindow", "1/4", nullptr));
        third->setText(QCoreApplication::translate("MainWindow", "1/3", nullptr));
        half->setText(QCoreApplication::translate("MainWindow", "1/2", nullptr));
        one->setText(QCoreApplication::translate("MainWindow", "1/1", nullptr));
        two->setText(QCoreApplication::translate("MainWindow", "2/1", nullptr));
        three->setText(QCoreApplication::translate("MainWindow", "3/1", nullptr));
        four->setText(QCoreApplication::translate("MainWindow", "4/1", nullptr));
        label_imagewidth->setText(QString());
        label_imageheight->setText(QString());
        x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        DetectEdges->setText(QCoreApplication::translate("MainWindow", "Detect Edges", nullptr));
        Skewing->setText(QCoreApplication::translate("MainWindow", "Skewing Image", nullptr));
        Purple->setText(QCoreApplication::translate("MainWindow", "Purple Light Image", nullptr));
        OilPainting->setText(QCoreApplication::translate("MainWindow", "Oil Painting Image", nullptr));
        Blur->setText(QCoreApplication::translate("MainWindow", "Blur Image", nullptr));
        Crop->setText(QCoreApplication::translate("MainWindow", "Crop Image", nullptr));
        GrayScale->setText(QCoreApplication::translate("MainWindow", "Gray Scale", nullptr));
        Premiumedge->setText(QCoreApplication::translate("MainWindow", "Pro Detect", nullptr));
        InvertColors->setText(QCoreApplication::translate("MainWindow", "Invert Colors", nullptr));
        FlipImage->setText(QCoreApplication::translate("MainWindow", "Flip Image", nullptr));
        RotateImage->setText(QCoreApplication::translate("MainWindow", "Rotate Image", nullptr));
        Infrared->setText(QCoreApplication::translate("MainWindow", " Infrared Photography Image", nullptr));
        AddFrame->setText(QCoreApplication::translate("MainWindow", "Add a Frame", nullptr));
        Resize->setText(QCoreApplication::translate("MainWindow", "Resize Image", nullptr));
        BlackWhite->setText(QCoreApplication::translate("MainWindow", "Black and White Image", nullptr));
        OldTV->setText(QCoreApplication::translate("MainWindow", "Old TV Image", nullptr));
        MergeImages->setText(QCoreApplication::translate("MainWindow", "Merge Images", nullptr));
        Sunlight->setText(QCoreApplication::translate("MainWindow", "Sun Light Image", nullptr));
        Saltpeppernoise->setText(QCoreApplication::translate("MainWindow", "Salt and Pepper Noise", nullptr));
        Lighten->setText(QCoreApplication::translate("MainWindow", "Lighten ", nullptr));
        Darken->setText(QCoreApplication::translate("MainWindow", "Darken", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        Load->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        undo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        redo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        version->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">V 1.3</span></p></body></html>", nullptr));
        applymirror->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        label_mirror->setText(QCoreApplication::translate("MainWindow", "Choose the part to mirror:", nullptr));
        up->setText(QCoreApplication::translate("MainWindow", "up", nullptr));
        down->setText(QCoreApplication::translate("MainWindow", "down", nullptr));
        right->setText(QCoreApplication::translate("MainWindow", "right", nullptr));
        left->setText(QCoreApplication::translate("MainWindow", "left", nullptr));
        Mirror->setText(QCoreApplication::translate("MainWindow", "Mirror Image", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "aby", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "hotoshop", nullptr));
        label_7->setText(QString());
        Mode->setText(QString());
        frameColor->setText(QCoreApplication::translate("MainWindow", "Choose a color", nullptr));
        degree->setText(QString());
        Logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
