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
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "BabyPhotoshop_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QPixmap image(":/img/Opening photo2.jpg");
    QPixmap icon(":/img/2.png");


    QSplashScreen splash(image);
    splash.show();

    MainWindow w;
    w.setWindowTitle("Baby Photoshop");
    w.setWindowIcon(icon);


    QTimer::singleShot(3000, &splash, &QSplashScreen::close);
    QTimer::singleShot(3000, &w, &MainWindow::show);


    return a.exec();
}
