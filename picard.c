#include <stdio.h>
#include <math.h>
#define E 0.5
#define M 100

float func(float x){
    return 1+x+pow(x, 2)/2;
}

void picard(float sv, float ev){
    float temp, y[M];
    int count;
    for(temp=sv, count=0;temp<=ev;temp=temp+E, count++){
        y[count]=func(temp);
        printf("%.4f ", y[count]);
    }
    
}

int main() {
    float start_value=0, end_value=3;
    picard(start_value, end_value);
}
