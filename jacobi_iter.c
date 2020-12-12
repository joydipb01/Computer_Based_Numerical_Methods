#include <stdio.h>
#include <math.h>
#define M 10

void jacobi(float a[M][M], float b[M], int size);

int main(){
    float a[M][M] = {
                {5, -2, -2},
                {1, -3, 1},
                {-6, 4, 11}
            };

    float b[M] = {9, -2, 1};

    jacobi(a, b, 3);
    return 0;

}

void jacobi(float a[M][M], float b[M], int size){
    float l[M][M], u[M][M], d[M][M], dtemp[M][M], id[M][M], idtemp[M][M], lu[M][M];
    float x[M] = {0, 0, 0}, c[M] = {0, 0, 0}, e[M][M];
    int i, j, m, ctr = 0;
    float w0, w1, w2, v0, v1, v2;
    float xtemp[M] = {0, 0, 0};

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
           if(i == j){
                d[i][j] = a[i][j];
                u[i][j] = 0;
                l[i][j] = 0;
                id[i][j] = 1;
                idtemp[i][j] = 1;
           }
           else if(i > j){
                u[i][j] = a[i][j];
                d[i][j] = 0;
                l[i][j] = 0;
                id[i][j] = 0;
                idtemp[i][j] = 0;
           }
           else{
                l[i][j] = a[i][j];
                u[i][j] = 0;
                d[i][j] = 0;
                id[i][j] = 0;
                idtemp[i][j] = 0;
           }
        }
    }

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            dtemp[i][j] = d[i][j];
            lu[i][j] = l[i][j] + u[i][j];
        }
    }

    for(m = 0; m < size; m++){
        for(i = 0; i < size; i++){
            for(j = 0; j < size; j++){
                if(i == m){
                    d[i][j] = dtemp[i][j]/dtemp[m][m];
                    id[i][j] = idtemp[i][j]/dtemp[m][m];

                }else{
                    d[i][j] = dtemp[i][j] - (dtemp[i][m]/dtemp[m][m])*dtemp[m][j];
                    if((m > 0 && j == m) || m == 0)
                        id[i][m] = 0 - (dtemp[i][m]/dtemp[m][m]);
                    else
                        id[i][j] = idtemp[i][j] - (dtemp[i][m]/dtemp[m][m])*idtemp[m][j];
                }
            }
        }

        for(i = 0; i < size; i++){
            for(j = 0; j < size; j++){
                idtemp[i][j] = id[i][j];
                dtemp[i][j] = d[i][j];
            }
        }

    }


    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            c[i] += id[i][j]*b[j];
        }
    }

    for(i = 0; i < size; i++){
            for(j = 0; j < size; j++){
                    e[i][j] = 0;
                for(m = 0; m < size; m++){
                    e[i][j] = e[i][j] + id[i][m]*lu[m][j];
                }
            }
        }

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            e[i][j] = - e[i][j];
        }
    }

    do{
        w0 = x[0];
        w1 = x[1];
        w2 = x[2];
        for(i = 0; i < size; i++){
            for(j = 0; j < size; j++){
                xtemp[i] += e[i][j]*x[j];
            }
            xtemp[i] += c[i];
        }

        for(i = 0; i < size; i++){
            x[i] = xtemp[i];
        }

        for(i = 0; i < size; i++){
            xtemp[i] = 0;
        }
        v0 = x[0];
        v1 = x[1];
        v2 = x[2];
        ctr++;

    }while(fabs(w0 - v0) > 0.000001 && fabs(w1 - v1) > 0.000001 && fabs(w2 - v2) > 0.000001);
    //while(ctr < 3);


    for(i = 0; i < size; i++){
            printf("%f\n", x[i]);
        }


}






