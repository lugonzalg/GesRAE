/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

# pragma once

#include "types.h"

typedef struct TADDatosEdificio {
  TipoVectorChars       nombre;
  VectorTipoApartamento numeroTipoApartamento;
  int                   totalApartamentos;
  int                   id;
};

typedef TADDatosEdificio *PtrDatosEdificio;
