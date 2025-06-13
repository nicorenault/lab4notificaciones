#include "Cliente.h"
#include "Usuario.h"

Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento): Usuario(nickname, contrasena, nombre, email){
    this->apellido = apellido;
    this->documento = documento;
}

std::string Cliente::getApellido() {
    return apellido;
}

std::string Cliente::getDocumento() {
    return documento;
}

Cliente::~Cliente() {}

void Cliente::notify(const DTNotificacion &dt) {
    notificaciones.insert(dt);
}

std::set<DTNotificacion> Cliente::getNotificaciones() const {
    return notificaciones;
}

void Cliente::clearNotificaciones() {
    notificaciones.clear();
}
