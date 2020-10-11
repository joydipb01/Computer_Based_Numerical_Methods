#include <stdio.h>
#include <math.h>
#define E 0.000001
#define M 10

float a[M], b[M], c[M];

void bairstow(float a[], int n, float p, float q){
    int count=0, l, k;
    float cc=0, den=0, delp=0, delq=0;
    do{
        b[0]=a[0];
        c[0]=b[0];
        b[1] = a[1] - p*b[0];
        for (int k = 2; k <= n; k++)
            b[k] = a[k] - p * b[k-1] - q * b[k-2];
        c[1] = b[1] - p*c[0];
        l = n - 1;
        for (k = 2; k <= l; k++)
            c[k] = b[k] - p * c[k-1] - q * c[k-2];
        cc = c[n-1] - b[n-1];
        den = c[n-2] * c[n-2] - cc * c[n-3];
        if(fabs(den) == 0.0){
	      printf("WRONG INITIAL APPROXIMATION\n");
	      return;
        }
        delp = -(b[n] * c[n-3] - b[n-1] * c[n-2]) / den;
        delq = -(b[n-1] * cc - b[n] * c[n-2]) / den;
        p = p + delp;
        q = q + delq;
        count++;
    }while((fabs(delp)>E)&&(fabs(delq)>E));
    printf("%.5f %.5f %d\n", p, q, count);
}

int main()
{
    float p, q;
    int n;
    char i;
    for(i='1';i<='3';i++){
        switch(i){
            case '1': 
                      n=3;
                      a[0]=1;
                      a[1]=-11;
                      a[2]=32;
                      a[3]=-22;
                      p=0.1;
                      q=0.1;
                      break;
            case '2': 
                      n=3;
                      a[0]=1;
                      a[1]=0;
                      a[2]=-1;
                      a[3]=-3;
                      p=0.1;
                      q=0.1;
                      break;
            case '3': 
                      n=4;
                      a[0]=1;
                      a[1]=-3;
                      a[2]=3;
                      a[3]=-3;
                      a[4]=2;
                      p=0.1;
                      q=0.1;
        }
        bairstow(a, n, p, q);
    }
}
