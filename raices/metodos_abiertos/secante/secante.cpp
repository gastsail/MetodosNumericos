#include <iostream>
using namespace std;
#include <math.h>

double fx(double x){
    return log(x) - 1/x; // Reemplazar por cualquier funcion
}

double g(double x, double xi){
    return x - (fx(x)*(x-xi))/(fx(x)-fx(xi)); // No cambiar
}

int main(){
    double x0,x1;        //x0,x1 son valores iniciales
    double xi;          // valor de la funcion g valuada en x0,x1
    double xr,xr2,xrold;  // Valor anterior a iniciar el algoritmo y valor de reemplazo
    int iter;         // Cantidad de iteraciones realizadas por el algoritmo
    double es,ea;     // Errores para cortar antes el bucle

    cout << "Ingrese un valor inicial: " << flush;
    cin >> x0;
    cout << "Ingrese un valor secundario: " << flush;
    cin >> x1;
    cout << "Ingrese la cantidad de iteraciones: " << flush;
    cin >> iter;
    cout << "Error: " << flush;
    cin >> es;

    xr = x0;
    xr2 = x1;

    for(int i = 0 ; i < iter; i++){
       xi = g(xr,xr2);
       ea = fabs(xr - xi);
       xr = xi;
       xi = xr2;

        if(ea < es){
            iter = i;
            break;
        }

    }

    cout << "El valor de la raiz es " << xr <<endl;
    cout << "Cantidad de iteraciones " << iter <<endl;

    return 0;
}