/*
 * Gravity Simulation
 * CS 410  Project
 *
 * main(), myDisplay(), myIdle(), readin()
 * author: Chenjun Li
 *
 * class SpaceObject
 * author: Sean Dashner
 *
 * Tip 1: Please include PlanetsDatabase.txt
 *        as database in the folder.
 *
 * Tip 2: Please install glut.
 *
 *
 * This is just sample version, it runs, but not follows the
 * gravity. It can only include sun, earth and moon.
 *
 * I compile and run it on IDE: code blocks (under windows 7)
 * If you run the program under a different environment,
 * Please adjust the header file.
 *
 * Everything in the database will be read in and store
 * in the spaceObjectVector which is in global scope and
 * is set static. All controls works on this vector.
 *
 * Need to do: I need a physics() function. Which can change
 * the current position(x,y,z) after one day(a unit in program).
 * The physics() function will be used in the myIdle() function.
 */

 /* Modified by Tianyu Kang
  * implemented physics part
  * don't forget download test03.txt for testing SUN-EARTH-MOON system!
  *
  * Modified by David Argueta
  * implemented Solar System part - the space objects are stored in this system
  * and are assigned to stars, planets, or moons.
  *
  * The planets will also have reference to their moons.
  * This could possibly make the physics easier if you need to assign the
  * moon orbits to their planet and then the planet to the sun.
  * The physics would probably need to be adjusted in order to take
  * in a solar system. Right now it still works as before.
  * I also have the solar system keep reference to the sun, but not quite
  * sure it will be needed since I also have it as part of the stars.
  *
  * I condensed the code in order to loop through necessary times
  * for each object and added setColor for code reuse
  * I also updated the moon name in test03.txt in order to specify what planet it belongs to:
  * 	EarthMoon1
  *
  */
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "SpaceObject.h"
#include "Physics.h"
#include "SolarSystem.h"


using namespace std;
void readin(void);
void myDisplay(void);
void setColors(GLfloat surfaceColor[], GLfloat specularColor[], GLfloat emissionColor[], float eMultiplier, SpaceObject spaceObject);

SpaceObject spaceObjectBuffer;
static vector<SpaceObject> spaceObjectVector;
static SolarSystem ss;
enum {NAME, X, Y, Z, MASS, XSPEED, YSPEED, ZSPEED, RADIUS, MYRED, MYGREEN, MYBLUE, MYTYPE};
Physics *phy;
float xxx = 5e8;
static float viewX = 0.0;
static float viewY = 0.0;
static float viewZ = -300.0;
static int speed = 360;


void readin(void)
{
    int inputType = NAME;
    string info;
    cout << "Welcome to Gravity Simulation system!" << endl;
        ifstream infile("test03.txt");
    if(!infile)//if can't open database, we still have an empty space object vector;
    {
        cerr << "Error, unable to open planets database.";
    }
    else
    {
         cout << "Database loaded!" << endl;
        while(infile >> info)//read in information from database one by one
        {
            switch(inputType)
            {
            case NAME:
                spaceObjectBuffer._planetName = info;
                inputType = X;
                break;
            case X:
                spaceObjectBuffer._x = atof(info.c_str());//convert string to char[] then to float
                inputType = Y;
                break;
            case Y:
                spaceObjectBuffer._y = atof(info.c_str());
                inputType = Z;
                break;
            case Z:
                spaceObjectBuffer._z = atof(info.c_str());
                inputType = MASS;
                break;
            case MASS:
                spaceObjectBuffer._mass = atof(info.c_str());
                inputType = XSPEED;
                break;
            case XSPEED:
                spaceObjectBuffer._x_speed = atof(info.c_str());
                inputType = YSPEED;
                break;
            case YSPEED:
                spaceObjectBuffer._y_speed = atof(info.c_str());
                inputType = ZSPEED;
                break;
            case ZSPEED:
                spaceObjectBuffer._z_speed = atof(info.c_str());
                inputType = RADIUS;
                break;
            case RADIUS:
                spaceObjectBuffer._radius = atof(info.c_str());
                inputType = MYRED;
                break;
            case MYRED:
                spaceObjectBuffer._red = atof(info.c_str());
                inputType = MYGREEN;
                break;
            case MYGREEN:
                spaceObjectBuffer._green = atof(info.c_str());
                inputType = MYBLUE;
                break;
            case MYBLUE:
                spaceObjectBuffer._blue = atof(info.c_str());
                inputType = MYTYPE;
                break;
            case MYTYPE:
                spaceObjectBuffer._type = info;
                spaceObjectVector.push_back(spaceObjectBuffer);
                inputType = NAME;
            }
        }
    }
    ss.update(spaceObjectVector);

}

void addLight(float x,float y,float z,int _lightNum){
    GLfloat light_position[] = {x/xxx, y/xxx, z/xxx, 1.0f};
    GLfloat light_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

    glLightfv(GL_LIGHT0+_lightNum, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0+_lightNum, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0+_lightNum, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0+_lightNum, GL_SPECULAR, light_specular);

    glEnable(GL_LIGHT0+_lightNum);
//    cout<<"light"<<lightNum<<" set at "<<x<<","<<y<<","<<z<<endl;
}

