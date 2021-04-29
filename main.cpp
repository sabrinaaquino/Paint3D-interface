#include <iostream>
#include "mainwindow.h"
#include <vector>
#include "Sculptor.h"
#include "outSphere.h"
#include "FiguraGeometrica.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "putVoxel.h"
#include "putEllipsoid.h"
#include <cutEllipsoid.h>
#include "cutSphere.h"
#include "cutVoxel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
