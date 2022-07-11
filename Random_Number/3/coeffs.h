//Function declaration
double **createMat(int m,int n);
void readMat(double **p, int m,int n);
void print(double **p,int m,int n);
double **loadtxt(char *str,int m,int n);
double linalg_norm(double **a, int m);
double **linalg_sub(double **a, double **b, int m, int n);
double **linalg_inv(double **mat, int m);
double **matmul(double **a, double **b, int m, int n, int p);
double **transpose(double **a,  int m, int n);
void uniform(char *str, int len);
void gaussian(char *str, int len);
void bernoulli(char *str, int len);
void bernoulli_gau(char *str,int len);
void chi(char *str,int len);
void ral(char *str,int len);
void ral_gamma(char *str,double gamma,int len);
void triangular(char *str, int len);
double mean(char *str);
double var(char *str);
void V_dist(char *str, int len);
double gau_rand();
//End function declaration


//Defining the function for matrix creation
double **createMat(int m,int n)
{
 int i;
 double **a;
 
 //Allocate memory to the pointer
a = (double **)malloc(m * sizeof( *a));
    for (i=0; i<m; i++)
         a[i] = (double *)malloc(n * sizeof( *a[i]));

 return a;
}
//End function for matrix creation


//Defining the function for reading matrix 
void readMat(double **p, int m,int n)
{
 int i,j;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%lf",&p[i][j]);
  }
 }
}
//End function for reading matrix

//Read  matrix from file
double **loadtxt(char *str,int m,int n)
{
FILE *fp;
double **a;
int i,j;


a = createMat(m,n);
fp = fopen(str, "r");

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   fscanf(fp,"%lf",&a[i][j]);
  }
 }
//End function for reading matrix from file

fclose(fp);
 return a;

}


//Defining the function for printing
void print(double **p, int m,int n)
{
 int i,j;

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  printf("%lf ",p[i][j]);
 printf("\n");
 }
}
//End function for printing

//Defining the function for norm

double linalg_norm(double **a, int m)
{
int i;
double norm=0.0;

 for(i=0;i<m;i++)
 {
norm = norm + a[i][0]*a[i][0];
}
return sqrt(norm);

}
//End function for norm

//Defining the function for difference of matrices

double **linalg_sub(double **a, double **b, int m, int n)
{
int i, j;
double **c;
c = createMat(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]-b[i][j];
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for inverse of 2x2 matrix


double **linalg_inv(double **mat, int m)
{
double **c, det;
c = createMat(m,m);

det = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];

c[0][0] = mat[1][1]/det;
c[0][1] = -mat[1][0]/det;
c[1][0] = -mat[0][1]/det;
c[1][1] = mat[0][0]/det;

return c;

}
// End  function for inverse of 2x2 matrix


//Defining the function for difference of matrices

double **matmul(double **a, double **b, int m, int n, int p)
{
int i, j, k;
double **c, temp =0;
c = createMat(m,p);

 for(i=0;i<m;i++)
 {
  for(k=0;k<p;k++)
  {
    for(j=0;j<n;j++)
    {
	temp= temp+a[i][j]*b[j][k];
    }
	c[i][k]=temp;
	temp = 0;
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for transpose of matrix

double **transpose(double **a,  int m, int n)
{
int i, j;
double **c;
//printf("I am here");
c = createMat(n,m);

 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
c[i][j]= a[j][i];
//  printf("%lf ",c[i][j]);
  }
 }
return c;

}
//End function for transpose of matrix

//Defining the function for generating uniform random numbers
void uniform(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
}
fclose(fp);

}
//End function for generating uniform random numbers

//Defining the function for calculating the mean of random numbers
double mean(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x;
}
fclose(fp);
temp = temp/(i-1);
return temp;

}
//End function for calculating the mean of random numbers

//Defining the function for generating Gaussian random numbers
void gaussian(char *str, int len)
{
int i,j;
double temp;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;
fprintf(fp,"%lf\n",temp);
}
fclose(fp);

}
//End function for generating Gaussian random numbers

