#ifndef _COLLISION_H
#define _COLLISION_H

#include <vector>

using namespace std;

class Collision {
  /* A collision event of two bodies of zero radius,
    records the time to collision, location of collision
     and after collision velocities.
   This object is needed because C++ functions cannot
    return more than one values. */
  public:
  Collision(){collision_pos.resize(3);new_vel1.resize(3);new_vel2.resize(3);};
  float time_to_collision;
  vector<float> collision_pos,new_vel1,new_vel2;
};
#endif