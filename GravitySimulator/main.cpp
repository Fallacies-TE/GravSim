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
#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
void readin(void);
void myDisplay(void);

class SpaceObject
{
private:
    string _planetName;
    float _x;
    float _y;
    float _z;
    float _mass;
    float _x_speed;
    float _y_speed;
    float _z_speed;
    float _radius;
    float _red;
    float _green;
    float _blue;
    string _type;

public:
    SpaceObject();// default constructor
    SpaceObject(  // initializing constructor for SpaceObject
        string _planetName,
        float _x,
        float _y,
        float _z,
        float _mass,
        float _x_speed,
        float _y_speed,
        float _z_speed,
        float _radius,
        float _red,
        float _green,
        float _blue,
        string _type);

    string getPlanetName(){return _planetName;}
    void setPlanetName(string name){_planetName = name;}
    float get_x(){return _x;}
    void set_x(float x){_x = x;}
    float get_y(){return _y;}
    void set_y(float y){_y = y;}
    float get_z(){return _z;}
    void set_z(float z){_z = z;}
    float getMass(){return _mass;}
    void setMass(float mass){_mass = mass;}
    float get_x_speed(){return _x_speed;}
    void set_x_speed(float x){_x_speed = x;}
    float get_y_speed(){return _x_speed;}
    void set_y_speed(float y){_y_speed = y;}
    float get_z_speed(){return _z_speed;}
    void set_z_speed(float z){_z_speed = z;}
    float getRadius(){return _radius;}
    void setRadius(float x){_radius = x;}
    float getRed(){return _red;}
    void setRed(float red){_red = red;}
    float getGreen(){return _green;}
    void setGreen(float green){_green = green;}
    float getBlue(){return _blue;}
    void setBlue(float blue){_blue = blue;}
    string getType(){return _type;}
    void setType(string t){_type = t;}
};

SpaceObject::SpaceObject(){}
SpaceObject::SpaceObject(
    string planetName,
    float x,
    float y,
    float z,
    float mass,
    float x_speed,
    float y_speed,
    float z_speed,
    float radius,
    float red,
    float green,
    float blue,
    string type)
    {
        _planetName = planetName;
        _x = x;
        _y = y;
        _z = z;
        _mass = mass;
        _x_speed = x_speed;
        _y_speed = y_speed;
        _z_speed = z_speed;
        _radius = radius;
        _red = red;
        _green = green;
        _blue = blue;
        _type = type;
    }

SpaceObject spaceObjectBuffer;
static vector<SpaceObject> spaceObjectVector;
enum {NAME, X, Y, Z, MASS, XSPEED, YSPEED, ZSPEED, RADIUS, MYRED, MYGREEN, MYBLUE, MYTYPE};
static GLfloat angle = 0.0f;
static int day = 200; // day

void readin(void)
{
    int inputType = NAME;
    string info;
    cout << "Welcome to Gravity Simulation system!" << endl;
        ifstream infile("PlanetsDatabase.txt");
    if(!infile)//if can't open database, we still have an empty space object vector;
    {
        cerr << "Error, unable to open planets database.";
    }
    else
    {
        while(infile >> info)//read in information from database one by one
        {
            switch(inputType)
            {
            case NAME:
                spaceObjectBuffer.setPlanetName(info);
                inputType = X;
                break;
            case X:
                spaceObjectBuffer.set_x(atof(info.c_str()));//convert string to char[] then to float
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
                spaceObjectBuffer.setRed(atof(info.c_str()));
                inputType = MYGREEN;
                break;
            case MYGREEN:
                spaceObjectBuffer.setGreen(atof(info.c_str()));
                inputType = MYBLUE;
                break;
            case MYBLUE:
                spaceObjectBuffer.setBlue(atof(info.c_str()));
                inputType = MYTYPE;
                break;
            case MYTYPE:
                spaceObjectBuffer.setType(info);
                spaceObjectVector.push_back(spaceObjectBuffer);
                inputType = NAME;
            }
        }
    }
}

