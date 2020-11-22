#include <stdio.h>
#include <math.h>

void num_diff(float x[], float y[], int d, float n){
    float l1[30][d-2], l[d][d-1], l11[] = {0, 0, 0, 0, 0, 0}, px = 0;
    float l22[] = {0, 0, 0, 0, 0, 0}, l2[120][d-3];
    int i, j, k = 0, m = 0;
    for(i = 0; i < d; i++){
            k = 0;
        for(j = 0; j < d; j++){
            if(i == j)
                continue;
                l[i][k] = n - x[j];
                k++;
            }
    }
    k = 0;
    for(i = 0; i < 30; i++){
            m = 0;
            if(i % 5 == 0 && i != 0)
                k++;
        for(j = 0; j < d-2; j++){
            if((i - m) % 5 == 0){
                m++;
            }
            l1[i][j] = l[k][m];
            m++;
        }
    }
    for(i = 0; i < 30; i++){
        l1[i][0] = l1[i][0]*l1[i][1]*l1[i][2]*l1[i][3];
    }
    j = 0;
    for(i = 0; i < 30; i++){
        if(i % 5 == 0 && i != 0)
            j++;
        l11[j] += l1[i][0];
    }
    for(i = 0; i < d; i++){
      for(j = 0; j < d; j++){
        if(i == j)
            continue;
        l11[i] = l11[i]/(x[i] - x[j]);
      }

    }
    for(i = 0; i < d; i++){
       px += l11[i]*y[i];
    }
    printf("f'(%.3f)=%.5f", n, px);
}

int main(){
    float a1[6]={0, 2, 3, 4, 7, 9};
    float a2[6]={4, 26, 58, 112, 466, 922};
    int n=6;
    float x=6;
    num_diff(a1, a2, n, x);
}
