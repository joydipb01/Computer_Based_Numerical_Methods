#include <stdio.h>

void high_ord_lag(float xa[], float ya[], float x, int n){
    float y=0.0, sum=0.0;
    for(int i=0;i<n;i++){
        sum=ya[i];
        for(int j=0;j<n;j++){
            if(i!=j)
                sum=sum*(x-xa[j])/(xa[i]-xa[j]);
        }
        y+=sum;
    }
    printf("f(%f)=%.5f\n", x, y);
}

int main(){
    float a1[3]={0, 1, 3};
    float a2[3]={1, 3, 35};
    float x1=2;
    int n1=3;
    
    float b1[6]={0, 1, 2, 4, 5, 6};
    float b2[6]={1, 14, 15, 5, 6, 19};
    float x2=3;
    int n2=6;
    
    float c1[5]={0.1, 0.2, 0.3, 0.4, 0.5};
    float c2[5]={9.9833, 4.9667, 3.2836, 2.4339, 1.9177};
    float x3=0.25;
    float x4=0.35;
    float n3=5;
    
    high_ord_lag(a1, a2, x1, n1);
    high_ord_lag(b1, b2, x2, n2);
    high_ord_lag(c1, c2, x3, n3);
    high_ord_lag(c1, c2, x4, n3);
}
