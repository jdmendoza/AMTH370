 #include<stdio.h>
 #include<math.h>
 
 double alternateVar (int i, double vinitial[], double tol);
 double derivFxn(double x, double y, double z, double functionNumber, char var);
 double lambdaSearch(double df[], double pvector[]);
 double doubleDerivFxn(int var);
//double function1 (double x, double y, double z);
 
 enum State { XX, XY, YX, XZ, YY, YZ, ZY, ZX, ZZ };
//double function1 (double x, double y, double z){
//	return(4*pow(x,2) + 0.5*pow(y,2) + 2*pow(z,2) - 20*x - y +4*z +26); } 
 
 int main(){
 
 double vecInitial[3] = {0,0,0};
 double lol = alternateVar(3, vecInitial, 0.001);
 
 return(0);
 }
 
double alternateVar (int n, double vinitial[], double tol) {
	
	int maxsteps = 100000;
	double v[3];
	
	int i = 1;
	
	for (i = 1; i < 4; i++){
		v[i] = vinitial[i]; }
	
	int step = 1;
   
	while (step < maxsteps){
	
		double p[] = {0, 0, 0};
		p[(step-1)%n + 1] = 1;
		
		double df[3];
   		df[0] = derivFxn(v[0],v[1],v[2],1,'X');
   		df[1] = derivFxn(v[0],v[1],v[2],1,'Y');
   		df[2] = derivFxn(v[0],v[1],v[2],1,'Z');
		
		double lambda = lambdaSearch(df,p);
   		int m;
   	
   		for (m = 0; m < n; m++) { v[m] = v[m] + lambda*p[m]; }
   		
   		

   		double mag = sqrt(pow(df[0],2) + pow(df[1],2) + pow(df[2],2));
   		
   		if (mag < tol) {
   			printf("We out here bro");
   			break; }
   	
   		step = step + 1; }
   	
   		printf("Step number %d \n",step);
   		printf(" x = %f, y = %f, z = %f \n",v[0],v[1],v[2]);
   	
   		return(0);
   	
   } 
   
double derivFxn(double x, double y, double z, double functionNumber, char var) {
	double f;
	
	switch(var) {
	
		case 'X':
			//printf("Derivative wrt variable X \n");

			if (functionNumber == 1){
				f = 3*x + z - 11; 
				break; }
			
			else {
				f = 3*x + z - 11; 
				break; }
			
		case 'Y':
			//printf("Derivative wrt variable Y \n");
			
			if (functionNumber == 1) {
				f = y - 1; 
				break;}
			
			else {	
				f = y - 1;
 				break;}
			
		case 'Z':
			//printf("Derivative wrt variable Z\n");
			
			if (functionNumber == 1) {
				f = 4*z + 4;	
				break; }
			
			else {
				f = 3*z + x + 9;
				break; }

		default:
			printf("Something aint right \n"); 
			}


return(f);
}

double lambdaSearch(double df[], double pvector[]) {
	double lambda1;
	
	double dfdydz = doubleDerivFxn(YZ);
	double dfdxdy = doubleDerivFxn(XY);
	double dfdxdz = doubleDerivFxn(XZ);
	double dfdxdx = doubleDerivFxn(XX);
	double dfdydy = doubleDerivFxn(YY);
	double dfdzdz = doubleDerivFxn(ZZ);
	
	
	double num = -1*(df[0]*pvector[0] + df[1]*pvector[1] + df[2]*pvector[2]);
	double den =  pvector[0]*(dfdxdx*pvector[0] + dfdxdy*pvector[1] + dfdxdx*pvector[2]) 
				+ pvector[1]*(dfdxdy*pvector[0] + dfdydy*pvector[1] + dfdydz*pvector[2]) 
				+ pvector[2]*(dfdxdz*pvector[0] + dfdydz*pvector[1] + dfdzdz*pvector[2]);
	lambda1 = num/den;
	
	return(lambda1);
	}

double doubleDerivFxn(int var){
	double ddf;
	
	switch(var) {
	

		case XY  YX:
			ddf = 0;
			break;
			
		case XZ ZX:
			ddf = 0;
			break;
			
		case YZ ZY:
			ddf = 0;
			break;
			
		case XX:
			ddf = 8;
			break;
			
		case YY:
			ddf = 1;
			break;
			
		case ZZ:
			ddf = 4;
			break;
	}	
		
return(ddf);
}