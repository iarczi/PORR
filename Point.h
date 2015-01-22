/*
 * Point.h
 *
 *  Created on: 21-01-2015
 *      Author: Artur Latoszewski
 *
 */

#ifndef POINT_H_
#define POINT_H_

#include <vector>
#include "Utilities.h"

namespace std {

/*
 *
 */
class Point {

vector<double> coordinates;
double value;


public:
	Point(vector<double> coordinates);

	Point(const Point &point );
	Point(int n, int up, int bottom);
	virtual ~Point();

	void generateRandomPoint(int n, int up, int bottom);

	void calculate();
	unsigned numberOfCoordinates();

	bool operator<(const Point& point) const;
	bool operator>(const Point& point) const;
};

} /* namespace std */
#endif /* POINT_H_ */
