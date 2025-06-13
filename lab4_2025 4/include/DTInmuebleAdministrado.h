#ifndef DTINMUEBLEADMINISTRADO_H
#define DTINMUEBLEADMINISTRADO_H
#include "DTFecha.h"
#include <string>

class DTInmuebleAdministrado {
    private:
        int codigo;
        std::string direccion;
        DTFecha* fechaComienzo;
        std::string nomProp;

    public:
        DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo, std::string nomProp);
        int getCodigo() const;
        std::string getDireccion() const;
        DTFecha* getFechaComienzo() const;
        bool operator<(const DTInmuebleAdministrado& otro) const;
        std::string getNomProp() const;
        ~DTInmuebleAdministrado();
};

#endif
