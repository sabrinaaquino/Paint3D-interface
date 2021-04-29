#include "putSphere.h"
#include <iostream>


putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a){

    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
    this->r=r; this->g=g; this->b=b; this->a=a;
}

putSphere::~putSphere()
{
    //dtor
}

void putSphere::draw(Sculptor &t){
    int i,j,k;
    t.setColor(r,g,b,a);
    double r=radius/2.0;
    double dist;
    for(i=0; i<(2*xcenter); i++){
        for(j=0; j<(2*ycenter); j++){
            for(k=0; k<(2*zcenter); k++){
                dist = (i-xcenter/2.0) * (i-xcenter/2.0 ) / (r*r) +
                       (j-ycenter/2.0) * (j-ycenter/2.0) / (r*r) +
                       (k-zcenter/2.0) * (k-zcenter/2.0 ) / (r*r);
                if(dist<=1.0){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}

