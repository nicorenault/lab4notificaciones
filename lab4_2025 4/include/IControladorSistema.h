#ifndef ICONTROLDORSISTEMA_H
#define ICONTROLDORSISTEMA_H

#include <string>
#include <set>

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "DTInmuebleListado.h"
#include "DTInmueble.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "TipoTecho.h"
#include "DTNotificacion.h"
#include "Inmobiliaria.h"

class IControladorSistema {
public:
    virtual ~IControladorSistema() {}
    
    virtual bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) = 0;
    
    virtual bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) = 0;
    
    virtual bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) = 0;
    
    virtual std::set<DTUsuario> listarInmobiliarias() = 0;
    
    virtual std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria) = 0;
    
    virtual std::set<DTPublicacion>listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble) = 0;
    
    virtual void eliminarInmueble(int codigoInmueble) = 0;
    
    virtual bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, std::string texto, float precio) = 0;
    
    virtual std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nickname) = 0;
    
    virtual void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) = 0;
    
    virtual std::set<DTUsuario> listarPropietarios() = 0;
    
    virtual void representarPropietario(std::string nicknamePropietario) = 0;
    
    virtual void finalizarAltaUsuario() = 0;
    
    virtual void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) = 0;
    
    virtual void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) = 0;
    
    virtual std::set<DTInmuebleListado> listarInmuebles() = 0;
    
    virtual DTInmueble* detalleInmueble(int codigoInmueble) = 0;
    
    virtual DTInmueble* detalleInmueblePublicacion(int codigoPublicacion) = 0;
    
    virtual void suscribirUsuario(std::string nickUsuario, std::string inmobiliarias) = 0;
    
    virtual std::set<DTNotificacion>consultarNotificaciones(std::string nickUsuario) = 0;
    
    virtual std::set<DTUsuario>listarInmobiliariasNoSuscritas(std::string nickUsuario) = 0;
    
    virtual void eliminarSuscripciones(std::string nickUsuario, std::string inmobiliaria) = 0;
    
    virtual std::set<DTUsuario>listarInmobiliariasSuscritas(const std::string nickUsuario) = 0;
};

#endif
