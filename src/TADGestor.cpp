/**************************************
* NOMBRE: #Lukas#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Ortega#
* DNI: #44334840V#
* EMAIL: #lgonzalez2660@alumno.uned.es#
***************************************/

//INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "TADGestor.h"
#include "TADDatosReserva.h"

//PROGRAM


int TADGestor::inputUsuarioNumero(PtrChar mensaje, PtrChar mensajeError) {
  TipoVectorChars inputUsuario;
  int             inputCorrecto;

  inputCorrecto = 1;

  do {
    printf(mensaje);
    scanf(VectorCharsScanf, inputUsuario);
    fflush(stdin);
    if (this->validarNumeros(inputUsuario)) {
      fprintf(stderr, mensajeError);
      continue ;
    }
    inputCorrecto = 0;
  } while (inputCorrecto);

  return atoi(inputUsuario);
}

int TADGestor::validarPalabra(TipoVectorChars InputUsuario) {

  for (int idx = 0; idx < LongitudVectorChars && InputUsuario[idx]; idx++) {
    if (!isalpha(InputUsuario[idx])) {
      fprintf(stderr, "\n[ERROR] - El input contiene caracteres fuera de a-z/A-Z!\n");
      return 1;
    }
  }
  return 0;
}

int TADGestor::validarNumeros(TipoVectorChars inputUsuario) {
  int negativo;
  int numero;

  negativo = 0;
  numero = 1;
  for (int idx = 0; idx < LongitudVectorChars && inputUsuario[idx]; idx++) {

    if (inputUsuario[idx] == '-') {
      numero = 1;
      negativo = negativo + 1;
    }

    if (isdigit(inputUsuario[idx])) {
      numero = 0;
    }

    if (!isdigit(inputUsuario[idx]) && inputUsuario[idx] != '-' || negativo > 1) {
      fprintf(stderr, "\n[ERROR] - El input no es un numero!\n");
      return 1;
    }
  }

  if (numero) {
    fprintf(stderr, "\n[ERROR] - Hay un signo negativo sin numero\n");
  }

  return numero;
}

int TADGestor::indiceEdificioValidado(PtrChar mensaje) {
  TipoVectorChars inputUsuario;
  int             idx;
  int             inputCorrecto;

  inputCorrecto = 1;
  do {
    printf(mensaje);
    scanf(VectorCharsScanf, inputUsuario);
    fflush(stdin);

    if (this->validarNumeros(inputUsuario)) {
      continue ;
    }

    idx = atoi(inputUsuario);
    if (idx < 1 || idx > 5) {
      fprintf(stderr, "\n[ERROR] - El id esta fuera del rango 1-5: %d\n", idx);
      continue ;
    }
    inputCorrecto = 0;
  } while (inputCorrecto);

  return idx;
}

void TADGestor::asignarNombreDeEdificio(PtrDatosEdificio datosEdificio) {
  TipoVectorChars inputUsuario;
  int             longitud;
  int             inputCorrecto;

  inputCorrecto = 1;
  memset(inputUsuario, 0, sizeof(TipoVectorChars));
  longitud = 0;

    do {
    printf("\tNombre (entre 1 y 20 caracteres)? ");
    scanf(VectorCharsScanf, inputUsuario);
    fflush(stdin);
    longitud = strlen(inputUsuario);
    if (longitud > 20 || longitud == 0) {
      fprintf(stderr, "\n[ERROR] - La longitud de la palabra supera el limite!\n");
      fprintf(stderr, "\t - Input: %s\n", inputUsuario);
      fprintf(stderr, "\t - Longitud input: %d\n\n", longitud);
      continue ;
    }

    if (this->validarPalabra(inputUsuario)) {
      fprintf(stderr, "[ERROR] - El nombre para el edificio es incorrecto!\n");
      fprintf(stderr, "\t - Input: %s\n", inputUsuario);
      fprintf(stderr, "\t - Longitud input: %d\n\n", longitud);
      continue ;
    }
    strncpy(datosEdificio->nombre, inputUsuario, LongitudVectorChars);
    inputCorrecto = 0;
    } while (inputCorrecto);
}

