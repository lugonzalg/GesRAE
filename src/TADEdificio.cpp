/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "TADEdificio.h"

//GETTERS
PtrChar  TADEdificio::obtenerNombre() { return this->nombre; }
int TADEdificio::obtenerId() { return this->id; }
int TADEdificio::obtenerApartamentoDisponible(TipoApartamento TipoApartamento) { return this->numeroTipoApartamento[TipoApartamento]; }

void  TADEdificio::obtenerApartamentosLibresPorFecha(PtrReserva reserva, VectorTipoApartamento apartamentos_libres) {
  TipoApartamento tipoApartamento;
  int             resultado;

  memset(apartamentos_libres, 0, sizeof(VectorTipoApartamento));
  for (int idx = 0; idx < this->totalApartamentos; idx++) {
    tipoApartamento = this->apartamentos[idx].obtenerTipo();
    resultado = this->apartamentos[idx].validarFechaReserva(reserva->obtenerEpochComienzo(), reserva->obtenerEpochFinal());
    apartamentos_libres[tipoApartamento] = apartamentos_libres[tipoApartamento] + resultado;
  }
}

PtrApartamento TADEdificio::asignarReserva(PtrReserva reserva) {

  int             comienzo;
  int             fin;

  switch(reserva->obtenerTipoApartamento()) {
    case BASICO:
      comienzo = 0;
      fin = this->numeroTipoApartamento[BASICO];
      break ;
    case NORMAL:
      comienzo = this->numeroTipoApartamento[BASICO];
      fin = this->numeroTipoApartamento[BASICO] + this->numeroTipoApartamento[NORMAL];
      break ;
    case LUJO:
      comienzo = this->numeroTipoApartamento[BASICO] + this->numeroTipoApartamento[NORMAL];
      fin = this->totalApartamentos;
      break ;
    default:
      return NULL;
  }

  if (fin > LongitudVectorApartamentos || comienzo > LongitudVectorApartamentos) {
    fprintf(stderr, "[ERROR] - error en la logica del programa, comienzo: %d o fin: %d. Tiene valores anomalos\n", comienzo, fin);
    return NULL;
  }

  for (int idx = comienzo; idx < fin; idx++) {

    if (reserva->obtenerTipoApartamento() != this->apartamentos[idx].obtenerTipo()) {
      fprintf(stderr, "[ERROR] - error en la logica del programa, el Tipo es incorrecto: %d\n", reserva->obtenerTipoApartamento());
      return NULL;
    }

    if (this->apartamentos[idx].asignarReserva(reserva)) {
      return &this->apartamentos[idx];
    }
  }
  return NULL;
}

//STDOUT

void TADEdificio::print() {

  printf("nombre: %s\n", this->nombre);
  printf("Apartamentos Basicos: %d\n", this->numeroTipoApartamento[BASICO]);
  printf("Apartamentos Normales: %d\n", this->numeroTipoApartamento[NORMAL]);
  printf("Apartamentos de Lujo: %d\n", this->numeroTipoApartamento[LUJO]);

  for (int idx = 0; idx < this->totalApartamentos; idx++) {
    this->apartamentos[idx].print();
  }
}

void TADEdificio::printParaList(int lontiudMaximaNombre) {
  printf("%-5d%-*s%-16d%-16d%d\n"
    , this->id
    , lontiudMaximaNombre + 5
    , this->nombre
    , this->numeroTipoApartamento[BASICO]
    , this->numeroTipoApartamento[NORMAL]
    , this->numeroTipoApartamento[LUJO]);
}

void TADEdificio::borrarApartamentos() {
  for (int idx = 0; idx < LongitudVectorApartamentos; idx++) {
    this->apartamentos[idx].borrarReservas();
  }
}

//constructorS

void TADEdificio::constructor(PtrDatosEdificio datosEdificio) {
  int offsetNormal;
  int offsetLujo;

  this->borrarApartamentos();
  memset(this, 0, sizeof(TADEdificio));

  strncpy(this->nombre, datosEdificio->nombre, LongitudVectorChars);
  memcpy(this->numeroTipoApartamento, datosEdificio->numeroTipoApartamento, SIZE * 4);

  offsetNormal = this->numeroTipoApartamento[BASICO];
  offsetLujo = this->numeroTipoApartamento[BASICO] + this->numeroTipoApartamento[NORMAL];

  this->totalApartamentos = datosEdificio->totalApartamentos;
  this->id = datosEdificio->id;

  for (int idx = 0; idx < LongitudVectorApartamentos; idx++) {

    if (idx < this->numeroTipoApartamento[BASICO]) {
      this->apartamentos[idx].constructor(BASICO, 'B', idx + 1);
    }
    else if (idx < offsetLujo) {
      this->apartamentos[idx].constructor(NORMAL, 'N', idx - offsetNormal + 1);
    }
    else if (idx < this->totalApartamentos) {
      this->apartamentos[idx].constructor(LUJO, 'L', idx - offsetLujo + 1);
    }
  }
}

// STATE

void  TADEdificio::reset() {
  this->borrarApartamentos();
  memset(this, 0, sizeof(TADEdificio));
}

int TADEdificio::printarReservasApartamentoPorFecha(TipoApartamento tipoApartamento, int offset, int mes, int periodoAnual) {

  int idx;

  switch(tipoApartamento) {
    case BASICO:
      idx = offset - 1;
      break ;
    case NORMAL:
      idx = this->numeroTipoApartamento[BASICO] + offset - 1;
      break ;
    case LUJO:
      idx = this->numeroTipoApartamento[BASICO] + this->numeroTipoApartamento[NORMAL] + offset  - 1;
      break ;
    default:
      return 1;
  }

  if (this->apartamentos[idx].obtenerTipo() != tipoApartamento) {
    fprintf(stderr, "[ERROR] - Fallo en la logica para printar calendario, tipo de apartamento no es igual\n");
    return 1;
  }

  printf("\n\t\tEdificio: %s\n\n", this->nombre);
  this->apartamentos[idx].printCalendario(mes, periodoAnual);
  return 0;
}
