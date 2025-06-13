#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"

class DTNotificacion {
private:
    std::string inmobiliaria;
    int codigoPub;
    std::string texto;
    TipoPublicacion tipoPub;
    TipoInmueble tipoInm;
    DTFecha* fecha;
public:
    DTNotificacion(const std::string& inm, int cod, const std::string& tx, TipoPublicacion tp, TipoInmueble ti, DTFecha* f);
    std::string getInmobiliaria() const;
    int getCodigoPublicacion() const;
    std::string getTexto() const;
    TipoPublicacion getTipoPublicacion() const;
    TipoInmueble getTipoInmueble() const;
    DTFecha* getFecha() const;
    bool operator<(const DTNotificacion& o) const;
    ~DTNotificacion();
};

#endif
