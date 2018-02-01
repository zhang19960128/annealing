#include "function.h"
#include <cmath>
#include <new>
#include <cstdlib>
#define Pi 3.141592653897932
double energy(double* x,int len){
	return -1*cos(x[0])*cos(x[1])*exp(-1*(x[0]-Pi)*(x[0]-Pi)-(x[1]-Pi)*(x[1]-Pi));
}
double possibility(double ener,double temperature){
	return exp(-3*ener/temperature);
}
double* next(double* x,int len,double temperature){
	double* x_go=new double[len];
	double enow=0;
	double ebefore=0;
	double randreal;
	for(size_t n=0;n<len;n++){
		x_go[n]=x[n]+(rand()-RAND_MAX/2.0)/RAND_MAX;
	}
	enow=energy(x_go,len);
	ebefore=energy(x,len);
	if(enow<ebefore){
		return x_go;
	}
	else{
		randreal=(rand()-RAND_MAX/2.0)/RAND_MAX*2.0;
		if(randreal<possibility(enow-ebefore,temperature)){
			return x_go;
		}
		else{
			x_go=x;
			return x_go;
		}
	}
}
