#include <stdio.h>
#define M 10 

int gaussjordan(float a[][M], int n) 
{ 
    int i, j, k = 0, c, flag = 0, m = 0; 
    float pro = 0; 
    for (i = 0; i < n; i++) 
    { 
        if (a[i][i] == 0)  
        { 
            c = 1; 
            while ((i + c) < n && a[i + c][i] == 0)  
                c++;             
            if ((i + c) == n) { 
                flag = 1; 
                break; 
            } 
            for (j = i, k = 0; k <= n; k++){ 
                a[j][k]=a[j][k]+a[j+c][k];
                a[j+c][k]=a[j][k]-a[j+c][k];
                a[j][k]=a[j][k]-a[j+c][k];
            }
        } 
        for (j = 0; j < n; j++) { 
            if (i != j){
                float pro = a[j][i] / a[i][i]; 
                for (k = 0; k <= n; k++)                  
                    a[j][k] = a[j][k] - (a[i][k]) * pro;                 
            } 
        } 
    } 
    return flag; 
} 
 
void PrintResult(float a[][M], int n, int flag) 
{ 
    printf("Solution of the system is:\n"); 
    if (flag == 2)      
      printf("Infinite Solutions Exists\n");     
    else if (flag == 3)      
      printf("No Solution Exists\n"); 
    else { 
        for (int i = 0; i < n; i++)          
            printf("x%d=%.6f\n", (i+1), a[i][n]/a[i][i]);         
    } 
} 
 
int CheckConsistency(float a[][M], int n, int flag) 
{ 
    int i, j; 
    float sum; 
    flag = 3; 
    for (i = 0; i < n; i++)  
    { 
        sum = 0; 
        for (j = 0; j < n; j++)         
            sum = sum + a[i][j]; 
        if (sum == a[i][j])  
            flag = 2;         
    } 
    return flag; 
} 

int main() 
{ 
    float a[M][M] = {{ 1, 3, -5, 2 },  
                     { 3, 11, -9, 4 },  
                     { -1, 1, 6, 5 }};
    float a1[M][M] = {{ 1, 1, 1, 5 },  
                     { 2, 3, 5, 8 },  
                     { 4, 0, 5, 2 }};
    float a2[M][M] = {{ 1, 2, -3, 2 },  
                     { 6, 3, 9, 6 },  
                     { 7, 17, -19, 13 }};
    int n = 3, flag = 0; 
    flag = gaussjordan(a, n); 
    if (flag == 1)      
        flag = CheckConsistency(a, n, flag);
    PrintResult(a, n, flag);
    printf("\n");
    
    flag = gaussjordan(a1, n); 
    if (flag == 1)      
        flag = CheckConsistency(a1, n, flag);
    PrintResult(a1, n, flag);
    printf("\n");
    
    flag = gaussjordan(a2, n); 
    if (flag == 1)      
        flag = CheckConsistency(a2, n, flag);
    PrintResult(a2, n, flag);
    return 0; 
} 
