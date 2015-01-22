/*
 * CRS3.h
 *
 *  Created on: 16-01-2015
 *      Author: Artur Latoszewski
 */

#ifndef CRS3_H_
#define CRS3_H_
#include <set>;
#include <vector>;
#include <ctime>;
#include <cstdlib>
#include <map>
#include "Utilities.h"
#include "Point.h"


namespace std {

/*typedef vector<double>Point;*/
typedef set<Point> Simplex;


class CRS3 {
private:
	static const int P_CARDINALITY_FACTOR = 10;
	static const float NMEXPANSION_ALPHA = 1.5f;
	static const float NMCONTRACTION_BETA = 0.5f;

	int max_iterations ;
	double epsilon ;
	double bottom_limit ;
	double upper_limit;
	int task_n ;
	double distance;

	double generateRandomDouble(double up, double bottom);
	Simplex getRandomPointsFromSimplex(int n, Simplex initial, Point max);
	Simplex generateRandomSimplex(int n, int up, int bottom);

	Point calculateCenter(Simplex simplex);

public:CRS3();

	CRS3(double bottom_limit, double upper_limit, double epsilon, int max_iterations, int task_n);
	virtual ~CRS3();

	double calculate();


};

} /* namespace std */
#endif /* CRS3_H_ */
