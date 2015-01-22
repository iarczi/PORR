/*
 * Point.cpp
 *
 *  Created on: 21-01-2015
 *      Author: arczi
 */

#include "Point.h"


namespace std {

Point::Point(vector<double> coord) {
	coordinates = coord;
	calculate();
}
Point::Point(int n, int up, int bottom) {
	generateRandomPoint(int n, int up, int bottom);
	calculate();
}

Point::~Point() {

}
Point::Point(const Point &point ) {
	value=point.value;
	coordinates=point.coordinates;
}


void Point::generateRandomPoint(int n, int up, int bottom){

	for (int i = 0; i < n; ++i) {
			coordinates.push_back(Utilities::generateRandomDouble(up,bottom));
	}
	return ;
}

unsigned Point::numberOfCoordinates(){
	return coordinates.size();
}
void Point::calculate(){
	this->value = Utilities::calculateGriewankFunction(this->coordinates);
}
bool Point::operator<(const Point& point) const
{
   return value < point.value;  //assume that you compare the record based on a
}
bool Point::operator > (const Point& point) const
{
   return value > point.value;  //assume that you compare the record based on a
}

} /* namespace std */
