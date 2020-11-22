#include <stdio.h>
#include <math.h>

float func(float x, int i){
    switch(i){
        case 1: return 1/(1+pow(x, 3));
                break;
        case 2: return pow(sin(M_PI*x), 2);
                break;
        case 3: return exp(-x*x);
                break;
        case 4: return x*exp(-x);
    }
}

void trapezoidal(float a, float b, float n, int j){
    float h = (b-a)/n; 
    float s = func(a, j)+func(b, j); 
    for (int i = 1; i < n; i++) 
        s += 2*func((a+i*h), j); 
    printf("(n=%.f): %.5f\n", n+1, (h/2)*s); 
}

int main(){
    float x0, x1, n;
    int i;
    for(i=1;i<5;i++){
        switch(i){
            case 1: 
                    x0=0;
                    x1=3;
                    break;
            case 2: 
                    x0=0;
                    x1=1;
                    break;
            case 3: 
                    x0=0;
                    x1=0.8;
                    break;
            case 4: 
                    x0=0;
                    x1=1;
        }
        printf("INTEGRAL NO. %d\n", i);
        for(n=1;n<=19;n++)
            trapezoidal(x0, x1, n, i);
        printf("\n");
    }
}
