#include "ManejadorPropietarios.h"
#include "Propietario.h"

ManejadorPropietarios* ManejadorPropietarios::instancia = NULL;

ManejadorPropietarios::ManejadorPropietarios() {}

ManejadorPropietarios::~ManejadorPropietarios() {
    std::map<std::string, Propietario*>::iterator it;
    for (it = props.begin(); it != props.end(); ++it) {
        delete it->second;
    }
    props.clear();
}

ManejadorPropietarios* ManejadorPropietarios::getInstance() {
    if (instancia == NULL) {
        instancia = new ManejadorPropietarios();
    }
    return instancia;
}

void ManejadorPropietarios::agregar(Propietario* p) {
    props[p->getNickname()] = p;
}

Propietario* ManejadorPropietarios::find(const std::string& nickname) {
    return props[nickname];
}

std::set<Propietario*> ManejadorPropietarios::getAll() {
    std::set<Propietario*> salida;
    std::map<std::string, Propietario*>::iterator it;
    for (it = props.begin(); it != props.end(); ++it) {
        if (it->second != nullptr){
            salida.insert(it->second);
        }
    }
    return salida;
}

void ManejadorPropietarios::clear() {
    std::map<std::string, Propietario*>::iterator it;
    for (it = props.begin(); it != props.end(); ++it) {
        delete it->second;
    }
    props.clear();
}
