#include <stdio.h>
#include <math.h>

void dd_lin_inter(float x0, float y0, float x1, float y1, float x){
    float y=y0+((x-x0)*(y1-y0)/(x1-x0));
    printf("f(%.2f) = %.5f\n", x, y);
}

float div_diff(float x0, float y0, float x1, float y1){
    return (y1-y0)/(x1-x0);
}

int main(){
    float arr1[5]={1, 2, 4, 7, 12};
    float arr2[5]={22, 30, 82, 106, 216};
    printf("x\ty\tf[x1, x2]\n");
    for(int i=0;i<5;i++){
        printf("%.2f\t%.2f\n", arr1[i], arr2[i]);
        if(i==4)
            break;
        printf("\t\t%.5f\n", div_diff(arr1[i], arr2[i], arr1[i+1], arr2[i+1]));
    }
    printf("\n");
    dd_lin_inter(2, 30, 4, 82, 3);
    dd_lin_inter(7, 106, 12, 216, 10);
} 
