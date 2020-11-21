#include <stdio.h>

float u_cal(float u, int n) { 
    float temp = u; 
    for (int i = 1; i < n; i++) 
        temp = temp * (u - i); 
    return temp; 
}

int fact(int n) { 
    int f = 1; 
    for (int i = 2; i <= n; i++) 
        f *= i; 
    return f; 
} 

void forw_diff_inter(float x[], float a[], float xin, int n){
    float y[n][n];
    for(int i=0; i<n; i++)
        y[i][0]=a[i];
    for (int i = 1; i < n; i++) { 
        for (int j = 0; j < n - i; j++) 
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1]; 
    } 
    /*for (int i = 0; i < n; i++) { 
        printf("%.3f\t", x[i]); 
        for (int j = 0; j < n - i; j++) 
            printf("%.3f\t", y[i][j]); 
        printf("\n"); 
    }*/                                 //To print Divided Difference table
    float sum = y[0][0]; 
    float u = (xin - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) { 
        sum = sum + (u_cal(u, i)*y[0][i])/fact(i); 
    }
    printf("f(%.3f)=%.5f\n\n", xin, sum);
}

int main(){
    float a1[5]={1891, 1901, 1911, 1921, 1931};
    float a2[5]={46, 66, 81, 93, 101};
    float x1=1895;
    int n1=5;
    
    float b1[4]={0, 1, 2, 3};
    float b2[4]={1, 0, 1, 10};
    float x2=-1;
    int n2=4;
    
    float c1[5]={2, 3, 4, 5, 6};
    float c2[5]={1, 2, 6, 24, 120};
    float x3=2.5;
    float x4=4.5;
    int n3=5;
    
    forw_diff_inter(a1, a2, x1, n1);
    forw_diff_inter(b1, b2, x2, n2);
    forw_diff_inter(c1, c2, x3, n3);
    forw_diff_inter(c1, c2, x4, n3);
}  
