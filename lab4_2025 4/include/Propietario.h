#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "Inmueble.h"
#include "DTInmuebleListado.h"
#include "IObserverNotificaciones.h"
#include "DTNotificacion.h"
#include <string>
#include <set>
class Inmobiliaria;
class Propietario : public Usuario, public IObserverNotificaciones {
    private:
        std::set<DTNotificacion> notificaciones;
        std::string cuentaBancaria;
        std::string telefono;
        std::set<Inmueble*> propiedades;
        std::set<Inmobiliaria*> inmmoRep;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        std::string getCuentaBanco();
        std::string getNumTelefono();
        void agregarPropiedad(Inmueble* in);
        void agregarInmobiliaria(Inmobiliaria* in);
        std::set<Inmueble*> getPropiedades() const;
        std::set<DTInmuebleListado> getInmueblesNoAdmin(const Inmobiliaria* i) const;
        void borrarPropiedad(Inmueble* inm);
        void notify(const DTNotificacion &dt) override;
        std::set<DTNotificacion> getNotificaciones() const;
        void clearNotificaciones();
    
};

#endif
