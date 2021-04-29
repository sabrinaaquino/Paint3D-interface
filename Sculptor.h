#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

enum{XY,ZX,YZ};

struct Voxel {
/**
* @brief Cores.
*/
float r,g,b; // Colors
/**
* @brief Transparencia.
*/
float a;// Transparency
/**
* @brief Incluir ou nao.
*/
bool is0n; // Included or not
};

class Sculptor
{

	protected:
        /**
        * @brief 3D Matrix.
        */
		Voxel ***v;// 3D matrix
		/**
        * @brief Dimensoes.
        */
 		float nx,ny,nz,nv,nf; // Dimensions
 		/**
        * @brief Cores.
        */
 		float rv,gv,bv,a; // Current drawing color
 		/**
        * @brief Posicoes.
        */
		int x,y,z;
		/**
        * @brief Variaveis auxiliares.
        */
		int i,j,k;
		/**
        * @brief Posicoes.
        */
		int x0, x1;
		/**
        * @brief Posicoes.
        */
		int y0, y1;
		/**
        * @brief Posicoes.
        */
		int z0, z1;
		float lado, delta;
		/**
        * @brief Coordenadas do centro do elipsoide e raio da esfera.
        */
		int xcenter, ycenter, zcenter, radius;
		/**
        * @brief Raios do elipsoide.
        */
		int rx, ry, rz;

	public:
	    /**
        * @brief Construtor da classe.
        * O Sculptor aloca dinamicamente o Voxel na memória da máquina.
        * @param _nx tamanho do eixo x a ser alocado.
        * @param _ny tamanho do eixo y a ser alocado.
        * @param _nz tamanho do eixo z a ser alocado.
        */
		Sculptor(int _nx, int _ny, int _nz);
		/**
        * @brief Destrutor da classe.
        */
		~Sculptor();
		/**
        * @brief Ativa o local da memória e atribui cores e transparencia a ele.
        * @param y local do eixo x a ser ativado.
        * @param y local do eixo y a ser ativado.
        * @param z local do eixo z a ser ativado.
        */


		void putVoxel(int x, int y, int z);
		/**
        * @brief Cria o arquivo .off.
        * @param filename nome do arquivo.
        */



        void writeOFF(string filename); //Creates the .off file
		/**
        * @brief Atribui as porcentagens de vermelho, verde e azul que o Voxel ira receber.
        * @param r porcentagem de vermelho.
        * @param g porcentagem de verde.
        * @param b porcentagem de azul.
        */
		void setColor(float r, float g, float b, float a);
		/**
        * @brief Exclui Voxels que estao ativados mas nao aparecem para o usuario.
        */
		void limpaVoxels(); // Erases not shown Voxels
		/**
        * @brief Exclui um voxel nas coordenadas indicadas.
        */
		void cutVoxel(int x0, int y0, int z0);
		/**
        * @brief Cria um paralelepipedo nas coordenandas indicadas.
        */
		void putBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1); // Creates a cobble
		/**
        * @brief Exclui um paralelepipedo nas coordenandas indicadas.
        */
		void cutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1); // Excludes a cobble
		/**
        * @brief Cria uma esfera nas coordenandas indicadas.
        */
        void putSphere(int _xcenter, int _ycenter, int _zcenter, int _radius); //Creates a sphere
        /**
        * @brief Exclui o que está fora da esfera nas coordenandas indicadas.
        */
        void outSphere(int _xcenter, int _ycenter, int _zcenter, int _radius); //Excludes what is outside a sphere
        /**
        * @brief Exclui uma esfera nas coordenandas indicadas.
        */
        void cutSphere(int xcenter, int ycenter, int zcenter, int radius); // Excludes what is inside a sphere
        /**
        * @brief Cria um elipsoide nas coordenandas indicadas.
        */
        void putEllipsoid(int _xcenter, int _ycenter, int _zcenter, float _rx, float _ry, float _rz); //Creates a ellipsoid
        vector< vector<Voxel> > getPlano(int i, int plano=XY);
        /**
        * @brief Deleta um elipsoide nas coordenandas indicadas.
        */
        void cutEllipsoid(int _xcenter, int _ycenter, int _zcenter, float _rx, float _ry, float _rz); //Deletes a ellipsoid
};
#endif