//Defining the function for calculating the variance of random numbers
double var(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0,term;
double m = mean(str);

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all terms
term = (x-m)*(x-m);
temp = temp+term;
}
fclose(fp);
temp = temp/(i-1);
return temp;

}

//Defining the function for generating V distribution random numbers
void V_dist(char *str, int len) {
int i;
double term;
double U;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
U = (double)rand()/RAND_MAX;
term = (-2)* log(1-U);
fprintf(fp,"%lf\n",term);
}
fclose(fp);
	
}

//Defining the function for generating triangular random numbers
void triangular(char *str, int len)
{
int i,j;
double temp;
double U1,U2;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{

U1 = (double)rand()/RAND_MAX;
U2 = (double)rand()/RAND_MAX;

temp = U1 + U2;
fprintf(fp,"%lf\n",temp);
}
fclose(fp);

}
//End function for generating triangular random numbers

//Defining the function for generating one gaussian random numbers

double gau_rand()
{
double temp;
int j;

//Generate numbers
temp = 0.0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;

return temp;
}

//End function for generating one gaussian random numbers

//Defining the function for generating bernoulli random numbers

void bernoulli(char *str, int len)
{
int i;
double term;
double U;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
U = (double)rand()/RAND_MAX;

if(U>0.5) {
  term = 1;
}
else{
  term = -1;
}

fprintf(fp,"%lf\n",term);
}
fclose(fp);
}

//End function for generating bernoulli random numbers

//Defining the function for generating 5*bernoulli + gaussian random numbers

void bernoulli_gau(char *str,int len)
{
int i,j;
double ber;
double term;
double U;
double temp;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
U = (double)rand()/RAND_MAX;

if(U>0.5) {
  ber = 1;
}
else{
  ber = -1;
}

temp = 0.0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;

term = pow(10,0.5)*ber + temp;

fprintf(fp,"%lf\n",term);
}
fclose(fp);
}

//End function for generating 5*bernoulli + gaussian random numbers

//Defining the function for generating chi-squared (2 degrees of freedom) random numbers

void chi(char *str,int len)
{
int i,j;
double temp1,temp2;
double term;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp1 = 0;
temp2 = 0;
for (j = 0; j < 12; j++)
{
temp1 += (double)rand()/RAND_MAX;
temp2 += (double)rand()/RAND_MAX;
}
temp1 -= 6;
temp2 -= 6;
term = temp1*temp1 + temp2*temp2;
fprintf(fp,"%lf\n",term);
}
fclose(fp);
}

//End function for generating chi-squared (2 degrees of freedom) random numbers

//Defining the function for generating rayleigh random numbers for gamma = 2

void ral(char *str,int len)
{
int i,j;
double temp1,temp2;
double term;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp1 = 0;
temp2 = 0;
for (j = 0; j < 12; j++)
{
temp1 += (double)rand()/RAND_MAX;
temp2 += (double)rand()/RAND_MAX;
}
temp1 -= 6;
temp2 -= 6;
term = sqrt(temp1*temp1 + temp2*temp2);
fprintf(fp,"%lf\n",term);
}
fclose(fp);
}

//End function for generating rayleigh random numbers for gamma = 2

//Defining the function for generating rayleigh random numbers for any gamma

void ral_gamma(char *str,double gamma,int len)
{
int i,j;
double temp1,temp2;
double term;
double sig = sqrt(gamma/2.0);
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp1 = 0;
temp2 = 0;
for (j = 0; j < 12; j++)
{
temp1 += (double)rand()/RAND_MAX;
temp2 += (double)rand()/RAND_MAX;
}
temp1 -= 6;
temp2 -= 6;

temp1*=sig;
temp2*=sig;
term = sqrt(temp1*temp1 + temp2*temp2);
fprintf(fp,"%lf\n",term);
}
fclose(fp);
}
//End function for generating rayleigh random numbers for any gamma