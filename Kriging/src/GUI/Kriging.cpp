#include "Kriging.h"

Kriging::Kriging()
{
}

Kriging::~Kriging()
{
}
void Kriging::generateRandomValues( int sizeData)
{
	this->sizeValues = sizeData;
	this->valuesX.clear();
	this->valuesY.clear();
	this->valuesZ.clear();
	
	std::cout<<"Generate ["<<sizeData<<"] random values "<<std::endl;
	srand(time(NULL));
    srand(0);
	for(int index = 0; index < this->sizeValues; index++)
	{
		this->valuesX.push_back( rand()%SIZE_WORLD );
		this->valuesY.push_back( rand()%SIZE_WORLD );
		this->valuesZ.push_back( rand()/(double)RAND_MAX );
	}
	std::cout<<"End generate random values"<<std::endl;
}
std::vector<double> Kriging::getValuesX()
{
	return this->valuesX;
}
std::vector<double> Kriging::getValuesY()
{
	return this->valuesY;
}
std::vector<double> Kriging::getValuesZ()
{
	return this->valuesZ;
}
void Kriging::calcSemivariogramEmpirical(int threadDis,int threadDif,int threadSem)
{
	this->threadsDistanceCalc = threadDis;
	this->threadsDiferenceCalc = threadDif;
	this->threadsSemivarianceCalc = threadSem;
	this->distances.clear();
	this->diferencesValues.clear();
	this->semivariance.clear();
	std::cout<<"Numbers threads to calculate distaces: [ "<<this->threadsDistanceCalc<<" ]"<<std::endl;
	std::cout<<"Numbers threads to calculate diferences: [ "<<this->threadsDiferenceCalc<<" ]"<<std::endl;
	std::cout<<"Numbers threads to calculate semivariance: [ "<<this->threadsSemivarianceCalc<<" ]"<<std::endl;	
	
	calculateDistancesLocation();
	calculateDifferenceValues();
	calculateSemivariance();
}
void Kriging::calculateDistancesLocation()
{
	for(int r = 0; r < this->valuesX.size();r++)
	{
		for(int rNext = (r+1); rNext < this->valuesX.size();rNext++)
		{	
			this->distances.push_back( calculateDistances(this->valuesX.at(r),this->valuesX.at(rNext),
														  this->valuesY.at(r),this->valuesY.at(rNext)));
		}
	}
}
std::vector<double> Kriging::getDistances()
{
	return this->distances;
}
double Kriging::calculateDistances(double locationX1,double locationX2,double locationY1,double locationY2)
{
	double dist = 0;
	double deltaX = (locationX1-locationX2)*(locationX1-locationX2);
	double deltaY = (locationY1-locationY2)*(locationY1-locationY2);
 
	dist = sqrt( (deltaX+deltaY) );
	
	return dist;
}
void Kriging::calculateDifferenceValues()
{
	for(int r = 0; r < this->valuesZ.size();r++)
	{		
		for(int rNext = (r+1); rNext < this->valuesZ.size();rNext++)
		{	
			this->diferencesValues.push_back(calculatediferencesSquard(this->valuesZ.at(r),
															   this->valuesZ.at(rNext)
															  ) );
		}
	}
}
std::vector<double> Kriging::getDiferencesSquard()
{
	return this->diferencesValues;
}
double Kriging::calculatediferencesSquard(double valueLocation, double valueLocationNext)
{
	double result = 0;
	result = pow( (valueLocation - valueLocationNext),2);
	
	return result;
}
void Kriging::calculateSemivariance()
{
	for(int r = 0; r < this->valuesZ.size();r++)
	{	
		for(int rNext = (r+1); rNext < this->valuesZ.size();rNext++)
		{	
			this->semivariance.push_back(empiricalSemivariance(this->valuesZ.at(r),
															   this->valuesZ.at(rNext)
															  ) );
		}
	}
}
std::vector<double> Kriging::getSemivariance()
{
	return this->semivariance;
}
double Kriging::empiricalSemivariance(double valueLocation,double valueLocationNext)
{
	double result = 0;
	
	result = 0.5*(pow( (valueLocation - valueLocationNext),2));
	
	return result;
}

