#include <stdio.h>
#define LEN 100

double x[]={0, 1, 2, 3, 4, 5, 6}, f[]={6.9897, 7.406, 7.7815, 8.1291, 8.4510, 8.7506, 9.0309};

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
    int len=6;
    printf("%lf\n", P1(1, len));
    printf("%lf\n", P1(3, len));
    printf("%lf\t%lf\n", P1(6, len), P2(6, len));
    return 0;
}
