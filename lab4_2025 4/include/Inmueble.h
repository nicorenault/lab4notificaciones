#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "AdministraPropiedad.h"
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
class Propietario;

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        Propietario* propietario;
        std::set<AdministraPropiedad*> adminPropiedad;
        static int codigoInmueble;
        

    public:
        Inmueble(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        void setPropietario(Propietario*);
        Propietario* getPropietario()const;
        int getCodigo() const;
        int getNumPuerta()const;
        int getSuperficie()const;
        int getAnoCons()const;
        std::string getDir()const;
        void setAdministraPropiedad(AdministraPropiedad* ap);
        std::set<AdministraPropiedad*> getAdministraPropiedad() const;
        bool esAdministrado(const Inmobiliaria* i) const;
        virtual bool esCasa() const = 0;
        virtual DTInmueble* toDT() const = 0;
        DTInmuebleListado toDTI() const;
        void borrarAdministraciones();
        virtual ~Inmueble();
}; 

#endif
 
