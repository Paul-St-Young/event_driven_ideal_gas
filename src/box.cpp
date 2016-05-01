
#include "box.h"

float Box::surface_area(){
  return 2.*(side_length[0]*side_length[1] 
           + side_length[1]*side_length[2] 
           + side_length[2]*side_length[0] );
}

Collision Box::next_collision_with(Particle* ptcl){
            
  // record the collision event
  Collision collision;
  collision.collision_pos = ptcl->get_pos();
  
  // calculate what happens after the collision
  collision.new_vel1 = ptcl->get_vel();
  int face_to_collide_with = 0;
  float time_to_collision = 1.0/0.0; // !! better define inf
            
  // loop through each wall, find time to collision
  for (unsigned int dir=0;dir<3;dir++){ // x,y,z
    for (unsigned int plus=0;plus<2;plus++){ // -,+ direction
      
      float distance_to_wall = 0;
      // [position of wall - position of particle] in given direction
      if (plus){
        distance_to_wall = side_length[dir]-ptcl->get_pos()[dir];
      } else {
        distance_to_wall = 0.0 - ptcl->get_pos()[dir];
      }
                                            
      float time = time_to_collision;
      if (distance_to_wall!=0){
        time = distance_to_wall/ptcl->get_vel()[dir];        
      }
      
      // if time is properly calculated this part is fine 
      //  assign nexy collision
      if (time >0 && time < time_to_collision){
        // enumerate faces (-x,+x,-y,+y,-z,+z) -> (0,1,2,3,4,5)
        face_to_collide_with = dir*2+plus;
        time_to_collision = time;
      }
                                            
    }
  }

  collision.time_to_collision = time_to_collision;
  for (unsigned int dir=0;dir<3;dir++){ // x,y,z
    for (unsigned int plus=0;plus<2;plus++){ // -,+ direction
      if (dir*2+plus==face_to_collide_with){
        collision.new_vel1[dir] = -1.*ptcl->get_vel()[dir];      
      }
    }
  }

  return collision;
}