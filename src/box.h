#ifndef _BOX_H
#define _BOX_H

#include "particle.h"
#include "collision.h"

class Box {
    // cubic box with one cornor at the origin
    vector<float> side_length;
    public:
    Box(float lx,float ly,float lz){
        side_length.resize(3);
        side_length[0] = lx;
        side_length[1] = ly;
        side_length[2] = lz;
    };
    float surface_area();
    
    Collision next_collision_with(Particle* ptcl);
    
};
#endif