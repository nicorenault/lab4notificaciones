
#include "Propietario.h"
#include "Usuario.h"

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono): Usuario(nickname, contrasena, nombre, email){
    this->cuentaBancaria = cuentaBancaria;
    this->telefono = telefono;
}

std::string Propietario::getCuentaBanco() {
    return cuentaBancaria;
}

std::string Propietario::getNumTelefono() {
    return telefono;
}

void Propietario::agregarPropiedad(Inmueble* in) {
    propiedades.insert(in);
}
void Propietario::agregarInmobiliaria(Inmobiliaria* in) {
    inmmoRep.insert(in);
}
std::set<Inmueble*> Propietario::getPropiedades() const {
    return propiedades;
}

std::set<DTInmuebleListado> Propietario::getInmueblesNoAdmin(const Inmobiliaria* i) const {
    std::set<DTInmuebleListado> resultado;
    std::set<Inmueble*>::const_iterator itI;
    for (itI = propiedades.begin(); itI != propiedades.end(); ++itI) {
        Inmueble* in = *itI;
        if (! in->esAdministrado(i)) {
            DTInmuebleListado dto = DTInmuebleListado(in->getCodigo(),in->getDir(), this->getNickname());
            resultado.insert(dto);
        }
    }
    return resultado;
}

void Propietario::borrarPropiedad(Inmueble* inm) {
    propiedades.erase(inm);
}

void Propietario::notify(const DTNotificacion &dt) {
    notificaciones.insert(dt);
}

std::set<DTNotificacion> Propietario::getNotificaciones() const {
    return notificaciones;
}

void Propietario::clearNotificaciones() {
    notificaciones.clear();
}
