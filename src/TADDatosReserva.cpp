/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

#include <stdio.h>
#include <string.h>

#include "TADDatosReserva.h"

int   TADDatosReserva::validar() {
  if (this->fecha.tm_year < 2025 || this->fecha.tm_year > 2035) {
    fprintf(stderr, "[ERROR] - El Periodo anual no esta dentro del margen 2025-2035\n");
    return 1;
  }

  if (this->fecha.tm_mon < 1 || this->fecha.tm_mon > 12) {
    fprintf(stderr, "[ERROR] - El Periodo mensual no esta dentro del margen 1-12\n");
    return 1;
  }
  if (this->fecha.tm_mday < 1 || this->fecha.tm_mday > 31) {
    fprintf(stderr, "[ERROR] - El Periodo de dia no esta dentro del margen 1-31\n");
    return 1;
  }
  return 0;
}

int TADDatosReserva::asignarTipoApartamento(char tipoApartamento) {
  switch (tipoApartamento) {
    case 'B':
      this->tipoApartamento = BASICO;
      break ;
    case 'N':
      this->tipoApartamento = NORMAL;
      break ;
    case 'L':
      this->tipoApartamento = LUJO;
      break ;
    default:
      return 1;
  }
  return 0;
}

void  TADDatosReserva::normalizar() {
  this->fecha.tm_mon = this->fecha.tm_mon - 1;
  this->fecha.tm_year = this->fecha.tm_year - 1900;
}

void  TADDatosReserva::constructor() {
  memset(this, 0, sizeof(TADDatosReserva));
}
