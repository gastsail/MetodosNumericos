#include <stdio.h>
#include <math.h>
#include <iostream>

#define N 4

using namespace std;

int main()
{
    double x[N];
    double y[N];
    double xinter; // Valor a evaluar la expresion, por ejemplo, para xinter = 1.75 = f(1.75) = ....
    double sum;
    double product;

    for (int i = 0; i < N; i++)
    {
        cout << "x" << i << ":";
        cin >> x[i];

        cout << "y" << i << ":";
        cin >> y[i];
    }

    cout << "Ingrese el valor a aproximar: " << endl;
    cin >> xinter;

    sum = 0;
    int i,j;
    for(i = 0; i < N ; i++){
        product = y[i];
        for(j = 0 ; j < N ; j++){
            if(i!=j){
                product = product*(xinter - x[j]) / (x[i] - x[j]);
            }
        }
        sum += product;
    }

    cout << "El resultado es : " << sum << endl;
    

    return 0;
}