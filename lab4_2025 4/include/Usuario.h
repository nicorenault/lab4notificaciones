#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "DTUsuario.h"
#include "DTNotificacion.h"
#include <set>
class Usuario {
    private:
        std::string nickname;
        std::string contrasena;
        std::string nombre;
        std::string email;

    public:
        Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email);
        std::string getNickname()const;
        std::string getNombre() const;
        DTUsuario toDTU() const;
        virtual ~Usuario();
        
        
};

#endif
