/*
AMTH370 Homework 2 Problem 1: Using the Newton's Method to find a root of
a function. The first and second derivatives are done using 
the finite difference approach
*/

#include<stdio.h>
#include <math.h>
#define e 2.71828


double newtonSecantMin(double initial, double tol, double maxniter);
double fxn(double x);
double derivFxn(double x, double epsilon);
double secDerivFxn(double x, double epsilon);

int main() {

	printf("Starting homework 3 problem 2 \n");
	double xinitial =  0;
	double tol = .0001;
	double maxniter = 1000;
	double xmin;

	xmin = newtonSecantMin(xinitial, tol, maxniter);
	printf("The y value at the min is %f \n", fxn(xmin));
	printf("The min is located at %f \n", xmin);

	return(0);
}


	double fxn(double x) {
		double y;
		y = 20 * pow(e, -0.5*x) + 0.09375*pow(x, 3) - 1.125*pow(x, 2) + 3.375*x + 2;
		return(y);
	}


double newtonSecantMin(double initial, double tol, double maxniter) {
double min;
double epsilon = 0.01;

double xprev;
double deltax = 0.0;
double deltaxprev,deltaxprev2;
double fcurr, fprev, f2prev;
double numer,denom;

double iter = 1;
double x = initial;

xprev = x;
deltaxprev = deltax;

while (iter < maxniter) {
	
	deltaxprev2 = deltaxprev;
	deltaxprev = deltax;
	
	if (iter < 3) {
		deltax = -derivFxn(x, epsilon)/secDerivFxn(x, epsilon);	
		printf("1This is the %f inter \n",iter); } //Have an initial routine to calculate this at the start
	
	else {
		numer = pow(deltaxprev,2)*f2prev - pow(deltaxprev + deltaxprev2,2) * fprev + deltaxprev2*(2*deltaxprev + deltaxprev2)*fcurr;
		denom = 2*deltaxprev*f2prev - 2*(deltaxprev+deltaxprev2)*fprev + 2*deltaxprev2*fcurr;
		deltax = -numer/denom; 
		printf("2This is the %f iter \n",iter); }
	
	xprev = x;
	x = x + deltax;
		
	if (fabs(x - xprev) < tol) {
		printf("The tolerance was met at %f iterations \n", iter);
		iter = maxniter; }
	
	f2prev = fprev;
	fprev = fcurr;
	fcurr = fxn(x);
	iter = iter + 1;
	}
	
	min = x;
	return(min);
	}

double derivFxn(double x, double epsilon) {
	double y;
	y = (fxn(x + epsilon) - fxn(x-epsilon))/(2*epsilon);
	return(y);
}

double secDerivFxn(double x, double epsilon) {
	double y;
	y = (fxn(x + epsilon) - 2*fxn(x) + fxn(x - epsilon))/pow(epsilon,2);
	return (y);
}