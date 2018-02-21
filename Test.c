
#include<stdio.h>

double function( double x, double y);

typedef struct pt{
    int a;
    int b;
    int c;;
    
    } point;	

point x,y,z;

void bubbleSort(point *x, point *y, point *z);

    
int main() {

point x,y,z;


	point p;
	p.a = 4;
	p.b = 2;
	
	point q;
	q.a = 3;
	q.b = 3;
	
	point r;
	r.a = 2;
	r.b = 4;
	
	x = p; y = q; z = r;
	printf("x has a = %d b = %d c = %d\n",x.a,x.b,x.c);
	printf("y has a = %d b = %d \n",y.a,y.b);
	printf("y has a = %d b = %d \n",z.a,z.b);	


	bubbleSort(&x, &y, &z);

	printf("x has a = %d b = %d \n",x.a,x.b);
	printf("y has a = %d b = %d \n",y.a,y.b);
	printf("y has a = %d b = %d \n",z.a,z.b);	
	

return(0);
}

int f (int a, int b){ return(a*b);};

void bubbleSort( point *x, point *y, point *z){
	point temp;
	
	if (x->a > y->a) {
		temp = *x;
		*x = *y;
		*y = temp; }

    if (y->a > z->a) {
		temp = *y;
		*y = *z;
		*z = temp; }
		
	if (x->a > y->a) {
		temp = *x;
		*x = *y;
		*y = temp; }
		}