void myDisplay(void)
{
    //glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 1, 1, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 5.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    //light
    {
        GLfloat sun_light_position[] = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat sun_light_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat sun_light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
        GLfloat sun_light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

        glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT,  sun_light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  sun_light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
    }

    for(int i=0; i < spaceObjectVector.size(); i++)
    {
        if(spaceObjectVector[i].getPlanetName() == "Sun")
        {//draw sun
            GLfloat sun_mat_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
            GLfloat sun_mat_diffuse[]  = {0.0f, 0.0f, 0.0f, 1.0f};
            GLfloat sun_mat_specular[] = {0.0f, 0.0f, 0.0f, 1.0f};
            GLfloat sun_mat_emission[] = {1.0f, 0.0f, 0.0f, 0.0f};
            GLfloat sun_mat_shininess  = 0.0f;

            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   sun_mat_ambient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   sun_mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  sun_mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  sun_mat_emission);
            glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, sun_mat_shininess);

            glColor3f(spaceObjectVector[i].getRed(), spaceObjectVector[i].getGreen(), spaceObjectVector[i].getBlue());
            glTranslatef(spaceObjectVector[i].get_x(), spaceObjectVector[i].get_y(), spaceObjectVector[i].get_z());
            glutSolidSphere(spaceObjectVector[i].getRadius(), 30, 30);
        }

        if(spaceObjectVector[i].getPlanetName() == "Earth") //Just a sample to make sure it runs. When The program can be run under gravity, don't need this match
        {//draw earth
            GLfloat earth_mat_ambient[]  = {spaceObjectVector[i].getRed()/2, spaceObjectVector[i].getGreen()/2, spaceObjectVector[i].getBlue()/2, 1.0f};
            GLfloat earth_mat_diffuse[]  = {spaceObjectVector[i].getRed()/2, spaceObjectVector[i].getGreen()/2, spaceObjectVector[i].getBlue()/2, 1.0f};
            GLfloat earth_mat_specular[] = {spaceObjectVector[i].getRed(), spaceObjectVector[i].getGreen(), spaceObjectVector[i].getBlue(), 1.0f};
            GLfloat earth_mat_emission[] = {spaceObjectVector[i].getRed()/2, spaceObjectVector[i].getGreen()/2, spaceObjectVector[i].getBlue()/2, 1.0f};
            GLfloat earth_mat_shininess  = 5.0f;

            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   earth_mat_ambient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   earth_mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  earth_mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  earth_mat_emission);
            glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, earth_mat_shininess);

            glColor3f(spaceObjectVector[i].getRed(), spaceObjectVector[i].getGreen(), spaceObjectVector[i].getBlue());
            glRotatef(day/360.0*360.0, 0.0f, -1.0f, 0.0f);//Don't need it if works by gravity
            glTranslatef(spaceObjectVector[i].get_x(), spaceObjectVector[i].get_y(), spaceObjectVector[i].get_z());
            glutSolidSphere(spaceObjectVector[i].getRadius(), 16, 16);
        }
        else //for moon, if gravity works, don't need this else and just think it a regular planet as earth
        {//draw moon
            GLfloat moon_mat_ambient[]  = {spaceObjectVector[i].getRed()/2, spaceObjectVector[i].getGreen()/2, spaceObjectVector[i].getBlue()/2, 1.0f};
            GLfloat moon_mat_diffuse[]  = {spaceObjectVector[i].getRed()/2, spaceObjectVector[i].getGreen()/2, spaceObjectVector[i].getBlue()/2, 1.0f};
            GLfloat moon_mat_specular[] = {spaceObjectVector[i].getRed(), spaceObjectVector[i].getGreen(), spaceObjectVector[i].getBlue(), 1.0f};
            GLfloat moon_mat_emission[] = {spaceObjectVector[i].getRed()/2, spaceObjectVector[i].getGreen()/2, spaceObjectVector[i].getBlue()/2, 1.0f};
            GLfloat moon_mat_shininess  = 5.0f;

            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   moon_mat_ambient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   moon_mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  moon_mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  moon_mat_emission);
            glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, moon_mat_shininess);

            glColor3f(spaceObjectVector[i].getRed(), spaceObjectVector[i].getGreen(), spaceObjectVector[i].getBlue());
            glRotatef(day/30.0*360.0 - day/360.0*360.0, 0.0f, -1.0f, 0.0f);//Don't need it if works by gravity
            glTranslatef(spaceObjectVector[i].get_x(), spaceObjectVector[i].get_y(), spaceObjectVector[i].get_z());
            glutSolidSphere(spaceObjectVector[i].getRadius(), 16, 16);
        }
    }
    glFlush();
    glutSwapBuffers();
}

void myIdle(void)
{
    ++day;
    //here we need run physics() one time which change the current x y z after one day
    //by calculate current speed and gravity
    if( day >= 360 )
        day = 0;
    for(int i = 0; i < 15000000; i++)//wait, let the picture change slowly
        ;
    myDisplay();
}

int main(int argc, char *argv[])
{
    readin();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("The first OpenGl project");
    glutDisplayFunc(&myDisplay);
    glutIdleFunc(&myIdle);
    glutMainLoop();
    return 0;
}