void Kriging::calcAverageSemivariogramEmpirical(int threadAveDis,int threadAveSemi,int databin)
{
	this->threadsAverageDistanceCalc = threadAveDis;
	this->threadsAverageSemivarianceCalc = threadAveSemi;
	this->bin = databin;
	
	std::cout<<"Numbers threads to calculate average distaces: [ "<<this->threadsAverageDistanceCalc<<" ]"<<std::endl;
	std::cout<<"Numbers threads to calculate average diferences: [ "<<this->threadsAverageSemivarianceCalc<<" ]"<<std::endl;
	std::cout<<"Numbers to bin: [ "<<this->bin<<" ]"<<std::endl;	

	
	this->idexSort = sortData(this->distances);
	calculateAverageDistance();
	calculateAverageSemivariance();
	calculateExponentialModelFunction();
}
std::vector<int> Kriging::sortData(std::vector<double> values)
{
	std::vector<int> indexSort(values.size());
	std::size_t n(0);
	
	std::generate(std::begin(indexSort), std::end(indexSort), [&]{ return n++; });

    std::sort(  std::begin(indexSort), 
                std::end(indexSort),
                [&](int i1, int i2) { return values[i1] < values[i2]; } );	
	return indexSort;
}
void Kriging::calculateAverageDistance()
{
	
	double averageDis;
	int elements;
		
	//#pragma omp parallel for default(none) num_threads(nThreads) shared(elements,bandera,averageDis)
	for(int iterbin = 1; iterbin < (this->idexSort.size());iterbin+=this->bin)
		{
			
			averageDis = 0;
			elements = 0;
	//#pragma omp parallel for default(none) num_threads(nThreads) shared(elements,iterbin,averageDis)
			for(int index = 0; index < this->idexSort.size(); index++)
			{

	//printf("iter distances in calcule distances average:%f , Thread id: %d \n",this->distances.at(this->idexSort.at(index)),idthread);
	//std::cout<<"iter distances in calcule distances average: "<<this->distances.at(this->idexSort.at(index))<<" thread id: "<<idthread<<std::endl;
				if( (this->distances.at(this->idexSort.at(index)) > iterbin) &&
					(this->distances.at(this->idexSort.at(index)) <= (iterbin+this->bin) ) )
				{
					elements++;
					averageDis = averageDis +  this->distances.at(this->idexSort.at(index));
				}
			}
			
			if(elements != 0)
			{
				averageDis = (averageDis/elements);
				this->averageDistance.push_back(averageDis);
			}
		}
}
std::vector<double> Kriging::getAverageDistance()
{
	return (this->averageDistance);
}
void Kriging::calculateAverageSemivariance()
{
	
	double averageSemi;
	int elements;
	
	for(int iterbin = 1; iterbin < (this->idexSort.size());iterbin+=this->bin)
		{	
			//std::cout<<"iter bin: "<<iterbin<<std::endl;
			averageSemi = 0;
			elements = 0;
			//#pragma omp parallel for num_threads(2) shared(averageSemi)
	//#pragma omp parallel for default(none) num_threads(nThreads) shared(elements,iterbin,averageSemi)
			for(int index = 0; index < this->idexSort.size(); index++)
			{	
				//int idthread = omp_get_thread_num();
				//std::cout<<"iter distances in calcule semivariance average: "<<this->distances.at(this->idexSort.at(index))<<" thread id: "<<idthread<<std::endl;
				//printf("iter distances in calcule distances average:%f , Thread id: %d \n",this->distances.at(this->idexSort.at(index)),idthread);
				if( (this->distances.at(this->idexSort.at(index)) > iterbin) &&
					(this->distances.at(this->idexSort.at(index)) <= (iterbin+this->bin) ) )
				{
					elements++;
					averageSemi = averageSemi +  this->semivariance.at(this->idexSort.at(index));
				}
			}
			if(elements != 0)
			{
				averageSemi = (averageSemi/elements);
				this->averageSemivariance.push_back(averageSemi);
			}
		}
		std::cout<<" OK! ";
}
std::vector<double> Kriging::getAverageSemivariance()
{
	return (this->averageSemivariance);
}
void Kriging::calculateExponentialModelFunction()
{
	foundParametersExpoModel();
	for(int index = 0; index < this->averageDistance.size();index++)
	{
		this->datosExponentialModelFunction.push_back(expoModel(this->averageDistance.at(index)));
	}
}
void Kriging::foundParametersExpoModel()
{
	std::vector<double>::const_iterator it;
	it = max_element(this->averageSemivariance.begin(), this->averageSemivariance.end());
	
	this->sill = *it;
	int position = 0;
	for(int index = 0; index < this->averageSemivariance.size();index++)
	{
		if(this->averageSemivariance.at(index)==this->sill)
		{
			position = index;
		}
	}
	this->rank = this->averageDistance.at(position);
	//std::cout<<"\n\t\tSill: "<<this->sill<<std::endl;
	//std::cout<<"\t\tRank: "<<this->rank<<std::endl;
}
double Kriging::expoModel(double h)
{	
	//double resultA = (-3*h/this->rank);
	//double resultB = pow(expon,(-3*h/this->rank));
	//double resultC = 1 - resultB;
	double result = this->sill*(1 - pow(expon,(-3*h/this->rank))) ;
 
//	double result =  this->sill * resultC;
return result;
}
std::vector<double> Kriging::getDatosExponentialModelFunction()
{
	return this->datosExponentialModelFunction; 
}