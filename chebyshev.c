#include <stdio.h>
#include <math.h>
#define E 0.000005

float func(float x, char c){
    switch(c){
        case '1': return pow(x, 3)-13*x-12;
                  break;
        case '2': return pow(x, 7)+3*pow(x, 6)+7*pow(x, 5)+pow(x, 4)+5*pow(x, 3)+2*x*x+5*x+5;
                  break;
        case '3': return x+sin(x)-0.5;
                  break;
        case '4': return pow(x, 4)-x-10;
    }
}

float fdash(float x, char c){
    switch(c){
        case '1': return 3*x*x-13;
                  break;
        case '2': return 7*pow(x, 6)+18*pow(x, 5)+35*pow(x, 4)+4*pow(x, 3)+15*pow(x, 2)+4*x+5;
                  break;
        case '3': return 1+cos(x);
                  break;
        case '4': return 4*pow(x, 3)-1;
    }
}

float fdash2(float x, char c){
    switch(c){
        case '1': return 6*x;
                  break;
        case '2': return 42*pow(x, 5)+90*pow(x, 4)+140*pow(x, 3)+12*x*x+30*x+4;
                  break;
        case '3': return -sin(x);
                  break;
        case '4': return 12*pow(x, 2);
    }
}

void chebyshev(float x1, char i){
    float h=func(x1, i)/fdash(x1, i)+(0.5*pow(func(x1, i), 2)*fdash2(x1, i)/pow(fdash(x1, i), 3));
    int count=0;
    while(fabs(h)>=E){
        h=func(x1, i)/fdash(x1, i)+0.5*pow(func(x1, i), 2)*fdash2(x1, i)/pow(fdash(x1, i), 3);
        if(func(x1, i)==0.0)
            break;
        x1-=h;
        count++;
    }
    printf("%.5f %d\n", x1, count);
}

int main(){
    float x1=0.0;
    char c;
    for(c='1';c<='4'; c++){
        switch(c){
            case '1': x1=5;
                      break;
            case '2': x1=-0.1;
                      break;
            case '3': x1=1.36;
                      break;
            case '4': x1 = 1.71;
        }
        chebyshev(x1, c);
    }
}
