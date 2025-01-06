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
#include "TADCalendarioMes.h"

typedef tm *Ptrtm;

typedef struct TADApartamento {

  void            constructor(TipoApartamento tipo, char tipoChar, int id);
  void            print();
  int             asignarReserva(PtrReserva reserva);
  void            borrarReservas();
  TipoApartamento obtenerTipo();
  char            obtenerTipoChar();
  int             obtenerId();
  int             validarFechaReserva(time_t comienzo, time_t final);
  void            printCalendario(int mes, int periodoAnual);
  int             insertarReserva(PtrReserva reserva);


  private:
    int               id;
    TipoApartamento   tipo;
    char              tipoChar;
    PtrReserva        reservas;
    TADCalendarioMes  calendario;
    int               rellenarMes(int comienzoDia, int final, int mes, PtrReserva reservaEnMes);
    PtrReserva        crearReserva();

};

typedef TADApartamento *PtrApartamento;
