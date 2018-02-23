/*
AMTH370 Homework 2 Problem 1: Using the Newton's Method to find a root of
a function .
*/

#include<stdio.h>
#include <math.h>
#define e 2.71828


double newtonMin(double initial, double tol, double maxniter);
double fxn(double x);
double derivFxn(double x);
double secDerivFxn(double x);

int main() {

	printf("Starting homework 2 problem 2 \n");
	double xinitial =  0;
	double tol = .0001;
	double maxniter = 1000;
	double xmin;

	xmin = newtonMin(xinitial, tol, maxniter);
	printf("The y value at the min is %f \n", fxn(xmin));
	printf("The min is located at %f \n", xmin);

	return(0);
}


	double fxn(double x) {
		double y;
		y = 20 * pow(e, -0.5*x) + 0.09375*pow(x, 3) - 1.125*pow(x, 2) + 3.375*x + 2;
		return(y);
	}

double derivFxn(double x) {
	double y;
	y = -10 * pow(e, -0.5*x) + 3*0.09375*pow(x, 2) - 2*1.125*pow(x, 1) + 3.375;
	return(y);
}

double secDerivFxn(double x) {
	double y;
	y = 5 * pow(e, -0.5*x) + 2 * 3 * 0.09375*x - 2 * 1.125;
	return (y);
}

double newtonMin(double initial, double tol, double maxniter){
double min;
double xprev;
double deltax;

double iter = 1;
double x = initial;

while (iter < maxniter) {
	xprev = x;
	deltax = -derivFxn(x) / secDerivFxn(x);
	x = x + deltax;
	iter = iter + 1;
	if (fabs(x - xprev) < tol) {
		printf("The tolerance was met at %f iterations\n", iter);
		iter = maxniter; }
	}
	
	min = x;
	return(min);
	}