int TADGestor::asignarApartamentosDeEdificio(PtrDatosEdificio datosEdificio) {
  int inputCorrecto;

  inputCorrecto = 1;
  do {
    datosEdificio->numeroTipoApartamento[BASICO] = this->inputUsuarioNumero(
      "\tNumero de Apartamentos Basicos? "
      , "[ERROR] - El numero de apartamentos basicos contiene letras!\n\n");
    if (datosEdificio->numeroTipoApartamento[BASICO] < 0) {
      fprintf(stderr, "\n[ERROR] - Apartamentos Basicos es negativo!\n");
      return 1;
    }

    datosEdificio->numeroTipoApartamento[NORMAL] = this->inputUsuarioNumero(
      "\tNumero de Apartamentos Normales? "
      , "[ERROR] - El numero de apartamentos normales contiene letras!\n\n");
    if (datosEdificio->numeroTipoApartamento[NORMAL] < 0) {
      fprintf(stderr, "\n[ERROR] - Apartamentos Normales es negativo!\n");
      return 1;
    }

    datosEdificio->numeroTipoApartamento[LUJO] = this->inputUsuarioNumero(
      "\tNumero de Apartamentos de Lujo? "
      , "[ERROR] - El numero de apartamentos de lujo contiene letras!\n\n");
    if (datosEdificio->numeroTipoApartamento[LUJO] < 0) {
      fprintf(stderr, "\n[ERROR] - Apartamentos de Lujo es negativo!\n");
      return 1;
    }

    datosEdificio->totalApartamentos = datosEdificio->numeroTipoApartamento[BASICO] + datosEdificio->numeroTipoApartamento[NORMAL] + datosEdificio->numeroTipoApartamento[LUJO];
    if (datosEdificio->totalApartamentos  == 0) {
      fprintf(stderr, "\n[ERROR] - El total de apartamentos es 0!\n");
      return 1;
    }
    if (datosEdificio->totalApartamentos > 20) {
      fprintf(stderr, "\n[ERROR] - El total de apartamentos supera los 20 permitidos!\n\n");
      continue ;
    }
    inputCorrecto = 0;
  } while (inputCorrecto);

  return 0;
}

int TADGestor::validarOperacion() {
  TipoVectorChars inputUsuario;
  char            respuesta;

  do {
    memset(inputUsuario, 0, LongitudVectorChars);
    printf("\nIMPORTANTE: Esta opcion borra los datos anteriores.\n");
    printf("Son correctos los nuevos datos (S/N)? ");
    scanf(VectorCharsScanf, inputUsuario);
    fflush(stdin);
    respuesta = toupper(inputUsuario[0]);

    if (strlen(inputUsuario) == 1 && (respuesta == 'S' || respuesta == 'N')) {
      if (respuesta == 'N') {
        fprintf(stderr, "Borrando datos de entrada ...\n");
        return 1;
      }
      return 0;
    }
    fprintf(stderr, "[ERROR] - Los valores afirmacion son incorrectos!!\n");
  } while(1);

}

void TADGestor::editarEdificio() {
  int                 idx;
  int                 longitud;
  PtrEdificio         edificio;
  TADDatosEdificio    datosEdificio;

  idx       = 0;
  longitud  = 0;
  edificio  = NULL;

  idx = this->indiceEdificioValidado("\n\tIdentificador (numero entre 1 y 5)? ");
  edificio = &this->vectorEdificios[idx - 1];
  datosEdificio.id = idx;

  this->asignarNombreDeEdificio(&datosEdificio);
  if (this->asignarApartamentosDeEdificio(&datosEdificio)) {
    fprintf(stderr, "[ERROR] - Los datos del edificio no son validos, borrando edificio ...\n");
    edificio->reset();
    return ;
  }

  if (this->validarOperacion() == 0) {
    edificio->constructor(&datosEdificio);
  }
}

void TADGestor::listarEdificios() {
  int longitud;
  int lontiudMaximaNombre;

  lontiudMaximaNombre = 10;
  for (int idx = 0; idx < LongitudVectorEdificios; idx++) {

    if (this->vectorEdificios[idx].obtenerId()) {
      longitud = strlen(this->vectorEdificios[idx].obtenerNombre());
      if (longitud > lontiudMaximaNombre) {
        lontiudMaximaNombre = longitud + 1;
      }
    }
  }

  printf("\n%-5s%-*s%-16s%-16s%s\n\n", "Id", lontiudMaximaNombre, "nombre", "Aptos Basicos", "Aptos Normales", "Aptos de Lujo");
  for (int idx = 0; idx < LongitudVectorEdificios; idx++) {

    if (this->vectorEdificios[idx].obtenerId()) {
      this->vectorEdificios[idx].printParaList(lontiudMaximaNombre);
    }
  }
}

