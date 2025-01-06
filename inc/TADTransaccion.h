/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

# pragma once

#include "TADEdificio.h"

typedef struct TADTransaccion {
  PtrEdificio    edificio;
  PtrApartamento apartamento;
  PtrReserva     reserva;
};

typedef TADTransaccion *PtrTransaccion;
