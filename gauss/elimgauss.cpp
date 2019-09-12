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
                            {0, 1, -1}, // 0
                            {3, -1, 2}, // 1
                            {-2, 1, 1}  // 2
                          };
    
       double matcpy[3][3] = {   //0  1   2
                            {0, 1, -1}, // 0
                            {3, -1, 2}, // 1
                            {-2, 1, 1}  // 2
                          };


    double b[] = { 8, -11, -3 };
    double bcpy[] = { 8, -11, -3 };

    int n = 3; // Tamaño de la matriz
    double factor;
    double xi[n]; // Valores finales para la solucion de la matriz
    double sum,aux;
    double eps;
    bool flag;

    cout << "\n Ingresar el grado de exactitud para la solucion:\n";
    cin >> eps;

    // Imprimimos la matriz
    printMatrix(mat);

    int i,j,k;
    for(i = 0 ; i < n; i++){
        // Pivoteo
        if(fabs(mat[i][i]) <= eps){
            flag = false;
            for(j = i+1 ; j < n ; j++){
                if(fabs(mat[j][0]) >= eps){
                    flag = true;
                    for(k = 0 ; k < n ; k++){
                        aux=mat[i][k];
						mat[i][k]=mat[j][k];
						mat[j][k]=aux;
                    }
                // Hacemos el mismo intercambio, pero para el vector
                aux=b[i];
				b[i]=b[j];
				b[j]=aux;
				break;
                }
            }
            if(flag==false) return -1;
        }
        // ------ Fin Pivoteo ------


        // Hacemos las operaciones para triangular la matriz para luego poder obtener los resultados mediante sustitucion regresiva
        for(int j = i + 1 ; j < n ; j++){
            factor = mat[j][i] / mat[i][i]; 
            for(int k = i; k < n; k++){ // Si se pone j = k, y ponemos printMatriz(mat) podemos ver la matriz triangulada
                mat[j][k] = mat[j][k] - (factor * mat[i][k]);
            }
             b[j] = b[j] - (factor * b[i]);
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



    // Chequeamos si el resultado reemplazado da 0 haciendo la resta y de esa forma verificamos que los valores 
    // de xi son correctos
    double s;
    for(int i = 0; i < n ; i++){
        s = -bcpy[i];
        for(int j = 0; j < n ; j++){
            s = s + matcpy[i][j] * xi[j];
        }
        cout << "result: " << s << endl;
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