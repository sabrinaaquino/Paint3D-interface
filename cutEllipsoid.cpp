#include "cutEllipsoid.h"

cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
}

cutEllipsoid::~cutEllipsoid()
{
    //dtor
}

void cutEllipsoid::draw(Sculptor &t){
    int i,j,k;
    double _rx=rx/2.0,_ry=ry/2.0,_rz=rz/2.0;
    double dist;
    for(i=0;i<xcenter+rx;i++){
        for(j=0;j<ycenter+ry;j++){
            for(k=0;k<zcenter+rz;k++){
                dist = (i-xcenter/2.0) * (i-xcenter/2.0) / (_rx*_rx) +
                (j-ycenter/2.0) * (j-ycenter/2.0) / (_ry*_ry) +
                (k-zcenter/2.0) * (k-zcenter/2.0) / (_rz*_rz);
                if((dist<=1) && (i<xcenter+rx && i>=0) && (j<ycenter+ry && j>=0) && (k<zcenter+rz && k>=0)){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
