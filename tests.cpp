#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("TASK A") 
{
  Coord3D pointA = {0, 0, 0};
  Coord3D pointB = {10,15,20};
  Coord3D pointC = {1.1, 2.2, 3.3};

  double result = length(&pointA);
  CHECK(result - 0.0 < 0.0001);

  result = length(&pointB);
  CHECK(result - 26.9258 < 0.0001);

  result = length(&pointC);
  CHECK(result - 4.11582< 0.0001);
}

TEST_CASE("TASK B") 
{
  Coord3D pointP1 = {11, 22, 33};
  Coord3D pointP2 = {5, 25, 1};
  CHECK_LE(fartherFromOrigin(&pointP1, &pointP2), &pointP2);

  Coord3D pointP3 = {1, 2, 23};
  Coord3D pointP4 = {5, 10, 15};
  CHECK_LE(fartherFromOrigin(&pointP3, &pointP4), &pointP3);
}

TEST_CASE("TASK C") 
{
    Coord3D pos = {0,0,0};
    Coord3D vel = {0, -12, 30};
    move(&pos, &vel, 2.0);
    CHECK(pos.x == 2);
    CHECK(pos.y == -10);
    CHECK(pos.z == 32);
  }

TEST_CASE("TASK E") 
{
  Coord3D *point1 = createCoord3D(5, 6, 9);
  Coord3D *point2 = createCoord3D(-12, 12, 122);
  Coord3D *point3 = createCoord3D(-100, -500, -121);

  CHECK(((*point1).x == 5 && (*point1).y == 6 && (*point1).z == 9));
  deleteCoord3D(point1);
  CHECK((*point1).x != 5); 
  CHECK(((*point2).x == -12 && (*point2).y == 12 && (*point2).z == 122));
  deleteCoord3D(point2);
  CHECK((*point2).x != -12);
  CHECK(((*point3).x == -100 && (*point3).y == -500 && (*point3).z == -121));
  deleteCoord3D(point3);
  CHECK((*point3).x != -100);
}