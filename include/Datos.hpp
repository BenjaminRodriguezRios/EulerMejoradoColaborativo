#pragma once
class Dato
{
private:
    /* data */
public:
    static void ingresarDatos(double &x0, double &y0, double &h, int &num_pasos)
    {
        std::cout << "Ingrese x0: ";
        std::cin >> x0;
        std::cout << "Ingrese y0: ";
        std::cin >> y0;
        std::cout << "Ingrese el tamaño del paso (h): ";
        std::cin >> h;
        std::cout << "Ingrese el número de pasos: ";
        std::cin >> num_pasos;
    }
    ~Dato() {}
};
