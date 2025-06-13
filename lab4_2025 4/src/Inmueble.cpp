#include "Inmueble.h"
#include "Propietario.h"
int Inmueble::codigoInmueble = 1;

Inmueble::Inmueble(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion) {
    codigo = codigoInmueble++;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anoConstruccion = anoConstruccion;
}


DTInmuebleListado Inmueble::toDTI() const {
    return DTInmuebleListado(getCodigo(), getDir(), getPropietario()->getNickname());
}

int Inmueble::getCodigo() const{
    return codigo;
}

int Inmueble::getNumPuerta() const{
    return numeroPuerta;
}

int Inmueble::getSuperficie() const{
    return superficie;
}

int Inmueble::getAnoCons() const{
    return anoConstruccion;
}

std::string Inmueble::getDir() const{
    return direccion;
}
void Inmueble::setPropietario(Propietario* p) {
    propietario = p;
}

Propietario* Inmueble::getPropietario() const{
    return propietario;
}

void Inmueble::setAdministraPropiedad(AdministraPropiedad* ap) {
    adminPropiedad.insert(ap);
}

std::set<AdministraPropiedad*> Inmueble::getAdministraPropiedad() const {
    return adminPropiedad;
}

bool Inmueble::esAdministrado(const Inmobiliaria* i) const {
    std::set<AdministraPropiedad*>::const_iterator it;
    for (it = adminPropiedad.begin(); it != adminPropiedad.end(); ++it) {
        if ((*it)->getInmobiliaria() == i) {
            return true;
        }
    }
    return false;
}

void Inmueble::borrarAdministraciones() {
    adminPropiedad.clear();
}

Inmueble::~Inmueble() {}
