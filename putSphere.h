#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putSphere : public FiguraGeometrica
{
    /**
     * @brief xcenter é o valor da coordenada x do centro da esfera.
     */
    int xcenter;
    /**
     * @brief ycenter é o valor da coordenada y do centro da esfera.
     */
    int ycenter;
    /**
     * @brief zcenter é o valor da coordenada z do centro da esfera.
     */
    int zcenter;
    /**
     * @brief radius é o valor do raio da esfera.
     */
    int radius;
    public:
        putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
        ~putSphere();
        void draw(Sculptor &t);

};

#endif // PUTSPHERE_H
