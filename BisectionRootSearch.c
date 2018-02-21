/*
AMTH370 Homework 1 Problem 1: Using the Bisection Search to find a root of
a function within some specified bounds or sections.
*/

#include<stdio.h>
#include <math.h>

double fxn(double c);
double bisection( double xleft, double xright, double tol, int maxniter);
double sgn(double z);

int main() {

	double xleft = 0;
	double xright = 10;
	double tol = .0001;
	int maxniter = 1000;
	double xzero;
	
	xzero = bisection (xleft, xright, tol, maxniter);
	printf("The y error is  %f percent \n",fxn(xzero)*100);
	printf("The root of is located at %f \n",xzero);

return(0);
}


double fxn( double x ){
double y;
y = -0.09375*pow(x,3) + 1.125*pow(x,2) - 3.375*x + 6;
//y = pow(x,2) - 5;
return(y); }

double bisection( double xleft, double xright, double tol, int maxniter){
double niter = 1;
double xmid;
double fleft,fright,fmid;
double xzero;

while (niter < maxniter) {
	//printf("the inter is %f \n",niter);
	xmid = (xleft + xright)/2;
	fmid = fxn(xmid);
	fleft = fxn(xleft);
	
	if ((xright - xleft) < tol ) {
		printf("Final left bound is %f, right bout is %f and tolerance %f \n",xleft,xright,fabs(xleft-xright));
		niter = maxniter; }
		
	if (sgn(fmid) == sgn(fleft)) {
		xleft = xmid; } else {
			xright = xmid;}
	//printf("going to add one \n");
	niter = niter + 1; 
	xzero = xmid;
	}
return(xzero);
}

double sgn(double z) {
  if (z > 0.0) {
  	return 1.0; }
  if (z < 0.0) { 
  	return -1.0; }
  
  return z;
}