#ifndef VOXEL_H_INCLUDED
#define VOXEL_H_INCLUDED

typedef struct{
    float r,g,b,a;
    bool is0n;
}Voxel;

typedef struct{
    int x,y,z;
    bool exists;
} VoxelCoords;

#endif // VOXEL_H_INCLUDED
