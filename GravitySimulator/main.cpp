/*
 author: Chenjun Li
 4/17/2014
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "SpaceObject.h"
#include "SolarSystem.h"
#include "Ship.h"

using namespace std;

SpaceObject spaceObjectBuffer; //used to buffer each space object.
vector<Planet> spaceObjectVectorBuffer;//
enum {NAME, X, Y, Z, MASS, XSPEED, YSPEED, ZSPEED, RADIUS, MYRED, MYGREEN, MYBLUE, MYTYPE};

int main()
{
    int inputType = NAME;
    string info;
    cout << "Welcome to Gravity Simulation system!" << endl;
/*
Read in the database. We can just use a .txt file with special format. Here I give the format:
name  x  y  z mass xSpeed ySpeed zSpeed radius red green blue type '\n'
So in our database(Here: "PlanetsDatabase.txt"), each line includes all attributes of one planet.
Ex: earth 1.0  1.0  1.0  100.0  2.0  2.0  2.0  10.0  12 32 24  planet
    moon  10.0 5.0  5.0  5.0    3.0  3.0  3.0  3.0    3 12 31  satellite
    sun   10.0 10.0 10.0 1000.0 0.0  0.0  0.0  100.0 100 10 0  star
    ...
*/
    ifstream infile("PlanetsDatabase.txt");
    if(!infile)//if can't open database, we still have an empty space object vector;
    {
        cerr << "Error, unable to open planets database.";
    }
    else
    {
        while(infile >> info)//read in string from database one by one
        {
            switch(inputType)
            {
            case NAME:
                spaceObjectBuffer.setPlantName(info);
                inputType = X;
                break;
            case X:
                spaceObjectBuffer.set_x(atof(info.c_str()));//convert string to char[] then to double
                inputType = Y;
                break;
            case Y:
                spaceObjectBuffer.set_y(atof(info.c_str()));
                inputType = Z;
                break;
            case Z:
                spaceObjectBuffer.set_z(atof(info.c_str()));
                inputType = MASS;
                break;
            case MASS:
                spaceObjectBuffer.setMass(atof(info.c_str()));
                inputType = XSPEED;
                break;
            case XSPEED:
                spaceObjectBuffer.set_x_speed(atof(info.c_str()));
                inputType = YSPEED;
                break;
            case YSPEED:
                spaceObjectBuffer.set_y_speed(atof(info.c_str()));
                inputType = ZSPEED;
                break;
            case ZSPEED:
                spaceObjectBuffer.set_z_speed(atof(info.c_str()));
                inputType = RADIUS;
                break;
            case RADIUS:
                spaceObjectBuffer.setRadius(atof(info.c_str()));
                inputType = MYRED;
                break;
            case MYRED:
                spaceObjectBuffer.setRed(atoi(info.c_str()));
                inputType = MYGREEN;
                break;
            case MYGREEN:
                spaceObjectBuffer.setGreen(atoi(info.c_str()));
                inputType = MYBLUE;
                break;
            case MYBLUE:
                spaceObjectBuffer.setBlue(atoi(info.c_str()));
                inputType = MYTYPE;
                break;
            case MYTYPE:
                spaceObjectBuffer.setType(info);
                spaceObjectVectorBuffer.push_back(spaceObjectBuffer);
                inputType = NAME;
            }
        }
    }

/*
Here we have a space object vector: spaceObjectVectorBuffer
which hold all space objects we read from database.
Now read it in to construct SolarSystem object.
*/

    SolarSystem mySolarSystem(spaceObjectVectorBuffer);


    physics(mySolarSystem);

//to do OpenGL part below

    return 0;
}
