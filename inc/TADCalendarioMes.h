/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

# pragma once

#include <time.h>

#include "TADReserva.h"


typedef struct TADCalendarioMes {

  void  printCalendario(PtrReserva reservaEnMes, int mes, int periodoAnual, time_t epochMes);

  private:
    int   rellenarMes(PtrReserva reservas, time_t epochMes, int comienzoDia, int final);
    int   diaEnReservas(PtrReserva reserva, time_t epochMes);
};
