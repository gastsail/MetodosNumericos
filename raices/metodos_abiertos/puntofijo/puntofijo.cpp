#include <iostream>
using namespace std;
#include <math.h>

double fx(double x){
    return exp(-x) - x ; // Reemplazar por cualquier funcion
}

double gx(double x){
    return fx(x) + x;
}

int main(){
    double xo; //x0 = x inicial
    double xr,xrold; //valores viejos y nuevos
    int iter; //cantidad de iteraciones
    double es,ea; // error
    cout << "Ingrese la aproximación inicial: " << flush;
    cin >> xo;
    cout << "Ingrese la cantidad de iteraciones: " << flush;
    cin >> iter;
    cout << "Error: " << flush;
    cin >> es;

    xr = xo; // Asignamos el valor inicial a x nueva

    for(int i = 0 ; i < iter; i++){
        xrold = xr;
        xr = gx(xrold);

        if(xr != 0){
            ea = fabs((xr - xrold)/xr)*100;
        }else{
            iter = i;
            break;
        }

        if(ea < es){
            iter = i;
            break;
        }

    }

    cout << "El valor de la raiz es: " << xr << endl;
    cout << "cantidad de iteraciones: " << iter << endl; 

    return 0;
}