#include <iostream>
#include <thread>
#include <chrono>
#include "Automovil.h"
#include "Semaforo.h"
#include "Conductor.h"

int main() {
    using namespace Vehiculos;
    using namespace ControlVial;

    Automovil auto1("Auto de Ana");
    Automovil auto2("Auto de Beto");

    Conductor conductorAna("Ana", &auto1);
    Conductor conductorBeto("Beto", &auto2);

    Semaforo semaforo;
    semaforo.agregarConductor(&conductorAna);
    semaforo.agregarConductor(&conductorBeto);

    int duraciones[3] = {15, 5, 25}; // Verde, Amarillo, Rojo, en segundos
    int indiceDuracion = 0;
    int segundosTranscurridos = 0;

    std::cout << "Simulador de semaforo iniciado (Ctrl+C para detener)\n";

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++segundosTranscurridos;

        if (segundosTranscurridos >= duraciones[indiceDuracion]) {
            semaforo.cambiarEstado();
            indiceDuracion = (indiceDuracion + 1) % 3;
            segundosTranscurridos = 0;
        }
    }

    return 0;
}