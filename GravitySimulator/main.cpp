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
  */
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "SpaceObject.h"
#include "Physics.h"


using namespace std;
void readin(void);
void myDisplay(void);

SpaceObject spaceObjectBuffer;
static vector<SpaceObject> spaceObjectVector;
enum {NAME, X, Y, Z, MASS, XSPEED, YSPEED, ZSPEED, RADIUS, MYRED, MYGREEN, MYBLUE, MYTYPE};
Physics *phy;
float xxx = 5e8;
static float viewX = 0.0;
static float viewY = 0.0;
static float viewZ = -300.0;

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
    gluPerspective(90, 1280.0f/720, 1, 300);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewX, viewY, viewZ, 0.0, 0.0, 10.0, 0.0, 1.0, 0.0);

    //light
    //only suns will have light

    int lightNum =0;
    for(int i=0; i < spaceObjectVector.size(); i++){
        if(spaceObjectVector[i]._type=="Star"){
            addLight(spaceObjectVector[i]._x, spaceObjectVector[i]._y, spaceObjectVector[i]._z,lightNum++);
        }
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
    for(int i=0; i < spaceObjectVector.size(); i++){
        surfaceColor[0] =spaceObjectVector[i]._red/2;
        surfaceColor[1] =spaceObjectVector[i]._green/2;
        surfaceColor[2] =spaceObjectVector[i]._blue/2;
        specularColor[0] =spaceObjectVector[i]._red;
        specularColor[1] =spaceObjectVector[i]._green;
        specularColor[2] =spaceObjectVector[i]._blue;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, surfaceColor);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 3.0f);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularColor);

        if(spaceObjectVector[i]._type=="Star"){
            emissionColor[0] =spaceObjectVector[i]._red;
            emissionColor[1] =spaceObjectVector[i]._green;
            emissionColor[2] =spaceObjectVector[i]._blue;
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissionColor);
        }else{
            emissionColor[0] =spaceObjectVector[i]._red*0.03f;
            emissionColor[1] =spaceObjectVector[i]._green*0.03f;
            emissionColor[2] =spaceObjectVector[i]._blue*0.03f;
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissionColor);
        }

        glTranslatef(spaceObjectVector[i]._x/xxx, spaceObjectVector[i]._y/xxx, spaceObjectVector[i]._z/xxx);
        if(spaceObjectVector[i]._type == "Star"){
            glutSolidSphere(50*spaceObjectVector[i]._radius/xxx, 16, 16);
        }else if (spaceObjectVector[i]._type == "Planet") {
            glutSolidSphere(500 * spaceObjectVector[i]._radius/xxx, 8, 8);
        } else if (spaceObjectVector[i]._type == "Satellite"){
            glutSolidSphere(500 * spaceObjectVector[i]._radius/xxx, 8, 8);
        }
        glTranslatef(-spaceObjectVector[i]._x/xxx, -spaceObjectVector[i]._y/xxx, -spaceObjectVector[i]._z/xxx);
    }

    glFlush();
    glutSwapBuffers();
}

void myIdle(void)
{
    for(int t=0;t<360;t++)
        phy->step();
    spaceObjectVector = phy->currentStep;
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
            if(viewX >= 1.0 && viewX <300.0)
            {
                viewX = viewX + 1.0;
            }
            else if(viewX <= -1.0 && viewX > -300.0 )
            {
                viewX = viewX - 1.0;
            }
            else if(viewZ >= 1.0 && viewZ < 300.0)
            {
                viewZ = viewZ + 1.0;
            }
            else if(viewZ <= -1.0 && viewZ > -300.0)
            {
                viewZ = viewZ - 1.0;
            }
            break;
    }
    systemDisplay();
}

int main(int argc, char *argv[])
{
    readin();
    phy = new Physics(spaceObjectVector,1);
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
