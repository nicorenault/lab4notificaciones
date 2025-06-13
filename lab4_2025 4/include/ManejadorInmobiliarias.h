
#ifndef MANEJADORINMOBILIARIAS_H
#define MANEJADORINMOBILIARIAS_H

#include <map>
#include <set>
#include <string>

class Inmobiliaria;

class ManejadorInmobiliarias {
private:
    static ManejadorInmobiliarias* instancia;
    std::map<std::string, Inmobiliaria*> muebles;

    ManejadorInmobiliarias();
    ~ManejadorInmobiliarias();

public:
    static ManejadorInmobiliarias* getInstance();
    void agregar(Inmobiliaria* i);
    Inmobiliaria* find(const std::string& nickname);
    std::set<Inmobiliaria*> getAll();
    void clear();
};

#endif 
