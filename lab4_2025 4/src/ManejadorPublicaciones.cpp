
#include "ManejadorPublicaciones.h"
#include "Publicacion.h"

ManejadorPublicaciones* ManejadorPublicaciones::instancia = 0;

ManejadorPublicaciones::ManejadorPublicaciones() {}

ManejadorPublicaciones::~ManejadorPublicaciones() {
    std::map<int, Publicacion*>::iterator it;
    for (it = pubs.begin(); it != pubs.end(); ++it) {
        delete it->second;
    }
    pubs.clear();
}

ManejadorPublicaciones* ManejadorPublicaciones::getInstance() {
    if (instancia == 0) {
        instancia = new ManejadorPublicaciones();
    }
    return instancia;
}

void ManejadorPublicaciones::agregar(Publicacion* p) {
    pubs[p->getCodigo()] = p;
}

Publicacion* ManejadorPublicaciones::find(int codigo) {
    return pubs[codigo];
}

std::set<Publicacion*> ManejadorPublicaciones::getAll() {
    std::set<Publicacion*> salida;
    std::map<int, Publicacion*>::iterator it;
    for (it = pubs.begin(); it != pubs.end(); ++it) {
        if (it->second != nullptr){
            salida.insert(it->second);
        }
    }
    return salida;
}
void ManejadorPublicaciones::clear() {
    std::map<int, Publicacion*>::iterator it;
    for (it = pubs.begin(); it != pubs.end(); ++it) {
        delete it->second;
    }
    pubs.clear();
}

void ManejadorPublicaciones::borrar(int codigo) {
    auto it = pubs.find(codigo);
    if (it != pubs.end()) {
        delete it->second;
        pubs.erase(it);
    }
}
