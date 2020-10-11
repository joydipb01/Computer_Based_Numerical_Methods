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

void muller(float x0, float x1, float x2, char i) {
   float res=0.0, l1=0.0, d=0.0, g=0.0, c=0.0, l2=0.0;
   int count=0;
   do{
       l1=(x2-x1)/(x1-x0);
       d=1+l1;
       g=pow(l1, 2)*func(x0, i)-pow(d, 2)*func(x1, i)+(l1+d)*func(x2, i);
       c=l1*(l1*func(x0, i)-d*func(x1, i)+func(x2, i));
       if(g<0)
           l2=(-g-sqrt(g*g-4*d*func(x2, i)*c))/(2*c);
       else
           l2=(-g+sqrt(g*g-4*d*func(x2, i)*c))/(2*c);
       res=x2+(x2-x1)*l2;
       if(res==0.0)
           break;
       x0=x1;
       x1=x2;
       x2=res;
       count++;
   }while(fabs((x2-x1)*l2)>=E);
   printf("%.5f %d\n", res, count);
}

int main(){
    float x0=0.0, x1=0.0, x2=0.0;
    char c;
    for(c='1';c<='4'; c++){
        switch(c){
            case '1': 
                      x0=4.5;
                      x1=5.5;
                      x2=5.0;
                      break;
            case '2': 
                      x0=0;
                      x1=-0.1;
                      x2=-0.2;
                      break;
            case '3': 
                      x0=1;
                      x1=2;
                      x2=1.36;
                      break;
            case '4': 
                      x0=1;
                      x1=2;
                      x2 = 1.71;
        }
        muller(x0, x1, x2, c);
    }
}
