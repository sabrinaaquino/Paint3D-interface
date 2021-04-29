#ifndef OUTSPHERE_H
#define OUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"


class outSphere: public FiguraGeometrica{
/**
* @brief xcenter é o valor da coordenada x do centro da esfera.
*/
int xcenter;
/**
* @brief ycenter é o valor da coordenada y do centro da esfera.
*/
int ycenter;
/**
*@brief zcenter é o valor da coordenada z do centro da esfera.
*/
int zcenter;
/**
* @brief radius é o valor do raio da esfera.
*/
int radius;

    public:
        outSphere(int xcenter, int ycenter, int zcenter, int radius);
        ~outSphere();
        void draw(Sculptor &t);
};

#endif // OUTSPHERE_H
