#ifndef IOBSERVERNOTIFICACIONES_H
#define IOBSERVERNOTIFICACIONES_H

#include "DTNotificacion.h"

class IObserverNotificaciones {
public:
    virtual void notify(const DTNotificacion &dt) = 0;
    virtual ~IObserverNotificaciones() {}
};

#endif
