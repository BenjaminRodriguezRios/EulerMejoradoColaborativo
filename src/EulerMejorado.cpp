//arantza y benjamin se van a casar <3
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include <iostream>
#include <cmath>
#include "iostream"
#include<stdlib.h>
#include <iostream>
#include <cmath>
// Función que define la EDO dy/dx = f(x, y)
double f(double x, double y) 
{
    return (2*(x * y)); // Cambia esta función por la EDO que quieras resolver
}
// Método de Euler mejorado
void eulerMejorado(double x0, double y0, double h, double x_target) {
    double x = x0;
    double y = y0;

    while (x < x_target) {
        double y_pred = y + h * f(x, y); // Predictor
        double y_corr = y + h * ((f(x, y) + f(x, y_pred))/2); // Corrector

        x += h;
        y = y_pred;//----

        std::cout << "x = " << x << ", y = " << y << std::endl;
    }
}
int main() {
    double x0 = 0; // Valor inicial de x
    double y0 = 1.0; // Valor inicial de y
    double h = 0.1; // Tamaño del paso
    double x_target = .3; // Valor de x en el que se quiere encontrar y
    eulerMejorado(x0, y0, h, x_target);
    return 0;
}