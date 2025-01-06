/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

# pragma once

#include <time.h>

#include "types.h"

typedef struct TADDatosReserva {
  TipoApartamento tipoApartamento;
  char            tipoApartamentoChar;
  tm              fecha;
  int             periodo;
  int             id;

  int             validar();
  void            normalizar();
  void            constructor();
  int             asignarTipoApartamento(char tipoApartamento);
};

typedef TADDatosReserva *PtrDatosReserva;
