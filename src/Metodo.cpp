
#include <iostream>
#include <cmath>
class DatosUsuario {
public:
    static void ingresarDatos(double& x0, double& y0, double& h, int& num_pasos) {
        std::cout << "Ingrese x0: ";
        std::cin >> x0;
        std::cout << "Ingrese y0: ";
        std::cin >> y0;
        std::cout << "Ingrese el tamaño del paso (h): ";
        std::cin >> h;
        std::cout << "Ingrese el número de pasos: ";
        std::cin >> num_pasos;
    }
};
class Validacion {
public:
    static void aplicarFix(double& h, int& num_pasos) {
        // Aplicar cualquier fix o validación necesaria a los valores ingresados por el usuario
        if (h <= 0) {
            std::cout << "El tamaño del paso (h) debe ser mayor que cero. Se ajustará a un valor por defecto." << std::endl;
            h = 0.1; // Valor por defecto si h es menor o igual a cero
        }
        if (num_pasos <= 0) {
            std::cout << "El número de pasos debe ser mayor que cero. Se ajustará a un valor por defecto." << std::endl;
            num_pasos = 10; // Valor por defecto si num_pasos es menor o igual a cero
        }
    }
};

class MetodoNumerico {
public:
    virtual double funcion(double x, double y) = 0;
    virtual double eulerMejorado(double x0, double y0, double h, int num_pasos) = 0;
};

class EulerMejorado : public MetodoNumerico {
public:
    double funcion(double x, double y) override {
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

class Menu {
public:
    void mostrarMenu() {
        std::cout << "Método Numérico de Euler Mejorado" << std::endl;
        std::cout << "1. Resolver ecuación diferencial" << std::endl;
        std::cout << "2. Salir" << std::endl;
    }

    void ejecutar() {
        int opcion;
        EulerMejorado euler;


        do {
            mostrarMenu();
            std::cout << "Ingrese una opción: ";
            std::cin >> opcion;

            switch (opcion) {
                case 1: {
                    double x0, y0, h;
                    int num_pasos;

                    DatosUsuario::ingresarDatos(x0, y0, h, num_pasos);
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
};
//a
int main() {
    Menu menu;
    menu.ejecutar();
    return 0;
}
