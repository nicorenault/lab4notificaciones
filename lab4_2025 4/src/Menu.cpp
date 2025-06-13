#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include <string>
#include <set>

void mostrarMenu() {
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Elimiinar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << " - ALTA DE USUARIO - " << std::endl;
            altaUsuario();
            break;
        case 2:
            std::cout << " - ALTA DE PUBLICACION - " << std::endl;
            altaPublicacion();
            break;
        case 3:
            std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
            consultaPublicaciones();
            break;
        case 4:
            std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
            eliminarInmueble();
            break;
        case 5:
            std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
            suscribirseNotificaciones();
            break;
        case 6:
            std::cout << " - CONSLTAR NOTIFICACIONES - " << std::endl;
            consultaNotificaciones();
            break;
        case 7:
            std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
            eliminarSuscripciones();
            break;
        case 8:
            std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
            altaAdministracionPropiedad();
            break;
        case 9:
            std::cout << " - CARGAR DATOS - " << std::endl;
            cargarDatos();
            break;
        case 10:
            std::cout << " - VER FECHA ACTUAL - " << std::endl;
            verFechaActual();
            break;
        case 11:
            std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
            asignarFechaActual();
            break;
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            exit(0);
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void altaUsuario(){

    Factory* factory = Factory::getInstance();
    IControladorSistema* ci = factory->getControladorSistema();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;
    
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;
    
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    if (tipoUsuario == 0){
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        usuarioOk = ci->altaCliente(nickname, contrasena, nombre, email, apellido, documento);
        

    }else if (tipoUsuario == 1){
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);

    }else if (tipoUsuario == 2){
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = ci->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);

    }
    if (usuarioOk){
        if (tipoUsuario == 1 || tipoUsuario == 2){
            int salir = 1;
            std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
            std::string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0){
                if (tipoUsuario == 1){
                    std::cout << "Lista de Propietarios:\n";
                    std::set<DTUsuario> propietarios = ci->listarPropietarios();
                     std::set<DTUsuario>::iterator it;
                     for (it = propietarios.begin(); it != propietarios.end(); ++it) {
                         std::cout << "- Nickname: " << it->getNickname() << ", Nombre: " << it->getNombre() << std::endl;
                     }
                    
                    std::cout << "Nickname propietario a representar: ";
                    std::string nicknamePropietario;
                    std::getline(std::cin, nicknamePropietario);
                    ci->representarPropietario(nicknamePropietario);
                }else if (tipoUsuario == 2){
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();
    
                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore(); 
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1){
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if(inTipoTecho == 1){
                            techo = A_dos_aguas;
                        }else if (inTipoTecho == 2){
                            techo = Plano;
                        }
                        ci->altaCasa(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                    }else{
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        ci->altaApartamento(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
                    }
                }
                std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
            }

        }
        ci->finalizarAltaUsuario();
    }else{
        std::cout << "Error al crear el usuario" << std::endl;
    }
}

void altaPublicacion(){
    
    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();

    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario> inmobiliarias = controlador->listarInmobiliarias();
    std::set<DTUsuario>::iterator it;
    for (it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        std::cout << "- Nickname: " << it->getNickname()
                  << ", Nombre: " << it->getNombre() << std::endl;
    }
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    std::set<DTInmuebleAdministrado> inmuebles = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);
    std::set<DTInmuebleAdministrado>::iterator itInmueble;
    for (itInmueble = inmuebles.begin(); itInmueble != inmuebles.end(); ++itInmueble) {
        std::cout << "- Código: " << itInmueble->getCodigo()
                  << ", Dirección: " << itInmueble->getDireccion()
            << ", Propietario: " << itInmueble->getNomProp() << std::endl;
    }
    int codigoInmueble;
    std::cout << "Inmueble: ";
    std::cin >> codigoInmueble;
    std::cin.ignore();
    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Texto: ";
    std::string texto;
    std::getline(std::cin, texto);
    std::cout << "Precio: ";
    float precio;
    std::cin >> precio;
    std::cin.ignore();
    controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
}

void consultaPublicaciones(){
    
    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Precio (Min): ";
    float precioMinimo;
    std::cin >> precioMinimo;
    std::cin.ignore();
    std::cout << "Precio (Max): ";
    float precioMaximo;
    std::cin >> precioMaximo;
    std::cin.ignore();
    int inTipoInmueble;
    std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos)";
    std::cin >> inTipoInmueble;
    std::cin.ignore();
    TipoInmueble tipoInmueble = Todos;
    if(inTipoPublicacion == 1){
        tipoInmueble = Casa;
    }else if(inTipoPublicacion == 2){
        tipoInmueble = Apartamento;
    }
    std::cout << "Publicaciones encontradas:\n";
    std::set<DTPublicacion> publicaciones = controlador->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
    std::set<DTPublicacion>::iterator it;
    for (it = publicaciones.begin(); it != publicaciones.end(); it++) {
        std::cout<<"- Codigo: "<< it->getCodigo()
                <<", fecha: "<< it->getFecha()->toString()
                <<", texto: "<<it->getTexto()
                <<", precio: "<<it->getPrecio()
                <<", inmobiliaria: "<< it->getInmobiliaria()
            <<std::endl;
    }

    int verDetalle;
    std::cout << "Ver detalle de la publicacion: (1: Si, 0: No)";
    std::cin >> verDetalle;
    std::cin.ignore();
    if (verDetalle == 1){
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        std::cin >> codigoPublicacion;
        std::cin.ignore();
        std::cout << "Detalle del inmueble:\n";
        DTInmueble* inmu = controlador->detalleInmueblePublicacion(codigoPublicacion);
        inmu->imprimirDetalle();
    }
}

