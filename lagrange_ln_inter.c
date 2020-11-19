#include <stdio.h>
#include <math.h>

void lag_lin_inter(float x0, float y0, float x1, float y1, float x){
    float y=y0*((x-x1)/(x0-x1))+y1*((x-x0)/(x1-x0));
    printf("f(%.2f) = %.5f\n", x, y);
}

int main(){
    lag_lin_inter(-2, -2.63906, 0, -2.48491, -0.8);
    lag_lin_inter(0, -2.48491, 2, -1.94591, 0.8);
    lag_lin_inter(5, -1.94591, 6, -1.79176, 5.5);
    lag_lin_inter(1.3, -0.6878, 1.6, -0.9962, 1.5);
    lag_lin_inter(1.6, -0.9962, 1.9, -0.5507, 1.8);
} 
