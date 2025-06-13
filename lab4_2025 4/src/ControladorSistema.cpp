#include "ControladorSistema.h"
#include "ManejadorClientes.h"
#include "ManejadorPropietarios.h"
#include "ManejadorInmobiliarias.h"
#include "ManejadorInmuebles.h"
#include "Cliente.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include "DTUsuario.h"
#include "Factory.h"
#include "Publicacion.h"
#include "Casa.h"
#include "Apartamento.h"
#include <iostream>
ControladorSistema* ControladorSistema::instancia = nullptr;

ControladorSistema::ControladorSistema() {}

ControladorSistema::~ControladorSistema() {}

ControladorSistema* ControladorSistema::getInstance() {
    if (instancia == nullptr) instancia = new ControladorSistema();
    return instancia;
}

bool ControladorSistema::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) {

    if(contrasena.length()<6) return false;
    ManejadorClientes* manCli=ManejadorClientes::getInstance();
    ManejadorPropietarios* manProp=ManejadorPropietarios::getInstance();
    ManejadorInmobiliarias* manInmo=ManejadorInmobiliarias::getInstance();
    if(manCli->find(nickname)!= nullptr ||manProp->find(nickname) != nullptr ||manInmo->find(nickname) != nullptr) return false;
    Cliente* c= new Cliente(nickname,contrasena,nombre,email,apellido,documento);
    manCli->agregar(c);
    return true;
}

bool ControladorSistema::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) {
    if(contrasena.size()<6) return false;
    ManejadorClientes* manCli=ManejadorClientes::getInstance();
    ManejadorPropietarios* manProp=ManejadorPropietarios::getInstance();
    ManejadorInmobiliarias* manInmo=ManejadorInmobiliarias::getInstance();
    if(manCli->find(nickname)!= nullptr ||manProp->find(nickname) != nullptr ||manInmo->find(nickname) != nullptr) return false;
    Propietario* p = new Propietario(nickname,contrasena,nombre,email,cuentaBancaria,telefono);
    manProp->agregar(p);
    propietarioRecordado = p;
    return true;
}

bool ControladorSistema::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) {
    if (contrasena.size() < 6) return false;
    ManejadorClientes* manCli      = ManejadorClientes::getInstance();
    ManejadorPropietarios* manProp = ManejadorPropietarios::getInstance();
    ManejadorInmobiliarias* manInmo= ManejadorInmobiliarias::getInstance();
    if (manCli->find(nickname) != nullptr || manProp->find(nickname) != nullptr || manInmo->find(nickname) != nullptr) return false;
    Inmobiliaria* inmo = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    manInmo->agregar(inmo);
    usuarioRecordado = inmo;
    return true;
}

std::set<DTUsuario> ControladorSistema::listarPropietarios() {
    ManejadorPropietarios* manProp = ManejadorPropietarios::getInstance();
    std::set<DTUsuario> resultado;
    std::set<Propietario*> propMap = manProp->getAll();
    std::set<Propietario*>::const_iterator it;
    for(it = propMap.begin(); it != propMap.end(); ++it){
        Propietario* p = *it;
        DTUsuario dt = p->toDTU();
        resultado.insert(dt);
    }
    return resultado;
    
}

std::set<DTUsuario> ControladorSistema::listarInmobiliarias() {
    ManejadorInmobiliarias* manInmo = ManejadorInmobiliarias::getInstance();
    std::set<Inmobiliaria*> todos = manInmo->getAll();
    std::set<DTUsuario> resultado;
    std::set<Inmobiliaria*>::const_iterator it;
    for (it = todos.begin(); it != todos.end(); ++it) {
        resultado.insert((*it)->toDTU());
    }
    return resultado;
}

std::set<DTInmuebleAdministrado> ControladorSistema::listarInmueblesAdministrados(std::string nicknameInmobiliaria) {
    std::set<DTInmuebleAdministrado> resultado;
    ManejadorInmobiliarias* manInmo = ManejadorInmobiliarias::getInstance();
    Inmobiliaria* inmo = manInmo->find(nicknameInmobiliaria);
    std::set<DTInmuebleAdministrado> administraciones = inmo->listarInmueblesAdministrados();
    return administraciones;
}

