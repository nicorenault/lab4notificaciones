#include "../include/DTCasa.h"
#include <iostream>
DTCasa::DTCasa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->esPH = esPH;
    this->techo = techo;
}

bool DTCasa::getEsPH() {
    return esPH;
}

TipoTecho DTCasa::getTecho() {
    return techo;
}

void DTCasa::imprimirDetalle(){
    std::cout
        << "Codigo: " << this->getCodigo()
        << ", direccion: " << this->getDireccion()
        << ", nro. puerta: " << this->getNumeroPuerta()
        << ", superficie: " << this->getSuperficie() << " m2"
        << ", consturccion: " << this->getAnioConstruccion()
        << ", PH: " << (this->getEsPH() ? "Si" : "No")
        << ", Tipo de techo: " << this->getTecho()
        << std::endl;
}
DTCasa::~DTCasa(){
    
}
