
#include "ManejadorInmuebles.h"
#include "Inmueble.h"

ManejadorInmuebles* ManejadorInmuebles::instancia = 0;

ManejadorInmuebles::ManejadorInmuebles() {}

ManejadorInmuebles::~ManejadorInmuebles() {
    std::map<int, Inmueble*>::iterator it;
    for (it = inmus.begin(); it != inmus.end(); ++it) {
        delete it->second;
    }
    inmus.clear();
}

ManejadorInmuebles* ManejadorInmuebles::getInstance() {
    if (instancia == 0) {
        instancia = new ManejadorInmuebles();
    }
    return instancia;
}

void ManejadorInmuebles::agregar(Inmueble* in) {
    inmus[in->getCodigo()] = in;
}

Inmueble* ManejadorInmuebles::find(int codigo) {
    return inmus[codigo];
}

std::set<Inmueble*> ManejadorInmuebles::getAll()  {
    std::set<Inmueble*> salida;
    std::map<int, Inmueble*>::iterator it;
    for (it = inmus.begin(); it != inmus.end(); it++) {
        if (it->second != nullptr){
            salida.insert(it->second);
        }
    }
    return salida;
}

void ManejadorInmuebles::clear() {
    std::map<int, Inmueble*>::iterator it;
    for (it = inmus.begin(); it != inmus.end(); ++it) {
        delete it->second;
    }
    inmus.clear();
}

void ManejadorInmuebles::borrar(int codigo) {
    inmus.erase(codigo);
}