void eliminarInmueble(){

    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();
    std::cout << "Listado de inmuebles:\n";
    std::set<DTInmuebleListado> inmuebles = controlador->listarInmuebles();
    std::set<DTInmuebleListado>::iterator it;

    for (it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        std::cout << "- Codigo: " << it->getCodigo()
             << ", Direccion: " << it->getDireccion()
             << ", Propietario: " << it->getPropietario()
        << std::endl;
    }
    std::cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    std::cout << "Detalle del inmueble:\n";
    DTInmueble* inmu = controlador->detalleInmueble(codigoInmueble);
    inmu->imprimirDetalle();
    int deseaEliminar;
    std::cout << "¿Desea eliminar?: (1: Si, 0: No)";
    std::cin >> deseaEliminar;
    std::cin.ignore();
    if (deseaEliminar == 1){
        controlador->eliminarInmueble(codigoInmueble);
    }

}

void suscribirseNotificaciones(){
    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();
    std::cout << "- SUSCRIBIR USUARIO A NOTIFICACIONES -\n";
    std::cout << "Nickname de cliente o propietario: ";
    std::string nickUsuario;
    std::getline(std::cin, nickUsuario);
    std::set<DTUsuario> disponibles = controlador->listarInmobiliariasNoSuscritas(nickUsuario);
    if (disponibles.empty()) {
        std::cout << "No hay inmobiliarias disponibles para suscribirse.\n\n";
        
    }else{

        int salir = 1;
        while (salir == 1) {
            std::cout << "Inmobiliarias disponibles:\n";
            for (std::set<DTUsuario>::iterator it = disponibles.begin(); it != disponibles.end(); ++it) {
                std::cout << "- Nickname: " << it->getNickname()
                << ", Nombre: "   << it->getNombre() << "\n";
            }
            std::cout << "Nickname de la inmobiliaria a suscribir: ";
            std::string inmoNick;
            std::getline(std::cin, inmoNick);
            controlador->suscribirUsuario(nickUsuario, inmoNick);
            std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
        }
        
        std::cout << "Suscripciones registradas correctamente.\n\n";
    }
}

void consultaNotificaciones(){
    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();
    std::cout << "- CONSULTA DE NOTIFICACIONES -\n";
    std::cout << "Nickname de cliente o propietario: ";
    std::string nickUsuario;
    std::getline(std::cin, nickUsuario);
    std::set<DTNotificacion> nots = controlador->consultarNotificaciones(nickUsuario);
    if (nots.empty()) {
        std::cout << "No hay notificaciones.\n\n";
        
    }else{
        for (std::set<DTNotificacion>::const_iterator it = nots.begin(); it != nots.end(); ++it) {
            const DTNotificacion &dt = *it;
            std::cout << "- Inmobiliaria: "     << dt.getInmobiliaria()
            << ", Codigo: "          << dt.getCodigoPublicacion()
            << ", Texto: "           << dt.getTexto()
            << ", TipoPublicacion: " << dt.getTipoPublicacion()
            << ", TipoInmueble: "    << dt.getTipoInmueble()
            << "\n";
        }
        std::cout << "\n";
    }

}

void eliminarSuscripciones(){
    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();
    std::cout << "- ELIMINAR SUSCRIPCIONES -\n";
    std::cout << "Nickname de cliente o propietario: ";
    std::string nickUsuario;
    std::getline(std::cin, nickUsuario);

    std::set<DTUsuario> suscritas = controlador->listarInmobiliariasSuscritas(nickUsuario);
    if (suscritas.empty()) {
        std::cout << "No hay suscripciones activas.\n\n";
        
    }else{
        int salir = 1;
        while (salir == 1) {
            std::cout << "Inmobiliarias suscritas:\n";
            for (std::set<DTUsuario>::const_iterator it = suscritas.begin();it != suscritas.end(); ++it){
                DTUsuario dtu = *it;
                std::cout << "- Nickname: " << dtu.getNickname()
                << ", Nombre:   " << dtu.getNombre() << "\n";
            }
            std::cout << "Nickname de la inmobiliaria a cancelar suscripción: ";
            std::string inmoNick;
            std::getline(std::cin, inmoNick);
            controlador->eliminarSuscripciones(nickUsuario, inmoNick);
            std::cout << "¿Quiere seguir eliminando? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
        }
        
        
        std::cout << "Suscripciones eliminadas.\n\n";
        
    }
}

void altaAdministracionPropiedad(){
    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();
    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario> inmobiliarias = controlador->listarInmobiliarias();
    
    std::set<DTUsuario>::iterator it;
    for (it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        std::cout << "- Nickname: " << it->getNickname()
                  << ", Nombre: " << it->getNombre() << std::endl;
    }
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    std::set<DTInmuebleListado> inmuebles = controlador->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
    for (std::set<DTInmuebleListado>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        std::cout << "- Codigo: " << it->getCodigo()
                << ", Direccion: " << it->getDireccion()
            << ", Propietario: " << it->getPropietario() << std::endl;
    }
    std::cout << "Codigo del inmueble a administrar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    controlador->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
}

void cargarDatos(){
    CargaDatos::getInstance();
}

 void verFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    DTFecha* fechaActual = cfecha->getFechaActual();
    std::cout << "fecha actual: " << fechaActual;
    delete fechaActual;
 }

 void asignarFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    std::cout << "dia: ";
    int dia;
    std::cin >> dia;
    std::cin.ignore();
    std::cout << "mes: ";
    int mes;
    std::cin >> mes;
    std::cin.ignore();
    std::cout << "ano: ";
    int ano;
    std::cin >> ano;
    std::cin.ignore();
    cfecha->setNewFechaActual(dia, mes, ano);
 }
