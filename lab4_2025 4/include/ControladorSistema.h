// include/ControladorSistema.h
#ifndef CONTROLDORSISTEMA_H
#define CONTROLDORSISTEMA_H
#include <string>
#include <set>
#include "IControladorSistema.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "DTInmuebleListado.h"
#include "DTInmueble.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "TipoTecho.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "Casa.h"
#include "ManejadorPublicaciones.h"
class ManejadorClientes;
class ManejadorPropietarios;
class ManejadorInmobiliarias;
class ManejadorInmuebles;


class ControladorSistema : public IControladorSistema {
private:
    static ControladorSistema* instancia;
    ManejadorClientes* manCli;
    ManejadorPropietarios* manProp;
    ManejadorInmobiliarias* manInmo;
    ManejadorInmuebles* manInmu;
    ManejadorPublicaciones* manPub;
    int ultimaPublicacion;
    ControladorSistema();
    Inmobiliaria* usuarioRecordado;
    Propietario* propietarioRecordado;
    ~ControladorSistema();
public:
    static ControladorSistema* getInstance();
    bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) override;
    bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) override;
    bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) override;
    std::set<DTUsuario> listarInmobiliarias() override;
    std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria) override;
    std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble) override;
    void eliminarInmueble(int codigoInmueble) override;
    bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, std::string texto, float precio) override;
    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nickname) override;
    void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) override;
    std::set<DTUsuario> listarPropietarios() override;
    void representarPropietario(std::string nicknamePropietario) override;
    void finalizarAltaUsuario() override;
    void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) override;
    void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) override;
    std::set<DTInmuebleListado> listarInmuebles() override;
    DTInmueble* detalleInmueble(int codigoInmueble) override;
    DTInmueble* detalleInmueblePublicacion(int codigoPublicacion) override;
    
    void suscribirUsuario(const std::string nickUsuario,std::string inmobiliaria) override;
    
    std::set<DTNotificacion> consultarNotificaciones(std::string nickUsuario) override;
    
    void eliminarSuscripciones(std::string nickUsuario, std::string inmobiliaria) override;
    
    std::set<DTUsuario>listarInmobiliariasSuscritas(const std::string nickUsuario) override;
    
    std::set<DTUsuario>listarInmobiliariasNoSuscritas(const std::string nickUsuario) override;
};
#endif
