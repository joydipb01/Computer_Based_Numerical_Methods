#include <stdio.h>

void lin_inter(float x0, float y0, float x1, float y1, float x){
    float y=y0+((y1-y0)/(x1-x0))*(x-x0);
    printf("tan(%.2f) = %.5f\n", x, y);
}

int main(){
    lin_inter(1.1, 1.9648, 1.2, 2.5722, 1.15);
    lin_inter(1.2, 2.5722, 1.3, 3.6021, 1.25);
} 
