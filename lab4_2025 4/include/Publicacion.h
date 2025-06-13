#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "DTPublicacion.h"
#include <string>
#include <set>
class AdministraPropiedad;

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad* ap;

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    int getCodigo();
    AdministraPropiedad* getAP();
    DTFecha* getFecha();
    TipoPublicacion getTipo();
    std::string getTexto();
    float getPrecio();
    bool estaActiva();
    void setActiva(bool activa);
    void setAp(AdministraPropiedad* ap);
    bool cumpleFiltro(TipoPublicacion tpub, float precioMin, float precioMax, TipoInmueble tipoInm) const;
    DTPublicacion toDT() const;
    static std::set<DTPublicacion> listar(TipoPublicacion tipoReq, float precioMin, float precioMax, TipoInmueble tipoInm);
    ~Publicacion();
};

#endif
