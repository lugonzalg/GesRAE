/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

# pragma once

#include <time.h>

#include "TADDatosReserva.h"
#include "types.h"

typedef tm    *PtrTm;

typedef struct TADReserva {

  char            obtenerTipoApartamentoChar();
  TipoApartamento obtenerTipoApartamento();
  PtrChar         obtenerReferencia();
  PtrTm           obtenerFechaComienzo();
  PtrTm           obtenerFechaFinal();
  time_t          obtenerEpochComienzo();
  time_t          obtenerEpochFinal();
  int             obtenerPeriodo();
  int             obtenerPeriodoAnualRegistro();
  int             obtenerPeriodoAnualOutput();
  int             obtenerId();
  void            asignarReferencia(int idEdificio, char TipoApartamento, int idApartamento);
  void            asignarDatosPrimero();
  void            asignarDatosUltimo();
  TADReserva      *siguiente;
  int             constructor(PtrDatosReserva datosReserva);

  private:
    int             id;
    char            tipoApartamentoChar;
    TipoApartamento tipoApartamento;
    tm              fechaComienzo;
    tm              fechaFinal;
    int             periodo;
    time_t          epochComienzo;
    time_t          epochFinal;
    TipoVectorChars referencia;
};

typedef TADReserva *PtrReserva;
