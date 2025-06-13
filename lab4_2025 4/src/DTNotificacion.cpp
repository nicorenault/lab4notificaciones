#include "DTNotificacion.h"

DTNotificacion::DTNotificacion(const std::string& inm, int cod, const std::string& tx,
                               TipoPublicacion tp, TipoInmueble ti, DTFecha* f)
  : inmobiliaria(inm), codigoPub(cod), texto(tx),
    tipoPub(tp), tipoInm(ti), fecha(new DTFecha(f)) {}

std::string DTNotificacion::getInmobiliaria() const { return inmobiliaria; }
int DTNotificacion::getCodigoPublicacion() const { return codigoPub; }
std::string DTNotificacion::getTexto() const { return texto; }
TipoPublicacion DTNotificacion::getTipoPublicacion() const { return tipoPub; }
TipoInmueble DTNotificacion::getTipoInmueble() const { return tipoInm; }
DTFecha* DTNotificacion::getFecha() const { return fecha; }

bool DTNotificacion::operator<(const DTNotificacion& o) const {
    if (fecha < o.fecha) return true;
    if (fecha == o.fecha) return codigoPub < o.codigoPub;
    return false;
}

DTNotificacion::~DTNotificacion() {
    //delete fecha;
}
