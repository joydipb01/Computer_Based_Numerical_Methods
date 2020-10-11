#include <stdio.h>
#include <math.h>
#define E 0.000005

float func(float x, int n){
    switch(n){
        case 1: return cos(x)+2*sin(x)+pow(x, 2);
                break;
        case 2: return pow(x, 3)-4;
                break;
        case 3: return 3*x+sin(x)-exp(x);
                break;
        case 4: return exp(x)-3*x;
                break;
    }
}

void sec(float x1, float x2){
    int count=0;
    float x3=0.0;
    for(int i=1; i<=4; i++){
        do{
            x3=(x1*func(x2, i)-x2*func(x1, i))/(func(x2, i)-func(x1, i));
            x1=x2;
            x2=x3;
            count++;
        }while(fabs(func(x3, i))>E);
        printf("%.5f %d\n", x2, count);
    }
}

int main()
{
    float x1=0, x2=1;
    sec(x1, x2);
}
