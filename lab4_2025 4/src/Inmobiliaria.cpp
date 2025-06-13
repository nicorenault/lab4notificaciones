#include "Inmobiliaria.h"
#include "Usuario.h"
#include "AdministraPropiedad.h"
Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono)
: Usuario(nickname, contrasena, nombre, email){
    this->direccion = direccion;
    this->url = url;
    this->telefono = telefono;
}

std::string Inmobiliaria::getDireccion() {
    return direccion;
}

std::string Inmobiliaria::getUrl() {
    return url;
}

std::string Inmobiliaria::getTelefono() {
    return telefono;
}

std::set<DTInmuebleAdministrado> Inmobiliaria::listarInmueblesAdministrados() const {
    std::set<DTInmuebleAdministrado> resultado;
    std::set<AdministraPropiedad*>::const_iterator it=administraciones.begin();
    for(;it!=administraciones.end();++it){
        resultado.insert((*it)->getDTInmuebleAdministrado());
    }
    return resultado;
}
std::set<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario() const {
    std::set<DTInmuebleListado> resultado;
    std::set<Propietario*>::const_iterator itP;
    for (itP = representados.begin(); itP != representados.end(); ++itP) {
        std::set<DTInmuebleListado> sub = (*itP)->getInmueblesNoAdmin(this);
        std::set<DTInmuebleListado>::const_iterator itD;
        for (itD = sub.begin(); itD != sub.end(); ++itD) {
            resultado.insert(*itD);
        }
    }
    return resultado;
}

void Inmobiliaria::altaAdministraPropiedad(Inmueble* inm, DTFecha* fecha) {
    AdministraPropiedad* ap = new AdministraPropiedad(fecha);
    ap->setInmobiliaria(this);
    ap->setInmueble(inm);
    this->setAdministraPropiedad(ap);
    inm->setAdministraPropiedad(ap);
    
}

AdministraPropiedad* Inmobiliaria::getAdministracionCon(Inmueble* in) {
    for (AdministraPropiedad* ap : administraciones) {
        if (ap->getInmueble() == in) {
            return ap;
        }
    }
    return nullptr;
}


void Inmobiliaria::agregarRepresentado(Propietario* p) {
    representados.insert(p);
}

void Inmobiliaria::setAdministraPropiedad(AdministraPropiedad* ap){
    this->administraciones.insert(ap);
}

void Inmobiliaria::borrarAdministracion(AdministraPropiedad* ap) {
    administraciones.erase(ap);
}

void Inmobiliaria::suscribir(IObserverNotificaciones *o) {
    suscriptores.insert(o);
}

void Inmobiliaria::desuscribir(IObserverNotificaciones *o) {
    suscriptores.erase(o);
}

void Inmobiliaria::notifyAll(const DTNotificacion &dt) {
    for (auto it = suscriptores.begin(); it != suscriptores.end(); ++it)
        (*it)->notify(dt);
}

bool Inmobiliaria::estaSuscrito(IObserverNotificaciones* obs) const {
    return suscriptores.find(obs) != suscriptores.end();
}


Inmobiliaria::~Inmobiliaria() {}
