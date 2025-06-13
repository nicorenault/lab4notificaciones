#include "AdministraPropiedad.h"
#include "Inmueble.h"
#include "Inmobiliaria.h"
#include "ManejadorPublicaciones.h"
#include "Publicacion.h"
AdministraPropiedad::AdministraPropiedad(DTFecha* fecha){
    this->fecha = fecha;
    this->inmobiliaria = nullptr;
    this->inmueble = nullptr;
}
DTFecha* AdministraPropiedad::getFecha() const{
    return fecha;
}
Inmueble* AdministraPropiedad::getInmueble() const{
    return inmueble;
}
Inmobiliaria* AdministraPropiedad::getInmobiliaria() const{
    return inmobiliaria;
}
void AdministraPropiedad::setInmueble(Inmueble* in){
    this->inmueble=in;
}
void AdministraPropiedad::setInmobiliaria(Inmobiliaria* i){
    this->inmobiliaria=i;
}
DTInmuebleAdministrado AdministraPropiedad::getDTInmuebleAdministrado() const {
    std::string nom = this->inmueble->getPropietario()->getNickname();
    return DTInmuebleAdministrado(inmueble->getCodigo(),inmueble->getDir(), fecha, nom);
}

void AdministraPropiedad::agregarPublicacion(Publicacion* p) {
    publicaciones.insert(p);
}

Publicacion* AdministraPropiedad::getPublicacionActivaDelTipo(TipoPublicacion tipo) const {
    for (Publicacion* p : publicaciones) {
        if (p->getTipo() == tipo && p->estaActiva())
            return p;
    }
    return nullptr;
}

void AdministraPropiedad::borrarPublicaciones() {
    ManejadorPublicaciones* manPub = ManejadorPublicaciones::getInstance();
    for (std::set<Publicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        Publicacion* p = *it;
        manPub->borrar(p->getCodigo());
    }
    publicaciones.clear();
}

AdministraPropiedad::~AdministraPropiedad(){ delete fecha; }
