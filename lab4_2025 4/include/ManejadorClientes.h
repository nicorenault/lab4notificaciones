#ifndef MANEJADORCLIENTES_H
#define MANEJADORCLIENTES_H

#include <map>
#include <set>
#include <string>

class Cliente;

class ManejadorClientes {
private:
    static ManejadorClientes* instancia;
    std::map<std::string, Cliente*> clientes;

    ManejadorClientes();
    ~ManejadorClientes();

public:
    static ManejadorClientes* getInstance();
    void agregar(Cliente* c);
    Cliente* find(const std::string& nickname);
    std::set<Cliente*> getAll();
    void clear();
};

#endif
