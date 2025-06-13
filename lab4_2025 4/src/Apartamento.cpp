#include "Apartamento.h"
#include "DTApartamento.h"
#include <iostream>
Apartamento::Apartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,int piso, bool tieneAscensor, float gastosComunes)
: Inmueble(direccion, numeroPuerta, superficie, anoConstruccion){
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
}

int Apartamento::getPiso() const {
    return piso;
}

bool Apartamento::getTieneAscensor() const {
    return tieneAscensor;
}

float Apartamento::getGastosComunes() const {
    return gastosComunes;
}

Apartamento::~Apartamento() {}


DTInmueble* Apartamento::toDT() const {
    return new DTApartamento(
        this->getCodigo(),
        this->getDir(),
        this->getNumPuerta(),
        this->getSuperficie(),
        this->getAnoCons(),
        this->getPiso(),
        this->getTieneAscensor(),
        this->getGastosComunes()
    );
}
