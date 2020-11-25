#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 3        

int forwardElim(double mat[N][N+1]); 
void backSub(double mat[N][N+1]); 

void gaussianElimination(double mat[N][N+1]) 
{ 
    int singular_flag = forwardElim(mat); 
    if (singular_flag != -1) 
    { 
        printf("Singular Matrix.\n"); 
        if (mat[singular_flag][N]) 
            printf("Inconsistent System."); 
        else
            printf("May have infinitely many "
                   "solutions."); 
        return; 
    } 
    backSub(mat); 
} 
void swap_row(double mat[N][N+1], int i, int j) 
{ 
    //printf("Swapped rows %d and %d\n", i, j); 
    for (int k=0; k<=N; k++) 
    { 
        double temp = mat[i][k]; 
        mat[i][k] = mat[j][k]; 
        mat[j][k] = temp; 
    } 
} 
void print(double mat[N][N+1]) 
{ 
    for (int i=0; i<N; i++, printf("\n")) 
        for (int j=0; j<=N; j++) 
            printf("%lf ", mat[i][j]); 
    printf("\n"); 
} 

int forwardElim(double mat[N][N+1]) 
{ 
    for (int k=0; k<N; k++) 
    { 
        int i_max = k; 
        int v_max = mat[i_max][k]; 
        for (int i = k+1; i < N; i++) 
            if (abs(mat[i][k]) > v_max) 
                v_max = mat[i][k], i_max = i;
        if (!mat[k][i_max]) 
            return k; 
        if (i_max != k) 
            swap_row(mat, k, i_max); 
        for (int i=k+1; i<N; i++) 
        { 
            double f = mat[i][k]/mat[k][k]; 
            for (int j=k+1; j<=N; j++) 
                mat[i][j] -= mat[k][j]*f; 
            mat[i][k] = 0; 
        } 
  
        //print(mat);         
    } 
    //print(mat);            =
    return -1; 
} 

void backSub(double mat[N][N+1]) 
{ 
    double x[N];  
    for (int i = N-1; i >= 0; i--) 
    { 
        x[i] = mat[i][N]; 
        for (int j=i+1; j<N; j++) 
        { 
            x[i] -= mat[i][j]*x[j]; 
        } 
        x[i] = x[i]/mat[i][i]; 
    } 
    printf("Solution for the system:\n"); 
    for (int i=0; i<N; i++) 
        printf("x%d=%lf\n", (i+1), x[i]); 
    printf("\n");
} 

int main() 
{ 
    
    double mat[N][N+1] = {{20, 15, 10, 45}, 
                          {-3, -2.249, 7, 1.751}, 
                          {5, 1, 3, 9} 
                         }; 
    gaussianElimination(mat); 
    double mat1[N][N+1] = {{0, 5, 6, 11}, 
                          {4, 5, 7, 16}, 
                          {9, 2, 3, 15} 
                         }; 
    gaussianElimination(mat1);
    double mat2[N][N+1] = {{2, 4, 6, 22}, 
                          {3, 8, 5, 27}, 
                          {-1, 1, 2, 2} 
                         }; 
    gaussianElimination(mat2);
    return 0; 
} 