void systemDisplay(){

    //glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120, 1280.0f/720, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewX, viewY, viewZ, 0.0, 0.0, 10.0, 0.0, 1.0, 0.0);

    //light
    //only suns will have light

    int lightNum =0;
    for(int i=0; i < ss.getStars().size(); i++){
    	addLight(ss.getStars().at(i)._x, ss.getStars().at(i)._y, ss.getStars().at(i)._z,lightNum++);
    }

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    //show all suns and planets
    GLfloat surfaceColor[4];
    GLfloat emissionColor[4];
    GLfloat specularColor[4];
    surfaceColor[3]=1.0f;
    emissionColor[3]=1.0f;
    specularColor[3]=1.0f;

    for(int i=0; i < ss.getPlanets().size(); i++){
        setColors(surfaceColor, specularColor, emissionColor, 0.03f,ss.getPlanets()[i].getSpaceObject());

        glutSolidSphere(1000 * ss.getPlanets()[i].getSpaceObject()._radius/xxx, 8, 8);
        glTranslatef(-ss.getPlanets()[i].getSpaceObject()._x/xxx, -ss.getPlanets()[i].getSpaceObject()._y/xxx, -ss.getPlanets()[i].getSpaceObject()._z/xxx);

        if(ss.getPlanets()[i].hasMoon()){
        	for(int j = 0; j < ss.getPlanets()[i].getMoons().size(); j++){
        		setColors(surfaceColor, specularColor, emissionColor, 0.03f,ss.getPlanets()[j].getMoons()[j]);

        		glutSolidSphere(500 * ss.getPlanets()[j].getMoons()[j]._radius/xxx, 8, 8);
        		glTranslatef(-ss.getPlanets()[j].getMoons()[j]._x/xxx, -ss.getPlanets()[j].getMoons()[j]._y/xxx, -ss.getPlanets()[j].getMoons()[j]._z/xxx);
        	}
        }
    }
    for(int i=0; i < ss.getStars().size(); i++){
    	setColors(surfaceColor, specularColor, emissionColor, 1.0f, ss.getStars()[i]);

    	glutSolidSphere(50*ss.getStars()[i]._radius/xxx, 16, 16);
    	glTranslatef(-ss.getStars()[i]._x/xxx, -ss.getStars()[i]._y/xxx, -ss.getStars()[i]._z/xxx);
    }

    glFlush();
    glutSwapBuffers();
}

void setColors(GLfloat surfaceColor[], GLfloat specularColor[], GLfloat emissionColor[], float eMultiplier, SpaceObject spaceObject){
	surfaceColor[0] =spaceObject._red/2;
	surfaceColor[1] =spaceObject._green/2;
	surfaceColor[2] =spaceObject._blue/2;
	specularColor[0] =spaceObject._red;
	specularColor[1] =spaceObject._green;
	specularColor[2] =spaceObject._blue;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, surfaceColor);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 3.0f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularColor);

	emissionColor[0] =spaceObject._red*eMultiplier;
	emissionColor[1] =spaceObject._green*eMultiplier;
	emissionColor[2] =spaceObject._blue*eMultiplier;
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissionColor);

	glTranslatef(spaceObject._x/xxx, spaceObject._y/xxx, spaceObject._z/xxx);
}

void myIdle(void)
{
    for(int t=0;t< speed;t++)
        phy->step();
    ss.update(phy->currentStep);
    systemDisplay();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case 'd':
            if(viewZ != 0.0)
            {
                viewX = -viewZ;
                viewZ = 0.0;
            }
            else
            {
                viewZ = viewX;
                viewX = 0.0;
            }
            break;

        case 'a':
            if(viewZ != 0.0)
            {
                viewX = viewZ;
                viewZ = 0.0;
            }
            else
            {
                viewZ = -viewX;
                viewX = 0.0;
            }
            break;
        case 'w':
            if(viewX > 1.0)
            {
                viewX = viewX - 1.0;
            }
            else if(viewX < -1.0)
            {
                viewX = viewX + 1.0;
            }
            else if(viewZ > 1.0)
            {
                viewZ = viewZ - 1.0;
            }
            else if(viewZ < -1.0)
            {
                viewZ = viewZ + 1.0;
            }
            break;
        case 's':

            if(viewX >= 1.0 && viewX < 1000.0) {
                viewX += 1.0;
            }
            else if (viewX <= -1.0 && viewX > -1000.0) {
                viewX -= 1.0;

            }
            else if (viewZ >= 1.0 && viewZ < 1000.0){
                viewZ += 1.0;
            }
            else if (viewZ <= -1.0 && viewZ > -1000.0){
                viewZ -= 1.0;
            }
            
            break;
        case ',':
            if (speed <= 360){
                break;
            }
            else {
                speed /= 2;
                break; 
            }
        case '.':
            if (speed >= 46080) {
                break;
            } else {
                speed *= 2;
                break;
            }

    }
    systemDisplay();
}

int main(int argc, char *argv[])
{
    readin();
    phy = new Physics(ss.getEntireSystem(),1);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,720);
    glutCreateWindow("The first OpenGl project");
    glutDisplayFunc(&systemDisplay);
    glutIdleFunc(&myIdle);
    glutKeyboardFunc(&key);
    glutMainLoop();
    return 0;
}
