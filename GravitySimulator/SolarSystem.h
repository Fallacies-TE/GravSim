/*
 * SolarSystem.h
 *
 *  Created on: Apr 10, 2014
 *      Author: David Argueta
 */



#ifndef SOLARSYSTEM_H_
#define SOLARSYSTEM_H_


#include <vector>
#include <map>

using namespace std;

class SolarSystem {
public:
	const double WIDTH = 0;
	const double HEIGHT = 0;
	const double DEPTH = 0;

	SolarSystem(vector<SpaceObject> spaceObjects);
	virtual ~SolarSystem();
	vector<SpaceObject> getPlanets();

	SpaceObject sun;

private:
	const string MOONTEXT = "moon";
	vector<SpaceObject> spaceObjects;
	map<string, Planet> planets;
	void createSun();
	void assignObjects(map<string, Planet> holder, string type);
	void assignMoons();
};

#endif /* SOLARSYSTEM_H_ */
