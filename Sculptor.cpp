/** @file Sculptor.cpp
*   @brief Definicoes das Funcoes
*/

#include "Sculptor.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cctype>


using namespace std;

/// Construtor
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    // CONSTRUTOR DA CLASSE
	nx=_nx; ny=_ny; nz=_nz;
    delta=0;
    lado=0.5-delta;
    v = new Voxel**[_nx];
        for(int i=0; i<nx; i++){
            v[i] = new Voxel*[_ny];
                for(int j=0; j<ny; j++){
                    v[i][j] = new Voxel[_nz];
                }
        }

    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                v[i][j][k].is0n = false;
            }
        }
    }

}

Sculptor::~Sculptor(){
    //DESTRUTOR DA CLASSE
    if(nx==0||ny==0||nz==0){
        return;
    }
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;

}

void Sculptor::putVoxel(int x0, int y0, int z0){
    if((x0>=nx)||(y0>=ny)||(z0>=nz)){
        return;
    }else if((x0<0)||(y0<0)||(z0<0)){
        return;
    }else{
        v[x0][y0][z0].is0n = true;
        // ATRIBUINDO AS CORES AO VOXEL
        v[x0][y0][z0].r = rv;
        v[x0][y0][z0].g = gv;
        v[x0][y0][z0].b = bv;
        v[x0][y0][z0].a = a;

    }
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    rv = r; //componente correspondente à cor vermelha.
    gv = g; //componente correspondente à cor verde.
    bv = b; //componente correspondente à cor azul.
    a = alpha; //componente correspondente à opacidade.
}

