#include "Publicacion.h"
#include "AdministraPropiedad.h"
#include "Inmueble.h"
#include "Inmobiliaria.h"
#include "ManejadorPublicaciones.h"
Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->tipo = tipo;
    this->texto = texto;
    this->precio = precio;
    this->activa = activa;
}

int Publicacion::getCodigo() {
    return codigo;
}

DTFecha* Publicacion::getFecha() {
    return fecha;
}

TipoPublicacion Publicacion::getTipo() {
    return tipo;
}

std::string Publicacion::getTexto() {
    return texto;
}

float Publicacion::getPrecio() {
    return precio;
}
void Publicacion::setActiva(bool activa){
    this->activa = activa;
}
bool Publicacion::estaActiva() {
    return activa;
}

void Publicacion::setAp(AdministraPropiedad* ap){
    this->ap = ap;
}

bool Publicacion::cumpleFiltro(TipoPublicacion tpub, float precioMin, float precioMax, TipoInmueble tipoInm) const {
    if (tipo != tpub) return false;
    if (precio < precioMin || precio > precioMax) return false;

    if (tipoInm != Todos) {
        Inmueble* in = ap->getInmueble();
        if (tipoInm == Casa && ! in->esCasa())   return false;
        if (tipoInm == Apartamento && in->esCasa()) return false;
    }
    return true;
}

DTPublicacion Publicacion::toDT() const {
    std::string nomInmo = ap->getInmobiliaria()->getNombre();
    return DTPublicacion(codigo, fecha, texto, std::to_string(precio), nomInmo);
}

AdministraPropiedad* Publicacion::getAP(){
    return ap;
}

std::set<DTPublicacion> Publicacion::listar(TipoPublicacion tipoReq, float precioMin, float precioMax, TipoInmueble tipoInm) {
    std::set<DTPublicacion> resultado;
    ManejadorPublicaciones* manPub = ManejadorPublicaciones::getInstance();
    std::set<Publicacion*> todas = manPub->getAll();
    if(todas.empty()) return resultado;
    std::set<Publicacion*>::const_iterator it = todas.begin();
    for(; it != todas.end(); ++it) {
        Publicacion* p = *it;
        if(p->cumpleFiltro(tipoReq, precioMin, precioMax, tipoInm)) {
            resultado.insert(p->toDT());
        }
    }
    return resultado;
}
Publicacion::~Publicacion() {
    //delete fecha;
}
