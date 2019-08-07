/*
 * Método cerrado - Bisección
 * Dados dos intervalos xl y xu y una funcion f(x), encontrar la raiz
 * que encierra ese intervalo.
 */

#include <iostream>
using namespace std;
#include <math.h>

double funcion(double x){
    return sin(10 * x) - cos(3 * x); // Reemplazar por cualquier funcion
}

int main(){
    // xl,xu -> Intervalos de busqueda [inferior,superior]
    // xr -> Resultado de subdividir los intervalos para re evaluar la funcion achicando el intervalo
    // ea -> Error relativo porcentual ; es -> Valor previamente fijado (TODO)
    double xl, xu, xr, ea, es;

    cout << "Limite inferior:" << flush;
    cin >> xl;
    cout << "Limite superior:" << flush;
    cin >> xu;

    if (funcion(xl) == 0){
        cout << "xl es raiz: " << xl << endl;
        return 0;
    }

    if (funcion(xu) == 0){
        cout << "xu es raiz: " << xu << endl;
        return 0;
    }

    if (funcion(xl) * funcion(xu) > 0){
        cout << "Existe un numero par de raizes " << endl;
        return 0;
    }

    for (int i; i < 1000; i++){
        
        xr = (xl + xu) / 2;
        if (funcion(xl) * funcion(xr) < 0){
            xu = xr;
        }else{
            xl = xr;
        }
        if (funcion(xl) * funcion(xr) == 0){
            break;
        }
    }

    cout << "La raiz encontrada entre los intervalos es: " << xr << endl;

    return 0;
}