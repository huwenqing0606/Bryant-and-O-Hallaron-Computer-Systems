/*
Ex 5.1
Swap value x at xp with value y at yp
*/

#include <stdio.h>
#include <stdlib.h>


void swap(long *xp, long *yp){
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}


long counter=0;


long f(){
	return counter++;
};


long func1(){
	return f()+f()+f()+f();
}


long func2(){
	return 4*f();	
}


int main(){
	long *p, *q, a, b;
	if (0) {
		a = 2;
		b = 3;
		p = &a;
		q = &b;
		swap(p, q); 
		printf("%d %d \n", *p, *q);
	}
	else {
		a = func1();
		b = func2();
		printf("a= %d, b= %d \n", a, b);
	}
	return 0;
}


