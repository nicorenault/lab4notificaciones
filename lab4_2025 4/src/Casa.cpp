#include "Casa.h"
#include "DTCasa.h"
#include <iostream>
Casa::Casa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo): Inmueble(direccion, numeroPuerta, superficie, anoConstruccion){
    this->esPH = esPH;
    this->techo =techo;
}

Casa::~Casa() {}

bool Casa::getEsPH() const{
    return esPH;
}




DTInmueble* Casa::toDT() const {
    return new DTCasa(
        this->getCodigo(),
        this->getDir(),
        this->getNumPuerta(),
        this->getSuperficie(),
        this->getAnoCons(),
        this->getEsPH(),
        this->getTecho()
    );
}
TipoTecho Casa::getTecho() const {
    return techo;
}
