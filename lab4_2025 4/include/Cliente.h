#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "IObserverNotificaciones.h"
#include "DTNotificacion.h"
#include <set>

#include <string>

class Cliente : public Usuario, public IObserverNotificaciones {
    private:
        std::string apellido;
        std::string documento;
        std::set<DTNotificacion> notificaciones;

    public:
        Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
        std::string getApellido();
        std::string getDocumento();
        void notify(const DTNotificacion &dt) override;
        std::set<DTNotificacion> getNotificaciones() const;
        void clearNotificaciones();
        ~Cliente();
};

#endif
