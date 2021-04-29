#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putEllipsoid : public FiguraGeometrica
{
    /**
     * @brief Coordenadas do centro do Elipsoide.
     */
    int xcenter, ycenter, zcenter;
    /**
     * @brief Valores dos raios do Elipsoide.
     */
    int rx,ry,rz;
    public:
        putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
        ~putEllipsoid();
        void draw(Sculptor &t);

};

#endif // PUTELLIPSOID_H