int TADGestor::recogerDatosFecha(PtrDatosReserva datosReserva) {
  int             inputCorrecto;

  inputCorrecto = 1;
  do {
    datosReserva->fecha.tm_mday = this->inputUsuarioNumero(
      "\tFecha Entrada: Dia? "
      , "[ERROR] - El dia contiene letras!\n\n");

    if (datosReserva->fecha.tm_mday < 1 || datosReserva->fecha.tm_mday > 31) {
      fprintf(stderr, "\n[ERROR] - El dia debe estar entre 1-31!\n\n");
      continue ;
    }
    inputCorrecto = 0;
  } while(inputCorrecto);

  inputCorrecto = 1;
  do {
    datosReserva->fecha.tm_mon = this->inputUsuarioNumero(
      "\tFecha Entrada: Mes? "
      , "[ERROR] - El mes contiene letras!\n\n");

    if (datosReserva->fecha.tm_mon < 1 || datosReserva->fecha.tm_mon > 12) {
      fprintf(stderr, "\n[ERROR] - El mes debe estar entre 1-12!\n\n");
      continue ;
    }

    inputCorrecto = 0;
  } while(inputCorrecto);

  inputCorrecto = 1;
  do {
    datosReserva->fecha.tm_year = this->inputUsuarioNumero(
      "\tFecha Entrada: Periodo anual? "
      , "[ERROR] - El Periodo anual contiene letras!\n\n");

    if (datosReserva->fecha.tm_year < 2025 || datosReserva->fecha.tm_year > 2035) {
      fprintf(stderr, "\n[ERROR] - El periodo anual debe estar entre 2025-2035!\n\n");
      continue ;
    }

    inputCorrecto = 0;
  } while(inputCorrecto);

  inputCorrecto = 1;
  do {
    datosReserva->periodo = this->inputUsuarioNumero(
      "\tDias de duracion de la estancia? "
      , "[ERROR] - El Periodo de estancia contiene letras!\n\n");

    if (datosReserva->periodo < 1) {
      fprintf(stderr, "\n[ERROR] - El periodo de estancia debe ser un numero positivo!\n\n");
      continue ;
    }
    else if (datosReserva->periodo > 365) {
      fprintf(stderr, "\n[WARNING] - El periodo de estancia maximo son 365 dias!\n\n");
      continue ;
    }

    inputCorrecto = 0;
  } while(inputCorrecto);

  return 0;
}

void TADGestor::apartamentosDisponibles() {
  int                   idx;
  TADDatosReserva       datosReserva;
  PtrEdificio           edificio;
  PtrReserva            reserva;
  VectorTipoApartamento apartamentosLibres;

  idx = this->indiceEdificioValidado("\nApartamentos Disponibles:\n\n\tIdentificador de Edificio? ");
  edificio = &this->vectorEdificios[idx - 1];
  memset(&datosReserva, 0, sizeof(TADDatosReserva));
  if (!edificio->obtenerId()) {
    fprintf(stderr, "\n[WARNING] - Edificio(%d) no disponible, seleccione otro\n", idx);
    return ;
  }

  if (this->recogerDatosFecha(&datosReserva)) {
    fprintf(stderr, "[ERROR] - Los datos del usuario para las Fechas es incorrecto\n");
    return ;
  }

  printf("\nEl edificio %s desde el %d/%d/%d y %d dias de estancia, tendria disponibles:\n\n"
  , edificio->obtenerNombre()
  , datosReserva.fecha.tm_mday
  , datosReserva.fecha.tm_mon
  , datosReserva.fecha.tm_year
  , datosReserva.periodo
  );

  if (datosReserva.validar()) {
    fprintf(stderr, "[ERROR] - Los datos de reserva son incorrectos\n");
    return ;
  }

  datosReserva.normalizar();
  reserva = this->crearReserva(&datosReserva);
  edificio->obtenerApartamentosLibresPorFecha(reserva, apartamentosLibres);
  printf("\t%d apartamentos tipo Basico\n", apartamentosLibres[BASICO]);
  printf("\t%d apartamentos tipo Normal\n", apartamentosLibres[NORMAL]);
  printf("\t%d apartamentos tipo Lujo\n", apartamentosLibres[LUJO]);

  delete reserva;
}

