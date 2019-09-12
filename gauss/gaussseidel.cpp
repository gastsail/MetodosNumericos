#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

void printMatrix(double mat[3][3]);

int main()
{

    double mat[3][3] = {
        //0  1   2
        {27, 6, -1}, // 0
        {6, 15, 2}, // 1
        {1, 1, 54}  // 2
    };
    // Ax = b
    double b[] = {85, 72, 110};

    int i, j, k, flag = 0, count = 0;
    int n = 3; // Cantidad de filas
    double eps, y;

    cout << "\n Ingresar el grado de exactitud para la solucion:\n";
    cin >> eps;

    cout.precision(eps);
    cout.setf(ios::fixed);

    printMatrix(mat);

    // ------- Pivoteo -------
    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (fabs(mat[i][i]) < fabs(mat[k][i]))
            {
                for (j = 0; j <= n; j++)
                {
                    double aux = mat[i][j];
                    mat[i][j] = mat[k][j];
                    mat[k][j] = aux;
                }
            }
        }
    }
    // ------- Fin pivoteo -------

    // TODO LOGICA GAUSS SEIDEL


    cout << "\n Soluciones \n";
    for (i = 0; i < n; i++)
    {
        cout << "x" << i << " = " << b[i] << endl;
    }

    printMatrix(mat);
}

// Imprimimos la matriz cargada
void printMatrix(double mat[3][3])
{
    int i, j;

    printf("Elementos en la matriz: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}