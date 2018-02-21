#include<stdio.h>
#include<math.h>

double function(double x, double y);

struct point { double a, b, c; };
 
double errorFunction(struct point x, struct point y, struct point z);

void bubbleSort( struct point *x, struct point *y, struct point *z);

struct point nedlerMead(struct point fw, struct point fg, struct point fb, double tol);

int main(){
	
	struct point fw = {0, 0 ,function(fw.a,fw.b)};
 	struct point fg = {1.2, 0, function(fg.a,fg.b)};
 	struct point fb = {0, 0.8, function(fb.a,fb.b)};
 	
 	
	double tol = 0.00001;
	
	printf("fw has a = %f, b = %f, c = %f \n",fw.a, fw.b, fw.c);
	printf("fg has a = %f, b = %f, c = %f \n",fg.a, fg.b, fg.c);
	printf("fb has a = %f, b = %f, c = %f \n",fb.a, fb.b, fb.c);
	printf("****** error is %f *******\n", errorFunction(fw, fg, fb));
	
	//bubbleSort(&fw, &fg, &fb); } 
	struct point min = nedlerMead(fw, fg, fb, tol);
		
	printf("The x = %f, y = %f, fxn = %f \n",min.a,min.b,min.c);
	
return(0);
}

void bubbleSort(struct point *x, struct point *y, struct point *z){
	struct point temp;
	
	if (x->c < y->c) {
		temp = *x;
		*x = *y;
		*y = temp; }

    if (y->c < z->c) {
		temp = *y;
		*y = *z;
		*z = temp; }
		
	if (x->c < y->c) {
		temp = *x;
		*x = *y;
		*y = temp; }
		}
		
double function(double x, double y) { return(pow(x,2) - 4*x + pow(y,2) - y - x*y +8); }
//return ( x*x + y*y + 1); }

double errorFunction(struct point x, struct point y, struct point z){
	double favg = (x.c + y.c + z.c)/3 ;
	double err = sqrt((pow(x.c - favg,2) + pow(y.c - favg,2) + pow(z.c - favg,2))/3);
	return(err);
}

struct point nedlerMead(struct point fw, struct point fg, struct point fb, double tol){
	struct point mid;
	struct point ref;
	struct point exp;
	struct point ci;
	struct point co;
	struct point c;
	struct point s;
	
	int i = 0;
		
	bubbleSort(&fw, &fg, &fb);

	double error = errorFunction(fw, fg, fb);
	
	while (error > tol) {
	
		printf("\n \n ----------start beginning---- \n");
		printf("fw has a = %f, b = %f, c = %f \n",fw.a, fw.b, fw.c);
		printf("fg has a = %f, b = %f, c = %f \n",fg.a, fg.b, fg.c);
		printf("fb has a = %f, b = %f, c = %f \n",fb.a, fb.b, fb.c);
		printf("****** error is %f *******\n", errorFunction(fw, fg, fb));
		printf("Iternation %d \n",i);
		printf("----------end beginning---- \n");
		i = i + 1;
		
		mid.a = (fb.a + fg.a)/2;
		mid.b = (fb.b + fg.b)/2;
		mid.c = function(mid.a, mid.b);
		
		ref.a = 2*mid.a - fw.a;
		ref.b = 2*mid.b - fw.b;
		ref.c = function(ref.a,ref.b);
		printf("ref has a = %f, b = %f, c = %f \n",ref.a, ref.b, ref.c);
		
		if (fb.c < ref.c && ref.c < fg.c) {
			fw = fg;
			fg = ref; 

			printf("The reflection point is accepted \n");
			printf("fw has a = %f, b = %f, c = %f \n",fw.a, fw.b, fw.c);
			printf("fg has a = %f, b = %f, c = %f \n",fg.a, fg.b, fg.c);
			printf("fb has a = %f, b = %f, c = %f \n",fb.a, fb.b, fb.c);
			//bubbleSort(&fw, &fg, &fb);

			}
			
		else {
			printf("The reflection point not accepted \n");

			if (ref.c < fb.c) {
				exp.a = 2*ref.a - mid.a;
				exp.b = 2*ref.b - mid.b;
				exp.c = function(exp.a,exp.b);
				printf("expansion has a = %f, b = %f, c = %f \n",exp.a, exp.b, exp.c);

				if (exp.c < ref.c) {
					fw = fg;
					fg = fb;
					fb = exp; 
					
					bubbleSort(&fw, &fg, &fb);

				//printf("the best is replaced by exp \n");
				//printf("fw has a = %f, b = %f, c = %f \n",fw.a, fw.b, fw.c);
				//printf("fg has a = %f, b = %f, c = %f \n",fg.a, fg.b, fg.c);
				//printf("fb has a = %f, b = %f, c = %f \n",fb.a, fb.b, fb.c);
}
				else {
					fw = fg;
					fg = fb;
					fb = ref; } }
			else {
				ci.a = 0.5*(mid.a + fw.a);
				ci.b = 0.5*(mid.b + fw.b);
				ci.c = function(ci.a, ci.b);
				
				co.a = 0.5*(mid.a + ref.a);
				co.b = 0.5*(mid.b + ref.b);
				co.c = function(co.a, co.b);
				
				if (ci.c < co.c) {
					c.a = ci.a;
					c.b = ci.b;
					c.c = ci.c; }
					
				else {
					c.a = co.a;
					c.b = co.b;
					c.c = co.c; }
					printf("accepted c is a = %f, b = %f, c = %f \n", c.a, c.b, c.c);

				if (c.c < fg.c) {
					fw = c; 
					bubbleSort(&fw, &fg, &fb);
				printf("worst has been replaced with C \n");
				printf("fw has a = %f, b = %f, c = %f \n",fw.a, fw.b, fw.c);
				printf("fg has a = %f, b = %f, c = %f \n",fg.a, fg.b, fg.c);
				printf("fb has a = %f, b = %f, c = %f \n",fb.a, fb.b, fb.c);
					}
				
				else {
					s.a = 0.5*(fw.a + fb.a);
					s.b = 0.5*(fw.b + fb.b);
					s.c = function(s.a, s.b);
					
					fw = fb;
					fg = s;
					fb = mid;	
					
					bubbleSort(&fw, &fg, &fb); } 
			}
		}
		//bubbleSort(&fw, &fg, &fb); 
		error = errorFunction(fw, fg, fb); 
		}
		return(fb);
		}
		

										
		
	


