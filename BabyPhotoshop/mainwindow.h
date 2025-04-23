#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QObject>
#include <QEvent>
#include <QPushButton>
#include <QShortcut>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Load_clicked();

    void on_Save_clicked();

    void on_Clear_clicked();

    void on_Blur_clicked();

    void on_AddFrame_clicked();

    void on_MergeImages_clicked();

    void on_RotateImage_clicked();

    void on_Darken_clicked();

    void on_Lighten_clicked();

    void on_FlipImage_clicked();

    void on_Skewing_clicked();

    void on_Resize_clicked();

    void on_Crop_clicked();

    void on_GrayScale_clicked();

    void on_BlackWhite_clicked();

    void on_InvertColors_clicked();

    void on_DetectEdges_clicked();

    void on_Sunlight_clicked();

    void on_OilPainting_clicked();

    void on_OldTV_clicked();

    void on_Purple_clicked();

    void on_Infrared_clicked();

    void on_Premiumedge_clicked();

    void on_Saltpeppernoise_clicked();

    void on_applyDarken_clicked();

    void on_applyLighten_clicked();

    void on_applyFlip_clicked();

    void on_applyRot_clicked();

    void on_applyMerge_clicked();

    void on_apply_resize_clicked();

    void on_applyBlur_clicked();

    void on_applycrop_clicked();

    void on_apply_frame_clicked();

    void on_applySkew_clicked();

    void on_Info_clicked();

    void on_apply_chooseresize_clicked();

    void on_back_resize_clicked();

    void on_undo_clicked();

    void on_redo_clicked();

    void on_Mirror_clicked();

    void on_applymirror_clicked();

    void hide();

    void on_Mode_clicked();

    void CheckUndo();

    void CheckRedo();

    void on_frameColor_clicked();

private:
    Ui::MainWindow *ui;

    bool eventFilter(QObject *obj, QEvent *event);

    void setButtonIcon();

    QPushButton *pushButton;



};
#endif // MAINWINDOW_H
