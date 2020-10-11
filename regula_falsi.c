#include <stdio.h>
#include <math.h>
#define E 0.000005

float func(float x, int n){
    switch(n){
        case 1: return pow(x, 3)-2*x-5;
                break;
        case 2: return cos(x)-x*exp(x);
                break;
        case 3: return x-exp(-x);
                break;
        case 4: return pow(x, 3)-2*pow(x, 2)+3*x-5;
                break;
    }
}

void regfals(float x1, float x2, int i){
    float temp=0.0;
    int count=0;
    do{
        temp=(x1*func(x2, i)-x2*func(x1, i))/(func(x2, i)-func(x1, i));
        if(func(temp, i)==0.0)
            break;
        else if(func(temp, i)*func(x1, i)<0)
            x2=temp;
        else
            x1=temp;
        count++;
    }while(fabs(func(temp, i))>E);
    printf("%.5f %d\n", temp, count);
}

int main()
{
    float x1=0.0, x2=0.0;
    int i;
    for(i=1;i<=4;i++){
        switch(i){
            case 1:
                    x1=2;
                    x2=3;
                    break;
            case 2: 
                    x1=0;
                    x2=1;
                    break;
            case 3:
                    x1=0;
                    x2=1;
                    break;
            case 4:
                    x1=1;
                    x2=2;
        }
        regfals(x1, x2, i);
    }
}
