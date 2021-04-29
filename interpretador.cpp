#include "interpretador.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"
#include "outSphere.h"

using namespace std;

interpretador::interpretador()
{

}

int interpretador::getDimx(){
    return dimx;
}

int interpretador::getDimy(){
    return dimy;
}

int interpretador::getDimz(){
    return dimz;
}

vector<FiguraGeometrica *> interpretador::parse(string filename) {
    vector<FiguraGeometrica *> input;
        ifstream fs;
        stringstream sstr;
        string str, token;

        fs.open("usuario.txt");
        if(!fs.is_open()){
            cout<<"Erro ao abrir o arquivo ou arquivo inexistente"<<endl;
            exit(0);
        }
        else{
            cout<<"Arquivo aberto com sucesso!"<<endl;
        }

        while(fs.good()){
            getline(fs, str);
            sstr.clear();
            sstr.str(str);
            sstr>>str;
            if(str.compare("dim")==0){
               int x, y, z;
               sstr >> x >> y >> z;
            }
            else if(str.compare("putvoxel")==0){
               int x,y,z;
               float r, g, b, a;
               sstr >> x >> y >> z >> r >> g >> b >> a;
               input.push_back(new putVoxel(x,y,z,r,g,b,a));
            }
            else if(str.compare("cutvoxel")==0){
               int x,y,z;
               sstr >> x >> y >> z;
               input.push_back(new cutVoxel(x,y,z));
            }
            else if(str.compare("outsphere")==0){
               int xcenter, ycenter, zcenter, radius;
               sstr >> xcenter >> ycenter >> zcenter >> radius;
               input.push_back(new outSphere(xcenter, ycenter, zcenter, radius));
            }
            else if(str.compare("putbox")==0){
               int x0, x1, y0, y1, z0, z1;
               float r, g, b, a;
               sstr >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
               input.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
            }
            else if(str.compare("cutbox")==0){
               int x0,x1,y0,y1,z0,z1;
               sstr >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
               input.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
            }
            else if(str.compare("putsphere")==0){
               int xcenter, ycenter, zcenter, radius;
               float r, g, b, a;
               sstr >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
               input.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
            }
            else if(str.compare("cutsphere")==0){
               int xcenter, ycenter, zcenter, radius;
               sstr >> xcenter >> ycenter >> zcenter >> radius;
               input.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
            }
            else if(str.compare("putellipsoid")==0){
               int xcenter, ycenter ,zcenter, rx, ry, rz;
               float r, g, b, a;
               sstr >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
               input.push_back(new putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
            }
            else if(str.compare("cutellipsoid")==0){
               int xcenter, ycenter ,zcenter, rx, ry, rz;
               sstr >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
               input.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
            }

        }

        return (input);
}


