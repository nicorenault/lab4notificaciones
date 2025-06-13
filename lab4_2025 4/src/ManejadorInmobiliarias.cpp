// src/ManejadorInmobiliarias.cpp
#include "ManejadorInmobiliarias.h"
#include "Inmobiliaria.h"

ManejadorInmobiliarias* ManejadorInmobiliarias::instancia = 0;

ManejadorInmobiliarias::ManejadorInmobiliarias() {}

ManejadorInmobiliarias::~ManejadorInmobiliarias() {
    std::map<std::string, Inmobiliaria*>::iterator it;
    for (it = muebles.begin(); it != muebles.end(); ++it) {
        delete it->second;
    }
    muebles.clear();
}

ManejadorInmobiliarias* ManejadorInmobiliarias::getInstance() {
    if (instancia == 0) {
        instancia = new ManejadorInmobiliarias();
    }
    return instancia;
}

void ManejadorInmobiliarias::agregar(Inmobiliaria* i) {
    this->muebles[i->getNickname()] = i;
}

Inmobiliaria* ManejadorInmobiliarias::find(const std::string& nickname) {
    return muebles[nickname];
}

std::set<Inmobiliaria*> ManejadorInmobiliarias::getAll() {
    std::set<Inmobiliaria*> salida;
    std::map<std::string, Inmobiliaria*>::iterator it;
    for (it = muebles.begin(); it != muebles.end(); ++it) {
        if (it->second != nullptr){
            salida.insert(it->second);
        }
    }
    return salida;
}

void ManejadorInmobiliarias::clear() {
    std::map<std::string, Inmobiliaria*>::iterator it;
    for (it = muebles.begin(); it != muebles.end(); ++it) {
        delete it->second;
    }
    muebles.clear();
}
