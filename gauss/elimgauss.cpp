#include <stdio.h>
#include <math.h>
#include <iostream>
#include <limits.h>
#include <float.h>

using namespace std;

void printMatrix(double mat[3][3]);

int main(){

    //Matriz de prueba, leer matriz de archivo
    
    double mat[3][3] = {   //0  1   2
                            {2, 1, -1}, // 0
                            {3, -1, 2}, // 1
                            {-2, 1, 1}  // 2
                          };
    
       double matcpy[3][3] = {   //0  1   2
                            {2, 1, -1}, // 0
                            {3, -1, 2}, // 1
                            {-2, 1, 1}  // 2
                          };


    double b[] = { 8, -11, -3 };
    double bcpy[] = { 8, -11, -3 };

    int n = 3; // Tamaño de la matriz
    double factor;
    double xi[n]; // Valores finales para la solucion de la matriz
    double sum;

    // Imprimimos la matriz
    printMatrix(mat);

    // Reducimos la matriz, podemos poner j = k en el ultimo for para ver la triangulación superior
    int i,j,k;
    for(k = 0 ; k < n; k++){
        for(i = k + 1 ; i < n ; i++){
            factor = mat[i][k] / mat[k][k]; // Primer pasada factor = mat[1][0] / mat[0,0] = 3/2
            for(j = k+1; j < n; j++){
                mat[i][j] = mat[i][j] - (factor * mat[k][j]); // mat[1][1] = mat[1][1] - 3/2 * mat[0][1]
            }
             b[i] = b[i] - (factor * b[k]);
        }
    }

    // Hacemos la sustitucion hacia atras para encontrar los valores de xi
    int p,o;
    for(p = n-1; p >= 0; p--){
        sum = b[p];
        for(o = p + 1 ; o < n ; o++){
            sum = sum - mat[p][o] * xi[o];
        }
        xi[p] = sum / mat[p][p];
        cout << "x"<< "" << p << ": " << xi[p] << endl;
    }

    double s;
    for(int i = 0; i < n ; i++){
        s = -bcpy[i];
        for(int j = 0; j < n ; j++){
            s = s + matcpy[i][j] * xi[j];
        }
        cout << "result" << s << endl;
    }

    printMatrix(mat);
   

    return 0;
}

// Imprimimos la matriz cargada
void printMatrix(double mat[3][3]){
    int i, j;

    printf("Elementos en la matriz: \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}