PtrReserva TADGestor::crearReserva(PtrDatosReserva datosReserva) {
  PtrReserva reserva;

  reserva = new TADReserva;

  if (!reserva) {
    return NULL;
  }

  if (reserva->constructor(datosReserva)) {
    fprintf(stderr, "[ERROR] - La reserva no ha podido ser creada!\n");
    delete reserva;
    return NULL;
  }
  return reserva;
}


void  TADGestor::recogerDatosApartamento(PtrDatosReserva datosReserva, PtrEdificio edificio) {
  TipoVectorChars inputUsuario;
  int             inputCorrecto;

  inputCorrecto = 1;
  do {

    memset(inputUsuario, 0, LongitudVectorChars);
    printf("\tTipo de Apartamento (B-Basico/N-Normal/L-Lujo)? ");
    scanf(VectorCharsScanf, inputUsuario);
    fflush(stdin);

    if (strlen(inputUsuario) != 1) {
      fprintf(stderr, "\n[ERROR] - La longitud no es la correcta: %s\n\n", inputUsuario);
      continue ;
    }

    if (datosReserva->asignarTipoApartamento(inputUsuario[0])) {
      fprintf(stderr, "\n[ERROR] - Tipo de apartamento no valido! [B-Basico/N-Normal/L-Lujo]\n\n");
      continue ;
    }

    if (!edificio->obtenerApartamentoDisponible(datosReserva->tipoApartamento)) {
      fprintf(stderr, "\n[WARNING] - El edificio no dispone de ese Tipo de apartamento: %s\n\n", inputUsuario);
      continue ;
    }

    inputCorrecto = 0;
  } while(inputCorrecto);
}

int TADGestor::validarReserva() {
  PtrTm   fechaComienzo;
  PtrTm   fechaFinal;

  fechaComienzo = this->transaccion.reserva->obtenerFechaComienzo();
  fechaFinal = this->transaccion.reserva->obtenerFechaFinal();

  printf("\n\t\tDatos de la Reserva:\n");
  printf("\n\tNumero de Reserva: %d/%d\n", this->transaccion.reserva->obtenerId(), fechaComienzo->tm_year + 1900);
  printf("\tEdificio: %s (Id = %d)\n", this->transaccion.edificio->obtenerNombre(), this->transaccion.edificio->obtenerId());
  printf("\tReferencia Apartamento: APT%02d%c%02d\n"
    , this->transaccion.edificio->obtenerId()
    , this->transaccion.apartamento->obtenerTipoChar()
    , this->transaccion.apartamento->obtenerId()
  );
  printf("\tFecha Entrada: %d/%d/%d\n", fechaComienzo->tm_mday, fechaComienzo->tm_mon + 1, fechaComienzo->tm_year + 1900);
  printf("\tDuracion estancia: %d dias\n", this->transaccion.reserva->obtenerPeriodo());
  printf("\tFecha Salida: %d/%d/%d\n", fechaFinal->tm_mday, fechaFinal->tm_mon + 1, fechaFinal->tm_year + 1900);

  return this->validarOperacion();
}

void TADGestor::reservarApartamento() {
  PtrReserva      reserva;
  PtrEdificio     edificio;
  PtrApartamento  apartamento;
  TADDatosReserva datosReserva;
  int             idx;
  int             idxReserva;

  idx = this->indiceEdificioValidado("Reservar Apartamento: \n\n\tIdentificador de Edificio? ");
  if (idx == -1) {
    return ;
  }

  edificio = &this->vectorEdificios[idx - 1];
  if (!edificio->obtenerId()) {
    fprintf(stderr, "\nEdificio(%d) no disponible, seleccione otro\n", idx);
    return ;
  }
  memset(&this->transaccion, 0, sizeof(TADTransaccion));
  datosReserva.constructor();
  this->transaccion.edificio = edificio;
  this->recogerDatosApartamento(&datosReserva, edificio);
  if (this->recogerDatosFecha(&datosReserva)) {
    return ;
  }

  if (datosReserva.validar()) {
    return ;
  }

  idxReserva = datosReserva.fecha.tm_year - 2025;
  datosReserva.id = this->vectorRegistros[idxReserva] + 1;
  datosReserva.normalizar();
  reserva = this->crearReserva(&datosReserva);
  if (!reserva) {
    return ;
  }
  this->transaccion.reserva = reserva;

  apartamento = edificio->asignarReserva(reserva);
  if (!apartamento) {
    fprintf(stderr, "\n[WARNING] - El edificio no tiene apartamentos disponibles en las fechas definidas!\n");
    return ;
  }

  this->transaccion.apartamento = apartamento;
  reserva->asignarReferencia(
    this->transaccion.edificio->obtenerId()
    , this->transaccion.reserva->obtenerTipoApartamento()
    , this->transaccion.apartamento->obtenerId()
  );

  if (this->validarReserva()) {
    delete reserva;
    return ;
  }

  this->transaccion.apartamento->insertarReserva(this->transaccion.reserva);
  this->vectorRegistros[idxReserva] = this->vectorRegistros[idxReserva] + 1;
}

