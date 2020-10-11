#include <stdio.h>
#include <math.h>
#define E 0.000005

float func(float x, int i){
    switch(i){
        case 1: return x*log10(x)-1.2;
                break;
        case 2: return x-exp(-x);
                break;
        case 3: return x-1.4*cos(x);
                break;
        case 4: return 2*(x-sin(x))-1;
                break;
        case 5: pow(x, 3)-5*x+1;
    }
}

void bis(float no1, float no2, int i){
    float temp=0.0;
    int count=0;
    if(func(no2, i)*func(no1, i)>=0){
        printf("Not the right arguments!!");
        return;
    }
    while(fabs(no2-no1)>=E){
        temp=(no1+no2)/2;
        if(func(temp, i)==0.0)
            break;
        else if(func(temp, i)*func(no1, i)<0)
            no2=temp;
        else if(func(temp, i)*func(no2, i)<0)
            no1=temp;
        count++;
    }
    printf("%.5f, %d\n", temp, count);
}

int main(){
    float x0, x1;
    int i;
    for(i=1;i<6;i++){
        switch(i){
            case 1:
                    x0=2;
                    x1=3;
                    break;
            case 2: 
                    x0=0.5;
                    x1=1;
                    break;
            case 3: 
                    x0=0;
                    x1=1;
                    break;
            case 4: 
                    x0=1;
                    x1=2;
                    break;
            case 5: 
                    x0=1;
                    x1=2;
        }
        bis(x0, x1, i);
    }
}
