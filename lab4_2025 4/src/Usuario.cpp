#include "Usuario.h"
#include <string>

Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email){
        this->nickname = nickname;
        this->contrasena = contrasena;
        this->nombre = nombre;
        this->email = email;
    }

std::string Usuario::getNombre()const{
    return nombre;
}
std::string Usuario::getNickname()const{
    return nickname;
}

DTUsuario Usuario::toDTU() const{
    return DTUsuario(this->nickname, this->nombre);
}



Usuario::~Usuario() {}
