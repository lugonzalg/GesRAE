/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "TADApartamento.h"

//CHECKERS

int TADApartamento::validarFechaReserva(time_t comienzo, time_t final) {
  PtrReserva  referenciaReserva;

  referenciaReserva = this->reservas->siguiente;
  while (referenciaReserva->siguiente) {
    if (!(final <= referenciaReserva->obtenerEpochComienzo()
      || comienzo >= referenciaReserva->obtenerEpochFinal())) {
        return 0;
      }
    referenciaReserva = referenciaReserva->siguiente;
  }
  return 1;
}

//RESERVA HANDLERS

void  TADApartamento::borrarReservas() {
  PtrReserva  reservaActual;
  PtrReserva  siguienteReserva;

  reservaActual = this->reservas;
  while (reservaActual) {
    siguienteReserva = reservaActual->siguiente;
    delete reservaActual;
    reservaActual = siguienteReserva;
  }
  this->reservas = NULL;
}

PtrReserva TADApartamento::crearReserva() {
  PtrReserva reserva;

  reserva = new TADReserva;

  if (!reserva) {
    return NULL;
  }
  memset(reserva, 0, sizeof(TADReserva));
  return reserva;
}

int TADApartamento::insertarReserva(PtrReserva reserva) {
  PtrReserva referenciaReserva;

  referenciaReserva = this->reservas;
  while (referenciaReserva) {

    if (reserva->obtenerEpochComienzo() >= referenciaReserva->obtenerEpochFinal()
      && reserva->obtenerEpochFinal() <= referenciaReserva->siguiente->obtenerEpochComienzo()) {
      reserva->siguiente = referenciaReserva->siguiente;
      referenciaReserva->siguiente = reserva;
      return 1;
    }
    referenciaReserva = referenciaReserva->siguiente;
  }
  return 1;
}

//constructorS

void TADApartamento::constructor(TipoApartamento tipo, char tipoChar, int id) {
  PtrReserva  primeraReserva;
  PtrReserva  ultimaReserva;

  this->borrarReservas();
  memset(this, 0, sizeof(TADApartamento));

  primeraReserva = this->crearReserva();
  ultimaReserva  = this->crearReserva();

  primeraReserva->asignarDatosPrimero();
  ultimaReserva->asignarDatosUltimo();
  primeraReserva->siguiente = ultimaReserva;

  this->reservas = primeraReserva;
  this->tipo = tipo;
  this->tipoChar = tipoChar;
  this->id = id;
}

//STDOUT

void TADApartamento::print() {
  printf("Tipo: %d", this->tipo);
}

void  TADApartamento::printCalendario(int mes, int periodoAnual) {
  PtrReserva  reservaEnMes;
  tm          fechaMes;
  time_t      epochMes;

  memset(&fechaMes, 0, sizeof(tm));
  fechaMes.tm_mday  = 1;
  fechaMes.tm_mon   = mes - 1;
  fechaMes.tm_year  = periodoAnual - 1900;
  epochMes          = mktime(&fechaMes);

  reservaEnMes = this->reservas->siguiente;
  while (reservaEnMes
    && reservaEnMes->obtenerFechaComienzo()->tm_mon != fechaMes.tm_mon) {
    reservaEnMes = reservaEnMes->siguiente;
  }

  this->calendario.printCalendario(reservaEnMes, mes, periodoAnual, epochMes);
}

//SETTERS

int TADApartamento::asignarReserva(PtrReserva reserva) {
  if (this->validarFechaReserva(reserva->obtenerEpochComienzo(), reserva->obtenerEpochFinal())) {
    return 1;
  }
  return 0;
}

//GETTERS

char            TADApartamento::obtenerTipoChar() {return this->tipoChar; }
TipoApartamento TADApartamento::obtenerTipo() {return this->tipo; }
int             TADApartamento::obtenerId() {return this->id; }
