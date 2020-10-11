#include <stdio.h>
#include <math.h>
#define E 0.000005

float func(float x, char c, float n){
    switch(c){
        case '1': return x*x-2*x-5;
                  break;
        case '2': return x*sin(x)+cos(x);
                  break;
        case '3': return x*tan(x)+1;
                  break;
        case '4': return x*x-n;
    }
}

float fdash(float x, char c){
    switch(c){
        case '1': return 2*x-2;
                  break;
        case '2': return x*cos(x);
                  break;
        case '3': return tan(x)+x*pow((1/cos(x)), 2);
                  break;
        case '4': return 2*x;
    }
}

void newtraph(float x1, char i, float n){
    float h=func(x1, i, n)/fdash(x1, i);
    int count=0;
    while(fabs(h)>=E){
        h=func(x1, i, n)/fdash(x1, i);
        if(func(x1, i, n)==0.0)
            break;
        x1-=h;
        count++;
    }
    printf("%.5f %d\n", x1, count);
}

int main(){
    float x1=0.0;
    char c;
    float n=0.0;
    for(c='1';c<='4'; c++){
        switch(c){
            case '1': x1=2;
                      break;
            case '2': x1=3.1416;
                      break;
            case '3': x1=2.5;
                      break;
            case '4': scanf("%f %f", &x1, &n);
        }
        newtraph(x1, c, n);
    }
}
