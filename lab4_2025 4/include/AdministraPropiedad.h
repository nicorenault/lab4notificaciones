#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "DTInmuebleAdministrado.h"
#include "Publicacion.h"
#include <set>
class Inmueble;
class Inmobiliaria;

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmueble* inmueble;
        Inmobiliaria* inmobiliaria;
        std::set<Publicacion*> publicaciones;
    public:
        AdministraPropiedad(DTFecha* fecha);
        DTFecha* getFecha() const;
        Inmueble* getInmueble() const;
        Inmobiliaria* getInmobiliaria() const;
        void setInmueble(Inmueble* in);
        void setInmobiliaria(Inmobiliaria* i);
        DTInmuebleAdministrado getDTInmuebleAdministrado() const;
        void agregarPublicacion(Publicacion* p);
        Publicacion* getPublicacionActivaDelTipo(TipoPublicacion tipo) const;
        void borrarPublicaciones();
        ~AdministraPropiedad();
};

#endif
