#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>
#include <QVector>
#include "Sculptor.h"

class plotter : public QWidget
{
    Q_OBJECT
private:
    int sizeX, sizeY, sizeZ, radius, rx,ry,rz, dimx,dimy,dimz;
    int nl, nc, dimCell;
    int borderv, borderh;
    bool pressed;
    vector <vector <Voxel> > v;
    float r,g,b,a;
    int widthCell, heightCell;
    int widthScr, heightScr;
public:
    explicit plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setSize(int _nl, int _nc);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void loadMatriz(vector <vector <Voxel> > m);

signals:
    void updatePos(int,int);
public slots:
    void setX(int _sizeX);
    void setY(int _sizeY);
    void setZ(int _sizeZ);
    void setRadius(int _Radius);
    void setRx(int rx_);
    void setRy(int ry_);
    void setRz(int rz_);
    void setColor_r(int r_);
    void setColor_g(int g_);
    void setColor_b(int b_);
    void setColor_a(int a_);
    void setDimx(int dimx_);
    void setDimy(int dimy_);
    void setDimz(int dimz_);

};

#endif // PLOTTER_H
