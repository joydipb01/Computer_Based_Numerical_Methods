#include <stdio.h>
#include <math.h>
#define M 30

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

float simpson(float ll, float ul, float n, int j) {
    float h = (ul - ll) / n; 
    float x[M], fx[M]; 
    for (int i = 0; i <= n; i++) { 
        x[i] = ll + i * h; 
        fx[i] = func(x[i], j); 
    } 
    float res = 0; 
    for (int i = 0; i <= n; i++) { 
        if (i == 0 || i == n) 
            res += fx[i]; 
        else if (i % 2 != 0) 
            res += 4*fx[i]; 
        else
            res += 2*fx[i]; 
    } 
    res = res*(h/3); 
    printf("(n=%.f): %.5f\n", n+1, res);  
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
        for(n=1;n<=19;n++){
            if((int)n%2!=0)
                continue;
            simpson(x0, x1, n, i);
        }
        printf("\n\n");
    }
}
