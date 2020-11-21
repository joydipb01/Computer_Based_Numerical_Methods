#include <stdio.h>
#include <math.h>

float u_cal(float u, int n) { 
    float temp = u; 
    for (int i = 1; i < n; i++) 
        temp = temp * (u+i); 
    return temp; 
}

int fact(int n) { 
    int f = 1; 
    for (int i = 2; i <= n; i++) 
        f *= i; 
    return f; 
} 

void back_diff_inter(float x[], float a[], float xin, int n){
    float y[n][n];
    for(int i=0; i<n; i++)
        y[i][0]=a[i];
    for (int i = 1; i < n; i++){ 
        for (int j = n - 1; j >= i; j--) 
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1]; 
    } 
    /*for (int i = 0; i < n; i++){ 
        for (int j = 0; j <= i; j++) 
            printf("%.1f\t", y[i][j]); 
        printf("\n"); 
    }*/                     //To print Divided Difference table
    float sum = y[n-1][0]; 
    float u = (xin - x[n-1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) { 
        sum = sum + (u_cal(u, i)*y[n-1][i])/fact(i); 
    }
    printf("f(%.3f)=%.5f\n\n", xin, sum);
}

int main(){
    float a1[5]={1891, 1901, 1911, 1921, 1931};
    float a2[5]={46, 66, 81, 93, 101};
    float x1=1925;
    int n1=5;
    
    float b1[5]={0, 0.2, 0.4, 0.6, 0.8};
    float b2[5]={0.12, 0.46, 0.74, 0.90, 1.20};
    float x2=0.1;
    int n2=5;
    
    float c1[7]={100, 150, 200, 250, 300, 350, 400};
    float c2[7]={10.63, 13.03, 15.04, 16.81, 18.42, 19.90, 21.27};
    float x3=160;
    float x4=410;
    int n3=7;
    
    back_diff_inter(a1, a2, x1, n1);
    back_diff_inter(b1, b2, x2, n2);
    back_diff_inter(c1, c2, x3, n3);
    back_diff_inter(c1, c2, x4, n3);
}
