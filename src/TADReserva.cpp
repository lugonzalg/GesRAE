/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "TADReserva.h"

//GETERS
int TADReserva::obtenerPeriodoAnualRegistro() { return this->fechaComienzo.tm_year - 125; }
int TADReserva::obtenerPeriodoAnualOutput() { return this->fechaComienzo.tm_year + 1900; }
PtrTm TADReserva::obtenerFechaComienzo() { return &this->fechaComienzo; }
PtrTm TADReserva::obtenerFechaFinal() { return &this->fechaFinal; }
int    TADReserva::obtenerPeriodo() { return this->periodo; }
time_t TADReserva::obtenerEpochComienzo() { return this->epochComienzo; }
time_t TADReserva::obtenerEpochFinal()  { return this->epochFinal; }
PtrChar TADReserva::obtenerReferencia() {return this->referencia;}
char  TADReserva::obtenerTipoApartamentoChar() { return this->tipoApartamentoChar; }
TipoApartamento TADReserva::obtenerTipoApartamento() { return this->tipoApartamento; }
int TADReserva::obtenerId() { return this->id; }

void  TADReserva::asignarReferencia(int idEdificio, char tipoApartamento, int idApartamento) {
  snprintf(
    this->referencia
    , LongitudVectorChars
    , "APT%02d%c%02d"
    , idEdificio
    , tipoApartamento
    , idApartamento
  );
}

void  TADReserva::asignarDatosPrimero() {
  this->epochComienzo = INT_MIN;
  this->epochFinal = INT_MIN;
  this->periodo = INT_MIN;
  this->fechaComienzo.tm_mon = -1;
}

void  TADReserva::asignarDatosUltimo() {
  this->epochComienzo = INT_MAX;
  this->epochFinal = INT_MAX;
  this->periodo = INT_MAX;
  this->fechaComienzo.tm_mon = -1;
}

int TADReserva::constructor(PtrDatosReserva datosReserva) {
  memset(this, 0, sizeof(TADReserva));

  this->fechaComienzo        = datosReserva->fecha;
  this->periodo              = datosReserva->periodo;
  this->fechaFinal           = this->fechaComienzo;
  this->fechaFinal.tm_mday   = this->fechaFinal.tm_mday + datosReserva->periodo;
  this->tipoApartamentoChar  = datosReserva->tipoApartamentoChar;
  this->tipoApartamento      = datosReserva->tipoApartamento;
  this->id                   = datosReserva->id;

  this->epochComienzo = mktime(&this->fechaComienzo);
  if (this->fechaComienzo.tm_mday != datosReserva->fecha.tm_mday
    || this->fechaComienzo.tm_mon != datosReserva->fecha.tm_mon
    || this->fechaComienzo.tm_year != datosReserva->fecha.tm_year) {

    fprintf(stderr, "\n[ERROR] - El formato de la Fecha contiene un error!\n");
    fprintf(
      stderr
      , "Fecha original:\n\t- dia: %d\n\t- mes: %d\n\t- Periodo anual: %d\n\n"
      , datosReserva->fecha.tm_mday
      , datosReserva->fecha.tm_mon + 1
      , datosReserva->fecha.tm_year + 1900);
    return 1;
  }

  if (this->epochComienzo == -1) {
    fprintf(stderr, "[ERROR] - La Fecha de comienzo no esta comprendido en el Periodo aceptado de las reservas.\n");
    fprintf(stderr, "Fecha insertada:\n");
    fprintf(
      stderr
      , "\t- Dia: %d\n\t- Mes: %d\n\t- Periodo anual: %d.\n"
      , datosReserva->fecha.tm_mday
      , datosReserva->fecha.tm_mon
      , datosReserva->fecha.tm_year
    );

    fprintf(stderr, "Los Periodos aceptados transcurren entre 2025 y 2035, dentro de los margenes logicos del calendario.\n");
    fprintf(stderr, "Inserte otra vez la Fecha.\n");
    return 1;
  }
  this->epochFinal = mktime(&this->fechaFinal);
  if (this->epochFinal == -1) {
    fprintf(stderr, "[ERROR] - Error inesperado con las Fechas, contacte con el equipo de desarrollo!\n");
    return 1;
  }
  return 0;
}
