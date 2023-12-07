#pragma once
#include <iostream>
#include <cmath>
class Menu
{
private:
    /* data */
public:
    void mostrarMenu()
    {
        std::cout << "Método Numérico de Euler Mejorado" << std::endl;
        std::cout << "1. Resolver ecuación diferencial" << std::endl;
        std::cout << "2. Salir" << std::endl;
    }

    void ejecutar()
    {
        int opcion;
        EulerMejorado euler;

        do
        {
            mostrarMenu();
            std::cout << "Ingrese una opción: ";
            std::cin >> opcion;

            switch (opcion)
            {
            case 1:
            {
                double x0, y0, h;
                int num_pasos;

                Dato::ingresarDatos(x0, y0, h, num_pasos);
                Validacion::aplicarFix(h, num_pasos);

                double resultado = euler.eulerMejorado(x0, y0, h, num_pasos);
                std::cout << "El resultado es: " << resultado << std::endl;
                break;
            }
            case 2:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo." << std::endl;
                break;
            }
        } while (opcion != 2);
    }
    ~Menu() {}
};