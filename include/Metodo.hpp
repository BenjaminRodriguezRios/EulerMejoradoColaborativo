#pragma once
class Metodo
{
private:
    /* data */
public:
    virtual double funcion(double x, double y) = 0;
    virtual double eulerMejorado(double x0, double y0, double h, int num_pasos) = 0;
};
