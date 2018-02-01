#include <iostream>
#include "function.h"
#include <new>
int main(){
	double* x=new double[2];
	x[0]=0.0;
	x[1]=0.0;
	double* nextstep=nullptr;
	double temperature=10000000;
	int count=0;
	do{
		count=0;
		do{
		nextstep=next(x,2,temperature);
		if(nextstep!=x){
			count++;
		}
		x=nextstep;
		}while(count<100);
		temperature=temperature*0.88;
		std::cout<<"the temperature now is "<<temperature<<std::endl;
	}while(temperature>0.00001);
	std::cout<<x[0]<<" "<<x[1]<<std::endl;
}
