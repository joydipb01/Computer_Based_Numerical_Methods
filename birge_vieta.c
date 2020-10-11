#include<stdio.h>
#include<math.h>
#define E 0.000001
#define M 10

float p[M], ply[M], q[M];

float synth (int m, float r)
{
    int i;
    q[0] = p[0];
    for (i = 1; i <= m; i++){
        q[i] = (q[i - 1] * r) + p[i];
    }
    return q[m];
}

void birgevieta(int m, float r){
    int i, count=0, flag = 0;
    float x, x1, fx, fdx;
    x = r;
    do{
        fx = synth (m, x);
        for (i = 0; i <= m; i++){
            p[i] = q[i];
        }
        fdx = synth (m - 1, x);
        x1 = x - (fx / fdx);
        if (fabs (x1 - x) <= E){
            flag = 1;
        }
        x = x1;
        for (i = 0; i <=m; i++){
            p[i] = ply[i];
        }
        count++;
    }while (flag != 1);

  printf ("%.5f %d\n", x1, count);
}

void main ()
{
    int m;
    float r;
    char c;
    for(c='1';c<='3';c++){
        switch(c){
            case '1': 
                      m=3;
                      p[0]=1;
                      p[1]=-1;
                      p[2]=-1;
                      p[3]=1;
                      r=0.5;
                      break;
            case '2': 
                      m=4;
                      p[0]=1;
                      p[1]=-3;
                      p[2]=3;
                      p[3]=-3;
                      p[4]=2;
                      r=0.5;
                      break;
            case '3': 
                      m=3;
                      p[0]=1;
                      p[1]=0;
                      p[2]=-1;
                      p[3]=-4;
                      r=1.5;
        } 
        for(int i=0;i<=m;i++){
            ply[i] = p[i];
        }
        birgevieta(m, r);
    }
}
