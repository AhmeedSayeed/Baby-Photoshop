/*
 * FCAI-CU – Structured Programming – 2024 - Assignment 3 - Part 3
 * Program Name: CS112_A3_Part3_S18_20230021_20230444_20230586.cpp
 * Program Description: This is a Baby Photoshop. It takes an image from the user, applies a filter or more on it, and saves the new image if needed.
 *                      This part includes 18 filters + 3 extra filters: (mirror - salt and pepper noise - pro edge detector).
 *

 * Last Modification Date: 17/4/2024

 * Author1 and ID and Group: Ahmed Sayed Ahmed, 20230021, S18
 * Author2 and ID and Group: Noureldin Mohamed Amin, 20230444, S18
 * Author3 and ID and Group: Salsabil Bahaaeldin Rohaiem, 20230586, S18

 * Who did what:
 * The main function was distributed between us.
 * In filters:
   Ahmed: Grayscale, merge images, Darken, Lighten, edge detector, pro edge detector,  sunlight, infrared photography.
   Noureldin: Black and white, flip image, Crop, resize, oil painting, image skewing, mirror.
   Salsabil: Invert image, rotate, frame, blur, TV noise, salt and pepper noise, purple, mirror.
 * In the GUI:
   Ahmed: grayscale, black and white, edge detector, pro edge detector, blur, infrared photography, sunlight, purple,
          rotate, invert colors, flip, load, redo buttons. Show image & GUI design.
   Noureldin: redo, undo, dark mode, merge, lighten, darken, mirror, TV noise, salt and pepper noise, skew, resize,
              crop, oil painting, frame buttons, and shortcuts.
   Salsabil: contributed to GUI Design.

   * Documents:
     Salsabil: did all of it

 * Teaching Assistant: Eng. Ahmed Lotfy
 * System design: https://drive.google.com/file/d/1LNBbq697i8JFA58ojfiKUmMJvORrV484/view?usp=drive_link
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qmessagebox>
#include <QFileDialog>
#include <QSlider>
#include <QDir>
#include <QApplication>
#include <QPixmap>
#include <QImage>
#include <QFile>
#include "Image_Class.h"
#include <QGraphicsDropShadowEffect>
#include <QShortcut>
#include <QColor>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setButtonIcon();
    ui->horizontalSliderdarken->setVisible(false);
    ui->horizontalSliderLighten->setVisible(false);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->applyLighten->setVisible(false);
    ui->applyDarken->setVisible(false);
    ui->flipDir->setVisible(false);
    ui->applyFlip->setVisible(false);
    ui->rotDeg->setVisible(false);
    ui->applyRot->setVisible(false);
    ui->mrgarea->setVisible(false);
    ui->applyMerge->setVisible(false);
    ui->lineEdit_width->setVisible(false);
    ui->lineEdit_height->setVisible(false);
    ui->label_width->setVisible(false);
    ui->label_height->setVisible(false);
    ui->apply_resize->setVisible(false);
    ui->blurlvl->setVisible(false);
    ui->applyBlur->setVisible(false);
    ui->x->setVisible(false);
    ui->y->setVisible(false);
    ui->lineEdit_x->setVisible(false);
    ui->lineEdit_y->setVisible(false);
    ui->lineEdit_cropw->setVisible(false);
    ui->lineEdit_croph->setVisible(false);
    ui->crop_width->setVisible(false);
    ui->crop_height->setVisible(false);
    ui->applycrop->setVisible(false);
    ui->simple->setVisible(false);
    ui->fancy->setVisible(false);
    ui->apply_frame->setVisible(false);
    ui->label_style->setVisible(false);
    ui->label_thick->setVisible(false);
    ui->horizontalSlider_thick->setVisible(false);
    ui->horizontalSlider_thick->setValue(0);
    ui->simple->setChecked(false);
    ui->fancy->setChecked(false);
    ui->applySkew->setVisible(false);
    ui->skewDeg->setVisible(false);
    ui->comboBox_resizehow->setVisible(false);
    ui->apply_chooseresize->setVisible(false);
    ui->back_resize->setVisible(false);
    ui->label_ratio->setVisible(false);
    ui->quartre->setVisible(false);
    ui->third->setVisible(false);
    ui->half->setVisible(false);
    ui->one->setVisible(false);
    ui->two->setVisible(false);
    ui->three->setVisible(false);
    ui->four->setVisible(false);
    ui->label_imagewidth->setVisible(false);
    ui->label_imageheight->setVisible(false);
    ui->undo->setVisible(false);
    ui->redo->setVisible(false);
    ui->up->setVisible(false);
    ui->down->setVisible(false);
    ui->right->setVisible(false);
    ui->left->setVisible(false);
    ui->label_mirror->setVisible(false);
    ui->applymirror->setVisible(false);
    ui->frameColor->setVisible(false);


    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    ui->Loaded_img->setText("Load an Image!");
    ui->Edited_img->setText("Apply a filter to show the result!");
    ui->Loaded_img->setAlignment(Qt::AlignCenter);
    ui->Edited_img->setAlignment(Qt::AlignCenter);

    ui->Load->installEventFilter(this);
    ui->Save->installEventFilter(this);
    ui->Clear->installEventFilter(this);
    ui->undo->installEventFilter(this);
    ui->redo->installEventFilter(this);
    ui->GrayScale->installEventFilter(this);
    ui->InvertColors->installEventFilter(this);
    ui->FlipImage->installEventFilter(this);
    ui->Lighten->installEventFilter(this);
    ui->Darken->installEventFilter(this);
    ui->Crop->installEventFilter(this);
    ui->DetectEdges->installEventFilter(this);
    ui->Blur->installEventFilter(this);
    ui->OilPainting->installEventFilter(this);
    ui->Purple->installEventFilter(this);
    ui->Skewing->installEventFilter(this);
    ui->Premiumedge->installEventFilter(this);
    ui->BlackWhite->installEventFilter(this);
    ui->MergeImages->installEventFilter(this);
    ui->RotateImage->installEventFilter(this);
    ui->AddFrame->installEventFilter(this);
    ui->Resize->installEventFilter(this);
    ui->Sunlight->installEventFilter(this);
    ui->OldTV->installEventFilter(this);
    ui->Infrared->installEventFilter(this);
    ui->Saltpeppernoise->installEventFilter(this);
    ui->applyBlur->installEventFilter(this);
    ui->applyDarken->installEventFilter(this);
    ui->applyFlip->installEventFilter(this);
    ui->applyLighten->installEventFilter(this);
    ui->applyMerge->installEventFilter(this);
    ui->applyRot->installEventFilter(this);
    ui->applySkew->installEventFilter(this);
    ui->apply_chooseresize->installEventFilter(this);
    ui->apply_frame->installEventFilter(this);
    ui->apply_resize->installEventFilter(this);
    ui->applycrop->installEventFilter(this);
    ui->back_resize->installEventFilter(this);
    ui->Mirror->installEventFilter(this);
    ui->applymirror->installEventFilter(this);

    ui->Mode->setText("Dark Mode");
    QImage modeimg;
    QPixmap modeicon;

    modeimg.load(":/img/dark-mode_6714978.png");

    modeicon = QPixmap::fromImage(modeimg).scaled(25,25);

    ui->Mode->setIcon(QIcon(modeicon));
    ui->Mode->setIconSize(QSize(25,25));


    QShortcut *load = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_L), this);
    connect(load, &QShortcut::activated, ui->Load, &QPushButton::click);

    QShortcut *save = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_S), this);
    connect(save, &QShortcut::activated, ui->Save, &QPushButton::click);

    QShortcut *clear = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_C), this);
    connect(clear, &QShortcut::activated, ui->Clear, &QPushButton::click);

    QShortcut *mode = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_M), this);
    connect(mode, &QShortcut::activated, ui->Mode, &QPushButton::click);

    QShortcut *info = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_I), this);
    connect(info, &QShortcut::activated, ui->Info, &QPushButton::click);

    QShortcut *undo = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z), this);
    connect(undo, &QShortcut::activated, this, &MainWindow::CheckUndo);

    QShortcut *redo = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Y), this);
    connect(redo, &QShortcut::activated, this, &MainWindow::CheckRedo);


    QPixmap logo(":/img/2.png");
    ui->Logo->setPixmap(logo.scaled(ui->Logo->width() , ui->Logo->height()));
}



void MainWindow::CheckUndo() {
    if (ui->undo->isVisible())
    {
        ui->undo->clicked();
    }
}

void MainWindow::CheckRedo() {
    if (ui->redo->isVisible())
    {
        ui->redo->clicked();
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

QString filename;
QString filename2;
std::string imgname;
std::string imgname2;
Image temp;
Image merge;
Image Original;
QImage editedImage;
QImage saveImage;
bool edi_null = 1;
int num_filters = -1;
QVector<std::pair<QImage,int>>imgs;
int undo_count = 0;
int redo_count = 0;
int curr_pos = -1;
bool cum_skew = 0;
bool lightMode = 1;
bool darkMode = 0;


void MainWindow::on_Mode_clicked()
{
    if(lightMode){
        lightMode = 0;
        darkMode = 1;
        ui->Mode->setText("Light Mode");
        QImage modeimg;
        QPixmap modeicon;
        modeimg.load(":/img/light-mode_9937122.png");
        modeicon = QPixmap::fromImage(modeimg).scaled(25,25);
        ui->Mode->setIcon(QIcon(modeicon));
        ui->Mode->setIconSize(QSize(25,25));
        ui->Mode->setStyleSheet("color: rgb(255, 255, 255); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5); background-color:rgb(89, 176, 227);");

        this->setStyleSheet("background-color: rgb(34, 34, 34); color: rgb(255, 255, 255);");

        QPixmap logo(":/img/dark2.png");
        ui->Logo->setPixmap(logo.scaled(ui->Logo->width() , ui->Logo->height()));



        ui->Load->setStyleSheet("color: rgb(250, 249, 246);border: 3px solid;border-right-color: rgb(0, 121, 188);border-top-color: rgb(34, 34, 34);border-left-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");


        ui->Save->setStyleSheet("border: 3px solid;border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-top-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");


        ui->Clear->setStyleSheet("color: rgb(250, 249, 246);border: 3px solid;border-left-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-top-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");


        ui->undo->setStyleSheet("border: 3px solid;color: rgb(250, 249, 246);border-bottom-color: rgb(34, 34, 34);border-left-color: rgb(34, 34, 34);border-top-color: rgb(34, 34, 34);border-right-color: rgb(0, 121, 188);");


        ui->redo->setStyleSheet("color: rgb(250, 249, 246);border: 3px solid;border-left-color: rgb(0, 121, 188);border-top-color: rgb(34, 34, 34);border-right-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");


        ui->GrayScale->setStyleSheet("border: 3px solid;border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-top-color: rgb(34, 34, 34);border-left-color: rgb(34, 34, 34);");


        ui->InvertColors->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(34, 34, 34);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");


        ui->FlipImage->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");


        ui->Lighten->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34)");


        ui->Darken->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);");


        ui->Crop->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");

        ui->Blur->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");

        ui->OilPainting->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");

        ui->DetectEdges->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");

        ui->Purple->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");

        ui->Skewing->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");


        ui->Premiumedge->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);");

        ui->Mirror->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(34, 34, 34);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");


        ui->BlackWhite->setStyleSheet("border: 3px solid;border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-top-color: rgb(34, 34, 34);border-right-color: rgb(34, 34, 34);background-color: rgb(34, 34, 34);");

        ui->MergeImages->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");


        ui->RotateImage->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");

        ui->AddFrame->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");

        ui->Resize->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");

        ui->Sunlight->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");

        ui->OldTV->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");

        ui->Infrared->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");

        ui->Saltpeppernoise->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");

        ui->version->setStyleSheet("color: rgb(89, 176, 227);");

        ui->label->setStyleSheet("color: rgb(89, 176, 227);");

        ui->label_3->setStyleSheet("color: rgb(89, 176, 227);");

        ui->label_2->setStyleSheet("color: rgb(89, 176, 227);");

        ui->label_5->setStyleSheet("color: rgb(89, 176, 227);");

        ui->label_4->setStyleSheet("color: rgb(250, 249, 246);");

        ui->label_6->setStyleSheet("color: rgb(250, 249, 246);");

        ui->label_7->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(34, 34, 34, 255), stop:1 rgba(190, 189, 187, 255));");


        ui->comboBox_resizehow->setStyleSheet("font: 600 9pt \"Sitka Text Semibold\";background-color: rgb(86, 86, 86);color: rgb(250, 249, 246);border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");

        ui->left->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");

        ui->right->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->up->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->down->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->simple->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->fancy->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->quartre->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->third->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->half->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->one->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->two->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->three->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->four->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_width->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_height->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->crop_height->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->crop_width->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_imageheight->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_imagewidth->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_mirror->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_ratio->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_style->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_thick->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->mrgarea->setStyleSheet("font: 600 9pt \"Sitka Text Semibold\";background-color: rgb(86, 86, 86);color: rgb(250, 249, 246);border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->rotDeg->setStyleSheet("font: 600 9pt \"Sitka Text Semibold\";background-color: rgb(86, 86, 86);color: rgb(250, 249, 246);border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->x->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->y->setStyleSheet("color: rgb(250, 249, 246);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->flipDir->setStyleSheet("font: 600 9pt \"Sitka Text Semibold\";background-color: rgb(86, 86, 86);color: rgb(250, 249, 246);border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");


    }
    else{
        lightMode = 1;
        darkMode = 0;

        ui->Mode->setText("Dark Mode");
        QImage modeimg;
        QPixmap modeicon;
        modeimg.load(":/img/dark-mode_6714978.png");
        modeicon = QPixmap::fromImage(modeimg).scaled(25,25);
        ui->Mode->setIcon(QIcon(modeicon));
        ui->Mode->setIconSize(QSize(25,25));
        ui->Mode->setStyleSheet("color: rgb(0, 0, 0); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5); background-color:rgb(89, 176, 227);");


        QPixmap logo(":/img/2.png");
        ui->Logo->setPixmap(logo.scaled(ui->Logo->width() , ui->Logo->height()));

        this->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);");


        ui->Load->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-left-color: rgb(250, 249, 246);border-right-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);");


        ui->Save->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);;border-bottom-color: rgb(250, 249, 246);");


        ui->Clear->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);");


        ui->undo->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);border-left-color: rgb(250, 249, 246);border-right-color: rgb(0, 121, 188);");


        ui->redo->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-left-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);border-right-color: rgb(250, 249, 246);");


        ui->GrayScale->setStyleSheet("border: 3px solid;border-top-color: rgb(250, 249, 246);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");


        ui->InvertColors->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(250, 249, 246);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");


        ui->FlipImage->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");


        ui->Lighten->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");


        ui->Darken->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");


        ui->Crop->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->Blur->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->OilPainting->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->DetectEdges->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->Purple->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->Skewing->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");



        ui->Premiumedge->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->Mirror->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");


        ui->BlackWhite->setStyleSheet("border: 3px solid;border-top-color: rgb(250, 249, 246);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->MergeImages->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");


        ui->RotateImage->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(255, 255, 255);color: rgb(9, 9, 9);");

        ui->AddFrame->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->Resize->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->Sunlight->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->OldTV->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->Infrared->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(255, 255, 255);color: rgb(9, 9, 9);");

        ui->Saltpeppernoise->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");

        ui->version->setStyleSheet("color: rgb(0, 121, 188);");

        ui->label->setStyleSheet("color: rgb(0, 121, 188);");

        ui->label_3->setStyleSheet("color: rgb(0, 121, 188);");

        ui->label_2->setStyleSheet("color: rgb(0, 121, 188);");

        ui->label_5->setStyleSheet("color: rgb(0, 121, 188);");

        ui->label_4->setStyleSheet("color: rgb(66, 66, 66);");

        ui->label_6->setStyleSheet("color: rgb(66, 66, 66);");

        ui->label_7->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(201, 201, 201, 255), stop:1 rgba(251, 249, 246, 255));");




        ui->comboBox_resizehow->setStyleSheet("font: 600 9pt \"Sitka Text Semibold\";background-color: rgb(230, 230, 230);color: rgb(9, 9, 9);border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");

        ui->left->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");

        ui->right->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->up->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->down->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->simple->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->fancy->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->quartre->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->third->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->half->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->one->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->two->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->three->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->four->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_width->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_height->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->crop_height->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->crop_width->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_imageheight->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_imagewidth->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_mirror->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_ratio->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_style->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->label_thick->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->mrgarea->setStyleSheet("font: 600 9pt \"Sitka Text Semibold\";background-color: rgb(230, 230, 230);color: rgb(9, 9, 9);border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->rotDeg->setStyleSheet("font: 600 9pt \"Sitka Text Semibold\";background-color: rgb(230, 230, 230);color: rgb(9, 9, 9);border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->x->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->y->setStyleSheet("color: rgb(0, 0, 0);font: 600 9pt \"Sitka Text Semibold\";border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        ui->flipDir->setStyleSheet("font: 600 9pt \"Sitka Text Semibold\";background-color: rgb(230, 230, 230);color: rgb(9, 9, 9);border-radius: 7px;box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");

    }
}


bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(lightMode == 1)
    {
        if (obj == ui->Load && event->type() == QEvent::Enter) {
            ui->Load->setStyleSheet("background-color: rgb(0,121,188); color: white;border: 3px solid;border-left-color: rgb(250, 249, 246);border-right-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);");
        } else if (obj == ui->Load && event->type() == QEvent::Leave) {
            ui->Load->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-left-color: rgb(250, 249, 246);border-right-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);");
        }

        if (obj == ui->Save && event->type() == QEvent::Enter) {
            ui->Save->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border: 3px solid;border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);;border-bottom-color: rgb(250, 249, 246);");
        } else if (obj == ui->Save && event->type() == QEvent::Leave) {
            ui->Save->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);;border-bottom-color: rgb(250, 249, 246);");
        }


        if (obj == ui->Clear && event->type() == QEvent::Enter) {
            ui->Clear->setStyleSheet("background-color: rgb(242, 41, 61); color: white; border: 3px solid;border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);");
        } else if (obj == ui->Clear && event->type() == QEvent::Leave) {
            ui->Clear->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);");
        }

        if (obj == ui->undo && event->type() == QEvent::Enter) {
            ui->undo->setStyleSheet("background-color: rgb(242, 41, 61); color: white; border: 3px solid;border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);border-left-color: rgb(250, 249, 246);border-right-color: rgb(0, 121, 188);");
        } else if (obj == ui->undo && event->type() == QEvent::Leave) {
            ui->undo->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);border-left-color: rgb(250, 249, 246);border-right-color: rgb(0, 121, 188);");
        }

        if (obj == ui->redo && event->type() == QEvent::Enter) {
            ui->redo->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border: 3px solid;border-left-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);border-right-color: rgb(250, 249, 246);");
        } else if (obj == ui->redo && event->type() == QEvent::Leave) {
            ui->redo->setStyleSheet("background-color: rgb(250, 249, 246);color: rgb(0, 0, 0);border: 3px solid;border-left-color: rgb(0, 121, 188);border-top-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);border-right-color: rgb(250, 249, 246);");
        }

        if (obj == ui->GrayScale && event->type() == QEvent::Enter) {
            ui->GrayScale->setStyleSheet("background-color: rgb(89, 176, 227);; color: white; border: 3px solid;border-top-color: rgb(250, 249, 246);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->GrayScale && event->type() == QEvent::Leave) {
            ui->GrayScale->setStyleSheet("border: 3px solid;border-top-color: rgb(250, 249, 246);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }

        if (obj == ui->InvertColors && event->type() == QEvent::Enter) {
            ui->InvertColors->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(250, 249, 246);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->InvertColors && event->type() == QEvent::Leave) {
            ui->InvertColors->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(250, 249, 246);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }

        if (obj == ui->FlipImage && event->type() == QEvent::Enter) {
            ui->FlipImage->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->FlipImage && event->type() == QEvent::Leave) {
            ui->FlipImage->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }

        if (obj == ui->Lighten && event->type() == QEvent::Enter) {
            ui->Lighten->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->Lighten && event->type() == QEvent::Leave) {
            ui->Lighten->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }

        if (obj == ui->Darken && event->type() == QEvent::Enter) {
            ui->Darken->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);");
        } else if (obj == ui->Darken && event->type() == QEvent::Leave) {
            ui->Darken->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }

        if (obj == ui->Crop && event->type() == QEvent::Enter) {
            ui->Crop->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->Crop && event->type() == QEvent::Leave) {
            ui->Crop->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->Blur && event->type() == QEvent::Enter) {
            ui->Blur->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->Blur && event->type() == QEvent::Leave) {
            ui->Blur->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->OilPainting && event->type() == QEvent::Enter) {
            ui->OilPainting->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->OilPainting && event->type() == QEvent::Leave) {
            ui->OilPainting->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->DetectEdges && event->type() == QEvent::Enter) {
            ui->DetectEdges->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->DetectEdges && event->type() == QEvent::Leave) {
            ui->DetectEdges->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->Purple && event->type() == QEvent::Enter) {
            ui->Purple->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->Purple && event->type() == QEvent::Leave) {
            ui->Purple->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->Skewing && event->type() == QEvent::Enter) {
            ui->Skewing->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);");
        } else if (obj == ui->Skewing && event->type() == QEvent::Leave) {
            ui->Skewing->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(250, 249, 246);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }


        if (obj == ui->Premiumedge && event->type() == QEvent::Enter) {
            ui->Premiumedge->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188)");
        } else if (obj == ui->Premiumedge && event->type() == QEvent::Leave) {
            ui->Premiumedge->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->Mirror && event->type() == QEvent::Enter) {
            ui->Mirror->setStyleSheet("background-color: rgb(89, 176, 227); color: white;border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);");
        } else if (obj == ui->Mirror && event->type() == QEvent::Leave) {
            ui->Mirror->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-bottom-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }

        if (obj == ui->BlackWhite && event->type() == QEvent::Enter) {
            ui->BlackWhite->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(250, 249, 246);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->BlackWhite && event->type() == QEvent::Leave) {
            ui->BlackWhite->setStyleSheet("border: 3px solid;border-top-color: rgb(250, 249, 246);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->MergeImages && event->type() == QEvent::Enter) {
            ui->MergeImages->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->MergeImages && event->type() == QEvent::Leave) {
            ui->MergeImages->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }

        if (obj == ui->RotateImage && event->type() == QEvent::Enter) {
            ui->RotateImage->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->RotateImage && event->type() == QEvent::Leave) {
            ui->RotateImage->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(255, 255, 255);color: rgb(9, 9, 9);");
        }
        if (obj == ui->AddFrame && event->type() == QEvent::Enter) {
            ui->AddFrame->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->AddFrame && event->type() == QEvent::Leave) {
            ui->AddFrame->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->Resize && event->type() == QEvent::Enter) {
            ui->Resize->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->Resize && event->type() == QEvent::Leave) {
            ui->Resize->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->Sunlight && event->type() == QEvent::Enter) {
            ui->Sunlight->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->Sunlight && event->type() == QEvent::Leave) {
            ui->Sunlight->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->OldTV && event->type() == QEvent::Enter) {
            ui->OldTV->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->OldTV && event->type() == QEvent::Leave) {
            ui->OldTV->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }
        if (obj == ui->Infrared && event->type() == QEvent::Enter) {
            ui->Infrared->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->Infrared && event->type() == QEvent::Leave) {
            ui->Infrared->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(255, 255, 255);color: rgb(9, 9, 9);");
        }
        if (obj == ui->Saltpeppernoise && event->type() == QEvent::Enter) {
            ui->Saltpeppernoise->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->Saltpeppernoise && event->type() == QEvent::Leave) {
            ui->Saltpeppernoise->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);background-color: rgb(250, 249, 246);color: rgb(9, 9, 9);");
        }




        if (obj == ui->applyBlur && event->type() == QEvent::Enter) {
            ui->applyBlur->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyBlur && event->type() == QEvent::Leave) {
            ui->applyBlur->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyDarken && event->type() == QEvent::Enter) {
            ui->applyDarken->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyDarken && event->type() == QEvent::Leave) {
            ui->applyDarken->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyFlip && event->type() == QEvent::Enter) {
            ui->applyFlip->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyFlip && event->type() == QEvent::Leave) {
            ui->applyFlip->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyLighten && event->type() == QEvent::Enter) {
            ui->applyLighten->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyLighten && event->type() == QEvent::Leave) {
            ui->applyLighten->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyMerge && event->type() == QEvent::Enter) {
            ui->applyMerge->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyMerge && event->type() == QEvent::Leave) {
            ui->applyMerge->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyRot && event->type() == QEvent::Enter) {
            ui->applyRot->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyRot && event->type() == QEvent::Leave) {
            ui->applyRot->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applySkew && event->type() == QEvent::Enter) {
            ui->applySkew->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applySkew && event->type() == QEvent::Leave) {
            ui->applySkew->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->apply_chooseresize && event->type() == QEvent::Enter) {
            ui->apply_chooseresize->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->apply_chooseresize && event->type() == QEvent::Leave) {
            ui->apply_chooseresize->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->apply_frame && event->type() == QEvent::Enter) {
            ui->apply_frame->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->apply_frame && event->type() == QEvent::Leave) {
            ui->apply_frame->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->apply_resize && event->type() == QEvent::Enter) {
            ui->apply_resize->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->apply_resize && event->type() == QEvent::Leave) {
            ui->apply_resize->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applymirror && event->type() == QEvent::Enter) {
            ui->applymirror->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applymirror && event->type() == QEvent::Leave) {
            ui->applymirror->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applycrop && event->type() == QEvent::Enter) {
            ui->applycrop->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applycrop && event->type() == QEvent::Leave) {
            ui->applycrop->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->back_resize && event->type() == QEvent::Enter) {
            ui->back_resize->setStyleSheet("background-color: rgb(242, 41, 61); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->back_resize && event->type() == QEvent::Leave) {
            ui->back_resize->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
    }
    else
    {

        if (obj == ui->Load && event->type() == QEvent::Enter) {
            ui->Load->setStyleSheet("background-color: rgb(0,121,188); color: white;border: 3px solid;border-right-color: rgb(0, 121, 188);border-top-color: rgb(34, 34, 34);border-left-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");
        } else if (obj == ui->Load && event->type() == QEvent::Leave) {
            ui->Load->setStyleSheet("color: rgb(250, 249, 246);border: 3px solid;border-right-color: rgb(0, 121, 188);border-top-color: rgb(34, 34, 34);border-left-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");
        }

        if (obj == ui->Save && event->type() == QEvent::Enter) {
            ui->Save->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border: 3px solid;border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-top-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");
        } else if (obj == ui->Save && event->type() == QEvent::Leave) {
            ui->Save->setStyleSheet("border: 3px solid;border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-top-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");
        }


        if (obj == ui->Clear && event->type() == QEvent::Enter) {
            ui->Clear->setStyleSheet("background-color: rgb(242, 41, 61); color: white; border: 3px solid;border-left-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-top-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");
        } else if (obj == ui->Clear && event->type() == QEvent::Leave) {
            ui->Clear->setStyleSheet("color: rgb(250, 249, 246);border: 3px solid;border-left-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-top-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");
        }

        if (obj == ui->undo && event->type() == QEvent::Enter) {
            ui->undo->setStyleSheet("background-color: rgb(242, 41, 61); color: white; border: 3px solid;border: 3px solid;color: rgb(250, 249, 246);border-bottom-color: rgb(34, 34, 34);border-left-color: rgb(34, 34, 34);border-top-color: rgb(34, 34, 34);border-right-color: rgb(0, 121, 188);");
        } else if (obj == ui->undo && event->type() == QEvent::Leave) {
            ui->undo->setStyleSheet("border: 3px solid;color: rgb(250, 249, 246);border-bottom-color: rgb(34, 34, 34);border-left-color: rgb(34, 34, 34);border-top-color: rgb(34, 34, 34);border-right-color: rgb(0, 121, 188);");
        }

        if (obj == ui->redo && event->type() == QEvent::Enter) {
            ui->redo->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border: 3px solid;border-left-color: rgb(0, 121, 188);border-top-color: rgb(34, 34, 34);border-right-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");
        } else if (obj == ui->redo && event->type() == QEvent::Leave) {
            ui->redo->setStyleSheet("color: rgb(250, 249, 246);border: 3px solid;border-left-color: rgb(0, 121, 188);border-top-color: rgb(34, 34, 34);border-right-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);");
        }

        if (obj == ui->GrayScale && event->type() == QEvent::Enter) {
            ui->GrayScale->setStyleSheet("background-color: rgb(89, 176, 227);; color: white; border: 3px solid;border-top-color: rgb(34, 34, 34);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->GrayScale && event->type() == QEvent::Leave) {
            ui->GrayScale->setStyleSheet("border: 3px solid;border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-top-color: rgb(34, 34, 34);border-left-color: rgb(34, 34, 34);");
        }

        if (obj == ui->InvertColors && event->type() == QEvent::Enter) {
            ui->InvertColors->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(34, 34, 34);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->InvertColors && event->type() == QEvent::Leave) {
            ui->InvertColors->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(34, 34, 34);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");
        }

        if (obj == ui->FlipImage && event->type() == QEvent::Enter) {
            ui->FlipImage->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->FlipImage && event->type() == QEvent::Leave) {
            ui->FlipImage->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");
        }

        if (obj == ui->Lighten && event->type() == QEvent::Enter) {
            ui->Lighten->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->Lighten && event->type() == QEvent::Leave) {
            ui->Lighten->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34)");
        }

        if (obj == ui->Darken && event->type() == QEvent::Enter) {
            ui->Darken->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);");
        } else if (obj == ui->Darken && event->type() == QEvent::Leave) {
            ui->Darken->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);");
        }

        if (obj == ui->Crop && event->type() == QEvent::Enter) {
            ui->Crop->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->Crop && event->type() == QEvent::Leave) {
            ui->Crop->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");
        }
        if (obj == ui->Blur && event->type() == QEvent::Enter) {
            ui->Blur->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->Blur && event->type() == QEvent::Leave) {
            ui->Blur->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");
        }
        if (obj == ui->OilPainting && event->type() == QEvent::Enter) {
            ui->OilPainting->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->OilPainting && event->type() == QEvent::Leave) {
            ui->OilPainting->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");
        }
        if (obj == ui->DetectEdges && event->type() == QEvent::Enter) {
            ui->DetectEdges->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->DetectEdges && event->type() == QEvent::Leave) {
            ui->DetectEdges->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");
        }
        if (obj == ui->Purple && event->type() == QEvent::Enter) {
            ui->Purple->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->Purple && event->type() == QEvent::Leave) {
            ui->Purple->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");
        }
        if (obj == ui->Skewing && event->type() == QEvent::Enter) {
            ui->Skewing->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-left-color: rgb(34, 34, 34);");
        } else if (obj == ui->Skewing && event->type() == QEvent::Leave) {
            ui->Skewing->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(34, 34, 34);");
        }


        if (obj == ui->Premiumedge && event->type() == QEvent::Enter) {
            ui->Premiumedge->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188)");
        } else if (obj == ui->Premiumedge && event->type() == QEvent::Leave) {
            ui->Premiumedge->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);color: rgb(250, 249, 246);border-left-color: rgb(0, 121, 188);");
        }
        if (obj == ui->Mirror && event->type() == QEvent::Enter) {
            ui->Mirror->setStyleSheet("background-color: rgb(89, 176, 227); color: white;border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-bottom-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);");
        } else if (obj == ui->Mirror && event->type() == QEvent::Leave) {
            ui->Mirror->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(34, 34, 34);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");
        }

        if (obj == ui->BlackWhite && event->type() == QEvent::Enter) {
            ui->BlackWhite->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(34, 34, 34);border-right-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->BlackWhite && event->type() == QEvent::Leave) {
            ui->BlackWhite->setStyleSheet("border: 3px solid;border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-top-color: rgb(34, 34, 34);border-right-color: rgb(34, 34, 34);background-color: rgb(34, 34, 34);");
        }
        if (obj == ui->MergeImages && event->type() == QEvent::Enter) {
            ui->MergeImages->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->MergeImages && event->type() == QEvent::Leave) {
            ui->MergeImages->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");
        }

        if (obj == ui->RotateImage && event->type() == QEvent::Enter) {
            ui->RotateImage->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->RotateImage && event->type() == QEvent::Leave) {
            ui->RotateImage->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");
        }
        if (obj == ui->AddFrame && event->type() == QEvent::Enter) {
            ui->AddFrame->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->AddFrame && event->type() == QEvent::Leave) {
            ui->AddFrame->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");
        }
        if (obj == ui->Resize && event->type() == QEvent::Enter) {
            ui->Resize->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->Resize && event->type() == QEvent::Leave) {
            ui->Resize->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");
        }
        if (obj == ui->Sunlight && event->type() == QEvent::Enter) {
            ui->Sunlight->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->Sunlight && event->type() == QEvent::Leave) {
            ui->Sunlight->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");
        }
        if (obj == ui->OldTV && event->type() == QEvent::Enter) {
            ui->OldTV->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->OldTV && event->type() == QEvent::Leave) {
            ui->OldTV->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");
        }
        if (obj == ui->Infrared && event->type() == QEvent::Enter) {
            ui->Infrared->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->Infrared && event->type() == QEvent::Leave) {
            ui->Infrared->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");
        }
        if (obj == ui->Saltpeppernoise && event->type() == QEvent::Enter) {
            ui->Saltpeppernoise->setStyleSheet("background-color: rgb(89, 176, 227); color: white; border: 3px solid;border-top-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);");
        } else if (obj == ui->Saltpeppernoise && event->type() == QEvent::Leave) {
            ui->Saltpeppernoise->setStyleSheet("border: 3px solid;border-top-color: rgb(0, 121, 188);border-left-color: rgb(0, 121, 188);border-bottom-color: rgb(0, 121, 188);border-right-color: rgb(34, 34, 34);color: rgb(250, 249, 246);");
        }




        if (obj == ui->applyBlur && event->type() == QEvent::Enter) {
            ui->applyBlur->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyBlur && event->type() == QEvent::Leave) {
            ui->applyBlur->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyDarken && event->type() == QEvent::Enter) {
            ui->applyDarken->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyDarken && event->type() == QEvent::Leave) {
            ui->applyDarken->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyFlip && event->type() == QEvent::Enter) {
            ui->applyFlip->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyFlip && event->type() == QEvent::Leave) {
            ui->applyFlip->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyLighten && event->type() == QEvent::Enter) {
            ui->applyLighten->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyLighten && event->type() == QEvent::Leave) {
            ui->applyLighten->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyMerge && event->type() == QEvent::Enter) {
            ui->applyMerge->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyMerge && event->type() == QEvent::Leave) {
            ui->applyMerge->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applyRot && event->type() == QEvent::Enter) {
            ui->applyRot->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applyRot && event->type() == QEvent::Leave) {
            ui->applyRot->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applySkew && event->type() == QEvent::Enter) {
            ui->applySkew->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applySkew && event->type() == QEvent::Leave) {
            ui->applySkew->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->apply_chooseresize && event->type() == QEvent::Enter) {
            ui->apply_chooseresize->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->apply_chooseresize && event->type() == QEvent::Leave) {
            ui->apply_chooseresize->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->apply_frame && event->type() == QEvent::Enter) {
            ui->apply_frame->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->apply_frame && event->type() == QEvent::Leave) {
            ui->apply_frame->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->apply_resize && event->type() == QEvent::Enter) {
            ui->apply_resize->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->apply_resize && event->type() == QEvent::Leave) {
            ui->apply_resize->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applymirror && event->type() == QEvent::Enter) {
            ui->applymirror->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applymirror && event->type() == QEvent::Leave) {
            ui->applymirror->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->applycrop && event->type() == QEvent::Enter) {
            ui->applycrop->setStyleSheet("background-color: rgb(73, 227, 111); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->applycrop && event->type() == QEvent::Leave) {
            ui->applycrop->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }
        if (obj == ui->back_resize && event->type() == QEvent::Enter) {
            ui->back_resize->setStyleSheet("background-color: rgb(242, 41, 61); color: white; border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        } else if (obj == ui->back_resize && event->type() == QEvent::Leave) {
            ui->back_resize->setStyleSheet("background-color: rgb(230, 230, 230); color: rgb(9, 9, 9); border-radius: 7px; box-shadow: 5px 10px 10px rgba(0, 0, 0, 0.5);");
        }

    }
    return QObject::eventFilter(obj, event);
}




void MainWindow::setButtonIcon()
{
    QImage loadimg , saveimg , clearimg , undo , redo;
    QPixmap pxLoad , pxSave , pxClear , pxUndo , pxRedo;

    loadimg.load(":/img/load2.png");
    saveimg.load(":/img/save2.png");
    clearimg.load(":/img/clear2.png");
    undo.load(":/img/undo.png");
    redo.load(":/img/redo.png");

    pxLoad = QPixmap::fromImage(loadimg).scaled(25,25);
    pxSave = QPixmap::fromImage(saveimg).scaled(25,25);
    pxClear = QPixmap::fromImage(clearimg).scaled(25,25);
    pxUndo = QPixmap::fromImage(undo).scaled(25,25);
    pxRedo = QPixmap::fromImage(redo).scaled(25,25);

    ui->Load->setIcon(QIcon(pxLoad));
    ui->Load->setIconSize(QSize(25,25));

    ui->Save->setIcon(QIcon(pxSave));
    ui->Save->setIconSize(QSize(25,25));

    ui->Clear->setIcon(QIcon(pxClear));
    ui->Clear->setIconSize(QSize(25,25));

    ui->undo->setIcon(QIcon(pxUndo));
    ui->undo->setIconSize(QSize(25,25));

    ui->redo->setIcon(QIcon(pxRedo));
    ui->redo->setIconSize(QSize(25,25));
}


void MainWindow::hide()
{
    ui->horizontalSliderdarken->setVisible(false);
    ui->horizontalSliderLighten->setVisible(false);
    ui->applyLighten->setVisible(false);
    ui->applyDarken->setVisible(false);
    ui->flipDir->setVisible(false);
    ui->applyFlip->setVisible(false);
    ui->rotDeg->setVisible(false);
    ui->applyRot->setVisible(false);
    ui->mrgarea->setVisible(false);
    ui->applyMerge->setVisible(false);
    ui->lineEdit_width->setVisible(false);
    ui->lineEdit_height->setVisible(false);
    ui->label_width->setVisible(false);
    ui->label_height->setVisible(false);
    ui->apply_resize->setVisible(false);
    ui->blurlvl->setVisible(false);
    ui->applyBlur->setVisible(false);
    ui->x->setVisible(false);
    ui->y->setVisible(false);
    ui->lineEdit_x->setVisible(false);
    ui->lineEdit_y->setVisible(false);
    ui->lineEdit_cropw->setVisible(false);
    ui->lineEdit_croph->setVisible(false);
    ui->crop_width->setVisible(false);
    ui->crop_height->setVisible(false);
    ui->applycrop->setVisible(false);
    ui->simple->setVisible(false);
    ui->fancy->setVisible(false);
    ui->apply_frame->setVisible(false);
    ui->label_style->setVisible(false);
    ui->label_thick->setVisible(false);
    ui->horizontalSlider_thick->setVisible(false);
    ui->simple->setChecked(false);
    ui->fancy->setChecked(false);
    ui->applySkew->setVisible(false);
    ui->skewDeg->setVisible(false);
    ui->comboBox_resizehow->setVisible(false);
    ui->apply_chooseresize->setVisible(false);
    ui->back_resize->setVisible(false);
    ui->label_ratio->setVisible(false);
    ui->quartre->setVisible(false);
    ui->third->setVisible(false);
    ui->half->setVisible(false);
    ui->one->setVisible(false);
    ui->two->setVisible(false);
    ui->three->setVisible(false);
    ui->four->setVisible(false);
    ui->label_imagewidth->setVisible(false);
    ui->label_imageheight->setVisible(false);
    ui->up->setVisible(false);
    ui->down->setVisible(false);
    ui->right->setVisible(false);
    ui->left->setVisible(false);
    ui->label_mirror->setVisible(false);
    ui->applymirror->setVisible(false);
    ui->frameColor->setVisible(false);
}


void MainWindow::on_Load_clicked()
{

    filename = QFileDialog::getOpenFileName(this,tr("Choose an Image"),"",tr("Images (*.png *.jpg *.jpeg *.bmp)"));
    if(QString::compare(filename,QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            ui->skewDeg->setValue(0);
            ui->blurlvl->setValue(0);
            ui->horizontalSlider_thick->setValue(0);
            ui->lineEdit_width->setText("");
            ui->lineEdit_height->setText("");
            ui->lineEdit_x->setText("");
            ui->lineEdit_y->setText("");
            ui->lineEdit_cropw->setText("");
            ui->lineEdit_croph->setText("");






            ui->Edited_img->setText("Apply a filter to show the result!");
            ui->Edited_img->setAlignment(Qt::AlignCenter);


            image = image.scaled(ui->Loaded_img->width(),ui->Loaded_img->height());
            ui->Loaded_img->setPixmap(QPixmap::fromImage(image));
            imgname = filename.toStdString();
            Image img(imgname);
            Original = img;
            temp = img;
            ui->label_imagewidth->setText("The width of the current image: " + QString::number(temp.width));
            ui->label_imageheight->setText("The height of the current image: " + QString::number(temp.height));
            QFile file("temp.jpg");
            if (file.exists())
                file.remove();
            imgs.clear();
            num_filters = -1;
            undo_count = 0;
            redo_count = 0;
            curr_pos = -1;
        }
    }
}




void MainWindow::on_Save_clicked()
{

    if (ui->Edited_img->pixmap().isNull())
    {
        QMessageBox::warning(this , "Error" , "You should apply a filter to save the image.");
        return;
    }
    filename = QFileDialog::getSaveFileName(this,tr("Save the image"),"",tr("Images (*.png *.jpg *.jpeg *.bmp)"));
    saveImage = imgs[curr_pos].first;
    if (!filename.isEmpty()) {
        if (!saveImage.isNull())
        {
            saveImage.save(filename);
            QMessageBox::information(this , "Save the image" , "Image saved successfully.");
        }
    }
}

void MainWindow::on_Clear_clicked()
{
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    ui->label_imagewidth->setText("The width of the current image: " + QString::number(Original.width));
    ui->label_imageheight->setText("The height of the current image: " + QString::number(Original.height));
    hide();

    cum_skew = 0;
    if (ui->Loaded_img->pixmap().isNull())
    {
        return;
    }
    else
    {
        ui->redo->setVisible(false);
        ui->undo->setVisible(false);
        imgs.clear();
        num_filters = -1;
        undo_count = 0;
        redo_count = 0;
        curr_pos = -1;
        ui->Edited_img->setText("Apply a filter to show the result!");
        ui->Edited_img->setAlignment(Qt::AlignCenter);


        Image img(imgname);
        temp = img;
        QFile file("temp.jpg");
        if (file.exists())
            file.remove();
    }
}


void MainWindow::on_Blur_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->blurlvl->setVisible(true);
    ui->applyBlur->setVisible(true);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);
        ui->blurlvl->setVisible(false);
        ui->applyBlur->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }

}


void MainWindow::on_AddFrame_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->simple->setVisible(true);
    ui->fancy->setVisible(true);
    ui->apply_frame->setVisible(true);
    ui->label_style->setVisible(true);
    ui->frameColor->setVisible(true);
    ui->label_thick->setVisible(true);
    ui->horizontalSlider_thick->setVisible(true);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    ui->horizontalSlider_thick->setValue(0);

    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->simple->setVisible(false);
        ui->fancy->setVisible(false);
        ui->apply_frame->setVisible(false);
        ui->label_style->setVisible(false);
        ui->label_thick->setVisible(false);
        ui->horizontalSlider_thick->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }

}


void MainWindow::on_MergeImages_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->mrgarea->setVisible(true);
    ui->applyMerge->setVisible(true);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->mrgarea->setVisible(false);
        ui->applyMerge->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }

    filename2 = QFileDialog::getOpenFileName(this,tr("Choose an Image"),"",tr("Images (*.png *.jpg *.jpeg *.bmp)"));
    if(QString::compare(filename2,QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename2);
        if(valid)
        {
            imgname2 = filename2.toStdString();
            Image img(imgname2);
            merge = img;
        }
    }
    else
    {
        ui->mrgarea->setVisible(false);
        ui->applyMerge->setVisible(false);
        QMessageBox::warning(this , "Error" , "You must choose a second image to apply merge filter.");
        return;
    }
}


void MainWindow::on_RotateImage_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->rotDeg->setVisible(true);
    ui->applyRot->setVisible(true);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->rotDeg->setVisible(false);
        ui->applyRot->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }
}


void MainWindow::on_Darken_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setVisible(true);
    ui->applyDarken->setVisible(true);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {

        ui->horizontalSliderdarken->setVisible(false);
        ui->horizontalSliderdarken->setValue(0);
        ui->applyDarken->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }
}


void MainWindow::on_Lighten_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderLighten->setVisible(true);
    ui->applyLighten->setVisible(true);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->horizontalSliderLighten->setVisible(false);
        ui->horizontalSliderLighten->setValue(0);
        ui->applyLighten->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }
}



void MainWindow::on_FlipImage_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->flipDir->setVisible(true);
    ui->applyFlip->setVisible(true);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->flipDir->setVisible(false);
        ui->applyFlip->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");   
        return;
    }
}


void MainWindow::on_Skewing_clicked()
{
    hide();
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->applySkew->setVisible(true);
    ui->skewDeg->setVisible(true);
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->applySkew->setVisible(false);
        ui->skewDeg->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }
}


void MainWindow::on_Resize_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->apply_resize->setVisible(true);
    ui->horizontalSlider_thick->setValue(0);
    ui->comboBox_resizehow->setVisible(true);
    ui->apply_chooseresize->setVisible(false);
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->comboBox_resizehow->setVisible(false);
        ui->apply_resize->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }

}


void MainWindow::on_Crop_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->x->setVisible(true);
    ui->y->setVisible(true);
    ui->lineEdit_x->setVisible(true);
    ui->lineEdit_y->setVisible(true);
    ui->lineEdit_cropw->setVisible(true);
    ui->lineEdit_croph->setVisible(true);
    ui->crop_width->setVisible(true);
    ui->crop_height->setVisible(true);
    ui->applycrop->setVisible(true);
    ui->horizontalSlider_thick->setValue(0);
    ui->label_imagewidth->setVisible(true);
    ui->label_imageheight->setVisible(true);
    if(curr_pos >= 0){
        Image curr("temp.jpg");
        ui->label_imagewidth->setText("The width of the current image: " + QString::number(temp.width));
        ui->label_imageheight->setText("The height of the current image: " + QString::number(curr.height));
    }

    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {

        ui->x->setVisible(false);
        ui->y->setVisible(false);
        ui->lineEdit_x->setVisible(false);
        ui->lineEdit_y->setVisible(false);
        ui->lineEdit_cropw->setVisible(false);
        ui->lineEdit_croph->setVisible(false);
        ui->crop_width->setVisible(false);
        ui->crop_height->setVisible(false);
        ui->applycrop->setVisible(false);
        ui->label_imagewidth->setVisible(false);
        ui->label_imageheight->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }

    QMessageBox::information(this , "Notes" , "X and Y point is the position you will start cropping from, Width and Height are the dimensions of the croped image.");

}


void MainWindow::on_GrayScale_clicked()
{
    hide();
    ui->undo->setVisible(true);
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        curr_pos++;
        num_filters++;
        // Loop over each row , column , channel
        for (int i = 0; i < temp.width; ++i)
        {
            for (int j = 0; j < temp.height; ++j)
            {
                // Intialize the avg value
                unsigned int avg = 0;
                for (int k = 0; k < temp.channels; ++k)
                {
                    avg += temp(i,j,k);
                }
                // Calculate avg
                avg /= 3;

                // Set all channels to the average value
                temp.setPixel(i,j,0,avg);
                temp.setPixel(i,j,1,avg);
                temp.setPixel(i,j,2,avg);
            }
        }
        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }

}


void MainWindow::on_BlackWhite_clicked()
{
    hide();
    ui->undo->setVisible(true);
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        curr_pos++;
        num_filters++;
        for (int i = 0; i < temp.width; ++i)
        {
            for (int j = 0; j < temp.height; ++j)
            {
                unsigned int bw = 0;
                for (int k = 0; k < temp.channels; ++k)
                { //image.channels = 3
                    bw += temp(i , j , k);
                }
                // Calculate avg
                bw/=3;
                // Set the light pixels to white and the darken to black
                for (int k = 0; k < 3; ++k) {
                    if (bw > 255/2)
                        temp(i , j , k) = 255;
                    else
                        temp(i , j , k) = 0;
                }
            }
        }

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }


}


void MainWindow::on_InvertColors_clicked()
{
    hide();
    ui->undo->setVisible(true);
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        num_filters++;
        curr_pos++;
        // Loop over each row , column , channel
        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height; ++j) {

                for (int k = 0; k < 3; ++k) { // 3 refers to number of channels (RGB).
                    // For each channel, reverse the color.
                    temp(i, j, k) = 255 - temp(i, j, k);
                }

            }
        }

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }

}


void MainWindow::on_DetectEdges_clicked()
{
    hide();
    ui->undo->setVisible(true);
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);

    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        num_filters++;
        curr_pos++;
        // Set X Matrix and Y Matrix
        int x[3][3] = {{1,0,-1},
                       {2,0,-2},
                       {1,0,-1}};

        int y[3][3] = {{1,2,1},
                       {0,0,0},
                       {-1,-2,-1}};

        for (int i = 0; i < temp.width - 2; ++i)
        {
            for (int j = 0; j < temp.height - 2; ++j)
            {
                // Intialize Treshold
                double sumx = 0, sumy = 0;
                int T = 100;
                for (int k = i; k < 3 + i; ++k)
                {
                    for (int l = j; l < 3 + j; ++l)
                    {
                        // Get the sum of multiply of matrix and the image pixels
                        sumx += (temp(k,l,0) * x[k - i][l - j]);
                        sumy += (temp(k,l,0) * y[k - i][l - j]);
                    }
                }

                float gradient = sqrt((sumx * sumx) + (sumy * sumy)) / 2;
                // Make the pixel white or black depending on T and gradient
                if (gradient > T)
                    for (int k = 0; k < 3; ++k)
                        temp(i, j, k) = 0;
                else
                    for (int k = 0; k < 3; ++k)
                        temp(i, j, k) = 255;

            }
        }

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }


}


void MainWindow::on_Sunlight_clicked()
{
    hide();
    ui->undo->setVisible(true);
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        num_filters++;
        curr_pos++;
        int avg = 0;
        for (int i = 0; i < temp.width; ++i)
        {
            for (int j = 0; j < temp.height; ++j)
            {
                if(temp(i,j,0) + 30 > 255)
                    temp(i,j,0) = 255;
                else
                    temp(i,j,0) += 30;

                if(temp(i,j,1) + 30 > 255)
                    temp(i,j,1) = 255;
                else
                    temp(i,j,1) += 30;

                if(temp(i,j,2) - 30 < 0)
                    temp(i,j,2) = 0;
                else
                    temp(i,j,2) -= 30;

            }
        }

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }

}


void MainWindow::on_OilPainting_clicked()
{
    hide();
    ui->undo->setVisible(true);
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        curr_pos++;
        num_filters++;
        int intensity_level = 2;
        int radius = 2;
        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height; ++j) {

                double red = 0, green = 0, blue = 0;
                int intensity;

                int startX = fmax(i-radius , 0);
                int endX = fmin(i + radius, temp.width - 1);
                int startY = fmax(j - radius, 0);
                int endY = fmin(j + radius, temp.height - 1);


                std::vector <double> R(intensity_level) , G(intensity_level) , B(intensity_level) , count(intensity_level);

                for (int x = startX; x <= endX; ++x) {
                    for (int y = startY; y <= endY; ++y) {
                        red = temp(x , y , 0);
                        green = temp(x , y , 1);
                        blue = temp(x , y , 2);
                        intensity = (int)((double)((red+green+blue)/3)*intensity_level/255.0f);
                        count[intensity]++;
                        R[intensity] += red ;
                        G[intensity] += green ;
                        B[intensity] += blue ;
                    }
                }
                double max_element = count[0];
                int max_index = 0;
                for (int k = 1; k < count.size(); ++k) {
                    if (count[k] > max_element)
                    {
                        max_element = count[k];
                        max_index = k;
                    }
                }
                temp(i, j, 0) = R[max_index] / max_element;
                temp(i, j, 1) = G[max_index] / max_element;
                temp(i, j, 2) = B[max_index] / max_element;

            }
        }


        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }

}


void MainWindow::on_OldTV_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->undo->setVisible(true);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        num_filters++;
        curr_pos++;
        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height; ++j) {

                if (j % 2 == 1) {
                    for (int k = 0; k < 3; ++k) {
                        // Generate random value for the noisy pixel.
                        int randomValue = rand() % 30;
                        temp(i, j, k) = fmin(temp(i, j, k) + randomValue, 255);
                    }
                } else {
                    for (int k = 0; k < 3; ++k) {
                        // Generate random value for the noisy pixel.
                        int randomValue = rand() % 60;
                        temp(i, j, k) = fmax(temp(i, j, k) - randomValue, 0);
                    }
                }
            }
        }

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }

}


void MainWindow::on_Purple_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->undo->setVisible(true);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        num_filters++;
        curr_pos++;
        // Loop over each row, column, channel
        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height; ++j) {

                // Check if the pixel is black.
                if (temp(i, j, 0) == 0 && temp(i, j, 1) == 0 && temp(i, j, 2) == 0) {
                    continue; // Leave black pixels unchanged.
                }

                // Calculate average of RGB
                unsigned int avg = (temp(i, j, 0) + temp(i, j, 1) + temp(i, j, 2)) / 3;

                // Determine brightness based on average RGB value.
                bool isDark = (avg < 185);

                // Adjust color based on brightness.
                if (isDark) {
                    // Make dark pixels less purple.
                    if (temp(i, j, 0) + 20 > 255)
                        temp(i, j, 0) = 255;
                    else
                        temp(i, j, 0) += 20;

                    if (temp(i, j, 1) - 30 < 0)
                        temp(i, j, 1) = 0;
                    else
                        temp(i, j, 1) -= 30;

                    if (temp(i, j, 2) + 15 > 255)
                        temp(i, j, 2) = 255;
                    else
                        temp(i, j, 2) += 15;
                }
                else {
                    // Make light pixels more purple.
                    if (temp(i, j, 0) + 40 > 255)
                        temp(i, j, 0) = 255;
                    else
                        temp(i, j, 0) += 40;

                    if (temp(i, j, 1) - 40 < 0)
                        temp(i, j, 1) = 0;
                    else
                        temp(i, j, 1) -= 40;

                    if (temp(i, j, 2) + 30 > 255)
                        temp(i, j, 2) = 255;
                    else
                        temp(i, j, 2) += 30;
                }
            }
        }

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }

}


void MainWindow::on_Infrared_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->undo->setVisible(true);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        num_filters++;
        curr_pos++;
        // Loop over each row , column , channel and declare the avg
        unsigned int avg;
        for (int i = 0; i < temp.width; ++i)
        {
            for (int j = 0; j < temp.height; ++j)
            {
                // Set the avg to zero
                avg = 0;

                // To get the sum and get the avg
                for (int k = 0; k < temp.channels; ++k)
                {
                    avg += temp(i,j,k);
                }

                // Set the avg
                avg /= 3;

                // Set the red and white correctly
                temp(i, j, 0) = 255;
                temp(i, j, 1) = 255 - avg;
                temp(i, j, 2) = 255 - avg;
            }
        }

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }

}


void MainWindow::on_Premiumedge_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->undo->setVisible(true);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        num_filters++;
        curr_pos++;
        // Set X Matrix and Y Matrix
        int x[3][3] = {{1,0,-1},
                       {2,0,-2},
                       {1,0,-1}};

        int y[3][3] = {{1,2,1},
                       {0,0,0},
                       {-1,-2,-1}};

        // Declare the new image
        Image imageEd(temp.width ,temp.height);

        for (int i = 0; i < temp.width - 2; ++i)
        {
            for (int j = 0; j < temp.height - 2; ++j)
            {
                // Intialize Treshold
                double sumx = 0, sumy = 0;
                int T = 100;
                for (int k = i; k < 3 + i; ++k)
                {
                    for (int l = j; l < 3 + j; ++l)
                    {
                        // Get the sum of multiply of matrix and the image pixels
                        sumx += (temp(i,l,0) * x[k - i][l - j]);
                        sumy += (temp(k,l,0) * y[k - i][l - j]);
                    }
                }

                float gradient = sqrt((sumx * sumx) + (sumy * sumy)) / 2;
                // Make the pixel white or black depending on T and gradient
                if (gradient > T)
                    for (int k = 0; k < 3; ++k)
                        imageEd(i, j, k) = 0;
                else
                    for (int k = 0; k < 3; ++k)
                        imageEd(i, j, k) = 255;

            }
        }
        temp = imageEd;

        // Loop over each row , column , channel
        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height; ++j) {

                for (int k = 0; k < 3; ++k) { // 3 refers to number of channels (RGB).
                    // For each channel, reverse the color.
                    temp(i, j, k) = 255 - temp(i, j, k);
                }

            }
        }

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }


}

void MainWindow::on_Saltpeppernoise_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->blurlvl->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->undo->setVisible(true);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->undo->setVisible(false);

        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
    }
    else
    {
        num_filters++;
        curr_pos++;
        float density = 0.1;
        int noisyPixels = static_cast<int>(temp.width * temp.height * density);

        for (int i = 0; i < noisyPixels; ++i) {

            // Select a random pixel
            int x = rand() % temp.width;
            int y = rand() % temp.height;

            // Generate random gray value for the noisy pixel
            unsigned char grayValue = rand() % 256;

            // Set pixel value to gray
            temp.setPixel(x, y, 0, grayValue);
            temp.setPixel(x, y, 1, grayValue);
            temp.setPixel(x, y, 2, grayValue);
        }

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    }

}


void MainWindow::on_applyDarken_clicked()
{
    ui->undo->setVisible(true);
    num_filters++;
    curr_pos++;
    float ratio = 1-((ui->horizontalSliderdarken->value())/100.0);

    for (int i = 0; i < temp.width; ++i)
    {
        for (int j = 0; j < temp.height; ++j)
        {
            for (int k = 0; k < temp.channels; ++k)
            {
                temp(i,j,k) *= ratio;
            }
        }
    }
    ui->horizontalSliderdarken->setValue(0);
    temp.saveImage("temp.jpg");
    QImage image;
    image.load("temp.jpg");
    imgs.insert(curr_pos,{image,0});
    ui->redo->setVisible(true);
    if(curr_pos == imgs.size() - 1)
        ui->redo->setVisible(false);
    editedImage = image;
    image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
    ui->Edited_img->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_applyLighten_clicked()
{
    ui->undo->setVisible(true);
    num_filters++;
    curr_pos++;
    float ratio = 1+((ui->horizontalSliderLighten->value())/100.0);

    for (int i = 0; i < temp.width; ++i)
    {
        for (int j = 0; j < temp.height; ++j)
        {
            for (int k = 0; k < temp.channels; ++k)
            {
                if(ratio * temp(i,j,k) >= 255)
                    temp(i,j,k) = 255;
                else
                    temp(i,j,k) *= ratio;
            }
        }
    }

    ui->horizontalSliderLighten->setValue(0);
    temp.saveImage("temp.jpg");
    QImage image;
    image.load("temp.jpg");
    imgs.insert(curr_pos,{image,0});
    ui->redo->setVisible(true);
    if(curr_pos == imgs.size() - 1)
        ui->redo->setVisible(false);
    editedImage = image;
    image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
    ui->Edited_img->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_applyFlip_clicked()
{
    ui->undo->setVisible(true);
    num_filters++;
    curr_pos++;
    if (ui->flipDir->currentIndex() == 0)
    {
        for (int i = 0; i < temp.width/2; ++i) {
            for (int j = 0; j < temp.height; ++j) {
                for (int k = 0; k < temp.channels; ++k) {
                    std::swap(temp(i , j , k) , temp(temp.width-i-1 , j , k));
                }
            }
        }
    }
    else if (ui->flipDir->currentIndex() == 1)
    {
        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height/2; ++j) {
                for (int k = 0; k < temp.channels; ++k) {
                    std::swap(temp(i , j , k) , temp(i , temp.height-j-1 , k));
                }
            }
        }
    }

    temp.saveImage("temp.jpg");
    QImage image;
    image.load("temp.jpg");
    imgs.insert(curr_pos,{image,0});
    ui->redo->setVisible(true);
    if(curr_pos == imgs.size() - 1)
        ui->redo->setVisible(false);
    editedImage = image;
    image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
    ui->Edited_img->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_applyRot_clicked()
{
    ui->undo->setVisible(true);
    num_filters++;
    curr_pos++;
    if (ui->rotDeg->currentIndex() == 0) {
        int newHeight = temp.width; // After rotation, the height becomes the old width.
        int newWidth = temp.height; // After rotation, the width becomes the old height.

        Image rotatedImage(newWidth, newHeight);

        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height; ++j) {
                for (int k = 0; k < 3; ++k) { // 3 refers to number of channels (RGB)
                    rotatedImage(temp.height - j - 1, i, k) = temp(i, j, k);
                }
            }
        }
        temp = rotatedImage;
    }
    else if (ui->rotDeg->currentIndex() == 1) {
        // Loop over the upper half of the picture and swap between each pixel in it and in the lower part.
        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height / 2; ++j) {
                for (int k = 0; k < temp.channels; ++k) {
                    std::swap(temp(i, j, k), temp(i, temp.height - j - 1, k));
                }
            }
        }
        for (int i = 0; i < temp.width/2; ++i) {
            for (int j = 0; j < temp.height; ++j) {
                for (int k = 0; k < temp.channels; ++k) {
                    std::swap(temp(i , j , k) , temp(temp.width-i-1 , j , k));
                }
            }
        }

    }
    else if (ui->rotDeg->currentIndex() == 2) {
        int newHeight = temp.width; // After rotation, the height becomes the old width.
        int newWidth = temp.height; // After rotation, the width becomes the old height.

        Image rotatedImage(newWidth, newHeight);

        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height / 2; ++j) {
                for (int k = 0; k < temp.channels; ++k) {
                    std::swap(temp(i, j, k), temp(i, temp.height - j - 1, k));
                }
            }
        }
        for (int i = 0; i < temp.width/2; ++i) {
            for (int j = 0; j < temp.height; ++j) {
                for (int k = 0; k < temp.channels; ++k) {
                    std::swap(temp(i , j , k) , temp(temp.width-i-1 , j , k));
                }
            }
        }
        for (int i = 0; i < temp.width; ++i) {
            for (int j = 0; j < temp.height; ++j) {
                for (int k = 0; k < 3; ++k) { // 3 refers to number of channels (RGB)
                    rotatedImage(temp.height - j - 1, i, k) = temp(i, j, k);
                }
            }
        }

        temp = rotatedImage;
    }

    temp.saveImage("temp.jpg");
    QImage image;
    image.load("temp.jpg");
    imgs.insert(curr_pos,{image,0});
    ui->redo->setVisible(true);
    if(curr_pos == imgs.size() - 1)
        ui->redo->setVisible(false);
    editedImage = image;
    image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
    ui->Edited_img->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_applyMerge_clicked()
{
    ui->undo->setVisible(true);
    num_filters++;
    curr_pos++;
    ui->applyMerge->setVisible(false);
    ui->mrgarea->setVisible(false);
    int n_width , n_height;
    if (ui->mrgarea->currentIndex() == 0)
    {
        n_width = fmin(temp.width,merge.width);
        n_height = fmin(temp.height,merge.height);
    }
    else if (ui->mrgarea->currentIndex() == 1)
    {
        long long area1 = temp.width * temp.height;
        long long area2 = merge.width * merge.height;
        if(area1 < area2)
        {
            n_width = merge.width;
            n_height = merge.height;
            Image image2(n_width , n_height);
            for (int i = 0; i < n_width; ++i)
            {
                for (int j = 0; j < n_height; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        image2(i,j,k) = temp(i * temp.width / n_width,j * temp.height / n_height,k);
                    }
                }
            }
            temp = image2;
        }
        else
        {
            n_width = temp.width;
            n_height = temp.height;
            Image image2(n_width , n_height);
            for (int i = 0; i < n_width; ++i)
            {
                for (int j = 0; j < n_height; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        image2(i,j,k) = merge(i * merge.width / n_width,j * merge.height / n_height,k);
                    }
                }
            }
            merge = image2;
        }
    }
    else if (ui->mrgarea->currentIndex() == 2)
    {
        n_width = fmax(temp.width,merge.width);
        n_height = fmax(temp.height,merge.height);
        Image image2(n_width , n_height);
        for (int i = 0; i < n_width; ++i)
        {
            for (int j = 0; j < n_height; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    image2(i,j,k) = temp(i * temp.width / n_width,j * temp.height / n_height,k);
                }
            }
        }
        temp = image2;

        Image image3(n_width , n_height);
        for (int i = 0; i < n_width; ++i)
        {
            for (int j = 0; j < n_height; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                        image3(i,j,k) = merge(i * merge.width / n_width,j * merge.height / n_height,k);
                }
            }
        }
        merge = image3;
    }

    // Set the image to the min width and the height
    Image imgRs(n_width,n_height);

    for (int i = 0; i < imgRs.width; ++i)
    {
        for (int j = 0; j < imgRs.height; ++j)
        {
            for (int k = 0; k < imgRs.channels; ++k)
            {
                // Set the pixel to half of sum of two coordinate pixels
                imgRs(i,j,k) = (temp(i,j,k) + merge(i,j,k)) / 2;
            }
        }
    }
    temp =imgRs;

    temp.saveImage("temp.jpg");
    QImage image;
    image.load("temp.jpg");
    imgs.insert(curr_pos,{image,0});
    ui->redo->setVisible(true);
    if(curr_pos == imgs.size() - 1)
        ui->redo->setVisible(false);
    editedImage = image;
    image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
    ui->Edited_img->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_apply_resize_clicked()
{
    ui->apply_chooseresize->setVisible(true);
    ui->back_resize->setVisible(true);
    ui->comboBox_resizehow->setVisible(false);
    ui->apply_resize->setVisible(false);
    if(ui->comboBox_resizehow->currentIndex() == 0)
    {
        ui->lineEdit_width->setVisible(true);
        ui->lineEdit_height->setVisible(true);
        ui->label_width->setVisible(true);
        ui->label_height->setVisible(true);
        ui->label_imagewidth->setVisible(true);
        ui->label_imageheight->setVisible(true);
        if(num_filters >= 0){
            Image curr("temp.jpg");
            ui->label_imagewidth->setText("The width of the current image: " + QString::number(temp.width));
            ui->label_imageheight->setText("The height of the current image: " + QString::number(curr.height));
        }
    }
    else if(ui->comboBox_resizehow->currentIndex() == 1)
    {
        ui->label_ratio->setVisible(true);
        ui->quartre->setVisible(true);
        ui->third->setVisible(true);
        ui->half->setVisible(true);
        ui->one->setVisible(true);
        if(curr_pos >= 0){
            Image curr("temp.jpg");
            ui->label_imagewidth->setText("The width of the current image: " + QString::number(curr.width));
            ui->label_imageheight->setText("The height of the current image: " + QString::number(curr.height));
            if(temp.width * temp.height <= 2000 * 2000){
                ui->two->setVisible(true);
                ui->three->setVisible(true);
                ui->four->setVisible(true);
            }
            else if(temp.width * temp.height <= 2500 * 2500){
                ui->two->setVisible(true);
                ui->three->setVisible(true);
            }
            else if(temp.width * temp.height <= 4000 * 4000){
                ui->two->setVisible(true);
            }
        }
        else{
            if(temp.width * temp.height <= 2000 * 2000){
                ui->two->setVisible(true);
                ui->three->setVisible(true);
                ui->four->setVisible(true);
            }
            else if(temp.width * temp.height <= 2500 * 2500){
                ui->two->setVisible(true);
                ui->three->setVisible(true);
            }
            else if(temp.width * temp.height <= 4000 * 4000){
                ui->two->setVisible(true);
            }
        }
    }
}


void MainWindow::on_applyBlur_clicked()
{
    ui->undo->setVisible(true);
    num_filters++;
    curr_pos++;
    int box = ui->blurlvl->value();
    // Compute prefix sums for each channel.
    std::vector<std::vector<std::vector<unsigned long long>>> prefixSum(temp.width + 1, std::vector<std::vector<unsigned long long>>(temp.height + 1, std::vector<unsigned long long>(3, 0)));
    for (int channel = 0; channel < 3; ++channel) {
        for (int i = 1; i <= temp.width; ++i) {
            for (int j = 1; j <= temp.height; ++j) {
                prefixSum[i][j][channel] = temp(i - 1, j - 1, channel) + prefixSum[i - 1][j][channel]
                                           + prefixSum[i][j - 1][channel] - prefixSum[i - 1][j - 1][channel];
            }
        }
    }

    for (int i = 0; i < temp.width; ++i) {
        for (int j = 0; j < temp.height; ++j) {

            unsigned int red = 0, green = 0, blue = 0;

            // Adjust the bounds to ensure the blur operation covers the edges.
            int startX = fmax(i - box, 0);
            int endX = fmin(i + box, temp.width - 1);
            int startY = fmax(j - box, 0);
            int endY = fmin(j + box, temp.height - 1);

            // Compute the sum of pixels in the rectangular area using prefix sums.
            for (int channel = 0; channel < 3; ++channel) {
                unsigned long long sum = prefixSum[endX + 1][endY + 1][channel] - prefixSum[startX][endY + 1][channel]
                                         - prefixSum[endX + 1][startY][channel] + prefixSum[startX][startY][channel];
                if (channel == 0)
                    red = sum;
                else if (channel == 1)
                    green = sum;
                else
                    blue = sum;

            }

            int area = (endX - startX + 1) * (endY - startY + 1);
            unsigned long long avgRed = red / area;
            unsigned long long avgGreen = green / area;
            unsigned long long avgBlue = blue / area;

            temp(i, j, 0) = avgRed;
            temp(i, j, 1) = avgGreen;
            temp(i, j, 2) = avgBlue;
        }
    }

    temp.saveImage("temp.jpg");
    QImage image;
    image.load("temp.jpg");
    imgs.insert(curr_pos,{image,0});
    ui->redo->setVisible(true);
    if(curr_pos == imgs.size() - 1)
        ui->redo->setVisible(false);
    editedImage = image;
    image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
    ui->Edited_img->setPixmap(QPixmap::fromImage(image));
    ui->blurlvl->setValue(0);
}


void MainWindow::on_applycrop_clicked()
{

    QString x = ui->lineEdit_x->text();
    QString y = ui->lineEdit_y->text();
    QString width = ui->lineEdit_cropw->text();
    QString height = ui->lineEdit_croph->text();

    bool flag = 0;
    for(int i = 0; i < width.size(); ++i){
        if(width[i] > '9' || width[i] < '0'){
            flag = 1;
            break;
        }
    }
    for(int i = 0; i < height.size(); ++i){
        if(height[i] > '9' || height[i] < '0'){
            flag = 1;
            break;
        }
    }
    for(int i = 0; i < x.size(); ++i){
        if(x[i] > '9' || x[i] < '0'){
            flag = 1;
            break;
        }
    }
    for(int i = 0; i < y.size(); ++i){
        if(y[i] > '9' || y[i] < '0'){
            flag = 1;
            break;
        }
    }
    if(y == "" || x == "" || width == "" || height == ""){
        flag = 1;
    }

    if(flag){
        ui->lineEdit_x->setText("");
        ui->lineEdit_y->setText("");
        ui->lineEdit_cropw->setText("");
        ui->lineEdit_croph->setText("");
        QMessageBox::warning(this,"Invalid Input","This input is invalid, please enter the input correctly and apply the filter!");
    }
    else
    {
        int n_x = x.toInt();
        int n_y = y.toInt();
        int n_width = width.toInt();
        int n_height = height.toInt();
        if(n_x > temp.width || n_x < 0 || n_width > temp.width || n_width < 0 || n_y > temp.height || n_y < 0 || n_height > temp.height || n_height < 0 || n_x + n_width > temp.width || n_y + n_height > temp.height)
        {
            QMessageBox::warning(this , "Error" , "Your Input does not match with image's dimensions.");
            ui->lineEdit_croph->clear();
            ui->lineEdit_cropw->clear();
            ui->lineEdit_x->clear();
            ui->lineEdit_y->clear();
            return;
        }

        Image image2(n_width , n_height);
        for (int i = n_x; i < n_width+n_x; ++i) {
            for (int j = n_y; j < n_height+n_y; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2(i - n_x , j - n_y , k) = temp(i , j , k);
                }
            }
        }
        num_filters++;
        curr_pos++;
        ui->undo->setVisible(true);


        temp = image2;
        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
        ui->lineEdit_x->setText("");
        ui->lineEdit_y->setText("");
        ui->lineEdit_cropw->setText("");
        ui->lineEdit_croph->setText("");

        if(curr_pos >= 0){
            Image curr("temp.jpg");
            ui->label_imagewidth->setText("The width of the image: " + QString::number(curr.width));
            ui->label_imageheight->setText("The height of the image: " + QString::number(curr.height));
        }
        else{

        }
    }

}

QColor framecolor;
void MainWindow::on_frameColor_clicked()
{
    framecolor = QColorDialog::getColor(Qt::white,this,"Choose frame color");
}

void MainWindow::on_apply_frame_clicked()
{

    if(!(ui->simple->isChecked()) && !(ui->fancy->isChecked())){
        ui->horizontalSlider_thick->setValue(0);
        ui->simple->setChecked(false);
        ui->fancy->setChecked(false);
        QMessageBox::warning(this,"Invalid Input","You should choose the style.");
    }

    else
    {
        int thickness = ui->horizontalSlider_thick->value();

        if (ui->simple->isChecked())
        {
            // Loop over each row and column for the frame.
            for (int i = 0; i < thickness; ++i) {
                for(int j = 0; j < temp.height; ++j) {
                    // Set the color of the pixel.
                    temp.setPixel(i, j, 0, framecolor.red());
                    temp.setPixel(i, j, 1, framecolor.green());
                    temp.setPixel(i, j, 2, framecolor.blue());
                    // Set the color of the corresponding pixel on the opposite side of the image.
                    temp.setPixel(temp.width - i - 1, j, 0, framecolor.red());
                    temp.setPixel(temp.width - i - 1, j, 1, framecolor.green());
                    temp.setPixel(temp.width - i - 1, j, 2, framecolor.blue());
                }
            }

            // Loop over each column and row for the frame.
            for (int j = 0; j < thickness; ++j) {
                for (int i = 0; i < temp.width; ++i) {

                    // Set the color of the pixel.
                    temp.setPixel(i, j, 0, framecolor.red());
                    temp.setPixel(i, j, 1, framecolor.green());
                    temp.setPixel(i, j, 2, framecolor.blue());

                    // Set the color of the corresponding pixel on the opposite side of the image.
                    temp.setPixel(i, temp.height - j - 1, 0, framecolor.red());
                    temp.setPixel(i, temp.height - j - 1, 1, framecolor.green());
                    temp.setPixel(i, temp.height - j - 1, 2, framecolor.blue());
                }
            }
        }
        else if (ui->fancy->isChecked())
        {
            // Loop over each row and column for the frame.
            for (int i = 0; i < thickness; ++i) {
                for(int j = 0; j < temp.height; ++j) {
                    // Set the color of the pixel.
                    temp.setPixel(i, j, 0, framecolor.red());
                    temp.setPixel(i, j, 1, framecolor.green());
                    temp.setPixel(i, j, 2, framecolor.blue());
                    // Set the color of the corresponding pixel on the opposite side of the image.
                    temp.setPixel(temp.width - i - 1, j, 0, framecolor.red());
                    temp.setPixel(temp.width - i - 1, j, 1, framecolor.green());
                    temp.setPixel(temp.width - i - 1, j, 2, framecolor.blue());
                }
            }

            // Loop over each column and row for the frame.
            for (int j = 0; j < thickness; ++j) {
                for (int i = 0; i < temp.width; ++i) {

                    // Set the color of the pixel.
                    temp.setPixel(i, j, 0, framecolor.red());
                    temp.setPixel(i, j, 1, framecolor.green());
                    temp.setPixel(i, j, 2, framecolor.blue());

                    // Set the color of the corresponding pixel on the opposite side of the image.
                    temp.setPixel(i, temp.height - j - 1, 0, framecolor.red());
                    temp.setPixel(i, temp.height - j - 1, 1, framecolor.green());
                    temp.setPixel(i, temp.height - j - 1, 2, framecolor.blue());
                }
            }



            // Draw the vertical white lines.
            for (int i = thickness + 25; i < thickness + 25 + thickness/2; ++i) {

                for(int j = thickness; j < temp.height - thickness; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        temp.setPixel(i, j, k, 250);
                        temp.setPixel(temp.width - i - 1, j, k, 250);

                    }
                }
            }

            for (int i = thickness + 45 + thickness/2; i < 2 * thickness + 45; ++i) {

                for(int j = thickness; j < temp.height - thickness; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        temp.setPixel(i, j, k, 250);
                        temp.setPixel(temp.width - i - 1, j, k, 250);

                    }
                }
            }

            // Draw the horizontal white lines.
            for (int j = thickness + 25; j < thickness + 25 + thickness/2; ++j) {

                for (int i = thickness; i < temp.width - thickness; ++i) {
                    for (int k = 0; k < 3; ++k) {
                        temp.setPixel(i, j, k, 250);
                        temp.setPixel(i, temp.height - j - 1, k, 250);
                    }
                }
            }

            for (int j = thickness + 45 + thickness/2; j < 2*thickness + 45; ++j) {

                for (int i = thickness; i < temp.width - thickness; ++i) {
                    for (int k = 0; k < 3; ++k) {
                        temp.setPixel(i, j, k, 250);
                        temp.setPixel(i, temp.height - j - 1, k, 250);
                    }
                }
            }


        }

        num_filters++;
        curr_pos++;
        ui->undo->setVisible(true);

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
        ui->horizontalSlider_thick->setValue(0);
        ui->simple->setChecked(false);
        ui->fancy->setChecked(false);
    }

}


void MainWindow::on_applySkew_clicked()
{
    curr_pos++;
    QImage intial;
    double d_theta = ui->skewDeg->value();
    if(curr_pos > 0)
        imgs.insert(curr_pos,{intial,imgs[curr_pos - 1].second});
    else
        imgs.insert(curr_pos,{intial,0});
    imgs[curr_pos].second += d_theta;
    if(temp.height * temp.width <= 4000 * 4000){
        if(imgs[curr_pos].second > 70){
            QMessageBox::warning(this,"Error","You crossed the degree limit for this image!");
            imgs.erase(imgs.begin() + curr_pos,imgs.begin() + curr_pos + 1);
            curr_pos--;
            ui->skewDeg->setValue(0);
            return;
        }
    }
    else{
        if(imgs[curr_pos].second > 62){
            QMessageBox::warning(this,"Error","You crossed the degree limit for this image!");
            imgs.erase(imgs.begin() + curr_pos,imgs.begin() + curr_pos + 1);
            curr_pos--;
            ui->skewDeg->setValue(0);
            return;
        }
    }

        cum_skew = 1;
        ui->undo->setVisible(true);
        num_filters++;
        double rad_theta = M_PI * d_theta / 180.0;

        int l = temp.height * tan(rad_theta);
        int n_width = temp.width + l;

        Image image2(n_width , temp.height);

        for (int i = 0; i < image2.width; ++i) {
            for (int j = 0; j < image2.height; ++j) {
                for (int k = 0; k < image2.channels; ++k) {
                    image2(i , j , k) = 255;
                }
            }
        }

        for (int i = l; i < image2.width; ++i) {
            double x = 0;
            for (int j = 0; j < image2.height; ++j) {
                for (int k = 0; k < image2.channels; ++k) {
                    image2(i - x, j , k) = temp(i-l , j , k);
                }
                x+=(double(l)/image2.height);
            }
        }
        temp = image2;

        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs[curr_pos].first = image;
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
        ui->skewDeg->setValue(0);

}


void MainWindow::on_Info_clicked()
{
    QMessageBox::information(this,"About Baby Photoshop","It is a simple photoshop application,"
                                                           " contains 22 filters:\n"
                                                           "   - B&W.\n"
                                                           "   - Grayscale.\n"
                                                           "   - Lighten.\n"
                                                           "   - Darken.\n"
                                                           "   - Old TV effect.\n"
                                                           "   - Salt and pepper noise.\n"
                                                           "   - Crop.\n"
                                                           "   - Resize.\n"
                                                           "   - Blur.\n"
                                                           "   - Detect image edges.\n"
                                                           "   - Premium detect image edges.\n"
                                                           "   - Merge images.\n"
                                                           "   - Rotate image.\n"
                                                           "   - Flip image.\n"
                                                           "   - Add a Frame.\n"
                                                           "   - Skewing image.\n"
                                                           "   - Purple light.\n"
                                                           "   - Oil painting.\n"
                                                           "   - Sun light.\n"
                                                           "   - Infrared Photography.\n"
                                                           "   - Invert colors.\n"
                                                           "   - Mirror.\n"
                                                           "It provides Dark mode and Light mode.\n"
                                                           "It provides shortcuts:\n"
                                                           "   - Load -> CTRL + L\n"
                                                           "   - Save -> CTRL + S\n"
                                                           "   - Clear -> CTRL + C\n"
                                                           "   - Undo -> CTRL + Z\n"
                                                           "   - Redo -> CTRL + Y\n"
                                                           "   - Mode -> CTRL + M\n"
                                                           "   - Info -> CTRL + I\n"
                                                           "The Authors:\n"
                                                           "   - Ahmed Sayed Ahmed.\n"
                                                           "   - Noureldin Mohamed Amin.\n"
                                                           "   - Salsabil Bahaaeldin Rohaiem.\n"
                                                           "Last Modification Date: 17/4/2024.\n"
                                                           "Under supervision: Dr. Mohamed ElRamly.");
}

void MainWindow::on_apply_chooseresize_clicked()
{
    if(ui->comboBox_resizehow->currentIndex() == 0)
    {
        ui->lineEdit_width->setVisible(true);
        ui->lineEdit_height->setVisible(true);
        ui->label_width->setVisible(true);
        ui->label_height->setVisible(true);
        ui->apply_chooseresize->setVisible(true);
        ui->back_resize->setVisible(true);

        QString width = ui->lineEdit_width->text();
        QString height = ui->lineEdit_height->text();

        bool flag = 0;
        for(int i = 0; i < width.size(); ++i){
            if(width[i] > '9' || width[i] < '0'){
                flag = 1;
                break;
            }
        }
        for(int i = 0; i < height.size(); ++i){
            if(height[i] > '9' || height[i] < '0'){
                flag = 1;
                break;
            }
        }
        if(width == "" || height == ""){
            flag = 1;
        }

        if(flag){
            ui->lineEdit_width->setText("");
            ui->lineEdit_height->setText("");
            QMessageBox::warning(this,"Invalid Input","This input is invalid, please input the width and height correctly and apply the filter!");
            return;
        }
        if(width.toInt() * height.toInt() > 8000 * 8000){
            QMessageBox::warning(this,"Error","These dimentions are very big to load in the program!");
            return;
        }

        int n_width = width.toInt();
        int n_height = height.toInt();
        Image image2(n_width , n_height);
        for (int i = 0; i < n_width; ++i)
        {
            for (int j = 0; j < n_height; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    image2(i,j,k) = temp(i*temp.width/n_width,j*temp.height/n_height,k);
                }
            }
        }

        num_filters++;
        curr_pos++;
        ui->undo->setVisible(true);

        temp = image2;
        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
        QMessageBox::information(this,"Resize","Save the resized image to see the difference clearly.");
        ui->lineEdit_width->setText("");
        ui->lineEdit_height->setText("");

        if(curr_pos >= 0){
            Image curr("temp.jpg");
            ui->label_imagewidth->setText("The width of the current image: " + QString::number(curr.width));
            ui->label_imageheight->setText("The height of the current image: " + QString::number(curr.height));
        }
    }

    else
    {
        if(!(ui->quartre->isChecked()) && !(ui->third->isChecked()) && !(ui->half->isChecked()) && !(ui->one->isChecked()) && !(ui->two->isChecked()) && !(ui->three->isChecked()) && !(ui->four->isChecked()))
        {
            QMessageBox::warning(this,"Invalid Input","You must choose one of them!");
            return;
        }
        int n_width , n_height;
        if(ui->quartre->isChecked())
        {
            n_width = temp.width/4;
            n_height = temp.height/4;
        }
        else if(ui->third->isChecked())
        {
            n_width = temp.width/3;
            n_height = temp.height/3;
        }
        else if(ui->half->isChecked())
        {
            n_width = temp.width/2;
            n_height = temp.height/2;
        }
        else if(ui->one->isChecked())
        {
            n_width = temp.width;
            n_height = temp.height;
        }
        else if(ui->two->isChecked())
        {
            n_width = temp.width*2;
            n_height = temp.height*2;
        }
        else if(ui->three->isChecked())
        {
            n_width = temp.width*3;
            n_height = temp.height*3;
        }
        else if(ui->four->isChecked())
        {
            n_width = temp.width*4;
            n_height = temp.height*4;
        }

        Image image2(n_width , n_height);

        for (int i = 0; i < n_width; ++i)
        {
            for (int j = 0; j < n_height; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    image2(i,j,k) = temp(i*temp.width/n_width,j*temp.height/n_height,k);
                }
            }
        }

        ui->undo->setVisible(true);
        num_filters++;
        curr_pos++;

        temp = image2;
        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        ui->two->setChecked(false);
        ui->three->setChecked(false);
        ui->four->setChecked(false);

        ui->two->setVisible(false);
        ui->three->setVisible(false);
        ui->four->setVisible(false);

        if(curr_pos >= 0){
            Image curr("temp.jpg");
            ui->label_imagewidth->setText("The width of the current image: " + QString::number(curr.width));
            ui->label_imageheight->setText("The height of the current image: " + QString::number(curr.height));
            if(temp.width * temp.height <= 2000 * 2000){
                ui->two->setVisible(true);
                ui->three->setVisible(true);
                ui->four->setVisible(true);
            }
            else if(temp.width * temp.height <= 2500 * 2500){
                ui->two->setVisible(true);
                ui->three->setVisible(true);
            }
            else if(temp.width * temp.height <= 4000 * 4000){
                ui->two->setVisible(true);
            }
        }
        else{
            if(Original.width * Original.height <= 2000 * 2000){
                ui->two->setVisible(true);
                ui->three->setVisible(true);
                ui->four->setVisible(true);
            }
            else if(Original.width * Original.height <= 2500 * 2500){
                ui->two->setVisible(true);
                ui->three->setVisible(true);
            }
            else if(Original.width * Original.height <= 4000 * 4000){
                ui->two->setVisible(true);
            }
        }

        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
        QMessageBox::information(this,"Resize","Save the resized image to see the difference clearly.");
    }

}


void MainWindow::on_back_resize_clicked()
{
    ui->apply_chooseresize->setVisible(false);
    ui->back_resize->setVisible(false);
    ui->comboBox_resizehow->setVisible(true);
    ui->apply_resize->setVisible(true);
    ui->lineEdit_width->setVisible(false);
    ui->lineEdit_height->setVisible(false);
    ui->label_width->setVisible(false);
    ui->label_height->setVisible(false);
    ui->label_ratio->setVisible(false);
    ui->quartre->setVisible(false);
    ui->third->setVisible(false);
    ui->half->setVisible(false);
    ui->one->setVisible(false);
    ui->two->setVisible(false);
    ui->three->setVisible(false);
    ui->four->setVisible(false);
    ui->label_imagewidth->setVisible(false);
    ui->label_imageheight->setVisible(false);
}


void MainWindow::on_undo_clicked()
{
    ui->redo->setVisible(true);
    curr_pos--;
    redo_count++;
    if (num_filters == 0)
    {
        ui->undo->setVisible(false);

        ui->Edited_img->setText("Apply a filter to show the result!");
        ui->Edited_img->setAlignment(Qt::AlignCenter);


        Image img(imgname);
        temp = img;
        QFile file("temp.jpg");
        if (file.exists())
            file.remove();

        undo_count++;
        num_filters--;

    }
    else
    {
        num_filters--;
        saveImage = imgs[num_filters].first;
        saveImage.save("temp.jpg");
        temp.loadNewImage("temp.jpg");
        QImage undo_image = imgs[num_filters].first.scaled(ui->Loaded_img->width() , ui->Loaded_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(undo_image));
        undo_count++;
    }

    if(curr_pos >= 0){
        Image curr("temp.jpg");
        ui->label_imagewidth->setText("The width of the current image: " + QString::number(curr.width));
        ui->label_imageheight->setText("The height of the current image: " + QString::number(curr.height));
    }
    else{
        ui->label_imagewidth->setText("The width of the current image: " + QString::number(Original.width));
        ui->label_imageheight->setText("The height of the current image: " + QString::number(Original.height));
    }

}


void MainWindow::on_redo_clicked()
{
    ui->undo->setVisible(true);
    redo_count--;
    curr_pos++;
    QImage redo_image;
    if(redo_count == 0)
    {
        ui->redo->setVisible(false);
        num_filters++;
        redo_image = imgs[num_filters].first.scaled(ui->Loaded_img->width() , ui->Loaded_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(redo_image));
    }
    else
    {
        ui->redo->setVisible(true);
        num_filters++;
        redo_image = imgs[num_filters].first.scaled(ui->Loaded_img->width() , ui->Loaded_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(redo_image));
    }
    saveImage = imgs[num_filters].first;
    saveImage.save("temp.jpg");
    temp.loadNewImage("temp.jpg");

    if(curr_pos >= 0){
        Image curr("temp.jpg");
        ui->label_imagewidth->setText("The width of the current image: " + QString::number(curr.width));
        ui->label_imageheight->setText("The height of the current image: " + QString::number(curr.height));
    }
}

void MainWindow::on_Mirror_clicked()
{
    hide();
    ui->skewDeg->setValue(0);
    ui->horizontalSliderLighten->setValue(0);
    ui->horizontalSliderdarken->setValue(0);
    ui->horizontalSlider_thick->setValue(0);
    ui->up->setVisible(true);
    ui->down->setVisible(true);
    ui->right->setVisible(true);
    ui->left->setVisible(true);
    ui->label_mirror->setVisible(true);
    ui->applymirror->setVisible(true);
    ui->lineEdit_width->setText("");
    ui->lineEdit_height->setText("");
    ui->lineEdit_x->setText("");
    ui->lineEdit_y->setText("");
    ui->lineEdit_cropw->setText("");
    ui->lineEdit_croph->setText("");
    if (ui->Loaded_img->pixmap().isNull())
    {
        ui->label_mirror->setVisible(false);
        ui->applymirror->setVisible(false);
        ui->undo->setVisible(false);
        ui->up->setVisible(false);
        ui->down->setVisible(false);
        ui->right->setVisible(false);
        ui->left->setVisible(false);
        QMessageBox::information(this , "No Loaded Image" , "You must load an image first.");
        return;
    }
}


void MainWindow::on_applymirror_clicked()
{
    if (!(ui->up->isChecked()) && !(ui->down->isChecked()) && !(ui->right->isChecked()) && !(ui->left->isChecked()))
    {
        QMessageBox::warning(this , "Error" , "You should choose any option to apply the filter.");
    }
    else
    {
        num_filters++;
        curr_pos++;
        ui->undo->setVisible(true);
        if(ui->up->isChecked())
        {
               for (int i = 0; i < temp.width; ++i) {
                   for (int j = 0; j < temp.height/2; ++j) {
                       for (int k = 0; k < 3; ++k) {
                           temp(i , temp.height - j - 1, k) = temp(i , j , k);
                       }
                   }
               }
        }
        if(ui->down->isChecked())
        {
            for (int i = 0; i < temp.width; ++i) {
                for (int j = temp.height/2; j < temp.height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        temp(i , temp.height - j - 1, k) = temp(i , j , k);
                    }
                }
            }
        }
        if(ui->right->isChecked())
        {
               for (int i = temp.width/2; i < temp.width; ++i) {
                   for (int j = 0; j < temp.height; ++j) {
                       for (int k = 0; k < 3; ++k) {
                           temp(temp.width - i - 1, j , k) = temp(i , j , k);
                       }
                   }
               }
        }
        if(ui->left->isChecked())
        {
               for (int i = 0; i < temp.width/2; ++i) {
                   for (int j = 0; j < temp.height; ++j) {
                       for (int k = 0; k < 3; ++k) {
                           temp(temp.width - i - 1, j , k) = temp(i , j , k);
                       }
                   }
               }
        }
        temp.saveImage("temp.jpg");
        QImage image;
        image.load("temp.jpg");
        imgs.insert(curr_pos,{image,0});
        ui->redo->setVisible(true);
        if(curr_pos == imgs.size() - 1)
            ui->redo->setVisible(false);
        editedImage = image;
        image = image.scaled(ui->Edited_img->width(),ui->Edited_img->height());
        ui->Edited_img->setPixmap(QPixmap::fromImage(image));
        ui->up->setChecked(false);
        ui->left->setChecked(false);
        ui->down->setChecked(false);
        ui->right->setChecked(false);
    }

}
