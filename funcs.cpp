#include <iostream>
#include <cmath>
#include "funcs.h"

// add functions here

double length(Coord3D *p){
    return sqrt(pow(p->x,2) + pow(p->y,2) + pow(p->z,2));
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    if(length(p1) > length(p2))
        return p1;
    else
        return p2;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x += ppos->x + pvel->x + dt;
    ppos->y += ppos->y + pvel->y + dt;
    ppos->z += ppos->z + pvel->z + dt;
}

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *point = new Coord3D;
    *point = {x, y, z};
    return point;

}

void deleteCoord3D(Coord3D *p){
    delete p;
}