void Sculptor::cutVoxel(int x0, int y0, int z0)
{
    // REMOVENDO UM VOXEL
    v[x0][y0][z0].is0n=false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    // ADICIONANDO PARALELEPIPEDO
    for(i=x0;i<x1;i++){
        for(j=y0;j<y1;j++){
            for(k=z0;k<z1;k++){
                putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::putSphere(int _xcenter, int _ycenter, int _zcenter, int _radius){
    // ADICIONANDO ESFERA
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
    double r=radius/2.0;
    double dist;
    for(i=0; i<(2*xcenter); i++){
        for(j=0; j<(2*ycenter); j++){
            for(k=0; k<(2*zcenter); k++){
                //Equação da esfera.
                dist = (i-xcenter/2.0) * (i-xcenter/2.0 ) / (r*r) +
                       (j-ycenter/2.0) * (j-ycenter/2.0) / (r*r) +
                       (k-zcenter/2.0) * (k-zcenter/2.0 ) / (r*r);
                if(dist<=1.0){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::outSphere(int _xcenter, int _ycenter, int _zcenter, int _radius){
    // REMOVENDO O EXTERIOR DE UMA ESFERA
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
    double rd=radius/2.0;
    double dist;
    for(i=0; i<nx-1; i++){
        for(j=0; j<ny-1; j++){
            for(k=0; k<nz-1; k++){
                //Equação da esfera.
                dist = (i-xcenter/2.0) * (i-xcenter/2.0 ) / (rd*rd) +
                       (j-ycenter/2.0) * (j-ycenter/2.0) / (rd*rd) +
                       (k-zcenter/2.0) * (k-zcenter/2.0 ) / (rd*rd);
                if(dist<=1.0){
                }
                else{
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}


void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    // REMOVENDO UMA ESFERA
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
    double rd=radius/2.0;
    double dist;
    for(i=0; i<(2*xcenter); i++){
        for(j=0; j<(2*ycenter); j++){
            for(k=0; k<(2*zcenter); k++){
                //Equação da esfera.
                dist = (i-xcenter/2.0) * (i-xcenter/2.0 ) / (rd*rd) +
                       (j-ycenter/2.0) * (j-ycenter/2.0) / (rd*rd) +
                       (k-zcenter/2.0) * (k-zcenter/2.0 ) / (rd*rd);
                if(dist<=1.0){
                    cutVoxel(i,j,k);;
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int _xcenter, int _ycenter, int _zcenter, float _rx, float _ry, float _rz){
    // ADICIONANDO UM ELIPSÓIDE
    xcenter=_xcenter;
    ycenter=_ycenter;
    zcenter=_zcenter;
    rx=_rx;
    ry=_ry;
    rz=_rz;
    for(i=0; i<=(xcenter+rx); i++){
        for(j=0; j<=(ycenter+ry); j++){
            for(k=0; k<=(zcenter+rz); k++){
                if(pow(float(i-xcenter)/float(rx),2) + pow(float(j-ycenter)/float(ry),2) + pow(float(k-zcenter)/float(rz),2) <= 1){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int _xcenter, int _ycenter, int _zcenter, float _rx, float _ry, float _rz){
    // ADICIONANDO UM ELIPSÓIDE
    xcenter=_xcenter;
    ycenter=_ycenter;
    zcenter=_zcenter;
    rx=_rx;
    ry=_ry;
    rz=_rz;
    for(i=0; i<=(xcenter+rx); i++){
        for(j=0; j<=(ycenter+ry); j++){
            for(k=0; k<=(zcenter+rz); k++){
                if(pow(float(i-xcenter)/float(rx),2) + pow(float(j-ycenter)/float(ry),2) + pow(float(k-zcenter)/float(rz),2) <= 1){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    // REMOVENDO UM PARALELEPIPEDO
    for(i=x0;i<x1;i++){
        for(j=y0;j<y1;j++){
            for(k=z0;k<z1;k++){
                cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::limpaVoxels(){
    // REMOVENDO VOXELS QUE NÃO SÃO MOSTRADOS
    queue<int> q;
    int lx,ly,lz;
    for(x=1; x<nx-1; x++){
        for(y=1; y<ny-1; y++){
            for(z=1; z<nz-1; z++){
                if((v[x][y][z].is0n == true) &&
                    (v[x+1][y][z].is0n == true) &&
                    (v[x-1][y][z].is0n == true) &&
                    (v[x][y+1][z].is0n == true) &&
                    (v[x][y-1][z].is0n == true) &&
                    (v[x][y][z+1].is0n == true) &&
                    (v[x][y][z-1].is0n == true)){
                    v[x][y][z].is0n = false;
                    q.push(x);
                    q.push(y);
                    q.push(z);

                }
            }
        }
    }
    while(!q.empty()){
        lx=q.front(); q.pop();
        ly=q.front(); q.pop();
        lz=q.front(); q.pop();
        v[lx][ly][lz].is0n = false;
    }
}

void Sculptor::writeOFF(string filename){
    // ESCREVENDO O ARQUIVO .OFF
    int total, faces, nv, nf;
    ofstream f(filename);
    total = 0;
    f << "OFF\n";
    for(int x=0;x<nx;x++){
        for(int y=0;y<ny;y++){
            for(int z=0;z<nz;z++){
                if (v[x][y][z].is0n == true){
                    total++;
                }
            }
        }
    }
    nv=8*total;
    nf=6*total;
    faces=0;
    f << nv << " " << nf << " 0 \n";
    for(x=0;x<nx;x++){
        for(y=0;y<ny;y++){
            for(z=0;z<nz;z++){
                if(v[x][y][z].is0n == true){
                    f << x-lado << " " << y+lado << " " << z-lado << "\n"
                    << x-lado << " " << y-lado << " " << z-lado << "\n"
                    << x+lado << " " << y-lado << " " << z-lado << "\n"
                    << x+lado << " " << y+lado << " " << z-lado << "\n"
                    << x-lado << " " << y+lado << " " << z+lado << "\n"
                    << x-lado << " " << y-lado << " " << z+lado << "\n"
                    << x+lado << " " << y-lado << " " << z+lado << "\n"
                    << x+lado << " " << y+lado << " " << z+lado << "\n" ;
                }
            }
        }
    }

     for(int x=0;x<nx;x++){
        for(int y=0;y<ny;y++){
            for(int z=0;z<nz;z++){
                if(v[x][y][z].is0n==true){
                    f << 4 << " " << 0+faces << " " << 3+faces << " " << 2+faces << " " << 1+faces << " "
                    << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl
                    << 4 << " " << 4+faces << " " << 5+faces << " " << 6+faces << " " << 7+faces<< " "
                    << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl
                    << 4 << " " << 0+faces << " " << 1+faces << " " << 5+faces << " " << 4+faces << " "
                    << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl
                    << 4 << " " << 0+faces << " " << 4+faces << " " << 7+faces << " " << 3+faces << " "
                    << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl
                    << 4 << " " << 3+faces << " " << 7+faces << " " << 6+faces << " " << 2+faces << " "
                    << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl
                    << 4 << " " << 1+faces << " " << 2+faces << " " << 6+faces << " " << 5+faces<< " "
                    << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;
                    faces = faces+8;
                 }
            }
        }
    }

    total=0;
    f.close();
    /*std::string file;
    std::ifstream MyReadFile("Vida.off");
    while (getline (MyReadFile, file)) {
    std::cout << file;
    }
    MyReadFile.close();*/
}

vector<vector<Voxel> > Sculptor::getPlano(int i, int plano)
{
    vector< vector<Voxel> > retorno;
    vector<Voxel> linha;
    if(plano == XY){
        linha.resize(ny);
        for(int x=0; x<nx; x++){
            for(int y=0; y<ny; y++){
                linha[y].r = v[x][y][i].r;
                linha[y].g = v[x][y][i].g;
                linha[y].b = v[x][y][i].b;
                linha[y].is0n = v[x][y][i].is0n;
            }
            retorno.push_back(linha);
        }
    }
    else if(plano == YZ){
        linha.resize(nz);
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                linha[z].r = v[i][y][z].r;
                linha[z].g = v[i][y][z].g;
                linha[z].b = v[i][y][z].b;
                linha[z].is0n = v[i][y][z].is0n;
            }
            retorno.push_back(linha);
        }
    }
    else{
        linha.resize(nx);
        for(int z=0; z<nz; z++){
            for(int x=0; x<nx; x++){
                linha[x].r = v[x][i][z].r;
                linha[x].g = v[x][i][z].g;
                linha[x].b = v[x][i][z].b;
                linha[x].is0n = v[x][i][z].is0n;
            }
            retorno.push_back(linha);
        }
    }
    return retorno;
}