void TADGestor::reservasMensualesApartamento() {
  TipoVectorChars     inputUsuario;
  TipoVectorChars     auxiliar;
  int                 idxEdificio;
  int                 idxApartamento;
  TipoApartamento     tipoApartamento;
  int                 mes;
  int                 periodoAnual;
  int                 inputCorrecto;

  inputCorrecto = 0;
  memset(inputUsuario, 0, LongitudVectorChars);
  memset(auxiliar, 0, LongitudVectorChars);
  printf("Reservas Mensuales Apartamento:\n");
  printf("Referencia Apartamento ? "); //APT03N04
  scanf(VectorCharsScanf, inputUsuario);
  fflush(stdin);


  if (strlen(inputUsuario) != 8) {
    fprintf(stderr, "[ERROR] - El formato de entrada es incorrecto: %s. ProtoTipo: APT01N01 \n", inputUsuario);
    return ;
  }

  strncpy(auxiliar, &inputUsuario[3], 2);
  auxiliar[2] = 0;
  if (this->validarNumeros(auxiliar)) {
    fprintf(stderr, "\n[ERROR] - El identificador de edificio no es un numero!\n");
    return ;
  }

  idxEdificio = atoi(auxiliar);
  if (!idxEdificio || idxEdificio > LongitudVectorEdificios) {
    fprintf(stderr, "[ERROR] - El identificador del edificio no puede ser 0 o mayor de 5\n");
    return ;
  }

  if (!this->vectorEdificios[idxEdificio - 1].obtenerId()) {
    fprintf(stderr, "\n[ERROR] - El edificio no esta disponible!\n");
    return ;
  }

  switch(inputUsuario[5]) {
    case 'B':
      tipoApartamento = BASICO;
      break ;
    case 'N':
      tipoApartamento = NORMAL;
      break ;
    case 'L':
      tipoApartamento = LUJO;
      break ;
    default:
      fprintf(stderr, "\n[ERROR] - El Tipo de apartamento es desconocido!\n");
      return ;
  }

  strncpy(auxiliar, &inputUsuario[6], 2);
  auxiliar[2] = 0;
  if (this->validarNumeros(auxiliar)) {
    fprintf(stderr, "\n[ERROR] - El identificador de apartamento no es un numero!\n");
    return ;
  }
  idxApartamento = atoi(auxiliar);

  if (!idxApartamento || idxApartamento > 20) {
    fprintf(stderr, "[ERROR] - el indice del apartamento no puede ser 0 o mayor de 20\n");
    return ;
  }

  if (idxApartamento > this->vectorEdificios[idxEdificio - 1].obtenerApartamentoDisponible(tipoApartamento)) {
    fprintf(stderr, "[ERROR] - El apartamento asociado al codigo APTXXY[NN] esta fuera de rango para este edificio\n");
    return ;
  }

  inputCorrecto = 1;
  do {
    mes = this->inputUsuarioNumero(
      "Seleccion Mes? "
      , "\n[ERROR] - El Periodo mes contiene letras!\n");
    if (mes < 1 || mes > 12) {
      fprintf(stderr, "\n[ERROR] - El mes debe estar entre 1-12!\n\n");
      continue ;
    }

    inputCorrecto = 0;
  } while(inputCorrecto);

  inputCorrecto = 1;
  do {
    periodoAnual = this->inputUsuarioNumero(
    "Seleccion Periodo Anual? "
    , "\n[ERROR] - El Periodo anual contiene letras!\n");

    if (periodoAnual < 2025 || periodoAnual > 2035) {
      fprintf(stderr, "\n[ERROR] - El periodo anual debe estar entre 2025-2035!\n\n");
      continue ;
    }

    inputCorrecto = 0;
  } while(inputCorrecto);

  printf("\n\tEstado Mensual Apartamento: %s", inputUsuario);
  this->vectorEdificios[idxEdificio - 1].printarReservasApartamentoPorFecha(
      tipoApartamento
    , idxApartamento
    , mes
    , periodoAnual);

}

