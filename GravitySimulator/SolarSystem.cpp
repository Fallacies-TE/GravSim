/*
 * SolarSystem.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: David Argueta
 *
 *      This class will take in space objects retrieved by parser.
 *      It will assign break out the space objects by planets and then assign
 *      any moons to it.
 *
 *      It will also house the information of the size of the solar system and have
 *      a reference to the sun, which is just another space object
 */

#include "SolarSystem.h"


SolarSystem::SolarSystem(vector<SpaceObject> spaceObjects) {

	this->spaceObjects.swap(spaceObjects);
	assignObjects(planets, "planet");
	assignMoons();

}

SolarSystem::~SolarSystem() {
	// TODO Auto-generated destructor stub
}

vector<SpaceObject> SolarSystem::getPlanets(){
	//TODO
	return planets;
}

/**
 * Will create the sun for this solar system
 */
void SolarSystem::createSun(){
	//TODO
}

/**
 * This function will take the info from the parser and pass it into corresponding
 * map that has been passed through
 *
 * @param holder : map passed in where parser info will be stored
 * @param type : the type name we are looking for in the parser
 */
void SolarSystem::assignObjects(map<string, Planet> holder, string type){
	for(SpaceObject object : spaceObjects){
		if(object.type() == type)
			holder.insert( pair<string, Planet>(object.type(),object));

	}
}

/**
 * This will look through the parser results and match moons to their corresponding
 * planet.
 */
void SolarSystem::assignMoons(){
	string planet;
	map<string, Planet>::iterator found;

	for(SpaceObject moon : spaceObjects){
			if(moon.type().find(MOONTEXT) != string::npos){ // Found type that contains moon specifier
				planet(moon.type().substr(0, moon.type().size()-MOONTEXT.size())); //Taking the planet name it belongs to
				found = planets.find(planet);
				if(found == planets.end())
					cout << "not found";
				else
					found->second.addMoon(moon); // Adding moon to planet
			}


		}
}

