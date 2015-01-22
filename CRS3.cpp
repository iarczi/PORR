/*
 * CRS3.cpp
 *
 *  Created on: 16-01-2015
 *      Author: Artur Latoszewski
 */

#include "CRS3.h"

namespace std {

CRS3::CRS3() {
	// TODO Auto-generated constructor stub

}
CRS3::CRS3(double bottom_limit, double upper_limit, double epsilon, int max_iterations, int task_n) {
	this->bottom_limit=bottom_limit;
	this->upper_limit=upper_limit;
	this->epsilon=epsilon;
	this->max_iterations=max_iterations;
	this->task_n=task_n;

}

CRS3::~CRS3() {
	// TODO Auto-generated destructor stub
}

double CRS3::calculate(){

	return 0.0;
/*
	FunctionXY fx;
	Simplex  p = generateRandomSimplex(task_n, upper_limit, bottom_limit);
	for (int i = 0; i < p.size(); ++i) {
		fx.insert(std::pair<double, Point>(Utilities::calculate(p[i]),p[i]));
	}

	FunctionXY::iterator min = fx.begin();
	FunctionXY::iterator max = fx.end();


	Simplex p2 = getRandomPointsFromSimplex(task_n,p,max->second);

	for (int i = 0; i < task_n; ++i) {
		p2.push_back(p[])
	}
*/


}



Point CRS3::calculateCenter(Simplex simplex){
	vector<double> center;
	unsigned size = simplex.begin()->numberOfCoordinates();
	for (int it_wsp = 0; it_wsp  < size; ++it_wsp ) {
		double x_i = 0;
		for (unsigned it_sym = 0; it_sym < simplex.size(); ++it_sym) {
			x_i+=simplex[it_sym][it_wsp];
		}
		x_i =  x_i/(simplex.size()-1);
		center.push_back(x_i);
	}

	return Point(center);

}

Simplex CRS3::getRandomPointsFromSimplex(int n, Simplex initial, Point max){
	srand48(time(NULL));
	Simplex new_simplex;
	new_simplex.insert(max);
	set<int> ints;

	for (int i = 0; i < n; ++i) {
		int x = (int)(bottom_limit + rand() * (upper_limit - bottom_limit));
		auto inserted = ints.insert(x);
		while(!inserted.second){
			x = (int)(bottom_limit + rand() * (upper_limit - bottom_limit));
			inserted = ints.insert(x);
		}
		new_simplex.insert(initial[x]);
	}
	return	new_simplex;
}

Simplex CRS3::generateRandomSimplex(int n, int up, int bottom){
	int nP = (n+1) * P_CARDINALITY_FACTOR;

	Simplex simplex;

	for (int i = 0; i < nP; ++i) {
		Point point(n,up,bottom);

		simplex.insert(point);
	}

	return simplex;
}


} /* namespace std */
