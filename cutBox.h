#ifndef CUTBOX_H
#define CUTBOX_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutBox : public FiguraGeometrica
{
    int x0, y0, z0;
    int x1, y1, z1;
    public:
        cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
        ~cutBox(){};
        void draw(Sculptor &t);

};

#endif // CUTBOX_H
