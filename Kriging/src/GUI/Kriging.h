#ifndef KRIGING_H
#define KRIGING_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

//#include <math.h>


class Kriging
{
public:
	Kriging();
	~Kriging();
	void generateRandomValues(int);
	std::vector<double> getValuesX();
	std::vector<double> getValuesY();
	std::vector<double> getValuesZ();
	std::vector<double> getDistances();
	std::vector<double> getDiferencesSquard();
	std::vector<double> getSemivariance();
	std::vector<double> getAverageDistance();
	std::vector<double> getAverageSemivariance();
	std::vector<double> getDatosExponentialModelFunction();
	

	void calcSemivariogramEmpirical(int,int,int);
	void calcAverageSemivariogramEmpirical(int,int,int);
private:
	void calculateDistancesLocation();
	double calculateDistances(double,double,double,double);
	void calculateDifferenceValues();
	double calculatediferencesSquard(double , double);
	void calculateSemivariance();
	double empiricalSemivariance(double,double);
	std::vector<int> sortData(std::vector<double>);
	void calculateAverageDistance();
	void calculateAverageSemivariance();
	void calculateExponentialModelFunction();
	double expoModel(double);
	void foundParametersExpoModel();

private:
	//const int SIZE_WORLD  = 640;
	const int SIZE_WORLD  = 1000;
	int sizeValues;
	std::vector<double> valuesX,valuesY,valuesZ;
	int threadsDistanceCalc;
	int threadsDiferenceCalc;
	int threadsSemivarianceCalc;
	std::vector<double> distances;
	std::vector<double> diferencesValues;
	std::vector<double> semivariance;
	int bin;
	int threadsAverageDistanceCalc;
	int threadsAverageSemivarianceCalc;
	std::vector<int> idexSort;
	std::vector<double> averageDistance;
	std::vector<double> averageSemivariance;
	const double expon = 2.718281828459045;
	double rank;
	double sill;

	std::vector<double> datosExponentialModelFunction;
	
};

#endif // KRIGING_H
