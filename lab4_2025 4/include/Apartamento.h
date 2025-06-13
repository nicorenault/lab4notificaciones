#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"


class Apartamento : public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        Apartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,int piso, bool tieneAscensor, float gastosComunes);
        //Apartamento(int piso, bool tieneAscensor, float gastosComunes);
        DTInmueble* toDT() const override;

        bool esCasa() const override { return false;}
        int getPiso() const;
        bool getTieneAscensor() const;
        float getGastosComunes() const;
        ~Apartamento();
};

#endif
