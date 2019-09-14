#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#define N 2

using namespace std;

void printMatrix(double mat[N][N],int n);
bool esDDM(double mat[N][N], int n);

int main()
{

    double mat[N][N] = {
        //0  1  
        {1, 2}, // 0
        {3, 4}   // 1
    };
    // Ax = b
    double b[N] = {1, 2};
    double x[N];
    double m[N];
    double errorRelativo = 0.000001;

    int i, j, k, flag = 0, count = 0;
    int n = N; // Cantidad de filas
    double eps, y;

    cout << "\n Ingresar el grado de exactitud para la solucion:\n";
    cin >> eps;

    cout.precision(eps);
    cout.setf(ios::fixed);

    printMatrix(mat,n);

    // Chequeamos si la matriz es diagonalmente dominante
    if (esDDM(mat, n))
    {
        cout << "La matriz es diagonalmente domianante" << endl;
    }
    else
    {
        cout << "La matriz no es diagonoalmente dominante, por lo tanto no puede converger" << endl;
    }

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

    // Inicializamos los valores en 0 para poder calcular la solucion
    for (int i=0; i<n; i++){
		m[i]=0;
	} 

    // TODO LOGICA GAUSS SEIDEL

    do
    {
        for (i = 0; i < n; i++)
        {
            x[i] = (b[i] / mat[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                x[i] = x[i] - ((mat[i][j] / mat[i][i]) * m[j]);
                m[i] = x[i];
            }
            cout << "x" << i + 1 << "=" << x[i] << " ";
        }
        cout << "\n";
    } while (errorRelativo > eps);

    printMatrix(mat,n);
}

// Imprimimos la matriz cargada
void printMatrix(double mat[N][N],int n)
{
    int i, j;

    printf("Elementos en la matriz: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}

// Metodo para chequear que la matriz sea diagonalmente dominante
bool esDDM(double mat[N][N], int n)
{
    // para cada fila
    for (int i = 0; i < n; i++)
    {

        // Para cada columna, encontrar la suma de cada fila.
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += abs(mat[i][j]);

        // Sumamos todos los elementos de la fila menos el elemento de la diagonal
        sum -= abs(mat[i][i]);

        // Chequeamos si el elemento de la diagonal es menor que la suma
        if (abs(mat[i][i]) < sum)
            return false;
    }

    return true;
}