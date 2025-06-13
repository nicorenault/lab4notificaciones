#include "../include/DTInmuebleAdministrado.h"

DTInmuebleAdministrado::DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo, std::string NomProp) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->fechaComienzo = new DTFecha(fechaComienzo);
    this->nomProp = NomProp;
    
}

int DTInmuebleAdministrado::getCodigo() const{
    return codigo;
}

std::string DTInmuebleAdministrado::getDireccion() const{
    return direccion;
}

std::string DTInmuebleAdministrado::getNomProp() const{
    return nomProp;
}
DTFecha* DTInmuebleAdministrado::getFechaComienzo() const{
    return fechaComienzo;
}

DTInmuebleAdministrado::~DTInmuebleAdministrado() {
    //delete fechaComienzo;
}

bool DTInmuebleAdministrado::operator<(const DTInmuebleAdministrado& otro) const {
    return this->codigo < otro.codigo;
}
