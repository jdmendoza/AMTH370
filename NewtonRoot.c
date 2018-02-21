/*
AMTH370 Homework 2 Problem 1: Using the Newton's Method to find a root of
a function .
*/

#include<stdio.h>
#include <math.h>

double newtonRoot(double initial, double tol, double maxniter);
double fxn(double x);
double derivFxn(double x);

	int main() {

	printf("Starting homework 2 problem 1 \n");
	double xinitial = 6.1;
	double tol = .0001;
	int maxniter = 1000;
	double xzero;

	xzero = newtonRoot(xinitial, tol, maxniter);
	//printf("The y value is  %f \n", fxn(xzero));
	printf("The root of is located at %f \n", xzero);

	return(0);
}


double fxn(double x) {
	double y;
	y = -0.09375*pow(x, 3) + 1.125*pow(x, 2) - 3.375*x + 6;
	return(y);
}

double derivFxn(double x) {
	double y;
	y = -0.09375*pow(x, 2) * 3 + 1.125*x * 2 - 3.375;
	return(y);
}

double newtonRoot(double initial, double tol, double maxniter){
double root;
double xprev;
double deltax;

int iter = 0;
double x = initial;

while (iter < maxniter) {
	iter = iter +1;
	xprev = x;
	deltax = -fxn(x) / derivFxn(x);
	x = x + deltax;

	if (fabs(x - xprev) < tol) {
		printf("The tolerance was met at %d iterations \n", iter);
		iter = maxniter; }
	}
	
	root = x;
	return(root);
	}