void TADGestor::intro() {
  printf("\nGesRAE: Gestion de Reservas Apartamentos-Edificios\n\n");
  printf("\tEditar Edificio (Pulsar E)\n");
  printf("\tListar Edificios (Pulsar L)\n");
  printf("\tApartamentos Disponibles (Pulsar A)\n");
  printf("\tReservar Apartamento (Pulsar R)\n");
  printf("\tReservas Mensuales Apartamento (Pulsar M)\n");
  printf("\tSalir (Pulsar S)\n\n");
  printf("Teclear una opcion valida (E|L|A|R|M|S)? ");
}

int TADGestor::main_loop() {
  TADDatosEdificio  datosEdificio;
  TipoVectorChars   inputUsuario;

  strcpy(datosEdificio.nombre, "testuno");
  datosEdificio.numeroTipoApartamento[BASICO] = 16;
  datosEdificio.numeroTipoApartamento[NORMAL] = 2;
  datosEdificio.numeroTipoApartamento[LUJO] = 2;
  datosEdificio.id = 1;
  datosEdificio.totalApartamentos = 20;
  this->vectorEdificios[0].constructor(&datosEdificio);

  strcpy(datosEdificio.nombre, "testdos");
  datosEdificio.numeroTipoApartamento[BASICO] = 2;
  datosEdificio.numeroTipoApartamento[NORMAL] = 16;
  datosEdificio.numeroTipoApartamento[LUJO] = 2;
  datosEdificio.id = 2;
  datosEdificio.totalApartamentos = 20;
  this->vectorEdificios[1].constructor(&datosEdificio);

  strcpy(datosEdificio.nombre, "testtres");
  datosEdificio.numeroTipoApartamento[BASICO] = 2;
  datosEdificio.numeroTipoApartamento[NORMAL] = 2;
  datosEdificio.numeroTipoApartamento[LUJO] = 16;
  datosEdificio.id = 3;
  datosEdificio.totalApartamentos = 20;
  this->vectorEdificios[2].constructor(&datosEdificio);

  strcpy(datosEdificio.nombre, "testcuatro");
  datosEdificio.numeroTipoApartamento[BASICO] = 6;
  datosEdificio.numeroTipoApartamento[NORMAL] = 6;
  datosEdificio.numeroTipoApartamento[LUJO] = 8;
  datosEdificio.id = 4;
  datosEdificio.totalApartamentos = 20;
  this->vectorEdificios[3].constructor(&datosEdificio);

  strcpy(datosEdificio.nombre, "testcinco");
  datosEdificio.numeroTipoApartamento[BASICO] = 0;
  datosEdificio.numeroTipoApartamento[NORMAL] = 0;
  datosEdificio.numeroTipoApartamento[LUJO] = 1;
  datosEdificio.id = 5;
  datosEdificio.totalApartamentos = 1;
  this->vectorEdificios[4].constructor(&datosEdificio);

  memset(&inputUsuario, 0, LongitudVectorChars);
  while (1) {
    this->intro();
    scanf("%29s", inputUsuario);
    fflush(stdin);
    if (strlen(inputUsuario) != 1) {
      fprintf(stderr, "\n\n[ERROR] - El input %s es incorrecto\n", inputUsuario);
      continue ;
    }

    switch(toupper(inputUsuario[0])) {
      case 'E':
        this->editarEdificio();
        break ;
      case 'L':
        this->listarEdificios();
        break ;
      case 'A':
        this->apartamentosDisponibles();
        break ;
      case 'R':
        this->reservarApartamento();
        break ;
      case 'M':
        this->reservasMensualesApartamento();
        break ;
      case 'S':
        return 0;
        break ;
      default:
        fprintf(stderr, "\n\n[ERROR] - El input %s es incorrecto\n", inputUsuario);
    }
  }
  return 0;
}
