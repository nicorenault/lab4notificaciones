#include "ManejadorClientes.h"
#include "Cliente.h"

ManejadorClientes* ManejadorClientes::instancia = 0;

ManejadorClientes::ManejadorClientes() {}

ManejadorClientes::~ManejadorClientes() {
    std::map<std::string, Cliente*>::iterator it;
    for (it = clientes.begin(); it != clientes.end(); ++it) {
        delete it->second;
    }
    clientes.clear();
}

ManejadorClientes* ManejadorClientes::getInstance() {
    if (instancia == 0) {
        instancia = new ManejadorClientes();
    }
    return instancia;
}

void ManejadorClientes::agregar(Cliente* c) {
    clientes[c->getNickname()] = c;
}

Cliente* ManejadorClientes::find(const std::string& nickname) {
    return clientes[nickname];
}

std::set<Cliente*> ManejadorClientes::getAll() {
    std::set<Cliente*> salida;
    std::map<std::string, Cliente*>::iterator it;
    for (it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->second != nullptr){
            salida.insert(it->second);
        }
    }
    return salida;
}

void ManejadorClientes::clear() {
    std::map<std::string, Cliente*>::iterator it;
    for (it = clientes.begin(); it != clientes.end(); ++it) {
        delete it->second;
    }
    clientes.clear();
}
