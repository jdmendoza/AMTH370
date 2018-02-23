/*
AMTH370 Homework 1 Problem 2: Using the Golden Section Search to find the minimum of
a function within some specified bounds or sections.
*/

#include<stdio.h>
#include<math.h>
#define e 2.71828

double fxn(double c);
double gss(double a, double b, double c, double tol, int maxniter);

int main(){

	double a = 0;
	double c = 10;
	double b = (c-a)*0.38197;
	double maxniter = 1000;
	double xmin, fmin;
	double tol = 0.0001;
	
	/*
	Testing the function
	double xtest = 0;
	double ytest = fxn(xtest);
	printf("The test variables are %f and %f",xtest,ytest);
	*/
	
	xmin = gss(a, b, c, tol, maxniter);
	fmin = fxn(xmin);
	printf("The min is at %f with a y value of %f \n",xmin,fmin);
	return(0);
}



//fxn() maps input x to out y 
double fxn( double x ){
double y;
y = 20*pow(e,-0.5*x) + 0.09375*pow(x,3) + - 1.125*pow(x,2) + 3.375*x + 2;

return(y); 
}

//gss() performs the minimum search function
double gss(double a, double b, double c, double tol, int maxniter){
	int niter = 1;
	double d;
	double xmin = 0;
	
	while (niter < maxniter) {
		if (fabs(c-a) < tol) {
			printf("c is %f, a is %f and the difference is %f \n",c,a,fabs(c-a));
			//Breaking the while by setting to max iteration
			niter = maxniter; }
			
		d = b + 0.38197*(c-b);
		
		if (fxn(d) < fxn(b)) {
			a = b;
			b = d; } else {
			c = a;
			a = d; }
		
		niter = niter + 1;
		xmin = b; }
		
		return(xmin); 
		}
