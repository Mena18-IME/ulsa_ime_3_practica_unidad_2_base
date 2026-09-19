#include "Semaforo.h"
#include "Conductor.h"
#include <iostream>

namespace ControlVial {

    Semaforo::Semaforo() {
        estados[0] = EstadoSemaforo::Verde;
        estados[1] = EstadoSemaforo::Amarillo;
        estados[2] = EstadoSemaforo::Rojo;
        actual = &estados[0]; // arranca en Verde
    }

    void Semaforo::agregarConductor(Conductor* c) {
        conductores.push_back(c);
    }

    void Semaforo::cambiarEstado() {
        if (actual == &estados[2]) {
            actual = &estados[0]; // de Rojo regresa a Verde
        } else {
            ++actual; // avanza al siguiente estado del arreglo
        }

        std::cout << "\n>>> El semaforo cambio de estado <<<\n";
        notificarConductores();
    }

    void Semaforo::notificarConductores() {
        for (Conductor* c : conductores) {
            c->reaccionar(*actual);
        }
    }

    EstadoSemaforo Semaforo::getColorActual() const {
        return *actual;
    }

}