#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QGradient>
#include <cmath>
#include "Sculptor.h"
#include <QPoint>
#include <QSize>
#include <qdebug.h>

plotter::plotter(QWidget *parent) : QWidget(parent)
{
    nl = 10;
    nc = 20;
    Sculptor(nl,nc,10);
    pressed = false;
    widthScr = rect().width();
    heightScr = rect().height();
    widthCell = widthScr/nc;
    heightCell = heightScr/nl;
    if (heightCell > widthCell){
        dimCell = widthCell;
    }else{
        dimCell = heightCell;
    }
    setSize(nl,nc);
}

void plotter::loadMatriz(vector<vector<Voxel> > m)
{
    nl = m.size();
    nc = m[0].size();
    v = m;
    repaint();
}

void plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    QColor color;
    QRadialGradient gradient(QPointF(1,1),20);
    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(1, Qt::white);
    brush.setStyle(Qt::SolidPattern);
    painter.setRenderHint(QPainter::Antialiasing, true);
    pen.setWidth(1);
    widthScr = rect().width();
    heightScr = rect().height();
    widthCell = widthScr/nc;
    heightCell = heightScr/nl;
    if (heightCell > widthCell){
        dimCell = widthCell;
    }else{
        dimCell = heightCell;
    }
    borderh = (widthScr - nc*dimCell)/2;
    //borderh = borderh/10
    borderv = (heightScr - nl*dimCell)/2;
    gradient.setRadius(dimCell);
    gradient.setFocalPoint(-0.15*dimCell, -0.15*dimCell);
    gradient.setCenter(-0.15*dimCell, -0.15*dimCell);
    painter.setPen(pen);
    painter.drawRect(borderh,borderv,nc*dimCell,nl*dimCell);

    qDebug() << nl << nc << v.size() << v[0].size();

    for(uint i = 0; i < v.size(); i++){
        for(uint j = 0; j < (v[i].size()); j++){
            if(v[i][j].is0n == true){
                painter.save();
                painter.translate(j*dimCell+borderh+dimCell/2,i*dimCell+borderv+dimCell/2);
                painter.setPen(Qt::NoPen);
                color.setRgb(qRgb(v[i][j].r, v[i][j].g, v[i][j].b));
                gradient.setColorAt(0, Qt::white);
                gradient.setColorAt(0.3, color);
                gradient.setColorAt(1, color.darker());
                painter.setBrush(gradient);
                painter.drawRect(-dimCell/2+1, -dimCell/2+1, dimCell, dimCell);
                painter.restore();
            }else{
                brush.setColor(QColor(255,255,255,0));
                painter.setBrush(brush);
                //painter.drawRect(j*dimCell+borderh,i*dimCell+borderv,dimCell, dimCell);
            }
        }
    }
}

void plotter::setX(int _sizeX)
{
    sizeX = _sizeX;
    repaint();
}

void plotter::setY(int _sizeY)
{
    sizeY = _sizeY;
    repaint();
}

void plotter::setZ(int _sizeZ)
{
    sizeZ = _sizeZ;
    repaint();
}

void plotter::setRadius(int _Radius)
{
    radius = _Radius;
    repaint();
}

void plotter::setRx(int rx_)
{
    rx = rx_;
    repaint();
}

void plotter::setRy(int ry_)
{
    ry = ry_;
    repaint();
}

void plotter::setRz(int rz_)
{
    rz = rz_;
    repaint();
}

void plotter::setDimx(int dimx_)
{
    dimx = dimx_;
    repaint();
}

void plotter::setDimy(int dimy_)
{
    dimy = dimy_;
    repaint();
}

void plotter::setDimz(int dimz_)
{
    dimz = dimz_;
    repaint();
}

void plotter::setSize(int _nl, int _nc)
{
    nl = _nl;
    nc = _nc;
    update();
}

void plotter::mousePressEvent(QMouseEvent *event)
{
    int posh, posv;
    QRect ret;
    ret = rect();
    pressed = true;
    ret.adjust(borderh, borderv, -borderh, -borderv);
    if(ret.contains(event->pos())){
        posh = (event->pos().x()-borderh)*nc/ret.width();
        posv = (event->pos().y()-borderv)*nl/ret.height();
        emit updatePos(posh, posv);
    }
}

void plotter::mouseMoveEvent(QMouseEvent *event)
{
    int posh, posv;
    QRect ret;
    ret = rect();
    ret.adjust(borderh, borderv, -borderh, -borderv);
    if(ret.contains(event->pos())&& pressed == true){
        posh = (event->pos().x()-borderh)*nc/ret.width();
        posv = (event->pos().y()-borderv)*nl/ret.height();
        emit updatePos(posh, posv);
    }

}

void plotter::mouseReleaseEvent(QMouseEvent *event)
{
    pressed = false;
}
