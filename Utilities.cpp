/*
 * GriewankFunction.cpp
 *
 *  Created on: 16-01-2015
 *      Author: Artur Latoszewski
 */

#include "Utilities.h"

using namespace std;
Utilities::Utilities() {
	// TODO Auto-generated constructor stub

}

Utilities::~Utilities() {
	// TODO Auto-generated destructor stub
}

static double Utilities::calculateGriewankFunction(std::vector<double> x_table){
		double sum = 0;
		double product = 1;

		for (unsigned k = 0; k < x_table.size(); k++) {
			sum += x_table[k]*x_table[k];
			product *= cos((M_PI * x_table[k])/((k+1) * 180.0));
		}

		return (double)(alpha * sum + 1 - product);
}
static double Utilities::generateRandomDouble(double up, double bottom){
	srand48(time(NULL));
	return (double)(bottom + rand() * (up - bottom));
}

