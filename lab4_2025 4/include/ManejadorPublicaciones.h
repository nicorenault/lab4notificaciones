#ifndef MANEJADORPUBLICACIONES_H
#define MANEJADORPUBLICACIONES_H
#include <map>
#include<set>
class Publicacion;

class ManejadorPublicaciones {
private:
    static ManejadorPublicaciones* instancia;
    std::map<int, Publicacion*> pubs;

    ManejadorPublicaciones();
    ~ManejadorPublicaciones();

public:
    static ManejadorPublicaciones* getInstance();
    std::set<Publicacion*> getAll();
    void agregar(Publicacion* p);
    Publicacion* find(int codigo);
    void borrar(int codigo);
    void clear();
};

#endif