bool ControladorSistema::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, std::string texto, float precio) {
    ManejadorInmobiliarias* manInmo = ManejadorInmobiliarias::getInstance();
    Inmobiliaria* inmo = manInmo->find(nicknameInmobiliaria);
    ManejadorInmuebles* manInm = ManejadorInmuebles::getInstance();
    Inmueble* inm = manInm->find(codigoInmueble);
    AdministraPropiedad* ap = inmo->getAdministracionCon(inm);

    
        IControladorFechaActual* cf = Factory::getInstance()->getControladorFechaActual();
        DTFecha* ahora = cf->getFechaActual();
        DTFecha* copiaFecha = new DTFecha(ahora);

        int codigo = ++ultimaPublicacion;
        Publicacion* nueva = new Publicacion(codigo,copiaFecha,tipo,texto,precio,true);
        nueva->setAp(ap);
        ap->agregarPublicacion(nueva);
        ManejadorPublicaciones* manPub = ManejadorPublicaciones::getInstance();
        manPub->agregar(nueva);
        Publicacion* vieja = ap->getPublicacionActivaDelTipo(tipo);
        if(vieja!=nullptr){
            vieja->setActiva(false);
            nueva->setActiva(true);
        }
    
    TipoInmueble tipoIn = Apartamento;
    
    if (inm->esCasa()){
        tipoIn = Casa;
    }
    DTNotificacion dt = DTNotificacion(
      inmo->getNickname(),
      nueva->getCodigo(),
      nueva->getTexto(),
      nueva->getTipo(),
      tipoIn,
      copiaFecha
    );
    inmo->notifyAll(dt);

        return true;
}


void ControladorSistema::representarPropietario(std::string nicknamePropietario) {
    ManejadorPropietarios* manProp = ManejadorPropietarios::getInstance();
    Propietario* p = manProp->find(nicknamePropietario);
    ManejadorInmobiliarias* manInmo = ManejadorInmobiliarias::getInstance();
    Inmobiliaria* inmo = manInmo->find(usuarioRecordado->getNickname());
    p->agregarInmobiliaria(inmo);
    usuarioRecordado->agregarRepresentado(p);
}

void ControladorSistema::altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) {
    ManejadorInmuebles* manInm = ManejadorInmuebles::getInstance();
    class Casa* c = new class Casa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    c->setPropietario(propietarioRecordado);
    propietarioRecordado->agregarPropiedad(c);
    manInm->agregar(c);

}

void ControladorSistema::altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) {
    ManejadorInmuebles* manInm = ManejadorInmuebles::getInstance();
    class Apartamento* a = new class Apartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    a->setPropietario(propietarioRecordado);
    propietarioRecordado->agregarPropiedad(a);
    manInm->agregar(a); 
}

std::set<DTInmuebleListado> ControladorSistema::listarInmueblesNoAdministradosInmobiliaria(std::string nickname) {
    ManejadorInmobiliarias* manInmo = ManejadorInmobiliarias::getInstance();
    Inmobiliaria* i = manInmo->find(nickname);
    std::set<DTInmuebleListado> resultado = i->getInmueblesNoAdminPropietario();
    return resultado;
    
}

void ControladorSistema::altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) {
    ManejadorInmobiliarias* manInmo = ManejadorInmobiliarias::getInstance();
    Inmobiliaria* inmo = manInmo->find(nicknameInmobiliaria);
    ManejadorInmuebles* manInmu = ManejadorInmuebles::getInstance();
    Inmueble* inm  = manInmu->find(codigoInmueble);
    IControladorFechaActual* cf = Factory::getInstance()->getControladorFechaActual();
    DTFecha* ahora = cf->getFechaActual();
    DTFecha* copiaFecha = new DTFecha(ahora);
    inmo->altaAdministraPropiedad(inm, copiaFecha);
}

std::set<DTPublicacion> ControladorSistema::listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble) {
    
     return Publicacion::listar(tipo, precioMin, precioMax, tipoInmueble);
}


std::set<DTInmuebleListado> ControladorSistema::listarInmuebles() {
    std::set<DTInmuebleListado> resultado;
    ManejadorInmuebles* manInm = ManejadorInmuebles::getInstance();
    std::set<Inmueble*> inmuebles = manInm->getAll();
    std::set<Inmueble*>::iterator it;
    for(it = inmuebles.begin(); it != inmuebles.end(); ++it){
        resultado.insert((*it)->toDTI());
    }
    return resultado;
}

DTInmueble* ControladorSistema::detalleInmueble(int codigoInmueble) {
    ManejadorInmuebles* manInmu = ManejadorInmuebles::getInstance();
    Inmueble* inmu = manInmu->find(codigoInmueble);
    
    return inmu->toDT();
}


void ControladorSistema::eliminarInmueble(int codigoInmueble){
    ManejadorInmuebles* manInm = ManejadorInmuebles::getInstance();
    Inmueble* in = manInm->find(codigoInmueble);
    if (!in) return;

    Propietario* prop = in->getPropietario();
    prop->borrarPropiedad(in);

    std::set<AdministraPropiedad*> adm = in->getAdministraPropiedad();
    for (std::set<AdministraPropiedad*>::iterator it = adm.begin(); it != adm.end(); ++it) {
        AdministraPropiedad* ap = *it;
        ap->getInmobiliaria()->borrarAdministracion(ap);
        ap->borrarPublicaciones();
        delete ap;
    }

    in->borrarAdministraciones();

    delete in;
    manInm->borrar(codigoInmueble);
}


