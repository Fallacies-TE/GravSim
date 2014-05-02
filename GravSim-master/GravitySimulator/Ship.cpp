/*
 * Ship.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: David Argueta
 */

#include "Ship.h"

Ship::Ship() {

	createShip();

}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

void Ship::createShip(){
	createBody();
}

void Ship::createBody(){
	Vector bottomRight(1,1,1);
	Vector topRight(1,1,-1);
	Vector topLeft(-1,1,-1);
	Vector bottomLeft(-1, 1, 1);
	Side top(topLeft, bottomLeft, topRight, bottomRight);

	Vector bottomRight1(1,1,1);
	Vector topRight1(-1,1,1);
	Vector topLeft1(-1,-1,1);
	Vector bottomLeft1(1, -1, 1);
	Side front(topLeft1, bottomLeft1, topRight1, bottomRight1);

	Vector bottomRight2(1,1,1);
	Vector topRight2(1,-1,1);
	Vector topLeft2(1,-1,-1);
	Vector bottomLeft2(1, 1, -1);
	Side right(topLeft2, bottomLeft2, topRight2, bottomRight2);

	Vector bottomRight3(-1,1,1);
	Vector topRight3(-1,1,-1);
	Vector topLeft3(-1,-1,-1);
	Vector bottomLeft3(-1, -1, 1);
	Side left(topLeft3, bottomLeft3, topRight3, bottomRight3);

	//GLdouble bottomRight4[] = {-1,1,1};
	Vector bottomRight4(1,1,-1);
	Vector topRight4(1,-1,-1);
	Vector topLeft4(-1,-1,-1);
	Vector bottomLeft4(-1, 1,-1);
	Side back(topLeft4, bottomLeft4, topRight4, bottomRight4);

	Vector bottomRight5(1,1,-1);
	Vector topRight5(1,-1,-1);
	Vector topLeft5(-1,-1,-1);
	Vector bottomLeft5(-1, 1,-1);
	Side bottom(topLeft5, bottomLeft5, topRight5, bottomRight5);

	Rectangle result(front, right, left, back, top, bottom);
	body = &result;
}

Ship::Rectangle Ship::getBody(){
	return *body;
}

Ship::Vector::Vector(){
	x = 0;
	y = 0;
	z = 0;
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
}

Ship::Vector::Vector(double newX, double newY, double newZ){
	x = newX;
	y = newY;
	z = newZ;
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
}
Ship::Vector::~Vector(){
}

/**
 * Retrieve point x
 */
GLdouble Ship::Vector::getX(){
	return x;
}

/**
 * Retrieve point y
 */
GLdouble Ship::Vector::getY(){
	return y;
}

/**
 * Retrieve point z
 */
GLdouble Ship::Vector::getZ(){
	return z;
}

GLdouble* Ship::Vector::getVector() {

	return vector;
}
/**
 * Update the points
 * @param x point x
 * @param y point y
 * @param z point z
 */
void Ship::Vector::update(double newX, double newY, double newZ){
	x = newX;
	y = newY;
	z = newZ;
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
}

Ship::Side::Side(){

}

/**
 * A side that will be used by the Rectangle
 *
 */
Ship::Side::Side(Vector topLeft, Vector bottomLeft, Vector topRight, Vector bottomRight){
	point[TOPLEFT] = topLeft;
	point[BOTTOMLEFT] = bottomLeft;
	point[TOPRIGHT] = topRight;
	point[BOTTOMRIGHT] = bottomRight;
}

Ship::Side::~Side(){

}

Ship::Vector Ship::Side::topLeftPoint(){
	return point[TOPLEFT];
}

Ship::Vector Ship::Side::bottomLeftPoint(){
	return point[BOTTOMLEFT];
}

Ship::Vector Ship::Side::topRightPoint(){
	return point[TOPRIGHT];
}

Ship::Vector Ship::Side::bottomRightPoint(){
	return point[BOTTOMRIGHT];
}

Ship::Rectangle::Rectangle(){

}

Ship::Rectangle::Rectangle(Side front, Side right, Side left, Side back, Side top, Side bottom){
	side[FRONT] = front;
	side[RIGHT] = right;
	side[LEFT] = left;
	side[BACK]	= back;
	side[TOP] = top;
	side[BOTTOM] = bottom;
}

Ship::Rectangle::~Rectangle(){

}

Ship::Side Ship::Rectangle::getFront(){
	return side[FRONT];
}

Ship::Side Ship::Rectangle::getRight(){
	return side[RIGHT];
}

Ship::Side Ship::Rectangle::getLeft(){
	return side[LEFT];
}

Ship::Side Ship::Rectangle::getBack(){
	return side[BACK];
}

Ship::Side Ship::Rectangle::getTop(){
	return side[TOP];
}

Ship::Side Ship::Rectangle::getBottom(){
	return side[BOTTOM];
}
