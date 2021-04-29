#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"


class FiguraGeometrica
{
    public:
        FiguraGeometrica();
        virtual ~FiguraGeometrica();
        virtual void draw(Sculptor &t)=0;

    protected:
        /**
        * @brief r, g, b e a armazena o valor das cores e da transparencia.
        */
        float r, g, b, a;

    private:
};

#endif // FIGURAGEOMETRICA_H
