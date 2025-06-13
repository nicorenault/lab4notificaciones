#ifndef CASA_H
#define CASA_H
#include "Inmueble.h"
#include "TipoTecho.h"

class Casa : public Inmueble {
    private:
        bool esPH;
        TipoTecho techo;
 

    public:
        //Casa(bool esPH, TipoTecho techo);
        
        bool esCasa() const override { return true;};
        DTInmueble* toDT() const override;
        Casa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo);
        bool getEsPH() const;
        TipoTecho getTecho() const;
        ~Casa();
};

#endif
