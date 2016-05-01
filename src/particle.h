#ifndef _PARTICLE_H
#define _PARTICLE_H

#include <vector>

using namespace std;

class Particle {
    
    vector<float> pos;
    vector<float> vel;
    float mass;
    
    public:
    
    Particle(){mass=1.;pos.resize(3);vel.resize(3);};
    
    vector<float> get_pos(){return this->pos;};
    vector<float> get_vel(){return this->vel;};
    void change_pos(vector<float> pos){this->pos=pos;};
    void change_pos_component(int idx, float value){this->pos[idx]=value;};
    void change_vel(vector<float> vel){this->vel=vel;};
    void change_vel_component(int idx, float value){this->vel[idx]=value;};
    
};
# endif