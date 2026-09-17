#include "Conductor.h"
#include <iostream>

Conductor::Conductor(const std::string& nombre, Vehiculos::Automovil* auto_) : nombre(nombre), miAuto(auto_) {}

void Conductor::reaccionar(ControlVial::EstadoSemaforo estado) {
    using ControlVial::EstadoSemaforo;

    std::cout << "[Conductor] " << nombre << " ve el cambio del semaforo...\n";

    if (estado == EstadoSemaforo::Verde){
        miAuto -> arrancar(60);
    } else {
        miAuto -> detener();
    }
}