#include <stdio.h>
#include <math.h>

float initVars(){
unsigned int a=24,b=6,c=8;
return (a/b)-(c/c);

}

int main(){
    float result;
	result=initVars();
	while(result!=3){
		printf("Error, there is a mistake! Check the variables and the formula...");
	}
	printf("The result is: %.2f\n", result);

}


