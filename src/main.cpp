#include <iostream>
#include <numeric> // inner_product
#include <cmath> // sqrt

#include "particle.h"
#include "box.h"

int main(){
    
    // initialize unit volume box
    Box box(1,1,1);
    
    // initialize particle at center of box
    Particle ptcl;
    vector<float> pos0 = {0.5,0.5,0.5};
    ptcl.change_pos(pos0);
    
    // give the particle a push
    ptcl.change_vel_component(0,0.5);
    ptcl.change_vel_component(1,0.2);
    ptcl.change_vel_component(2,-0.3);
    
    // simulate some number of collision events, record total impulse
    //  deposited onto the surface of the box
    
    float t = 0.0;
    float T = 36000.0;
    int max_event = 1;
    
    vector<double> dvel(3);
    float impulse = 0.0;
    
    unsigned int ievent = 0;
    for (ievent = 0; ievent < max_event; ievent += 1){
        
        // find next collision event
        Collision col = box.next_collision_with(&ptcl);
        
        // calculate impulse
        for (unsigned int dir=0;dir<3;dir++){
            dvel[dir] = col.new_vel1[dir] - ptcl.get_vel()[dir];
            float dv2 = inner_product(dvel.begin(),dvel.end(),dvel.begin(),0);
            impulse += sqrt(dv2);
        }
        
        // let particle know of its collision
        ptcl.change_pos(col.collision_pos);
        ptcl.change_vel(col.new_vel1);
        
        // increment time
        t += col.time_to_collision;
        if (t>T) break;
    }
    cout << ievent << endl;
    cout << impulse/t/box.surface_area() << endl;
    
    return 0;
}