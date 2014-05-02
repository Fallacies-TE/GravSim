/*
 * Ship.h
 *
 *  Created on: Apr 16, 2014
 *      Author: David Argueta
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <GL/gl.h>

class Ship {
	class Vector {
	public:
		Vector();
		Vector(double newX, double newY, double newZ);
		virtual ~Vector();
		GLdouble getX();
		GLdouble getY();
		GLdouble getZ();
		GLdouble* getVector();
		void update(double newX, double newY, double newZ);
	private:
		GLdouble x, y, z;
		GLdouble vector[3];

	};
	class Side {
	public:
		Side();
		Side(Vector topLeft, Vector bottomLeft, Vector topRight, Vector bottomRight);
		virtual ~Side();
		Vector topLeftPoint();
		Vector bottomLeftPoint();
		Vector topRightPoint();
		Vector bottomRightPoint();

	private:
		enum PointLabels {TOPLEFT = 0, BOTTOMLEFT, TOPRIGHT, BOTTOMRIGHT};
		Vector point[4];

	};
	class Rectangle {
	public:
		Rectangle();
		Rectangle(Side front, Side right, Side left, Side back, Side top, Side bottom);
		virtual ~Rectangle();
		Side getFront();
		Side getRight();
		Side getLeft();
		Side getBack();
		Side getTop();
		Side getBottom();


	private:
		enum SideLabels {FRONT = 0, RIGHT, LEFT, BACK, TOP, BOTTOM};
		Side side[6];

	};
public:
	Ship();
	virtual ~Ship();
	float size();
	Rectangle getBody();

private:
	enum Position {TOPLEFT=0, BOTTOMLEFT, TOPRIGHT, BOTTOMRIGHT};
	Rectangle wings[];
	Rectangle *body;
	Rectangle nose;
	Rectangle thrusters[];
	Rectangle blasters[];
	void createShip();
	void createBody();
};

#endif /* SHIP_H_ */
