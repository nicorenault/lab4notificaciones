
#ifndef MANEJADORPROPIETARIOS_H
#define MANEJADORPROPIETARIOS_H

#include <map>
#include <set>
#include <string>

class Propietario;

class ManejadorPropietarios {
private:
    static ManejadorPropietarios* instancia;
    std::map<std::string, Propietario*> props;

    ManejadorPropietarios();
    ~ManejadorPropietarios();

public:
    static ManejadorPropietarios* getInstance();
    void agregar(Propietario* p);
    Propietario* find(const std::string& nickname);
    std::set<Propietario*> getAll();
    void clear();
};

#endif
