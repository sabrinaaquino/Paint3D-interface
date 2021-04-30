#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include "FiguraGeometrica.h"
#include <string>

/*! \brief A classe interpretador interpretará as esculturas para as outras classes.
*
*/

class interpretador
{
    int dimx; /*!< dimx representa a dimensao x. */
    int dimy; /*!< dimy representa a dimensao y. */
    int dimz; /*!< dimz representa a dimensao z. */
    float r; /*!< r representa a cor vermelha. */
    float g; /*!< g representa a cor verde. */
    float b; /*!< b representa a cor blue. */
    float a;  /*!< a representa a transparencia. */
public:
    interpretador();
    std::vector<FiguraGeometrica*> parse(std::string filename);
    /*! \brief Retorna a dimensão x*/
    int getDimx();
    /*! \brief Retorna a dimensão y*/
    int getDimy();
    /*! \brief Retorna a dimensão z*/
    int getDimz();
};

#endif // INTERPRETADOR_H
