#include <stdio.h>
#define LEN 100

double x[]={1.5, 2.0, 2.5, 3.0, 3.5, 4.0}, f[]={3.375, 7.0, 13.625, 24.0, 38.875, 59.0};

double l1(double xa, int k, int n) {
    double den=1, num=0, temp=1,temp1=0;
    int i,j;
    for(i=0;i<=n;i++) {
        if(i!=k) {
            //printf("i=%d, k=%d\n", i, k);
            den = den * (x[k] - x[i]);
        }
    }
    
    for(i=0;i<=n;i++) {
        if (i!=n){
            temp=1;
            for(j=0;j<=n;j++) {
                temp1=0;
                if(i>=k)
                    temp1++;
                if((k!=j) & (j!=(i+temp1))) {
                    //printf("i=%d, j=%d, k=%d, \n",i,j,k);
                    temp = temp * (xa - x[j]);
                }
            }
            num = num + temp;
        }
    }
    //printf("num=%lf, den=%lf\n",num, den);
    temp = num/den;
    return temp;
}

double l2(double xa, int k, int n) {
    double den=1, num=0, temp=1, temp1, temp2;
    int a[LEN];
    int i,j,l,c,index;
    for(i=0;i<=n;i++) {
        if(i!=k)
            den = den * (x[k] - x[i]);
    }
    for(i=0;i<n;i++) {
        index = 0;
        for(j=0;j<=n;j++) {
            temp1=i;
            if(i>=k)
                temp1++;
            if((j!=k) & (j!=temp1)) {
                a[index] = j;
                //printf("i=%d, j=%d, k=%d, a[%d]=%lf\n",i,j,k,index,a[index]);
                index++;
            }
        }
        for(j=0;j<n-1;j++) {
            temp=1;
            c=0;
            for(l=0;l<n-1;l++){
                if (a[l] != a[j]) {
                    //printf("%d, ",a[l]);
                    temp = temp * (xa - x[a[l]]);
                    c++;
                }
            }
            //printf("\n");
            num = num + temp;
        }
    }
    temp = num/den;
    return temp;
}

double P1(double xa, int n) {
    int k;
    double temp=0;
    for(k=0;k<=n;k++) {
        temp = temp + l1(xa, k, n) * f[k];
        //printf("%lf\n", l1(xa, k, n));
    }
    return temp;
}

double P2(double xa, int n) {
    int k;
    double temp=0;
    for(k=0;k<=n;k++) {
        temp = temp + l2(xa, k, n) * f[k];
    }
    return temp;
}

int main() {
    int len=5;
    printf("%lf\n%lf", P1(1.5, len), P2(1.5, len));
    return 0;
}
