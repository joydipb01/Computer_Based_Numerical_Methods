#include <stdio.h>
#include <math.h>
#define E 0.00001

float derv_func(float x, float y){
    return -2*x*y*y;
}

float mod_euler_predict(float x, float y, float h){
    float p=y+h*derv_func(x, y);
    return p;
}

float mod_euler_correct(float x, float y, float x1, float y1, float h){
    float c=y1;
    do{
        y1=c;
        c=y+0.5*h*(derv_func(x, y)+derv_func(x1, y1));
    }while(fabs(c-y1)>E);
    return c;
}

int main(){
    float x0=0, y0=1, x=0.4, h=0.2;
    while(x0<x){
        float x1=x0+h;
        float yp=mod_euler_predict(x0, y0, h);
        float yc=mod_euler_correct(x0, y0, x1, yp, h);
        x0=x1;
        y0=yc;
    }
    printf("%.4f", y0);
}
