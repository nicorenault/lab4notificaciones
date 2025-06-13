#include "../include/DTApartamento.h"
#include <iostream>
DTApartamento::DTApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
}

int DTApartamento::getPiso() {
    return piso;
}

bool DTApartamento::getTieneAscensor() {
    return tieneAscensor;
}

float DTApartamento::getGastosComunes() {
    return gastosComunes;
}


void DTApartamento::imprimirDetalle(){
    std::cout
        << "Codigo: " << this->getCodigo()
        << ", direccion: " << this->getDireccion()
        << ", nro. puerta: " << this->getNumeroPuerta()
        << ", superficie: " << this->getSuperficie() << " m2"
        << ", consturccion: " << this->getAnioConstruccion()
        << ", piso: " << this->getPiso()
        << ", ascensor: " << (this->getTieneAscensor() ? "Si" : "No")
        << ", gastos comunes: " << this->getGastosComunes()
        << std::endl;
}

DTApartamento::~DTApartamento(){

}
