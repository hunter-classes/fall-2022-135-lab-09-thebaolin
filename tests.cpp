#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "coord3d.h"
#include <cmath>

Coord3D pointP = {10, 20, 30};
Coord3D pointQ = {-20, 21, -22};
Coord3D pointR = {124, 164, -42};
Coord3D pointS = {20, -12, 312};

Coord3D vel_1 = {1, -5, 0.2};
Coord3D vel_2 = {5, -3, 1};

TEST_CASE("TASK A") 
{
   Coord3D a = {15,25,36};
   Coord3D b = {20,30,40};
   Coord3D c = {0, 0, 0};
   Coord3D d = {-10, -20, -30};
   CHECK(length(&a) == length(&a));
   CHECK(length(&b) == length(&b));
   CHECK(length(&c) == 0.0);
   CHECK(length(&d) == length(&a));
}

TEST_CASE("TASK B") 
{
    CHECK(fartherFromOrigin(&pointP,&pointQ) == &pointP);
    CHECK(fartherFromOrigin(&pointP,&pointR) == &pointR);
    CHECK(fartherFromOrigin(&pointQ,&pointS) == &pointS);

}

TEST_CASE("TASK C") 
{
  move(&pointP,&vel_1,2.0);
  move(&pointQ,&vel_2,3.1);
  move(&pointR,&vel_1,10.0);
  CHECK(pointP.x == 12.0);
  CHECK(pointQ.x == -4.5);
  CHECK(pointR.x == 134.0);
  CHECK(pointP.y == 10.0);
  CHECK(pointQ.y == 11.7);
  CHECK(pointR.y == 114.0);
  CHECK(pointP.z == 30.4);
  CHECK(pointQ.z == -18.9);
  CHECK(pointR.z == -40);
}

TEST_CASE("TASK E") 
{
    Coord3D *p = createCoord3D(2, 7, 26);
    Coord3D *v = createCoord3D(1, -1.0, 3.5);
    move(p, v, 10);
    CHECK(p -> x == 12);
    CHECK(p -> y == -3);
    CHECK(p -> z == 61);
    move(p, v, -5);
    CHECK(p -> x == 7);
    CHECK(p -> y == 2);
    CHECK(p -> z == 43.5);

    delete(p);
    delete(v);
}