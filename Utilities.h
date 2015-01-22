/*
 * GriewankFunction.h
 *
 *  Created on: 16-01-2015
 *      Author: Artur Latoszewski
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <math.h>
#include <vector>
#include <cstdlib>


class Utilities {
private:

	 static const double alpha = 1/40;

public:
	Utilities();
	virtual ~Utilities();

	static double calculateGriewankFunction(std::vector<double> x_table);
	static double generateRandomDouble(double up, double bottom);


};

#endif /* UTILITIES_H_*/
