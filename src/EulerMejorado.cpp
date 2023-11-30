
#include <iostream>
#include <cmath>

// Clase base para las ecuaciones diferenciales
class EcuacionDiferencial {
public:
    virtual double funcion(double x, double y) const = 0;
};

// Clase para la ecuación específica: y' = x^2 + y^2
class EcuacionEjemplo : public EcuacionDiferencial {
public:
    double funcion(double x, double y) const override {
        return pow(x, 2) + pow(y, 2);
    }
};

// Clase para el método de Euler mejorado
class EulerMejorado {
public:
    double resolver(const EcuacionDiferencial& ecuacion, double x0, double y0, double h, int iteraciones) {
        double x = x0;
        double y = y0;

        for (int i = 0; i < iteraciones; ++i) {
            double y_pred = y + h * ecuacion.funcion(x, y);
            double y_next = y + h * (ecuacion.funcion(x, y) + ecuacion.funcion(x + h, y_pred)) / 2.0;
            x += h;
            y = y_next;
        }

        return y;
    }
};

// Clase para el menú
class Menu {
public:
    void mostrarMenu() {
        std::cout << "Seleccione la ecuacion a resolver:" << std::endl;
        std::cout << "1. y' = x^2 + y^2" << std::endl;
        std::cout << "Seleccione una opcion: ";
    }

    void ejecutar() {
        int opcion;
        double x0, y0, h;
        int iteraciones;

        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                {
                    EcuacionEjemplo ecuacion;
                    EulerMejorado euler;

                    std::cout << "Ingrese el valor inicial de x: ";
                    std::cin >> x0;

                    std::cout << "Ingrese el valor inicial de y: ";
                    std::cin >> y0;

                    std::cout << "Ingrese el tamaño de paso h: ";
                    std::cin >> h;

                    std::cout << "Ingrese el numero de iteraciones: ";
                    std::cin >> iteraciones;

                    double resultado = euler.resolver(ecuacion, x0, y0, h, iteraciones);
                    std::cout << "El resultado es: " << resultado << std::endl;
                    break;
                }
            default:
                std::cout << "Opcion no valida. Saliendo del programa." << std::endl;
                break;
        }
    }
};

int main() {
    Menu menu;
    menu.ejecutar();
    return 0;
}
