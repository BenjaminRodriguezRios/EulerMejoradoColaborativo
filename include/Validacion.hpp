#pragma once
class Validacion
{
private:
    /* data */
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
    ~Validacion() {}
};