void ControladorSistema::finalizarAltaUsuario(){
    usuarioRecordado = NULL;
    propietarioRecordado = NULL;

}


DTInmueble* ControladorSistema::detalleInmueblePublicacion(int codigoPublicacion) {
    ManejadorPublicaciones* manPub = ManejadorPublicaciones::getInstance();
    Publicacion* pub = manPub->find(codigoPublicacion);
    Inmueble* inmu = pub->getAP()->getInmueble();
    return inmu->toDT();
}




void ControladorSistema::suscribirUsuario(std::string nickUsuario, std::string inmobiliarias){
    ManejadorClientes*       manC = ManejadorClientes::getInstance();
    ManejadorPropietarios*   manP = ManejadorPropietarios::getInstance();
    ManejadorInmobiliarias*  manI = ManejadorInmobiliarias::getInstance();
    Cliente* cli = manC->find(nickUsuario);
    IObserverNotificaciones* obs = cli;
    if (cli == nullptr) {
        Propietario* prop = manP->find(nickUsuario);
        obs = prop;
    }
    if (!obs) return;
    
    Inmobiliaria* inmo = manI->find(inmobiliarias);

        if (inmo) {
            inmo->suscribir(obs);
        }
    
}

std::set<DTNotificacion>ControladorSistema::consultarNotificaciones(std::string nickUsuario) {
    ManejadorClientes*     manC = ManejadorClientes::getInstance();
    ManejadorPropietarios* manP = ManejadorPropietarios::getInstance();

    std::set<DTNotificacion> res;
    Cliente*     cli  = manC->find(nickUsuario);
    
    if (cli == nullptr) {
        Propietario* prop = manP->find(nickUsuario);
        res = prop->getNotificaciones();
        prop->clearNotificaciones();
    }else{
        res = cli->getNotificaciones();
        cli->clearNotificaciones();
    }

    return res;
}


std::set<DTUsuario>ControladorSistema::listarInmobiliariasNoSuscritas(std::string nickUsuario) {
    ManejadorClientes*     manC = ManejadorClientes::getInstance();
    ManejadorPropietarios* manP = ManejadorPropietarios::getInstance();
    Cliente*     cli  = manC->find(nickUsuario);
    IObserverNotificaciones* obs = cli;
    
    if (cli == nullptr) {
        Propietario* prop = manP->find(nickUsuario);
        obs =prop;
    }
    std::set<DTUsuario> res;
    if (!obs) return res;
    ManejadorInmobiliarias* manI = ManejadorInmobiliarias::getInstance();
    std::set<Inmobiliaria*> todas = manI->getAll();
    
    std::set<Inmobiliaria*>::const_iterator it;
    for (it = todas.begin();it != todas.end(); ++it){
        Inmobiliaria* inmo = *it;
        if (!inmo->estaSuscrito(obs)) {
            res.insert(inmo->toDTU());
        }
    }

    return res;
}




void ControladorSistema::eliminarSuscripciones(std::string nickUsuario, std::string inmo){
    ManejadorClientes*     manC = ManejadorClientes::getInstance();
    ManejadorPropietarios* manP = ManejadorPropietarios::getInstance();
    ManejadorInmobiliarias* manI = ManejadorInmobiliarias::getInstance();
    Inmobiliaria* inmob = manI->find(inmo);
    
    Cliente*     cli  = manC->find(nickUsuario);
    IObserverNotificaciones* obs = cli;
    
    if (cli == nullptr) {
        Propietario* prop = manP->find(nickUsuario);
        obs =prop;
    }

    inmob->desuscribir(obs);
        
    
}


std::set<DTUsuario>ControladorSistema::listarInmobiliariasSuscritas(std::string nickUsuario) {
    ManejadorClientes*     manC = ManejadorClientes::getInstance();
    ManejadorPropietarios* manP = ManejadorPropietarios::getInstance();
    
    Cliente*     cli  = manC->find(nickUsuario);
    IObserverNotificaciones* obs = cli;
    if (cli == nullptr) {
        Propietario* prop = manP->find(nickUsuario);
        obs =prop;
    }

    std::set<DTUsuario> res;
    if (!obs) return res;

    ManejadorInmobiliarias* manI = ManejadorInmobiliarias::getInstance();
    std::set<Inmobiliaria*> todas = manI->getAll();
    std::set<Inmobiliaria*>::const_iterator it;
    for ( it = todas.begin(); it != todas.end(); ++it){
        Inmobiliaria* inmo = *it;
        if (inmo->estaSuscrito(obs)) {
            res.insert(inmo->toDTU());
        }
    }

    return res;
}

