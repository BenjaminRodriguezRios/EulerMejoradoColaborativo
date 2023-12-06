#pragma once
#include <Metodo.hpp> 
class EulerMejorado : public Metodo 
{
private:
    /* data */
public:
    double funcion(double x, double y) override 
    {
        return 2*(x * y);
    }
        double eulerMejorado(double x0, double y0, double h, int num_pasos) override {
        double x = x0;
        double y = y0;
        
        for (int i = 0; i < num_pasos; ++i) {
            double y_pred = y + h * funcion(x, y);
            double slope_average = (funcion(x, y) + funcion(x + h, y_pred)) / 2.0;
            y = y + h * slope_average;
            x = x + h;
        }
        
        return y;
    }
};
