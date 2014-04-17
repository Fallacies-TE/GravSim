// Gravity Sim Project
// Sean Dashner
// SpaceObject.h header file
#include <iostream>

#ifndef SpaceObject_h
#define SpaceObject_h

class SpaceObject {

	private:
		string _planetName;
		double _x; 
		double _y; 
		double _z; 
		double _mass; 
		double _x_speed;
		double _y_speed;
		double _z_speed; 
		double _radius; 
		int _red;
		int _green;
		int _blue; 
		string _type;

	public:
		// default constructor
		SpaceObject ();
		// initializing constructor for SpaceObject
		SpaceObject (
						string _planetName,
						double _x, 
						double _y, 
						double _z, 
						double _mass, 
						double _x_speed,
						double _y_speed,
						double _z_speed, 
						double _radius, 
						int _red,
						int _green,
						int _blue, 
						string _type
					);


};





#endif
