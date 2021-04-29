#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "Sculptor.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dimX = 10; dimY = 10; dimZ = 10;
    sculptor = new Sculptor(dimX,dimY,dimZ);
    ui->horizontalSliderDimX->setMaximum(dimX-1);
    ui->horizontalSliderDimY->setMaximum(dimY-1);
    ui->horizontalSliderDimZ->setMaximum(dimZ-1);
    ui->widget->loadMatriz(sculptor->getPlano(ui->horizontalSliderDimZ->value(),XY));
    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionBox);
    actionGroup->addAction(ui->actionBox_cut);
    actionGroup->addAction(ui->actionEllipsoid);
    actionGroup->addAction(ui->actionEllipsoid_cut);
    actionGroup->addAction(ui->actionSphere);
    actionGroup->addAction(ui->actionSphere_cut);
    actionGroup->addAction(ui->actionVoxel);
    actionGroup->addAction(ui->actionVoxel_cut);
    ui->actionVoxel->setChecked(true);
    connect(ui->pushButtonOpenDialog,
            SIGNAL(clicked()),
            this,
            SLOT(openDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
    QFileDialog dialog;
    QString selectedFilter;
    QString filename = dialog.getSaveFileName(this,tr("Save"),
                                              QDir::currentPath(),
                                              tr("Arquivo OFF(*.off);;Arquivo VECT(*.vect)"),
                                              &selectedFilter);
    if(filename.isNull()){
        return;
    }
    sculptor->writeOFF(filename.toStdString());
}

void MainWindow::openDialog()
{
    Dialog d;
    if(d.exec() == QDialog::Accepted){
        dimX = d.dimXDialog().toInt();
        dimY = d.dimYDialog().toInt();
        dimZ = d.dimZDialog().toInt();
        qDebug() << dimX << dimY << dimZ;
        ui->horizontalSliderDimX->setMaximum(dimX-1);
        ui->horizontalSliderDimY->setMaximum(dimY-1);
        ui->horizontalSliderDimZ->setMaximum(dimZ-1);
    }


}

void MainWindow::setRed(int _r)
{
    r = _r;
    updateColor();
}

void MainWindow::setGreen(int _g)
{
    g = _g;
    updateColor();
}

void MainWindow::setBlue(int _b)
{
    b = _b;
    updateColor();
}

void MainWindow::drawShape(int hClick, int vClick)
{
    switch(currentObject){
    case(PUTSPHERE):
        sculptor->putSphere(vClick,hClick,ui->horizontalSliderDimZ->value(),ui->horizontalSliderRaio->value());
        ui->widget->loadMatriz(sculptor->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(CUTSPHERE):
        sculptor->cutSphere(vClick,hClick,ui->horizontalSliderDimZ->value(),ui->horizontalSliderRaio->value());
        ui->widget->loadMatriz(sculptor->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(PUTVOXEL):
        sculptor->putVoxel(vClick,hClick,ui->horizontalSliderDimZ->value());
        ui->widget->loadMatriz(sculptor->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(CUTVOXEL):
        sculptor->cutVoxel(vClick,hClick,ui->horizontalSliderDimZ->value());
        ui->widget->loadMatriz(sculptor->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(PUTBOX):
        sculptor->putBox(vClick-ui->horizontalSliderBoxX->value()/2,
                     vClick+ui->horizontalSliderBoxX->value()/2,
                     hClick-ui->horizontalSliderBoxY->value()/2,
                     hClick+ui->horizontalSliderBoxY->value()/2,
                     ui->horizontalSliderDimZ->value()-ui->horizontalSliderBoxZ->value()/2,
                     ui->horizontalSliderDimZ->value()+ui->horizontalSliderBoxZ->value()/2);
        ui->widget->loadMatriz(sculptor->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(CUTBOX):
        sculptor->cutBox(vClick-ui->horizontalSliderBoxX->value()/2,
                     vClick+ui->horizontalSliderBoxX->value()/2,
                     hClick-ui->horizontalSliderBoxY->value()/2,
                     hClick+ui->horizontalSliderBoxY->value()/2,
                     ui->horizontalSliderDimZ->value()-ui->horizontalSliderBoxZ->value()/2,
                     ui->horizontalSliderDimZ->value()+ui->horizontalSliderBoxZ->value()/2);
        ui->widget->loadMatriz(sculptor->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(PUTELLIPSOID):
        sculptor->putEllipsoid(vClick,hClick,ui->horizontalSliderDimZ->value(),
                      ui->horizontalSliderERx->value(),
                      ui->horizontalSliderERy->value(),
                      ui->horizontalSliderERz->value());
        ui->widget->loadMatriz(sculptor->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(CUTELLIPSOID):
        sculptor->cutEllipsoid(vClick,hClick,ui->horizontalSliderDimZ->value(),
                      ui->horizontalSliderERx->value(),
                      ui->horizontalSliderERy->value(),
                      ui->horizontalSliderERz->value());
        ui->widget->loadMatriz(sculptor->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;

    }
}


void MainWindow::on_action_Voxel_triggered()
{
    currentObject = PUTVOXEL;
}

void MainWindow::on_action_Voxel_cut_triggered()
{
    currentObject = CUTVOXEL;
}

void MainWindow::on_action_Box_triggered()
{
    currentObject = PUTBOX;
}

void MainWindow::on_action_Box_cut_triggered()
{
    currentObject = CUTBOX;
}

void MainWindow::on_action_Sphere_triggered()
{
    currentObject = PUTSPHERE;
}

void MainWindow::on_action_Sphere_cut_triggered()
{
    currentObject = CUTSPHERE;
}

void MainWindow::on_action_Ellipsoid_triggered()
{
    currentObject = PUTELLIPSOID;
}

void MainWindow::on_action_Ellipsoid_cut_triggered()
{
    currentObject = CUTELLIPSOID;
}

void MainWindow::updateColor()
{
    QString color;
    color = "QPushButton { background-color: rgb(" +
            QString().setNum(r) + "," +
            QString().setNum(g) + "," +
            QString().setNum(b) + ");}";
    ui->pushButtonColor->setStyleSheet(color);
    sculptor->setColor(r,g,b,255);
}

void MainWindow::on_actionSave_triggered()
{
    QFileDialog dialog;
    QString selectedFilter;
    QString filename = dialog.getSaveFileName(this,tr("Salvar"),
                                              QDir::currentPath(),
                                              tr("Arquivo OFF(*.off);;Arquivo VECT(*.vect)"),
                                              &selectedFilter);
    if(filename.isNull()){
        return;
    }
    sculptor->writeOFF(filename.toStdString().c_str());
}

void MainWindow::on_actionNew_triggered()
{
    Dialog *dialog;
    dialog = new Dialog();
    dialog->exec();
    if(dialog->result() == QDialog::Accepted){
        dimX = dialog->dimXDialog().toInt();
        dimY = dialog->dimYDialog().toInt();
        dimZ = dialog->dimZDialog().toInt();
        if(sculptor != NULL)
           delete sculptor;
        sculptor = new Sculptor(dimX,dimY,dimZ);
        //ui->actionXY->trigger();
        ui->horizontalSliderDimX->setMaximum(dimX-1);
        ui->horizontalSliderDimY->setMaximum(dimY-1);
        ui->horizontalSliderDimZ->setMaximum(dimZ-1);
    }
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}
