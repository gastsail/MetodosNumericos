#include <stdio.h>
#include <math.h>
#include <iostream>
#include <limits.h>
#include <float.h>

using namespace std;

void printMatrix(double mat[3][3]);

int main(){

    //Matriz de prueba, leer matriz de archivo
    double mat[3][3] = {
                            {1, 2, 3}, 
                            {4, 5, 6},
                            {7, 8, 9}
                          };
    
    double b[] = { 10, 20, 30 };

    int n = 3; // Tamaño de la matriz
    double factor; 

    // Print elements of two dimensional array.
    printMatrix(mat);

    int i,j,k;
    for(k = 0 ; k < n; k++){
        for(i = k + 1 ; i < n ; i++){
            factor = mat[i][k] / mat[k][k];
            for(j = k+1; j < n; j++){
                mat[i][j] = mat[i][j] - factor * mat[k][j];
                b[i] = b[i] - factor * b[k];
            }
        }
    }

    printMatrix(mat);

    return 0;
}

// Imprimimos la matriz cargada
void printMatrix(double mat[3][3]){
    int i, j;

    printf("Elementos en la matris: \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}