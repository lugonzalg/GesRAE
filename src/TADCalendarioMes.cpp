/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

#include <stdio.h>

#include "TADCalendarioMes.h"

typedef TipoVectorChars Meses[12];
Meses globalVectorMeses = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

int TADCalendarioMes::diaEnReservas(PtrReserva reserva, time_t epochMes) {
  PtrReserva referenciaReserva;

  referenciaReserva = reserva;
  while (referenciaReserva) {
    if (epochMes >= referenciaReserva->obtenerEpochComienzo()
      && epochMes < referenciaReserva->obtenerEpochFinal()) {
      return 1;
    }
    referenciaReserva = referenciaReserva->siguiente;
  }
  return 0;
}

int TADCalendarioMes::rellenarMes(PtrReserva reservas, time_t epochMes, int comienzoDia, int final) {

  int     diaSemana;
  int     diasReservados;

  diasReservados    = 0;
  diaSemana         = 1;

  if (comienzoDia == 1) {
    comienzoDia = 0;
  } else if (comienzoDia == 0) {
    comienzoDia = 7;
  }

  while (diaSemana < comienzoDia) {
    diaSemana++;
    printf("    ");
  }

  for (int dia = 1; dia <= final; dia++) {
    if (this->diaEnReservas(reservas, epochMes)) {
      printf("%2s  ", "Re");
      diasReservados = diasReservados + 1;
    } else {
      printf("%2d  ", dia);
    }

    if (diaSemana == 7) {
      printf("\n\t\t");
    }

    epochMes = epochMes + 86400;
    diaSemana = (diaSemana % 7) + 1;
  }
  return diasReservados;
}

void  TADCalendarioMes::printCalendario(PtrReserva reservaEnMes, int mes, int periodoAnual, time_t epochMes) {

  int         c;
  int         h;
  int         final;
  int         auxMes;
  int         auxPeriodoAnual;
  int         diasReservados;

  auxMes = mes;
  auxPeriodoAnual = periodoAnual;

  if (mes < 3) {
    mes = mes + 12;
    periodoAnual--;
  }
  c = periodoAnual / 100;
  periodoAnual = periodoAnual % 100;
  h = (c / 4 - 2 * c + periodoAnual + periodoAnual / 4 + 13 * (mes + 1) / 5 + 1 - 1) % 7;

  printf("\t\t%-22s %d\n\n", globalVectorMeses[auxMes - 1], auxPeriodoAnual);
  printf("\t\t===========================\n");
  printf("\t\tLU  MA  MI  JU  VI | SA  DO\n");
  printf("\t\t===========================\n\t\t");

  final = 30;
  if (auxMes == 2) {

    final = 28;
    if (auxPeriodoAnual % 4 == 0 && ((auxPeriodoAnual % 400 == 0) || (auxPeriodoAnual % 100 != 0))) {
      final = 29;
    }
  } else if (auxMes == 1 || auxMes == 3 || auxMes == 5 || auxMes == 7 || auxMes == 8 || auxMes == 10 || auxMes == 12) {
    final = 31;
  }

  diasReservados = this->rellenarMes(reservaEnMes, epochMes, (h + 7) % 7, final);
  printf("\n\n");

  while (reservaEnMes
    && reservaEnMes->obtenerFechaComienzo()->tm_mon + 1 == auxMes) {

    printf("Reserva %d/%d: Fecha entrada %d/%d/%d y de %d dias\n"
      , reservaEnMes->obtenerId()
      , reservaEnMes->obtenerFechaComienzo()->tm_year + 1900
      , reservaEnMes->obtenerFechaComienzo()->tm_mday
      , reservaEnMes->obtenerFechaComienzo()->tm_mon + 1
      , reservaEnMes->obtenerFechaComienzo()->tm_year + 1900
      , reservaEnMes->obtenerPeriodo()
      );
    reservaEnMes = reservaEnMes->siguiente;
  }
  printf("Total dias reservados del mes: %d dias\n", diasReservados);
  printf("Total dias libres del mes: %d dias\n", final - diasReservados);
}
