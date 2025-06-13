#include "../include/DTInmuebleListado.h"

DTInmuebleListado::DTInmuebleListado(int codigo, std::string direccion, std::string propietario) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->propietario = propietario;
}

int DTInmuebleListado::getCodigo() const{
    return codigo;
}

std::string DTInmuebleListado::getDireccion() const{
    return direccion;
}

std::string DTInmuebleListado::getPropietario() const{
    return propietario;
}

bool DTInmuebleListado::operator<(const DTInmuebleListado& otro) const {
    return this->codigo < otro.codigo;
}

