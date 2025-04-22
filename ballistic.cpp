/*
Name: Rayen Ben Ismail
Date: 2/20/2025
Description: This program is a ballistics calculator
file naming: ballistic.cpp
*/

#include <iostream>
#include "libs\iotools.h"
using namespace std;

class Projectile {
    public:

    float x0;
    float y0; 

    float yFloor;
    float xWall;

    float crossSection;
    float fCoef;
    bool friction;

    private:

    float xcoord();

    float ycoord();

};

int main(){

    return 0;
}