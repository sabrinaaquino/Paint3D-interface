#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "Sculptor.h"
#include "FiguraGeometrica.h"

class putVoxel : public FiguraGeometrica
{
    /**
    * @brief Posicoes do voxel.
    */
    int x,y,z;

    public:
        putVoxel(int x, int y, int z, float r, float g, float b, float a);
        /**
        * @brief Destrutor da funcao putVoxel
        */
        ~putVoxel(){};
        void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
