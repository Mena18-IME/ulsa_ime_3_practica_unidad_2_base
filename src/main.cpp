#include <iostream>
#include <thread>
#include <chrono>
#include "Semaforo.h"
#include "Conductor.h"
#include "Automovil.h"

int main() {
    using namespace Vehiculos;
    using namespace ControlVial;

    Automovil auto1("Auto de Ana");
    Automovil auto2("Auto de Beto");

    Conductor conductor("Ana", &auto1);
    Conductor conductor2("Beto", &auto2);

    Semaforo semaforo;
    semaforo.agregarConductor(&conductor);
    semaforo.agregarConductor(&conductor2);

    int duraciones[3] = {15, 5, 25};
    int indiceDuracion = 0;
    int segundosTranscurridos = 0;

    std::cout << "Simulador de semaforo iniciando (Ctrl+C para detener)\n";

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