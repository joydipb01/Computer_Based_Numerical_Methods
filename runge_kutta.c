#include <stdio.h>

float derv_func(float x, float y){
    return (x-y)/2;
}

float runge_kutta(float x0, float y0, float x, float h){
    int n = (int)((x-x0)/h);
    float k1, k2, k3, k4;
    for(int i=0;i<n;i++){
        k1=h*derv_func(x0, y0);
        k2=h*derv_func(x0+0.5*h, y0+0.5*k1);
        k3=h*derv_func(x0+0.5*h, y0+0.5*k2);
        k4=h*derv_func(x0+h, y0+k3);
        
        y0+=(1.0/6.0)*(k1+2*k2+2*k3+k4);
        x0+=h;
    }
    return y0;
}

int main() {
    float x0 = 0, y = 1, x = 2, h = 0.2; 
    printf("\nThe value of y at x is : %f", 
            runge_kutta(x0, y, x, h)); 
    return 0;
}
