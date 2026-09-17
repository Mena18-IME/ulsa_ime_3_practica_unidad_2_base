#include "Automovil.h"
#include <iostream>

namespace Vehiculos {

    Automovil::Automovil(const std::string& nombre) : nombre(nombre), velocidad(0) {}

    void Automovil::arrancar(){
        velocidad = 20;
        std::cout << "[Auto] " << nombre << "arranca a velocidad por defecto (" << velocidad << " km/h)\n";

    }

    void Automovil::arrancar(int potencia){
        velocidad = potencia;
        std::cout << "[Auto] " << nombre << "arranca con potencia asignada(" << velocidad << "km/h)\n";

    }

    void Automovil::detener(){
        velocidad = 0;
        std::cout << "[Auto] " << nombre << " se detiene\n";

    }

    std::string Automovil::getNombre() const{
        return nombre; }
        int Automovil::getVelocidad() const { return velocidad; }

    }
