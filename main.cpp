#include <iostream>
#include "coord3d.h"
#include "funcs.h"

int main()
{ 
  Coord3D pointP = {5,15,20};
  Coord3D pointQ = {-20, 10, -5};

  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1,-8, 2};

  std::cout<<"TASK A"<<std::endl;
  std::cout << length(&pointP) << std::endl;
  std::cout<<std::endl;

  std::cout<<"TASK B"<<std::endl;
  Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
  std::cout << "Address of pointP: " << &pointP << "\n" << "Adress of pointQ: " << &pointQ << "\n" << "Answer: " << ans << "\n";
  std::cout<<std::endl;

  std::cout<<"TASK C"<<std::endl;
  move(&pos, &vel, 2.0);
  std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
  std::cout<<std::endl;

  std::cout<<"TASK E"<<std::endl;
  Coord3D *newpos = createCoord3D(12, 23, -20);
  Coord3D *newvel = createCoord3D(26, 96, 90);
  move(newpos, newvel, 10.0);
  std::cout << "Coordinates after 10 seconds: " << (*newpos).x << " " << (*newpos).y << " " << (*newpos).z << std::endl;

  deleteCoord3D(newpos);
  deleteCoord3D(newvel);

  return 0;
}
