#ifndef FACTORY_H
#define FACTORY_H
#include "IControladorSistema.h"
#include "IControladorFechaActual.h"

class Factory {
    private:
        static Factory* instance;
        Factory();
        IControladorSistema* ctrlSis;
        IControladorFechaActual* ctrlFecha;
    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        IControladorSistema* getControladorSistema();
        ~Factory();
};

#endif
