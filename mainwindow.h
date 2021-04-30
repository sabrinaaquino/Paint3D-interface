#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Sculptor.h"
#include "dialog.h"
#include <QActionGroup>
#include <QMainWindow>

enum{
    PUTBOX, CUTBOX, PUTSPHERE, CUTSPHERE, PUTVOXEL, CUTVOXEL, PUTELLIPSOID, CUTELLIPSOID
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int dimX, dimY, dimZ;
    int r, g, b;
    int currentObject;
    void updateColor();
    Sculptor *sculptor;
    QActionGroup *actionGroup;

public slots:

    void setRed(int _r);
    void setGreen(int _g);
    void setBlue(int _b);
    void save();
    void openDialog(void);
    void drawShape(int, int);
    void updateCoord(int, int);

private slots:
    void on_action_Voxel_cut_triggered();
    void on_action_Box_triggered();
    void on_action_Box_cut_triggered();
    void on_action_Sphere_triggered();
    void on_action_Sphere_cut_triggered();
    void on_action_Ellipsoid_triggered();
    void on_action_Ellipsoid_cut_triggered();
    void on_actionSave_triggered();
    void on_actionNew_triggered();
    void on_actionExit_triggered();
    void on_horizontalSliderDimZ_valueChanged(int value);
    void on_actionVoxel_triggered();
};
#endif // MAINWINDOW_H
