#ifndef MANEJADORINMUEBLES_H
#define MANEJADORINMUEBLES_H

#include <map>
#include <set>
class Inmueble;

class ManejadorInmuebles {
private:
    static ManejadorInmuebles* instancia;
    std::map<int, Inmueble*> inmus;

    ManejadorInmuebles();
    ~ManejadorInmuebles();

public:
    static ManejadorInmuebles* getInstance();
    void agregar(Inmueble* in);
    Inmueble* find(int codigo);
    std::set<Inmueble*> getAll();
    void borrar(int codigo);
    void clear();
};

#endif
