#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include <string>
#include "DTInmuebleAdministrado.h"
#include <set>
#include "Propietario.h"
#include "AdministraPropiedad.h"
#include "IObserverNotificaciones.h"

class Inmobiliaria : public Usuario {
    private:
        std::set<IObserverNotificaciones*> suscriptores;
        std::string direccion;
        std::string url;
        std::string telefono;
        std::set<Propietario*> representados;
        std::set<AdministraPropiedad*> administraciones;



    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        std::string getDireccion();
        std::string getUrl();
        std::string getTelefono();
        std::set<DTInmuebleAdministrado> listarInmueblesAdministrados() const;
        std::set<DTInmuebleListado> getInmueblesNoAdminPropietario() const;
        void altaAdministraPropiedad(Inmueble* inm,DTFecha* fecha);
        AdministraPropiedad* getAdministracionCon(Inmueble* in);
        void agregarRepresentado(Propietario* p);
        void setAdministraPropiedad(AdministraPropiedad* ap);
        void borrarAdministracion(AdministraPropiedad* ap);
        void suscribir(IObserverNotificaciones *o);
        void desuscribir(IObserverNotificaciones *o);
        void notifyAll(const DTNotificacion &dt);
        bool estaSuscrito(IObserverNotificaciones* obs) const;
        ~Inmobiliaria();
};

#endif
