#include <iostream>
using namespace std;
#include <math.h>

double fx(double x){
    return sin(sqrt(x)) - x; // Reemplazar por cualquier funcion
}
// Usar el + x si es necesario
double gx(double x){
  return fx(x) + x;
}

double gp(double x){
    return ((gx(x + 0.01) - gx(x)) / 0.01); //Valor aproximado de G prima
}

int main(){
    double xo;        //x0 = x inicial
    double xr, xrold; //valores viejos y nuevos
    int iter;         //cantidad de iteraciones
    double es, ea;    // error
    cout << "Ingrese la aproximación inicial: " << flush;
    cin >> xo;
    cout << "Ingrese la cantidad de iteraciones: " << flush;
    cin >> iter;
    cout << "Error: " << flush;
    cin >> es;

    xr = xo; // Asignamos el valor inicial a x nueva

    for (int i = 0; i < iter; i++){
        xrold = xr;
        xr = gx(xrold);

        if(fabs(gp(xrold)) < 1){
           ea = fabs((xr - xrold) / xr) * 100;
        }else{
            cout << "La derivada diverge y no se puede encontrar la raiz" << endl;
            iter = i;
            break;
        }

        if (ea < es){
            iter = i;
            break;
        }
    }

    cout << "El valor de la raiz es: " << xr << endl;
    cout << "cantidad de iteraciones: " << iter << endl;

    return 0;
}

