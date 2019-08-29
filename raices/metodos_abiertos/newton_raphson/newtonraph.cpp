#include <iostream>
using namespace std;
#include <math.h>

double fx(double x){
    return log(x) - 1/x; // Reemplazar por cualquier funcion
}

double fp(double x){
    return (fx(x + 0.01) - fx(x)) / 0.01; //Valor aproximado de G prima
}

int main(){
    double x0;        //x0 = x inicial
    double xf;        // Valor de f(x0)
    double xr,xrold;  // Valor anterior a iniciar el algoritmo y valor de reemplazo
    double xfp;       // Valor de la derivada f'(x0)
    double xd;        // Resultado del nuevo valor aproximado de x para calcular de nuevo la proyeccion
    int iter;         // Cantidad de iteraciones realizadas por el algoritmo
    double es,ea;     // Errores para cortar antes el bucle

    cout << "Ingrese la aproximación inicial: " << flush;
    cin >> x0;
    cout << "Ingrese la cantidad de iteraciones: " << flush;
    cin >> iter;
    cout << "Error: " << flush;
    cin >> es;

    xr = x0;
    for(int i = 0 ; i < iter; i++){
        xrold = xr;
        xf = fx(xrold);
        xfp = fp(xrold);
        if(xfp != 0){
        xd = xrold - (xf / xfp);
        ea = fx(xd);
        xr = xd;
        }else{
            iter = i;
            cout << "La funcion derivada valuada en x0 es 0, por lo tanto no se puede calcular el nuevo xd"<<endl;
            break;
        }

        if(ea < es){
            iter = i;
            break;
        }

    }

    cout << "El valor de la raiz es " << xd <<endl;
    cout << "Valor de la funcion en ese punto " << xf <<endl; // Acá podemos ver que si el valor es 0.00000 aprox, dimos con una raiz
    cout << "Cantidad de iteraciones " << iter <<endl;

    return 0;
}